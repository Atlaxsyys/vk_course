#include <iostream>
#include <vector>
#include <filesystem>

#include "BinaryTree.hpp"
#include "algorithms.hpp"

int main()
{   
    // 1
    BinaryTree<int> tree1;
    std::vector<int> array1 = {8, 9, 11, 7, 16, 3, 1};

    TreeAlgorithms::buildFromArray(tree1, array1);

    tree1.generateDOTfile("dot/tree1.dot");
    tree1.generatePNGfile("dot/tree1.dot", "img/tree1.png");

    // 2 BFS symmetric
    BinaryTree<int> tree2;
    std::vector<int> array2 = {1, 2, 2, 3, 4, 4, 3};
    
    TreeAlgorithms::buildFromArray(tree2, array2);

    tree2.generateDOTfile("dot/tree2_symmetric.dot");
    tree2.generatePNGfile("dot/tree2_symmetric.dot", "img/tree2_symmetric.png");
    
    std::cout << "isSymmetric (BFS): " << (TreeAlgorithms::isSymmetric(tree2) ? "true" : "false") << std::endl;
    std::cout << "isSymmetricDFS:    " << (TreeAlgorithms::isSymmetricDFS(tree2) ? "true" : "false") << std::endl;

    // 2 asymmetric BFS 
    BinaryTree<int> tree3;
    std::vector<int> array3 = {1, 2, 2, 3, 4, 5, 3};
    
    TreeAlgorithms::buildFromArray(tree3, array3);

    tree3.generateDOTfile("dot/tree3_asymmetric.dot");
    tree3.generatePNGfile("dot/tree3_asymmetric.dot", "img/tree3_asymmetric.png");
    
    std::cout << "isSymmetric (BFS): " << (TreeAlgorithms::isSymmetric(tree3) ? "true" : "false") << std::endl;
    std::cout << "isSymmetricDFS:    " << (TreeAlgorithms::isSymmetricDFS(tree3) ? "true" : "false") << std::endl;

    // 3
    BinaryTree<int> tree5a, tree5b;
    std::vector<int> array5 = {1, 2, 3, 4, 5};
    
    TreeAlgorithms::buildFromArray(tree5a, array5);
    TreeAlgorithms::buildFromArray(tree5b, array5);

    BinaryTree<int> tree5c;
    std::vector<int> array5c = {1, 2, 3, 4, 6};
    TreeAlgorithms::buildFromArray(tree5c, array5c);

    std::cout << (TreeAlgorithms::isSameTree(tree5a, tree5b) ? "true" : "false") << std::endl;
    std::cout << (TreeAlgorithms::isSameTree(tree5a, tree5c) ? "true" : "false") << std::endl;

    // 4
    std::vector<int> array4 = {8, 9, 11, 7, 16, 3, 1, 4};
    BinaryTree<int> tree4;
    TreeAlgorithms::buildFromArray(tree4, array4);

    tree4.generateDOTfile("dot/tree4.dot");
    tree4.generatePNGfile("dot/tree4.dot", "img/tree4.png");

    std::cout << TreeAlgorithms::minDepth(tree4) << std::endl;

    // 5
    std::cout << TreeAlgorithms::maxMinMultiplication(array1) << std::endl;

    return 0;
}