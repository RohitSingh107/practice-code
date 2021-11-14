import json
import requests

response = requests.get("https://jsonplaceholder.typicode.com/todos")
# print(response.text)

todos = json.loads(response.text)

# with open("todos.json", "w") as f:
    # json.dump(todos, f, indent= 4)

print(todos[0]["userId"])