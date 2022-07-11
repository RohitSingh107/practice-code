from bs4 import BeautifulSoup
import re
import json


with open('Bookmarks1.html') as f:
    soup = BeautifulSoup(f, "html.parser")

sl = soup.find_all()

tmp = []

for tag in sl:
    if tag.name == 'a' or tag.name == 'h3':
        tmp.insert(0, tag.get_text())
        # print(tag.get('href'))


Bookmarks = {}

for tag in sl:

    if tag.name == 'h3':
        nk = tag.get_text()
        newKey = re.sub(r"[^a-zA-Z0-9 ]","",nk)
        Bookmarks[newKey] = {}
    
    if tag.name == 'a':
        nk = tag.get_text()
        k = re.sub(r"[^a-zA-Z0-9 ()!'\"&|:]","",nk)
        Bookmarks[newKey][k] = tag.get('href')

# Bookmarks = {
#         "dir1" : {
#             "Item1" : "Link"
#             },
#         "dir2" : {}
#         }

# print(Bookmarks)

# for k,v in Bookmarks.items():
#     print(k, v)
#     print("\n")
#     print("\n")
#     print("\n")
#     print("\n")
#     print("\n")
#     print("\n")
#     print("\n")

# for d in Bookmarks.keys():
#     print(d)


for d in Bookmarks.keys():
    if len(Bookmarks[d]) == 0:
        print("Popping: ", d)



with open("bookmarks.json", "w") as outfile:
    json.dump(Bookmarks, outfile)
