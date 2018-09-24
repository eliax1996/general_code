import threading
import time
import multiprocessing
import hashlib


def fib(x):

    if (x <= 1):
        return 1

    return fib(x - 1) + fib(x - 2)


def worker(x, i):
    """thread worker function"""
    duration = time.time()
    fib(x)
    duration = time.time() - duration
    # print 'thread number ' + str(i) + ' finished in: ' + str(duration)
    return


duration = time.time()


# for i in range(0, 1000):
# fib(20)

threads = []
for i in range(100):
    for k in range(0, 10):
        t = multiprocessing.Process(target=worker, args=(20, i,))
        threads.append(t)
        t.start()

    for t in threads:
        t.join()


duration = time.time() - duration

print("launch complete in: " + str(duration))
