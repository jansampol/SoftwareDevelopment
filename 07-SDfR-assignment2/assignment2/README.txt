g++ -std=c++14 -c src/main.cpp  -o build/main.o 
g++ -std=c++14 -c src/print_maze.cpp  -o build/print_maze.o
g++ -std=c++14 -c src/find_init.cpp  -o build/find_init.o
g++ build/main.o build/print_maze.o build/find_init.o -o assignment2
./assignment2