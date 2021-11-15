import os

cwd = os.getcwd()

# print(cwd)

lis_dir = os.listdir(cwd)

# print(lis_dir)

files_to_delete = []

for i in lis_dir:
    if os.path.isdir(i) or i.endswith('.cpp') or i.endswith('.py'):
        # print(i)
        pass
    else:
        files_to_delete.append(i)

print("Following files will be deleted.\n")
print(files_to_delete)
confirm = input("\nConfirm ? : ")

if confirm == 'yes':
    for file in files_to_delete:
        path = os.path.join(cwd, file)
        os.remove(path)
    print("Done.")

else:
    print("\nAborted")