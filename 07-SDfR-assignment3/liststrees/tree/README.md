Main program

cd liststrees/tree

g++ -std=c++14 -Iinclude -o assignment3.2 src/main.cpp src/isValidInteger.cpp
./assignment3.2


Test

g++ -std=c++14 -Iinclude -o test_bin test/test.cpp src/isValidInteger.cpp
./test_bin