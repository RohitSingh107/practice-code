import subprocess

process = subprocess.Popen(['ping', '-c 4', 'python.org'], 
                           stdout=subprocess.PIPE,
                           stderr=subprocess.PIPE,
                           universal_newlines=True)

while True:
    output = process.stdout.readline()
    print(output)
    
    return_code = process.poll()
    if return_code is not None:
        print('RETURN CODE', return_code)
         
        for output in process.stdout.readlines():
            print(output)
        break