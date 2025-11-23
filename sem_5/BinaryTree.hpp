#pragma once

#include <iostream>
#include <fstream>

template <typename T>
class BinaryTree {
private:
    class Node {
    private:
        T data;
        Node* left;
        Node* right;
        int balanceFactor;
        
    public:
        Node(T value) : data(value), left(nullptr), right(nullptr), balanceFactor(0) {}
        
        T getData() const { return data; }
        Node* getLeft() const { return left; }
        Node* getRight() const { return right; }
        int getBalanceFactor() const { return balanceFactor; }
        
        void setLeft(Node* node) { left = node; }
        void setRight(Node* node) { right = node; }
        void setData(T value) { data = value; }
        void setBalanceFactor(int bf) { balanceFactor = bf; }

        friend class BinaryTree;
    };

    Node* buildTreeFromArrayHelper(std::vector<T>& array, int i)
    {
        if (i >= array.size()) { return nullptr; }

        Node* root = createNode(array[i]);
        root->setLeft(buildTreeFromArrayHelper(array, 2 * i + 1));
        root->setRight(buildTreeFromArrayHelper(array, 2 * i + 2));

        return root;
    }
    
    Node* root;

    void clear(Node* node)
    {
        if (node)
        {
            clear(node->getLeft());
            clear(node->getRight());
            delete node;
        }
    }

    void generateDOT(Node* node, std::ostream& out) const
    {
        if (node == nullptr) { return; }

        out << "    \"" << node << "\" [label=\"" << node->getData() << "\"];\n";

        if (node->getLeft() != nullptr)
        {
            out << "    \"" << node << "\" -> \"" << node->getLeft() << "\" [color=red];\n";
            generateDOT(node->getLeft(), out);
        }
        else
        {
            out << "    \"" << node << "\" -> \"null" << node << "L\" [color=red];\n";
            out << "    \"null" << node << "L\" [label=\"nullptr\", shape=plaintext];\n";
        }

        if (node->getRight() != nullptr)
        {
            out << "    \"" << node << "\" -> \"" << node->getRight() << "\" [color=blue];\n";
            generateDOT(node->getRight(), out);
        }
        else
        {
            out << "    \"" << node << "\" -> \"null" << node << "R\" [color=blue];\n";
            out << "    \"null" << node << "R\" [label=\"nullptr\", shape=plaintext];\n";
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    ~BinaryTree()
    {
        clear(root);
    }

    Node* createNode(T value) const { return new Node(value); }
    Node* getRoot() const { return root; }
    void setRoot(Node* newRoot) { root = newRoot; }
    void clearTree() { clear(root); root = nullptr; }

    void buildTreeFromArray(std::vector<T>& array)
    {
        clearTree();
        root = buildTreeFromArrayHelper(array, 0);
    }

    void generateDOTfile(const std::string& filename) const
    {
        std::ofstream file(filename);
        if (!file.is_open())
        {
            std::cerr << "file didn`t open" << filename << std::endl;
            return;
        }

        file << "digraph BinaryTree {\n";
        file << "    node [fontname=\"Arial\", shape=circle, style=filled, fillcolor=lightblue];\n";
        file << "    edge [fontname=\"Arial\", fontsize=10];\n";
        
        if (root != nullptr)
        {
            generateDOT(root, file);
        }
        else
        {
            file << "    \"empty\" [label=\"Empty Tree\"];\n";
        }
        
        file << "}\n";
        file.close();
    }

    void generatePNGfile(const std::string& dotFilename, const std::string& pngFilename) const
    {
        generateDOTfile(dotFilename);
        
        std::string command = "dot -Tpng " + dotFilename + " -o " + pngFilename;
        int result = system(command.c_str());
        
        if (result == 0) 
        {
            std::cout << "PNG file has been created: " << pngFilename << std::endl;
        }
        else
        {
            std::cout << "PNG file creation error" << std::endl;
        }
    }

    friend class TreeAlgorithms;
};