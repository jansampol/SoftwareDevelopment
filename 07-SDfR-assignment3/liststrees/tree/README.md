## Main program

Change if you are not tree:

```cd liststrees/tree```

Run the following in the terminal depending on the OS you have:

- Mac

```
g++ -std=c++14 -Iinclude -o assignment3.2 src/main.cpp src/isValidInteger.cpp
./assignment3.2
```

- Windows 

```
g++ -std=c++14 -Iinclude -o assignment3.2.exe src/main.cpp src/isValidInteger.cpp
.\assignment3.2.exe
```

## Test program

Run the following in the terminal depending on the OS you have:

- Mac

```
g++ -std=c++14 -Iinclude -o test_bin test/test.cpp src/isValidInteger.cpp
./test_bin
```

- Windows

```
g++ -std=c++14 -Iinclude -o test_bin.exe test/test.cpp src/isValidInteger.cpp
.\test_bin.exe
```