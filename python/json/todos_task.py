import json
import requests

response = requests.get("https://jsonplaceholder.typicode.com/todos")

todos = json.loads(response.text)

# with open("todos.json", "w") as f:
    # json.dump(todos, f, indent= 4)

# print(todos[0]["userId"])

top_users = {}

for i in todos:
    if i["completed"]:
        try:
            top_users[i["userId"]] += 1
        except KeyError:
            top_users[i["userId"]] = 1

sorted_top_users = sorted(top_users.items(), key = lambda x: x[1], reverse= True)

max_task = sorted_top_users[0][1]

toppers = []
for i in sorted_top_users:
    if i[1] < max_task:
        break
    toppers.append(str(i[0]))

max_users = " and ".join(toppers)

s = "s" if len(max_users) > 1 else ""

print(f"user{s} {max_users} completed {max_task} TODOs")


def keep(todo):
    is_complete = todo["completed"]
    has_max_completed = str(todo["userId"]) in toppers
    return is_complete and has_max_completed

with open("filtered_list.json", "w") as f:
    filtered_todo = list(filter(keep, todos))
    print(filtered_todo)
    json.dump(filtered_todo, f, indent= 4)

