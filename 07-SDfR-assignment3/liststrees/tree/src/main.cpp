#include "Tree.h"
#include <iostream>

int main() {
    Tree<int> intTree;

    // Insert 10 predefined, unsorted integers
    int values[] = {17, 42, 13, 50, 27, 11, 1, 6, 33, 20, 47, 48};

    std::cout << "Inserting values into the tree: ";
    for (int value : values) {
        std::cout << value << " ";
        intTree.insertNode(value);
    }

    std::cout << "\n\n";

    // Display tree traversals
    std::cout << "Preorder traversal: ";
    intTree.preOrderTraversal();
    std::cout << "\n";

    std::cout << "Inorder traversal: ";
    intTree.inOrderTraversal();
    std::cout << "\n";

    std::cout << "Postorder traversal: ";
    intTree.postOrderTraversal();
    std::cout << "\n\n";

int searchValue;

do {
    std::cout << "Introduce an integer here: ";
    
    // Check if the user entered a valid integer
    if (!(std::cin >> searchValue)) {
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        std::cout << "Invalid input! Please enter an integer.\n";
    } else {
        break; // Exit loop if input is valid
    }

} while (true);
    
    TreeNode<int>* result = intTree.search(searchValue);
    if (result) {
        std::cout << "The integer " << searchValue << " was found in the tree.\n";
    } else {
        std::cout << "The integer " << searchValue << " was NOT found in the tree.\n";
    }

std::cout << "Tree structure:\n";
intTree.outputTree();

    return 0;
}
