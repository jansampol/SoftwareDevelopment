# Steps to run the code of Assignment 1.3

First of all, we have to set our directory:

```cd assignment1.3```

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