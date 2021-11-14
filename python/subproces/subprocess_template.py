import subprocess as sp

# cmd= ["ls"]
# p  = sp.Popen(cmd, shell=False, stdout=sp.PIPE, stdin=sp.PIPE, stderr=sp.PIPE, text=True) 
# rc =p.wait()

cmd= ["echo $HOME"]
p  = sp.Popen(cmd, shell=True, stdout=sp.PIPE, stdin=sp.PIPE, stderr=sp.PIPE, text=True) 
rc = p.wait()

output, error = p.communicate()

for i in output.split():
    print(i)

for i in error.split():
    print(i)