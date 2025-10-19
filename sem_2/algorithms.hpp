#pragma once

#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <cctype>

#include "my_forward_list.hpp"

// 1
bool hasCycle(const my_forward_list<int>& list)
{
    auto head = list.get_head();

    if (!head || !head->get_next()) { return false; }

    auto slow = head;
    auto fast = head->get_next();

    while (slow != fast)
    {
        if (!fast || !fast->get_next()) { return false; }

        slow = slow->get_next();
        fast = fast->get_next()->get_next();
    }

    return true;
}

// 2
void reverseLinkedList(my_forward_list<int>& list)
{
    auto prev = list.create_node(0);
    prev = nullptr;
    auto current = list.get_head();

    while (current)
    {
        auto next = current->get_next();
        current->set_next(prev);
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

    while (fast && fast->get_next())
    {
        slow = slow->get_next();
        fast = fast->get_next()->get_next();
    }

    return list.get_data(slow);
}

// 4
void removeElements(my_forward_list<int>& list, int val)
{
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

        left_b++;
    }

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
}

// 6 
bool isPalindrome_stack(const std::string& str)
{
    if (str.empty()) { return true; }

    std::stack<char> stack;

    for (char elem : str) { stack.push(elem); }

    for (char elem : str)
    {
        if (elem != stack.top()) { return false; }

        stack.pop();
    }

    return true;
}

bool isPalindrome_deque(const std::string& str)
{
    if (str.empty()) { return true; }
    
    std::deque<char> deque;
    
    for (char elem : str) { deque.push_back(elem); }
    
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
}