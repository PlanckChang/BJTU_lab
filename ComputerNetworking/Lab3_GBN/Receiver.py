
import socket
from random import random
import time
import re


class Receiver:
    def __init__(self, total_packet=10, time_during=5, receiver_port=12345, prob=0.1):
        receiver_address = ('127.0.0.1', receiver_port)
        self.s = socket.socket()
        socket.setdefaulttimeout(time_during)
        self.s.bind(receiver_address)
        self.s.listen(1)
        socket.setdefaulttimeout(time_during)
        self.nexseq = 0
        self.prob = prob
        self.total_packet = total_packet

    def receive(self):
        conc, addr = self.s.accept()
        print(f"{addr} connected Receiver")

        while True:
            try:
                data = conc.recv(20)
                # print(data)
                ack = int(re.findall(r"\d", data.decode())[0])
            except:
                if self.nexseq == self.total_packet:
                    print("Receiver received all packet")
                    time.sleep(100)

            #  simulate corruption
            if random() < self.prob:
                print(f"Receiver gain a corruption {ack}")
                continue
            else:
                print(f"Receiver receive packet {ack}")
                if int(ack) == self.nexseq:
                    packet = f"ack {ack}"
                    self.nexseq += 1
                    self.nexseq = min(self.nexseq, self.total_packet)
                    conc.send(packet.encode())
                    time.sleep(1)
                    print(f"Receiver send ack {ack}")
                else:
                    if self.nexseq == 0:
                        continue
                    packet = f"ack {self.nexseq-1}"
                    print(f'Receiver send ack {self.nexseq - 1}')
                    conc.send(packet.encode())
                    time.sleep(1)


    def run(self):
        self.receive()
        time.sleep(100)


if __name__ == "__main__":
    receiver = Receiver()
    receiver.run()
