#pragma once

#include "my_forward_list.hpp"

#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <cctype>

// 1
bool hasCycle(const my_forward_list<int>& list)
{
    auto head = list.get_head();

    if (!head || !head->next) { return false; }

    auto slow = head;
    auto fast = head->next;

    while (slow != fast)
    {
        if (!fast || !fast->next) { return false; }

        slow = slow->next;
        fast = fast->next->next;
    }

    return true;
}

// 2
void reverseLinkedList(my_forward_list<int>& list)
{
    auto prev = (decltype(list.get_head()))nullptr;
    auto current = list.get_head();

    while (current)
    {
        auto next = current->next;
        current->next = prev;
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

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return list.get_data(slow);
}

// 4
void removeElements(my_forward_list<int>& list, int val)
{
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

        left_b++;
    }

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
}

// 6 
bool isPalindrome_stack(const std::string& str)
{
    std::stack<char> stack;

    for (char c : str) { stack.push(c); }

    for (char c : str)
    {
        if (c != stack.top()) { return false; }

        stack.pop();
    }

    return true;
}

bool isPalindrome_deque(const std::string& str)
{
     std::deque<char> deque;
    
    for (char c : str) { deque.push_back(c); }
    
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
}