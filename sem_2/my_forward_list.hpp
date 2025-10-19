
#pragma once

#include <iostream>

template<typename T>
class my_forward_list {
private:
    class Node {
    private:
        T data;
        Node* next;
    public:
        Node(const T& value) : data(value), next(nullptr) {}
        
        T get_data() const { return data; }
        Node* get_next() const { return next; }
        void set_next(Node* next_node) { next = next_node; }
    };

    Node* head;
    size_t list_size;

public:
    my_forward_list() : head(nullptr), list_size(0) {}

    ~my_forward_list()
    {
        clear();
    }

    void clear()
    {
        while(head)
        {
            Node* temp = head;
            head = head->get_next();
            delete temp;
        }

        list_size = 0;
    }

    void push_front(const T& value)
    {
        Node* new_node = new Node(value);
        new_node->set_next(head);
        head = new_node;
        list_size++;
    }

    void push_back(const T& value)
    {
        Node* new_node = new Node(value);
        
        if (!head)
        {
            head = new_node;
            list_size = 1;
        }

        else
        {
            Node* current = head;

            while (current->get_next()) { current = current->get_next(); }

            current->set_next(new_node);
            list_size++;
        }

    }

    bool empty() const { return head == nullptr; }

    size_t size() const { return list_size; }

    Node* get_head() const { return head; }

    void set_head(Node* new_head) { head = new_head; }

    T get_data(Node* current) { return current->get_data(); }

    void decrement_size() { if (list_size > 0) list_size--; }

    Node* create_node(const T& value) const { return new Node(value); }

    void print() const
    {
        if (empty())
        {
            std::cout << "List is empty" << std::endl;
            return;
        }
        
        Node* current = head;

        while (current)
        {
            std::cout << current->get_data();

            if (current->get_next()) { std::cout << " -> "; }

            current = current->get_next();
        }

        std::cout << std::endl;
    }
};