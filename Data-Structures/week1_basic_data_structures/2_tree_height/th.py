
import sys, threading
sys.setrecursionlimit(10**7)
threading.stack_size(2**27)

def height(i, h, arr):
    if(arr[i] == -1):
        h[i] = 1
        return h[i]

    elif(h[i] != -1):
        return h[i]
    else:
        h[i] = 1 + height(arr[i], h, arr)
        return h[i]


def main():

    n = int(input())
    arr = [int(x) for x in input().split()]
    h = [-1] * n
#    print(h)
    mx = -1
    for i in range(n):
        hm = height(i, h, arr)
        if(hm > mx):
            mx = hm

    print(mx)


main()
