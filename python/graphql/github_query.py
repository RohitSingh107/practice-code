# An example to get the remaining rate limit using the Github GraphQL API.

import requests
import json
import matplotlib.pyplot as plt
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

# print(len(result["data"]["user"]["repositories"]["nodes"]))
# print(json.dumps(result["data"]["user"]["repositories"]["nodes"][0], indent=2))
# print(json.dumps(result["data"]["user"]["repositories"]["nodes"][0]["languages"]["edges"][0], indent=4))
# print(result["data"]["user"]["repositories"]["nodes"])

total = 0

lang_count = {}


for repo in result["data"]["user"]["repositories"]["nodes"]:

    for lang in repo["languages"]["edges"]:

        # print("name is {},  size is {}".format(
        #     lang["node"]["name"], lang["size"]))
        # print("language is {}, size is {}".format(l, s))
        l = lang["node"]["name"]
        s = lang["size"]

        total += s

        if l not in lang_count:
            lang_count[l] = s
        else:
            lang_count[l] += s

print(total)
# print(lang_count)


plt.bar(range(len(lang_count)), list(lang_count.values()), align='center')
plt.xticks(range(len(lang_count)), list(
    lang_count.keys()), rotation='vertical')
# plt.show()
