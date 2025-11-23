#pragma once

#include <vector>
#include <queue>
#include <algorithm>

#include "BinaryTree.hpp"

class TreeAlgorithms {
private:
// 1
    template <typename T>
    static typename BinaryTree<T>::Node* buildTreeRecursive(BinaryTree<T>& tree, std::vector<T>& array, int i)
    {
        if (i >= array.size()) { return nullptr; }

        typename BinaryTree<T>::Node* root = tree.createNode(array[i]);
        root->setLeft(buildTreeRecursive(tree, array, 2 * i + 1));
        root->setRight(buildTreeRecursive(tree, array, 2 * i + 2));

        return root;
    }

    template <typename T>
    static void depthSearch(typename BinaryTree<T>::Node* root, std::vector<T>& res)
    {
        if (root == nullptr) { return; }
        
        depthSearch(root->getLeft(), res);
        res.push_back(root->getData());
        depthSearch(root->getRight(), res);
    }

    template <typename T>
    static bool isSameTreeRecursive(typename BinaryTree<T>::Node* a, typename BinaryTree<T>::Node* b)
    {
        if (a == nullptr && b == nullptr) {
            return true;
        }
        if (a == nullptr || b == nullptr) {
            return false;
        }
        if (a->getData() != b->getData()) {
            return false;
        }
        
        return isSameTreeRecursive<T>(a->getLeft(), b->getLeft()) && 
               isSameTreeRecursive<T>(a->getRight(), b->getRight());
    }

    template <typename T>
    static int minDepthRecursive(typename BinaryTree<T>::Node* root)
    {
        if (!root) { return 0; }

        if (!root->getLeft() && !root->getRight()) { return 1; }

        if (root->getLeft() && root->getRight())
        {
            return 1 + std::min(minDepthRecursive<T>(root->getLeft()), 
                               minDepthRecursive<T>(root->getRight()));
        }

        if (root->getLeft()) { return 1 + minDepthRecursive<T>(root->getLeft()); }
        if (root->getRight()) { return 1 + minDepthRecursive<T>(root->getRight()); }
        
        return -1;
    }

public:
    // 1
    template <typename T>
    static void buildFromArray(BinaryTree<T>& tree, std::vector<T>& array)
    {
        tree.clearTree();
        typename BinaryTree<T>::Node* root = buildTreeRecursive(tree, array, 0);
        tree.setRoot(root);
    }

    // 2 BFS
    template <typename T>
    static bool isSymmetric(const BinaryTree<T>& tree)
    {
        auto root = tree.getRoot();
        if (root == nullptr) return true;
        
        std::queue<typename BinaryTree<T>::Node*> q;
        q.push(root->getLeft());
        q.push(root->getRight());
        
        while (!q.empty())
        {
            typename BinaryTree<T>::Node* leftNode = q.front();
            q.pop();
            typename BinaryTree<T>::Node* rightNode = q.front();
            q.pop();
            
            if (leftNode == nullptr && rightNode == nullptr) { continue; }
            if (leftNode == nullptr || rightNode == nullptr) { return false; }
            if (leftNode->getData() != rightNode->getData()) { return false; }
            
            q.push(leftNode->getLeft());
            q.push(rightNode->getRight());
            q.push(leftNode->getRight());
            q.push(rightNode->getLeft());
        }
        
        return true;
    }
    
    // 2 DFS
    template <typename T>
    static bool isSymmetricDFS(const BinaryTree<T>& tree)
    {
        auto root = tree.getRoot();
        if (root == nullptr) { return true; }
        
        std::vector<T> data;
        depthSearch<T>(root, data);
        
        int j = data.size() - 1;
        
        for (int i = 0; i < data.size() / 2; i++)
        {
            if (data[i] != data[j])
            {
                return false;
            }
            j--;
        }
        
        return true;
    }

    // 3
    template <typename T>
    static int minDepth(const BinaryTree<T>& tree)
    {
        return minDepthRecursive<T>(tree.getRoot());
    }
    
    // 4
    template <typename T>
    static T maxMinMultiplication(std::vector<T> data)
    {
        if (data.size() < 3) { return -1; }
        
        int min_index = 1;
        int max_index = 2;
        
        for (int i = 1; i < data.size(); i = 2 * i + 1)
        {
            min_index = i;
        }
        
        for (int i = 2; i < data.size(); i = 2 * i + 2)
        {
            max_index = i;
        }
        
        return data[min_index] * data[max_index];
    }
    
    
    // 5
    template <typename T>
    static bool isSameTree(const BinaryTree<T>& a, const BinaryTree<T>& b)
    {
        return isSameTreeRecursive<T>(a.getRoot(), b.getRoot());
    }
};