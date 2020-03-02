#pragma once
#include <iostream>
#include <string>
#include <vector>
#define NOMINMAX
#include <windows.h>

#pragma once
class Utility {
public:
    // Prints one dimensional vectors. "element, element\n"
    template<typename T>
    static void print(std::vector<T>& const s, std::string (*func)(T) = std::to_string) {
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
    static void print(T* const head, std::string (*func)(T*)) {
        if(!head) 
            return;

        auto cur = head;
        while (cur->next) {
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

    // Prints the value in green if assertion succeeded and red if it did not.
    template<typename T>
    static void print_assert(T var, T expected) {
        // Change color depending on assertion result.
        setConsole(var == expected ? ConsoleMessageType::Success : ConsoleMessageType::Failure);
        print(var);
        // Return the color to default.
        setConsole(ConsoleMessageType::Default);
    }

    enum class ConsoleMessageType {
        Success = 10,   // Console foreground Bright Green
        Failure = 12,   // Bright Red
        Default = 15    // White
    };
    static void setConsole(ConsoleMessageType type) {
        auto hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, (int)type);
    }
        
    // Check values of a linked list.
    template<typename T, typename V>
    static bool compare(T* const head, std::vector<V>& const set) {
        if(!head) 
            return set.size() == 0;

        auto cur = head;
        int i = 0;
        while (cur->next) {
            if(cur->val != set[i])
                return false;

            i++;
            cur = cur->next;
        }
        return true;
    }
        
    // Delete all elements of the linekd list.
    template<typename T>
    static void freeAlloc(T* head) {
        if(!head) 
            return;

        auto cur = head;
        while (cur->next) {
            auto tmp = cur->next;
            delete cur;
            cur = tmp;
        }
    }
};