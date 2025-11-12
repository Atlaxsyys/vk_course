<<<<<<< HEAD
=======

>>>>>>> 2c92688a174767902f578177f2905eddd5e43702
#pragma once

#include <iostream>

template<typename T>
class my_forward_list {
private:
<<<<<<< HEAD
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
=======
    class Node {
    private:
        T data;
        Node* next;
    public:
        Node(const T& value) : data(value), next(nullptr) {}
        
        T get_data() const { return data; }
        Node* get_next() const { return next; }
        void set_next(Node* next_node) { next = next_node; }
>>>>>>> 2c92688a174767902f578177f2905eddd5e43702
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
<<<<<<< HEAD
            head = head->next;
=======
            head = head->get_next();
>>>>>>> 2c92688a174767902f578177f2905eddd5e43702
            delete temp;
        }

        list_size = 0;
    }

    void push_front(const T& value)
    {
        Node* new_node = new Node(value);
<<<<<<< HEAD
        new_node->next = head;
=======
        new_node->set_next(head);
>>>>>>> 2c92688a174767902f578177f2905eddd5e43702
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

<<<<<<< HEAD
            while (current->next) { current = current->next; }

            current->next = new_node;
=======
            while (current->get_next()) { current = current->get_next(); }

            current->set_next(new_node);
>>>>>>> 2c92688a174767902f578177f2905eddd5e43702
            list_size++;
        }

    }

    bool empty() const { return head == nullptr; }

    size_t size() const { return list_size; }

    Node* get_head() const { return head; }

    void set_head(Node* new_head) { head = new_head; }

<<<<<<< HEAD
    T get_data(Node* current) { return current->data; }

    void remove(const T& value)
    {
        Node* dummy = new Node(T());
        dummy->next = get_head();

        Node* prev = dummy;
        Node* current = get_head();

        while (current)
        {
            if (current->data == value)
            {
            prev->next = current->next;
            delete current;
            current = prev->next;
            list_size--; 
            }

            else
            {
                prev = current;
                current = current->next;
            }
        }

        head = dummy->next;
        delete dummy;
    }
=======
    T get_data(Node* current) { return current->get_data(); }

    void decrement_size() { if (list_size > 0) list_size--; }

    Node* create_node(const T& value) const { return new Node(value); }
>>>>>>> 2c92688a174767902f578177f2905eddd5e43702

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
<<<<<<< HEAD
            std::cout << current->data;

            if (current->next)
            {
                std::cout << " -> ";
            }

            current = current->next;
        }
        std::cout << std::endl;
    }

//     bool hasCycle()
// {
//     auto head = this->get_head();

//     if (!head || !head->next) { return false; }

//     auto slow = head;
//     auto fast = head->next;

//     while (slow != fast)
//     {
//         if (!fast || !fast->next) { return false; }

//         slow = slow->next;
//         fast = fast->next->next;
//     }

//     return true;
// }

// void createCycle(size_t to_position)
// {
//     auto head = this->get_head();
//     if (head == nullptr || to_position == 0) return;
    
//     auto cycle_node = head;
//     auto last_node = head;
    
//     for (size_t i = 0; i < to_position && cycle_node; i++) { cycle_node = cycle_node->next; }
    
//     if (!cycle_node) return;
    
//     while (last_node->next) { last_node = last_node->next; }
    
//     last_node->next = cycle_node;
// }
=======
            std::cout << current->get_data();

            if (current->get_next()) { std::cout << " -> "; }

            current = current->get_next();
        }

        std::cout << std::endl;
    }
>>>>>>> 2c92688a174767902f578177f2905eddd5e43702
};