#!/usr/bin/python3
import os
import sys

def main():
    print("unit_test.py:compiling unit test...")
    target_name = sys.argv[1].split('.')[0]
    is_compile_success = os.system("g++ -D UNIT_TEST -std=gnu++0x -g -Wall -lboost_serialization -I/usr/include/opencv2 -lopencv_core -lopencv_highgui -lopencv_imgproc {target}.cpp -o unit_test.out".format(target = target_name))
    if(is_compile_success!=0):
        return 1
    else:
        
        os.system("chmod +x unit_test.out")
        print("unit_test.py:result is...")
        return_code = os.system("./unit_test.out")
        print("unit_test.py:return_code is {code}.".format(code = return_code))
        if(return_code == 11):
            print("unit_test.py:segumentation fault?")
        #os.system("rm unit_test.out")
        
        return 0

if __name__ == "__main__":
    main()
