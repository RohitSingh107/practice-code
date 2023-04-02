import socket
import sys


class MyServer:
    """My Server for testing purposes
    """

    def __init__(self, sock=None):
        if sock is None:
            self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM) # AF_INET is the Internet address family for IPv4, SOCK_STREAM is the socket type for TCP
        else:
            self.sock = sock

    def bind_and_listen(self, host = "", port = 9999):
        try:

            print(f"Binding socket to port: {port} and host: {host}")
            self.sock.bind((host, port))
            self.sock.listen(5) # the number of unaccepted connections that the system will allow before refusing new connections. If not specified, a default reasonable value is chosen.

        except socket.error as e:
            print(f"Error binding socket: {str(e)}")
            print("Retrying...")

            self.bind_and_listen()

    def accept(self):
        try:
            con, add  =self.sock.accept()
            self.conn = con
            print(f"Connection has been established, IP: {add[0]}, Port: {add[1]}")

            if self.sock and self.conn:
                self.__send_commands()



        except socket.error as e:
            print(f"Error Establishing connection to client: {str(e)}")


    def __send_commands(self, bufSize = 2048):

        while True:
            cmd = input()

            if cmd == "quit":
                self.conn.close()
                self.sock.close()
                sys.exit()

            if len(str.encode(cmd)) == 0:
                continue

            self.conn.send(str.encode(cmd))

            client_response = str(self.conn.recv(bufSize), "utf-8")
            print(client_response, end="")


def main():
    s = MyServer()

    s.bind_and_listen()
    s.accept()




if __name__ == "__main__":
    main()



