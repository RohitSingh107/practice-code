def readfile(filename):
    
    try:
        with open(filename, "r") as f:
            # print(f.readline())
            # for line in f:
                # print(line, end= '')
            return f.read()

    except FileNotFoundError:
        print(f"{filename} is not found, first create it")

def writefile(filename, content = ""):
    with open(filename, "w") as f:
        f.write(content)

if __name__ == "__main__":
    # writefile("file2.txt")
    # readfile("file1.txt")

    with open("file1.txt") as f:
        file1 = f.read()
        # print(file1)
    with open("file3.txt", "w") as f:
        for line in file1:
            f.write(line)