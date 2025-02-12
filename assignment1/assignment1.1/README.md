# Steps to run the code

Go to the desired directory: ```cd assignment1.1```


Compile the ```main.cpp```and ```divide.cpp```files

```
g++ -std=c++14 -c src/main.cpp -o build/main.o

g++ -std=c++14 -c src/divide.cpp -o build/divide.o
```

and link them

```
g++ build/main.o build/divide.o -o assignment1.1
```

Run the executable using 

```
./assignment1.1
```
