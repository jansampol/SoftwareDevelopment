## Main program

- Mac

```
g++ -std=c++14 -Iinclude -o assignment4.1 src/*.cpp
./assignment4.1
```

- Windows

```
g++ -std=c++14 -Iinclude -o assignment4.1.exe src/*.cpp
./assignment4.1.exe
```


## Test program

- Mac
```
g++ -std=c++14 -I./include -o test_program test/test.cpp  src/Package.cpp src/TwoDayPackage.cpp src/OvernightPackage.cpp 
./test_program
```

- Windows
```
g++ -std=c++14 -I./include -o test_program.exe test/test.cpp  src/Package.cpp src/TwoDayPackage.cpp src/OvernightPackage.cpp 
./test_program.exe
```