#pragma once

<<<<<<< HEAD
#include "my_forward_list.hpp"

=======
>>>>>>> 2c92688a174767902f578177f2905eddd5e43702
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <cctype>

<<<<<<< HEAD
=======
#include "my_forward_list.hpp"

>>>>>>> 2c92688a174767902f578177f2905eddd5e43702
// 1
bool hasCycle(const my_forward_list<int>& list)
{
    auto head = list.get_head();

<<<<<<< HEAD
    if (!head || !head->next) { return false; }

    auto slow = head;
    auto fast = head->next;

    while (slow != fast)
    {
        if (!fast || !fast->next) { return false; }

        slow = slow->next;
        fast = fast->next->next;
=======
    if (!head || !head->get_next()) { return false; }

    auto slow = head;
    auto fast = head->get_next();

    while (slow != fast)
    {
        if (!fast || !fast->get_next()) { return false; }

        slow = slow->get_next();
        fast = fast->get_next()->get_next();
>>>>>>> 2c92688a174767902f578177f2905eddd5e43702
    }

    return true;
}

// 2
void reverseLinkedList(my_forward_list<int>& list)
{
<<<<<<< HEAD
    auto prev = (decltype(list.get_head()))nullptr;
=======
    auto prev = list.create_node(0);
    prev = nullptr;
>>>>>>> 2c92688a174767902f578177f2905eddd5e43702
    auto current = list.get_head();

    while (current)
    {
<<<<<<< HEAD
        auto next = current->next;
        current->next = prev;
=======
        auto next = current->get_next();
        current->set_next(prev);
>>>>>>> 2c92688a174767902f578177f2905eddd5e43702
        prev = current;
        current = next;
    }

    list.set_head(prev);
}

// 3
int middleNode(my_forward_list<int>& list)
{
    auto slow = list.get_head();
    auto fast = list.get_head();

<<<<<<< HEAD
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
=======
    while (fast && fast->get_next())
    {
        slow = slow->get_next();
        fast = fast->get_next()->get_next();
>>>>>>> 2c92688a174767902f578177f2905eddd5e43702
    }

    return list.get_data(slow);
}

// 4
void removeElements(my_forward_list<int>& list, int val)
{
<<<<<<< HEAD
    list.remove(val);
}

// 5
bool isSubsequence_pointers(const std::string& a, const std::string& b)
{
    std::size_t left_a = 0;
    std::size_t left_b = 0;

    while (left_a < a.length() && left_b < b.length())
    {
        if (a[left_a] == b[left_b])
        {
            left_a++;
        }
=======
    if (list.empty()) return;
    
    auto head = list.get_head();
    
    auto dummy = list.create_node(0);
    dummy->set_next(head);
    
    auto prev = dummy;
    auto current = head;
    
    while (current)
    {
        if (current->get_data() == val)
        {
            prev->set_next(current->get_next());
            delete current;
            current = prev->get_next();
            list.decrement_size();
        }
        else
        {
            prev = current;
            current = current->get_next();
        }
    }
    
    list.set_head(dummy->get_next());
    delete dummy;
}

// 5
bool isSubsequence_pointers(const std::string& str_a, const std::string& str_b)
{

    if (str_a.empty()) { return true;  }
    if (str_b.empty()) { return false; }

    std::size_t left_a = 0;
    std::size_t left_b = 0;

    while (left_a < str_a.length() && left_b < str_b.length())
    {
        if (str_a[left_a] == str_b[left_b]) { left_a++; }
>>>>>>> 2c92688a174767902f578177f2905eddd5e43702

        left_b++;
    }

<<<<<<< HEAD
    return left_a == a.length();
}

bool isSubsequence_queue(const std::string& a, const std::string& b)
{
    std::queue<char> q;
    
    for (char el : a) { q.push(el); }
    
    for (char el : b)
    {
        if (!q.empty() && q.front() == el) { q.pop(); }
    }
    
    return q.size() == 0;
=======
    return left_a == str_a.length();
}

bool isSubsequence_queue(const std::string& str_a, const std::string& str_b)
{
    if (str_a.empty()) { return true;  }
    if (str_b.empty()) { return false; }

    std::queue<char> queue;
    
    for (char elem : str_a) { queue.push(elem); }
    
    for (char elem : str_b)
    {
        if (!queue.empty() && queue.front() == elem) { queue.pop(); }
    }
    
    return queue.size() == 0;
>>>>>>> 2c92688a174767902f578177f2905eddd5e43702
}

// 6 
bool isPalindrome_stack(const std::string& str)
{
<<<<<<< HEAD
    std::stack<char> stack;

    for (char c : str) { stack.push(c); }

    for (char c : str)
    {
        if (c != stack.top()) { return false; }
=======
    if (str.empty()) { return true; }

    std::stack<char> stack;

    for (char elem : str) { stack.push(elem); }

    for (char elem : str)
    {
        if (elem != stack.top()) { return false; }
>>>>>>> 2c92688a174767902f578177f2905eddd5e43702

        stack.pop();
    }

    return true;
}

bool isPalindrome_deque(const std::string& str)
{
<<<<<<< HEAD
     std::deque<char> deque;
    
    for (char c : str) { deque.push_back(c); }
=======
    if (str.empty()) { return true; }
    
    std::deque<char> deque;
    
    for (char elem : str) { deque.push_back(elem); }
>>>>>>> 2c92688a174767902f578177f2905eddd5e43702
    
    while (deque.size() > 1)
    {
        if (deque.front() != deque.back()) { return false; }

        deque.pop_front();
        deque.pop_back();
    }
    
    return true;
}

bool isPalindrome_pointers(const std::string& str)
{
    int left = 0;
    int right = str.length() - 1;

    while (left < right)
    {
        if (str[left] != str[right]) { return false; }

        left++;
        right--;
    }

    return true;
}

// 7
<<<<<<< HEAD
my_forward_list<int> mergeSortedLists(const my_forward_list<int>& list_1, const my_forward_list<int>& list_2)
{
    my_forward_list<int> result;
    
    auto curr_1 = list_1.get_head();
    auto curr_2 = list_2.get_head();
    
    // Сливаем два отсортированных списка
    while (curr_1 && curr_2) {
        if (curr_1->data <= curr_2->data) {
            result.push_back(curr_1->data);
            curr_1 = curr_1->next;
        } else {
            result.push_back(curr_2->data);
            curr_2 = curr_2->next;
        }
    }
    
    // Добавляем оставшиеся элементы из list_1
    while (curr_1) {
        result.push_back(curr_1->data);
        curr_1 = curr_1->next;
    }
    
    // Добавляем оставшиеся элементы из list_2
    while (curr_2) {
        result.push_back(curr_2->data);
        curr_2 = curr_2->next;
    }
    
    return result;
=======
my_forward_list<int> mergeSortedLists(const my_forward_list<int>& list_a, const my_forward_list<int>& list_b)
{
    my_forward_list<int> merged_list;

    auto current_a = list_a.get_head();
    auto current_b = list_b.get_head();

    while (current_a && current_b)
    {
        if (current_a->get_data() <= current_b->get_data())
        {
            merged_list.push_back(current_a->get_data());
            current_a = current_a->get_next();
        }
        else
        {
            merged_list.push_back(current_b->get_data());
            current_b = current_b->get_next();
        }
    }

    while (current_a)
    {
        merged_list.push_back(current_a->get_data());
        current_a = current_a->get_next();
    }

    while (current_b)
    {
        merged_list.push_back(current_b->get_data());
        current_b = current_b->get_next();
    }

    return merged_list;
>>>>>>> 2c92688a174767902f578177f2905eddd5e43702
}