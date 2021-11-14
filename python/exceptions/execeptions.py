import sys

def windows_interaction():
    assert ('linux'in sys.platform), "This code runs on Windows only :("
    print("Doing something")    

try:
    windows_interaction()
        
except AssertionError as error:
    print("It is not windows")
    print(error)

else:
    try:
        with open('file.log') as file:
            read_data = file.read()
        
    except FileNotFoundError as fnf_error:
        print(fnf_error)

finally:
    print("Cleaning Up, irrespective of any expectations. This section always run.")
    
