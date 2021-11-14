# importing libraries
import subprocess
import os
  
# a function to ping given host
def ping(host):
  
    # command is pong
    cmd = 'ping'
  
    # send two packets of data to the host
    # this is specified by '-c 2' in the 
    # args list
    temp = subprocess.Popen([cmd, '-c 5', host], stdout = subprocess.PIPE)
      
    # get the output of ping
    output = str(temp.communicate())
          
    output = output.split("\n")
      
    output = output[0].split('\\')
  
    # variable to store the result
    res = []
  
    for line in output:
        res.append(line)
  
    # print the results
    print('ping results: ')
    print('\n'.join(res[len(res) - 3:len(res) - 1]))
  
    return res
  
  
if __name__ == '__main__':
          
    # ping google
    ping('www.google.com')