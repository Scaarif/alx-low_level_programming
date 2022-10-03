import ctypes

cops = ctypes.CDLL('liball.so')
l = cops._strlen("this is a test!")
print("len: {} ".format(l))
ab = cops._abs(-50)
print("abs: ", ab)
cops._puts("This is a test!")
