# An example to get the remaining rate limit using the Github GraphQL API.

import requests
import json
headers = {"Authorization": "Bearer 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"}


# A simple function to use requests.post to make the API call. Note the json= section.
def run_query(query):
    request = requests.post('https://api.github.com/graphql',
                            json={'query': query}, headers=headers)
    if request.status_code == 200:
        return request.json()
    else:
        raise Exception("Query failed to run by returning code of {}. {}".format(
            request.status_code, query))


# The GraphQL query (with a few aditional bits included) itself defined as a multi-line string.
query = """
query userInfo($login: String = "%s") {
        user(login: $login) {
          # fetch only owner repos & not forks
          repositories(ownerAffiliations: OWNER, isFork: false, first: %s) {
            nodes {
              name
              languages(first: %s, orderBy: {field: SIZE, direction: DESC}) {
                edges {
                  size
                  node {
                    color
                    name
                  }
                }
              }
            }
          }
        }
      }
"""


variables = {
    "username": "RohitSingh107",
    "noOfRepos": 50,
    "langCount": 10
}


result = run_query(query % tuple(variables.values()))  # Execute the query

# print(result)

print(len(result["data"]["user"]["repositories"]["nodes"]))
print(result["data"]["user"]["repositories"]["nodes"])
# print(json.dumps(result["data"]["user"]["repositories"]["nodes"][0]["languages"]["edges"], indent=4))
# print(result["data"]["user"]["repositories"]["nodes"])
