# Steps to run the code

### Explanation of the folder organization

This folder contains the main 1.1 assignment and a folder with all the versions that generate the different errors we were asked to create. 

#### Error_exercises folder

The error_exercises folder is composed by three different subfolders in which there are the the codes with the asked errors. To run the codes you first have to go to the desired directory. To to that, depending on which error do you want to check, yo have to right down the following:

- **Compilation error:** ``` cd assignment1.1/error_exercises/compilation_error/src```
- **Linking error:** ```cd assignment1.1/error_exercises/linking_error/src```
- **Runtime error:** ```cd assignment1.1/error_exercises/runtime_error/src```


Once you are in the desired directory, you can "try" to compile the ```main.cpp``` and the  ```divide.cpp``` files using:

```
g++ -std=c++14 -c main.cpp
g++ -std=c++14 -c divide.cpp
```

After compiling, we can link both files and run the executable by means of this

```
g++ main.o divide.o -o assignment1.1_error
./assignment1.1_error
```

#### Main assignment

Go to the desired directory: ```cd assignment1.1/src```


Compile the ```main.cpp```and ```divide.cpp```files and link them as you did before (change the name of the executable)

```
g++ -std=c++14 -c main.cpp
g++ -std=c++14 -c divide.cpp
g++ main.o divide.o -o assignment1.1
```
Run the executable using 

```
./assignment1.1
```
