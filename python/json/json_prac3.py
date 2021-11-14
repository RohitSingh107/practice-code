# Python Program to update JSON

import json

x = """{"organization" : "GeeksForGeeks",
"city" : "Noida",
"country" : "India"
}"""

y = {"pin" : 110096}

z = json.loads(x)

z.update(y)

# print(json.dumps(z))