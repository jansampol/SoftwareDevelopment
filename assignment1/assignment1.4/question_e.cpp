#include <iostream>
void function();


// Declare global variable
int a = 20;

int main() {

    // Declare local variable
    int a = 10;
    // Calls the function, which uses the global variable
    function();
    // This displays the locals variable, since we are inside main()
    std::cout << a;
    return 0;
}
void function() {
    // Prints the global a variable
    std::cout << a << std::endl;
}