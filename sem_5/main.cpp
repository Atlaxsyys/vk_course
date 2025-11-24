#include <iostream>
#include <vector>

#include "BinaryTree.hpp"
#include "algorithms.hpp"

int main()
{
    // 1
    std::cout << "1. Testing isMaxHeap (array versions):" << std::endl;
    std::vector<int> maxHeapArray = {90, 70, 80, 20, 10, 50, 60};
    std::vector<int> notMaxHeapArray = {10, 20, 30, 40, 50};
    
    std::cout << "   Array [90,70,80,20,10,50,60] is max heap: " 
              << TreeAlgorithms::isMaxHeap(maxHeapArray) << std::endl;
    std::cout << "   Array [10,20,30,40,50] is max heap: " 
              << TreeAlgorithms::isMaxHeap(notMaxHeapArray) << std::endl;
    std::cout << "   BFS version - Array [90,70,80,20,10,50,60] is max heap: " 
              << TreeAlgorithms::isMaxHeapBFS(maxHeapArray) << std::endl;
    std::cout << std::endl;

    // 1
    std::cout << "1. Testing isMaxHeap (tree version):" << std::endl;
    BinaryTree<int> tree1;
    std::vector<int> heapTreeData = {90, 70, 80, 20, 10, 50, 60};
    tree1.buildTreeFromArray(heapTreeData);
    std::cout << "   Max heap tree is max heap: " 
              << TreeAlgorithms::isMaxHeapTree<int>(tree1) << std::endl;
    std::cout << std::endl;

    // 2
    std::cout << "2. Testing isCompleteTree:" << std::endl;
    BinaryTree<int> tree2;
    std::vector<int> completeTreeData = {1, 2, 3, 4, 5, 6};
    tree2.buildTreeFromArray(completeTreeData);
    std::cout << "   Complete tree [1,2,3,4,5,6] is complete: " 
              << TreeAlgorithms::isCompleteTree<int>(tree2) << std::endl;

    // 3
    std::cout << "3. Testing mergeKSortedArrays:" << std::endl;
    std::vector<std::vector<int>> sortedArrays = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };
    std::vector<int> merged1 = TreeAlgorithms::mergeKSortedArrays(sortedArrays);
    std::vector<int> merged2 = TreeAlgorithms::mergeKSortedArraysOptimized(sortedArrays);
    
    std::cout << "   Simple merge result: ";
    for (int num : merged1) std::cout << num << " ";
    std::cout << std::endl;
    
    std::cout << "   Optimized merge result: ";
    for (int num : merged2) std::cout << num << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    // 4
    std::cout << "4. Testing kth smallest element:" << std::endl;
    BinaryTree<int> bst;
    std::vector<int> bstData = {5, 3, 7, 2, 4, 6, 8};
    bst.buildTreeFromArray(bstData);
    
    std::cout << "   3rd smallest (iterative): " 
              << TreeAlgorithms::inorderMinIterative<int>(bst, 3) << std::endl;
    std::cout << "   3rd smallest (recursive): " 
              << TreeAlgorithms::inorderMin<int>(bst, 3) << std::endl;
    std::cout << "   5th smallest (iterative): " 
              << TreeAlgorithms::inorderMinIterative<int>(bst, 5) << std::endl;
    std::cout << "   Invalid k (10): " 
              << TreeAlgorithms::inorderMinIterative<int>(bst, 10) << std::endl;
    std::cout << std::endl;

    // 5
    std::cout << "5." << std::endl;
    BinaryTree<int> balanceTree;
    std::vector<int> balanceData = {10, 5, 15, 2, 7};
    balanceTree.buildTreeFromArray(balanceData);
    
    int height = TreeAlgorithms::calculateHeightsAndBalance<int>(balanceTree.getRoot());
    std::cout << "   Tree height: " << height << std::endl;
    std::cout << std::endl;

    // 6
    std::cout << "6. Testing mirror tree:" << std::endl;
    BinaryTree<int> mirrorTree;
    std::vector<int> mirrorData = {1, 2, 3, 4, 5};
    mirrorTree.buildTreeFromArray(mirrorData);
    
    mirrorTree.generatePNGfile("original_mirror.dot", "original_mirror.png");
    
    TreeAlgorithms::mirrorTreeIterative<int>(mirrorTree);
    mirrorTree.generatePNGfile("mirrored_tree.dot", "mirrored_tree.png");

    return 0;
}