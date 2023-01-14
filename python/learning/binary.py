data = [47,7,32,10,159]
buffer = bytes(data)
print(buffer)
f = open('binaryfile.txt', 'bw')
f.write(buffer)
f.close()