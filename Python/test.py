# from threading import Timer
from time import time_ns


print(time_ns())

st = time_ns()
cnt = 0
while True:
    et = time_ns()
    if et - st >= (cnt + 1) * 1000:
        cnt += 1
    
    if cnt % 100000 == 0:
        print((et - st) // 1000, cnt)

    # a = 0
    # for i in range(10):
    #     a += 1


# c = 0

# def hello():
#     global c
#     c += 1

# def display():
#     global c
#     print(c)

# class RepeatingTimer(Timer): 
#     def run(self):
#         while not self.finished.is_set():
#             self.function(*self.args, **self.kwargs)
#             self.finished.wait(self.interval)

# RepeatingTimer(0.00001, hello).start()
# RepeatingTimer(1, display).start()

