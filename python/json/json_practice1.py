import json

# with open("data_file.json", "r") as f:
    # data = json.load(f)

# print(data)
# print(type(data))

json_string = """
{
    "researcher" : {
        "name" : "Ford Perfect",
        "species" : "Belud",
        "relatives" : [
            {
                "name" : "Zea Gaad",
                "species" : "Betzx"
            }
        ]
    }
}
"""

data = json.loads(json_string)
# print(data)
# print(type(data))

print(json_string)
print(type(json_string))