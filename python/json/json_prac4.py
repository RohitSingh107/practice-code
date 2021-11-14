import json

def write_json(new_data, filename = "data_file.json"):
    with open(filename, "r+") as file:
        file_data = json.load(file)
        file_data["president"].update(new_data)
        file.seek(0)

        json.dump(file_data, file, indent=4)

def update_json(new_data, filename = "data_file.json"):
    with open(filename, "r+") as file:
        file_data = json.load(file)
        file_data.update(new_data)
        file.seek(0)

        json.dump(file_data, file, indent=4)


y = {"emp_name":"Nikhil",
     "email": "nikhil@geeksforgeeks.org",
     "job_profile": "Full Time"
     }

x = {"emp_name":"R",
     "email": "R@geeksforgeeks.org",
     "job_profile": "Time"
     }


write_json(y)
update_json(x)