MAC

To run the main code:

g++ -std=c++14 -Iinclude -c src/print_maze.cpp  -o build/print_maze.o
g++ -std=c++14 -Iinclude -c src/find_init.cpp  -o build/find_init.o
g++ -std=c++14 -Iinclude -c src/place_exit.cpp  -o build/place_exit.o
g++ -std=c++14 -Iinclude -c src/traverseMaze.cpp  -o build/traverseMaze.o
g++ -std=c++14 -Iinclude -c src/main.cpp  -o build/main.o
g++ build/main.o build/print_maze.o build/find_init.o build/place_exit.o build/traverseMaze.o -o assignment2
./assignment2

To check the test file:

g++ -std=c++14 -Iinclude -o test_runner test/test_maze.cpp src/print_maze.cpp src/find_init.cpp src/place_exit.cpp src/traverseMaze.cpp
./test_runner 

WINDOWS

To run the main code:

g++ -std=c++14 -Iinclude -c src/print_maze.cpp  -o build/print_maze.o
g++ -std=c++14 -Iinclude -c src/find_init.cpp  -o build/find_init.o
g++ -std=c++14 -Iinclude -c src/place_exit.cpp  -o build/place_exit.o
g++ -std=c++14 -Iinclude -c src/traverseMaze.cpp  -o build/traverseMaze.o
g++ -std=c++14 -Iinclude -c src/main.cpp  -o build/main.o
g++ build/main.o build/print_maze.o build/find_init.o build/place_exit.o build/traverseMaze.o -o assignment2.exe
.\assignment2.exe

To cjeck the test file:

g++ -std=c++14 -Iinclude -o test_runner.exe test/test_maze.cpp src/print_maze.cpp src/find_init.cpp src/place_exit.cpp src/traverseMaze.cpp
.\test_runner.exe