import serial
from threading import Thread
import chardet
import time, sched

ser = serial.Serial('COM9', 115200, timeout=1)
data = []

def read():
    s = str(ser.readline())
    if len(s) >= 6:
        s = s[2:6]
        # print(time.time())
        if s.isnumeric():
            # print(s)
            data.append(int(s))


delta = 0.001
begin = time.time()
cnt = 1

while cnt < int(1 / delta):
    if (time.time() - begin) / delta >= cnt:
        cnt += 1
        Thread(target=read).start()

print(len(data))

# from matplotlib import pyplot as plt

# plt.plot(data)
# plt.show()

# import serial
# ser = serial.Serial('COM9', 115200, timeout=1)
# s = str(ser.readline())[2:6]
# print(s)
# print(int(ser_bytes[0:len(ser_bytes)-2].decode("utf-8")))