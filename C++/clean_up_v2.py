import os

cwd = os.getcwd()

# print(cwd)


# lis_dir = os.listdir(cwd)
# sub_dirs = [dirs for dirs in lis_dir if os.path.isdir(dirs)]
# print(sub_dirs)

def clean_dir(dir_name):
    lis_dir = os.listdir(dir_name)
    files_to_delete = []
    for i in lis_dir:
        if os.path.isdir(i):
            clean_dir(os.path.join(dir_name, i))

        elif i.endswith('.cpp') or i.endswith('.py'):
            pass
        else:
            files_to_delete.append(os.path.join(dir_name, i))
    
    if len(files_to_delete) != 0: 

        print("\nFollowing files will be deleted.\n")
        for f in files_to_delete:
            print(f)
        confirm = input("\nConfirm ? : ")

        if confirm == 'yes':
            for file in files_to_delete:
                # path = os.path.join(cwd, file)
                os.remove(file)
            print("Cleaned this directory.")

        else:
            print("Not touching this directory.")

    # print("All Done.")

clean_dir(cwd)