import json

with open("myjsonfile.json", "r") as f:
    json_object = json.load(f)

print(json_object["people"][0]["name"])
