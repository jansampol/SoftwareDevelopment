# Steps to run the code of Assignment 1.2

First of all, we have to set our directory:

```cd assignment1.2```

To run the code, since there already exist an executable file, you can simply write down the following line in the terminal:

```
./bmi_calculator
```

To create the executable, the following steps must be followed:

```
g++ -std=c++14 -c src/main.cpp -o build/main.o

g++ -std=c++14 -c src/compute_BMI.cpp -o build/compute_BMI.o

g++ -std=c++14 -c src/print_info.cpp -o build/print_info.o

g++ -std=c++14 -c src/evaluate_BMI.cpp -o build/evaluate_BMI.o


```

After compiling, we can link both files and run the executable by means of this

```
g++ build/main.o build/compute_BMI.o build/print_info.o build/evaluate_BMI.o -o bmi_calculator

./bmi_calculator
```