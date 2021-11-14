# Python 3 program to demonstrate subprocess 
# module
  
import subprocess
import os
  
def excuteC():
  
    # store the return code of the c program(return 0)
    # and display the output
    s = subprocess.check_call("gcc subp.c -o out1;./out1", shell = True)
    print(", return code", s)
  
def executeCpp():
  
    # create a pipe to a child process
    data, temp = os.pipe()
  
    # write to STDIN as a byte object(convert string
    # to bytes with encoding utf8)
    os.write(temp, bytes("5 10\n", "utf-8"));
    os.close(temp)
  
    # store output of the program as a byte string in s
    s = subprocess.check_output("g++ subp.cpp -o out2;./out2", stdin = data, shell = True)
  
    # decode s to a normal string
    print(s.decode("utf-8"))
  
def executeJava():
  
    # store the output of
    # the java program
    s = subprocess.check_output("javac subp.java;java HelloWorld", shell = True)
    print(s.decode("utf-8"))
  
  
# Driver function
if __name__=="__main__":
    excuteC()    
    executeCpp()
    executeJava()