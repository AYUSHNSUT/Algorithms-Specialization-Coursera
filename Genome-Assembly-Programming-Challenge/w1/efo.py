
def read_data():
    numreads = 1608
    reads = set()
    for _ in range(numreads):
        reads.add(input().strip())
    return sorted(reads)


def LCSubStr(X, Y, m, n):

    LCSuff = [[0 for k in range(n+1)] for l in range(m+1)]

    result = 0

    row = 0
    col  = 0
    for i in range(m + 1):
        for j in range(n + 1):
            if (i == 0 or j == 0):
                LCSuff[i][j] = 0
            elif (X[i-1] == Y[j-1]):
                LCSuff[i][j] = LCSuff[i-1][j-1] + 1
                if LCSuff[i][j] > result:
                    result = LCSuff[i][j]
                    row = i
                    col = j
            else:
                LCSuff[i][j] = 0

    LCS = [0] * result
    length = result
    while(LCSuff[row][col] != 0):
        length -= 1
        LCS[length] = X[row-1]

        row -=1
        col-=1


    return result, "".joinStr(LCs)



reads = read_data()
done = [0] * len(reads)
done_c = 0

while(done_c < len(reads)):
    c_max = 0
    cindex = 0
    curr  = 0
    fLCS = ""
    tLCS = ""
    for i in range (1,len(reads)):
        if(done[i] == 0):
            ccount, fLCS  = LCSubStr(reads[curr], reads[i])
            if(ccount > c_max):
                cmax = ccount
                cindex = i
