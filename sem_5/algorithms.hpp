#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <algorithm>

#include "BinaryTree.hpp"

class TreeAlgorithms {
    public:
    // 1
    static bool isMaxHeap(const std::vector<int>& arr)
    {
        int n = arr.size();
    
        for (int i = 0; i <= (n - 2) / 2; i++)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            
            if (left < n && arr[i] < arr[left])
            {
                return false;
            }
    
            if (right < n && arr[i] < arr[right])
            {
                return false;
            }
        }
        return true;
    }
    
    static bool isMaxHeapBFS(const std::vector<int>& arr)
    {
        int n = arr.size();
        if (n <= 1) { return true; }
        
        std::queue<int> q;
        q.push(0);
        
        while (!q.empty())
        {
            int i = q.front();
            q.pop();
            
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            
            if (left < n)
            {
                if (arr[i] < arr[left]) { return false; }
                q.push(left);
            }
    
            if (right < n)
            {
                if (arr[i] < arr[right]) { return false; }
                q.push(right);
            }
        }
        return true;
    }

    template <typename T>
    static bool isMaxHeap(const typename BinaryTree<T>::Node* root)
    {
        if (!root) { return true; }

        std::queue<const typename BinaryTree<T>::Node*> q;
        q.push(root);
        bool shouldBeLeaf = false;

        while (!q.empty())
        {
            const typename BinaryTree<T>::Node* current = q.front();
            q.pop();
            
            if (current->getLeft())
            {
                if (shouldBeLeaf || current->getLeft()->getData() > current->getData())
                {
                    return false;
                }
                q.push(current->getLeft());
            }
            else
            {
                shouldBeLeaf = true;
            }
            
            if (current->getRight())
            {
                if (shouldBeLeaf || current->getRight()->getData() > current->getData())
                {
                    return false;
                }
                q.push(current->getRight());
            }
            else
            {
                shouldBeLeaf = true;
            }
        }

        return true;
    }

    template <typename T>
    static bool isMaxHeapTree(const BinaryTree<T>& tree)
    {
        return isMaxHeap<T>(tree.getRoot());
    }
    
    // 2
    template <typename T>
    static bool isCompleteTree(const typename BinaryTree<T>::Node* root)
    {
        if (!root) { return true; }

        std::queue<const typename BinaryTree<T>::Node*> q;
        q.push(root);
        bool shouldBeLeaf = false;

        while (!q.empty())
        {
            const typename BinaryTree<T>::Node* node = q.front();
            q.pop();
            
            if (!node)
            {
                shouldBeLeaf = true;
            }
            else
            {
                if (shouldBeLeaf) { return false; }
                q.push(node->getLeft());
                q.push(node->getRight());
            }
        }
        return true;
    }

    template <typename T>
    static bool isCompleteTree(const BinaryTree<T>& tree)
    {
        return isCompleteTree<T>(tree.getRoot());
    }
    
    // 3
    static std::vector<int> mergeKSortedArrays(const std::vector<std::vector<int>>& sortedArrays)
    {
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        
        for (const auto& arr : sortedArrays)
        {
            for (int value : arr)
            {
                minHeap.push(value);
            }
        }
        
        std::vector<int> mergedArray;
        while (!minHeap.empty())
        {
            mergedArray.push_back(minHeap.top());
            minHeap.pop();
        }
        
        return mergedArray;
    }

    // 3 optimized
    struct HeapNode {
        int value;
        int arrayIndex;
        int elementIndex;
        
        bool operator>(const HeapNode& other) const
        {
            return value > other.value;
        }
    };

    static std::vector<int> mergeKSortedArraysOptimized(const std::vector<std::vector<int>>& sortedArrays)
    {
        if (sortedArrays.empty()) return {};
        
        std::priority_queue<HeapNode, std::vector<HeapNode>, std::greater<HeapNode>> minHeap;
        
        for (int i = 0; i < sortedArrays.size(); i++)
        {
            if (!sortedArrays[i].empty())
            {
                minHeap.push({sortedArrays[i][0], i, 0});
            }
        }
        
        std::vector<int> mergedArray;
        
        while (!minHeap.empty()) {
            HeapNode current = minHeap.top();
            minHeap.pop();
            
            mergedArray.push_back(current.value);
            
            int nextIndex = current.elementIndex + 1;
            if (nextIndex < sortedArrays[current.arrayIndex].size())
            {
                minHeap.push({
                    sortedArrays[current.arrayIndex][nextIndex],
                    current.arrayIndex,
                    nextIndex
                });
            }
        }
        
        return mergedArray;
    }

    // 4
    template <typename T>
    static T inorderMinIterative(const typename BinaryTree<T>::Node* root, int k)
    {
        if (!root || k <= 0) return -1;

        std::stack<const typename BinaryTree<T>::Node*> stack;
        const typename BinaryTree<T>::Node* current = root;
        int counter = 0;

        while (!stack.empty() || current != nullptr)
        {
            while (current != nullptr)
            {
                stack.push(current);
                current = current->getLeft();
            }

            current = stack.top();
            stack.pop();
            counter++;

            if (counter == k)
            {
                return current->getData();
            }

            current = current->getRight();
        }

        return -1;
    }

    template <typename T>
    static T inorderMinIterative(const BinaryTree<T>& tree, int k)
    {
        return inorderMinIterative<T>(tree.getRoot(), k);
    }
    
    template <typename T>
    static T inorderMinHelper(const typename BinaryTree<T>::Node* node, int k, int& counter)
    {
        if (node == nullptr) { return -1; }
        
        T leftResult = inorderMinHelper<T>(node->getLeft(), k, counter);
        if (leftResult != -1)
        {
            return leftResult;
        }
        
        counter++;

        if (counter == k)
        {
            return node->getData();
        }
        
        return inorderMinHelper<T>(node->getRight(), k, counter);
    }

    template <typename T>
    static T inorderMin(const typename BinaryTree<T>::Node* root, int k)
    {
        if (!root || k <= 0) return -1;
        
        int counter = 0;
        return inorderMinHelper<T>(root, k, counter);
    }
    
    template <typename T>
    static T inorderMin(const BinaryTree<T>& tree, int k)
    {
        return inorderMin<T>(tree.getRoot(), k);
    }
    
    // 5
    template <typename T>
    static int calculateHeightsAndBalance(typename BinaryTree<T>::Node* node)
    {
        if (!node) { return 0; }

        int leftHeight = calculateHeightsAndBalance<T>(node->getLeft());
        int rightHeight = calculateHeightsAndBalance<T>(node->getRight());

        int balanceFactor = leftHeight - rightHeight;

        return 1 + std::max(leftHeight, rightHeight);
    }

    template <typename T>
    static void calculateBalanceFactors(BinaryTree<T>& tree)
    {
        calculateHeightsAndBalance<T>(tree.getRoot());
    }

    // 6
    template <typename T>
    static typename BinaryTree<T>::Node* mirrorTreeIterative(typename BinaryTree<T>::Node* node)
    {
        if (node == nullptr) { return nullptr; }

        std::queue<typename BinaryTree<T>::Node*> q;
        q.push(node);

        while (!q.empty())
        {
            typename BinaryTree<T>::Node* current = q.front();
            q.pop();

            typename BinaryTree<T>::Node* temp = current->getLeft();
            current->setLeft(current->getRight());
            current->setRight(temp);

            if (current->getLeft() != nullptr)
            {
                q.push(current->getLeft());
            }
            if (current->getRight() != nullptr)
            {
                q.push(current->getRight());
            }
        }
        return node;
    }

    template <typename T>
    static void mirrorTreeIterative(BinaryTree<T>& tree)
    {
        mirrorTreeIterative<T>(tree.getRoot());
    }
};