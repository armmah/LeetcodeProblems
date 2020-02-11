#pragma once
#include <iostream>
#include <string>
#include <vector>

#pragma once
class Utility {
public:
    // Prints one dimensional vectors. "element, element\n"
    template<typename T>
    static void print(std::vector<T>& s, std::string (*func)(T) = std::to_string) {
        auto n = s.size();
        if(n == 0)
            return;

        // Separately print the last element so we need to make conditionals or other stuff for the very last unnecessary comma ','.
        for(int i = 0; i < n - 1; i++)
            std::cout<<func(s[i])<<", ";
        std::cout<<func(s[n - 1])<<std::endl;
    }

    // Print a linked list from HEAD to NULL.
    template<typename T>
    static void print(T* head, std::string (*func)(T*)) {
        if(!head) 
            return;

        auto cur = head;
        while (cur->next != NULL) {
            std::cout << func(cur)<<", ";
            cur = cur->next;
        }
        std::cout<<func(cur)<<std::endl;
    }


    // Just prints the value with an endl at the end... nothing exciting.
    template<typename T>
    static void print(T var) {
        std::cout << var << std::endl;
    }

};