# with open("haskell.png", "rb") as byte_reader:
    # for lines in f:
        # print(lines)


# with open("file1.txt", "r") as r:
#     file1 = r.read()

# with open("file1.txt", "r") as r:
#     file1= r.read()

with open("file3.txt", "a") as w, open("file1.txt") as r:

    file1 = r.read()

    w.writelines(file1)
