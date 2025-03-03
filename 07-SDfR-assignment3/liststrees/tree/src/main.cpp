#include "Tree.h"
#include <iostream>
#include <sstream>
#include <string>

bool isValidInteger(const std::string &str) {
    std::istringstream iss(str);
    int value;
    char extra;
    return (iss >> value) && !(iss >> extra); // Asegura que sea un entero válido sin caracteres extra
}

int main() {
    Tree<int> intTree;

    // Insertar valores en el árbol
    int values[] = {17, 42, 13, 50, 27, 11, 1, 6, 33, 20, 47, 48};

    std::cout << "Inserting values into the tree: ";
    for (int value : values) {
        std::cout << value << " ";
        intTree.insertNode(value);
    }
    std::cout << "\n\n";

    // Mostrar recorridos del árbol
    std::cout << "Preorder traversal: ";
    intTree.preOrderTraversal();
    std::cout << "\n";

    std::cout << "Inorder traversal: ";
    intTree.inOrderTraversal();
    std::cout << "\n";

    std::cout << "Postorder traversal: ";
    intTree.postOrderTraversal();
    std::cout << "\n\n";

    // Pedir repetidamente un número entero hasta que sea válido
    std::string input;
    int searchValue;
    while (true) {
        std::cout << "Introduce un solo número entero: ";
        if (!std::getline(std::cin, input) || input.empty()) {
            std::cerr << "Error: No se ingresó ningún número.\n";
            continue; // Volver a pedir la entrada
        }

        if (isValidInteger(input)) {
            searchValue = std::stoi(input);
            std::cout << "Número válido ingresado: " << searchValue << "\n";
            break; // Salir del bucle si es válido
        } else {
            std::cerr << "Error: Entrada inválida. Solo se permite un número entero.\n";
        }
    }

    // Buscar el número en el árbol
    TreeNode<int>* result = intTree.search(searchValue);
    if (result) {
        std::cout << "The integer " << searchValue << " was found in the tree.\n";
    } else {
        std::cout << "The integer " << searchValue << " was NOT found in the tree.\n";
    }

    // Mostrar la estructura del árbol
    std::cout << "Tree structure:\n";
    intTree.outputTree();

    return 0;
}
