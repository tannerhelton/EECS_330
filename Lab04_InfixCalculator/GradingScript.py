import os
import sys

if __name__ == '__main__':
    f1 = open(sys.argv[1])
    f2 = open(sys.argv[2])
    num1 = float(f1.readline().strip())
    num2 = float(f2.readline().strip())
    if (abs(num1 - num2) * 2 / (num1 + num2)) < 0.01:
        print('Yes')
    else:
        print('No')   