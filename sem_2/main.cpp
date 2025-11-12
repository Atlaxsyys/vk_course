<<<<<<< HEAD
#include "algorithms.hpp"
#include "my_forward_list.hpp"
#include <iostream>

template<typename T>
void createCycle(my_forward_list<T>& list);
=======
#include <iostream>

#include "algorithms.hpp"
#include "my_forward_list.hpp"

void createCycle(my_forward_list<int>& list);
void breakCycleSimple(my_forward_list<int>& list);
>>>>>>> 2c92688a174767902f578177f2905eddd5e43702

int main()
{
    // 1
<<<<<<< HEAD
    my_forward_list<int> list_1;
    
    for (int i = 1; i <= 5; i++) { list_1.push_back(i); }
    
    list_1.print();
    
    std::cout << (hasCycle(list_1) ? "yes" : "no") << std::endl;

    createCycle(list_1);
    
    std::cout << (hasCycle(list_1) ? "yes" : "no") << std::endl;

    // 2
=======

    std::cout << "=== 1. ===" << std::endl;

    my_forward_list<int> list_1;
    
    for (int i = 1; i <= 5; i++) { list_1.push_back(i); }

    std::cout << std::boolalpha;
    
    std::cout << hasCycle(list_1) << std::endl;

    createCycle(list_1);
    
    std::cout << hasCycle(list_1) << std::endl;

    breakCycleSimple(list_1);

    // 2

    std::cout << "=== 2. ===" << std::endl;

>>>>>>> 2c92688a174767902f578177f2905eddd5e43702
    my_forward_list<int> list_2;

    for (int i = 1; i <= 5; i++) { list_2.push_back(i); }

    list_2.print();

    reverseLinkedList(list_2);

    list_2.print();

    // 3

<<<<<<< HEAD
=======
    std::cout << "=== 3. ===" << std::endl;

>>>>>>> 2c92688a174767902f578177f2905eddd5e43702
    my_forward_list<int> list_3;

    list_3.push_back(3);
    list_3.push_back(8);
    list_3.push_back(9);
    list_3.push_back(6);
    list_3.push_back(11);
    list_3.push_back(16);
    list_3.push_back(17);

<<<<<<< HEAD
    std::cout << "\nmiddle node : " << middleNode(list_3) << std::endl;

    // 4
=======
    std::cout << "middle node : " << middleNode(list_3) << std::endl;

    // 4

    std::cout << "=== 4. ===" << std::endl;

>>>>>>> 2c92688a174767902f578177f2905eddd5e43702
    my_forward_list<int> list_4;

    for (int i = 1; i <= 5; i++) { list_4.push_back(i); }

    removeElements(list_4, 2);

    list_4.print();

    // 5
<<<<<<< HEAD
=======

    std::cout << "=== 5. ===" << std::endl;

>>>>>>> 2c92688a174767902f578177f2905eddd5e43702
    std::cout << std::boolalpha;

    std::cout << isSubsequence_pointers("abd", "uabqd") << std::endl;
    std::cout << isSubsequence_pointers("axc", "ahbgdc") << std::endl;

    std::cout << isSubsequence_queue("abd", "uabqd") << std::endl;
    std::cout << isSubsequence_queue("axc", "ahbgdc") << std::endl;

    //6

<<<<<<< HEAD

    // 7
=======
    std::cout << "=== 6. ===" << std::endl;

    std::cout << "Stack - 'level': " << isPalindrome_stack("level") << std::endl;
    std::cout << "Deque - 'level': " << isPalindrome_deque("level") << std::endl;
    std::cout << "Pointers - 'level': " << isPalindrome_pointers("level") << std::endl;

    std::cout << "Stack - 'privet': " << isPalindrome_stack("privet") << std::endl;
    std::cout << "Deque - 'privet': " << isPalindrome_deque("privet") << std::endl;
    std::cout << "Pointers - 'privet': " << isPalindrome_pointers("privet") << std::endl;

    // 7

    std::cout << "=== 7. ===" << std::endl;

>>>>>>> 2c92688a174767902f578177f2905eddd5e43702
    my_forward_list<int> list_5;
    list_5.push_back(1);
    list_5.push_back(3);
    list_5.push_back(5);
    
    my_forward_list<int> list_6;
    list_6.push_back(2);
    list_6.push_back(4);
    list_6.push_back(6);

    my_forward_list<int> merged_list = mergeSortedLists(list_5, list_6); 
    
    merged_list.print();

    return 0;
}

<<<<<<< HEAD
template<typename T>
void createCycle(my_forward_list<T>& list)
=======
void createCycle(my_forward_list<int>& list)
>>>>>>> 2c92688a174767902f578177f2905eddd5e43702
{
    auto head = list.get_head();
    if (!head) { return; }
    
    auto last_node = head;

<<<<<<< HEAD
    while (last_node->next) { last_node = last_node->next; }
    
    last_node->next = head;
}

template<typename T>
void breakCycleSimple(my_forward_list<T>& list)
=======
    while (last_node->get_next()) { last_node = last_node->get_next(); }
    
    last_node->set_next(head);
}

void breakCycleSimple(my_forward_list<int>& list)
>>>>>>> 2c92688a174767902f578177f2905eddd5e43702
{
    auto head = list.get_head();
    if (!head) { return; }
    
    auto last_node = head;
    auto prev = head;
    
<<<<<<< HEAD
    while (last_node && last_node->next)
    {
        prev = last_node;
        last_node = last_node->next;
        
        if (last_node == head)
        {
            prev->next = nullptr;
=======
    while (last_node && last_node->get_next())
    {
        prev = last_node;
        last_node = last_node->get_next();
        
        if (last_node == head)
        {
            prev->set_next(nullptr);
>>>>>>> 2c92688a174767902f578177f2905eddd5e43702
            return;
        }
    }
}