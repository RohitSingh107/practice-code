import subprocess

# p1 = subprocess.run(["ls", "-la"], shell=False, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

# print(p1.returncode)
# print(p1.stdout)

# with open("subprocess_file.txt", "w") as f:
    # p2 = subprocess.run(["ls", "-la"], shell=False, stdout= f, stderr=subprocess.PIPE, text=True)

# p3 = subprocess.run(["ls", "-la", "Fgfwdj"], shell=False, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, check=False)

# print(p3.stderr)

# p4 = subprocess.run(["ls", "-la", "Fgfwdj"], shell=False, stdout=subprocess.PIPE, stderr=subprocess.DEVNULL, text=True, check=False)

# print(p4.stderr)


p5 = subprocess.run(["cat", "subprocess_file.txt"], stdout=subprocess.PIPE ,stderr=subprocess.PIPE, text=True, check=True)

p6 = subprocess.run(["grep", "-n", "ping"], stderr=subprocess.PIPE, text=True, check=True, stdout=subprocess.PIPE, input=p5.stdout)

print(p6.stdout)
