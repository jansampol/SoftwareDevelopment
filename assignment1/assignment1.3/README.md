# Steps to run the code of Assignment 1.3

First of all, we have to set our directory:

```cd assignment1.3```

To run the code, since there already exist an executable file, you can simply write down the following line in the terminal:

```
./person_info
```

To create the executable, the following steps must be followed:

```
g++ -std=c++14 -c src/main.cpp -o build/main.o

g++ -std=c++14 -c src/person.cpp -o build/person.o
```

After compiling, we can link both files and run the executable by means of this

```
g++ build/main.o build/person.o -o assignment1.3

./assignment1.3
```