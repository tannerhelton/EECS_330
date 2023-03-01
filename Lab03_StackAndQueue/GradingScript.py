import os
import sys

if __name__ == '__main__':
    f1 = sys.argv[1]
    f2 = sys.argv[2]
    res_file = "test_result"
    cmd = "diff " + str(f1) + " " + str(f2) + " 2>" + res_file + " >>" + res_file
    #print(cmd)
    os.system(cmd)
    if os.stat(res_file).st_size == 0:
        print('Yes')
    else:
        print('No')     