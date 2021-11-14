import json

data = {
    "president" : {
        "name" : "Zaphodshdh Adsdzz",
        "Species" : "Szxkdw"
    }
}

# with open("data_file.json", "w") as f:
    # json.dump(data, f, indent= 4)

json_string = json.dumps(data, indent= 4)

# print(json_string)
print(type(json_string))

# print(data)
print(type(data))

