import json

mydict = {
    "people": [
        {
            "name" : "Blob",
            "age" : 28,
            "weight" : 80
        },
        {
            "name" : "Anna",
            "age" : 34,
            "weight" : 67
        },
        {
            "name" : "Charles",
            "age" : 45,
            "weight" : 78
        }
    ]
}

json_string = json.dumps(mydict, indent=4)
with open("myjsonfile.json", "w") as f:
        f.write(json_string)

