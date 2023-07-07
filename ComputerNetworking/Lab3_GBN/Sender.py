import socket
import time
from random import random
import re


class Sender:
    def __init__(self, window_size=5, total_packet=10, time_during=5, prob=0.3, receiver_port=12345):
        receiver_address = ("127.0.0.1", receiver_port)
        self.s = socket.socket()
        self.s.connect(receiver_address)
        socket.setdefaulttimeout(time_during)
        print(f"Sender connect to Receiver at {receiver_address}")

        self.base = self.nextseq = 0
        self.window_size = window_size
        self.total_packet = total_packet
        self.time_during = time_during
        self.timer = -1
        self.prob = prob
        self.during = time_during

    def send(self):
        while self.nextseq-self.base < self.window_size:
            if self.nextseq >= self.total_packet:
                self.nextseq = self.total_packet
                break
            packet = "Sender sent packet " + str(self.nextseq)

            self.s.send(packet.encode())
            # sleep for 1 sec to avert packet splicing
            time.sleep(1)
            if self.base == self.nextseq:
                self.timer = time.time()
            self.nextseq += 1

            print(packet)



    def receive(self):
        while True:
            try:
                data = self.s.recv(5)
                # print(data.decode())
            except:
                if self.base == self.total_packet:
                    print("Sender sent all packet")


            acknum = int(re.findall(r"\d", data.decode())[0])
            # simulate the corruption
            if random() < self.prob:

                print(f"sender receive corruption {acknum}")

                continue
            else:
                print(f"Sender receive ack {acknum}")
                self.base = int(acknum) + 1
                if self.base == self.nextseq:
                    self.timer = -1
                else:
                    self.timer = time.time()
                self.send()
            self.timeout()
            if self.base == self.total_packet:
                print("Sender sent all packet")
                time.sleep(100)

    def timeout(self):
        if self.timer == -1:
            return False
        elif time.time() - self.timer >= self.during:
            print("timeout")
            self.timer = time.time()
            for i in range(self.base, self.nextseq):
                packet = "Sender sent packet " + str(i)
                self.s.send(packet.encode())
                time.sleep(1)
                self.timer = time.time()
                print(packet)

    def run(self):
        self.send()
        self.receive()
        time.sleep(10)


if __name__ == "__main__":
    Window_size = 5
    Packet_num = 10
    Time_during = 100
    send = Sender()
    send.run()

