from pymongo import MongoClient
def get_db_handle(db_name, host, port):

 # client = MongoClient(host=host,
 #                      port=int(port),
 #                      username=username,
 #                      password=password
 #                     )
 client = MongoClient('localhost', 27017)
 db_handle = client['db_name']
 return db_handle, client
