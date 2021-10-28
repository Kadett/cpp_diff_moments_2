#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <fstream>
#include "Timer.h"


template<typename T>
void swap(T *a, T *b) {
    T tmp = *a;
    *a = *b;
    *b = tmp;
}

template<typename T>
void SortPointers(std::vector<T> &vec) {
    std::sort(vec.begin(), vec.end(), [](const auto &val1, const auto &val2) {

        return *val1 < *val2;
    });
}

uint32_t count_vowels_count_if__find(std::string &str, std::string &vowels) {
    return std::count_if(str.begin(), str.end(), [&vowels](char ch) {
        auto res = std::find(vowels.begin(), vowels.end(), ch);
        return res != vowels.end();
    });
}

uint32_t count_vowels_count_if__for(std::string &str, std::string &vowels) {

    return std::count_if(str.begin(), str.end(), [&vowels](char ch) {
        for (auto i: vowels) {
            if (ch == i) return true;
        }
        return false;
    });
}

uint32_t count_vowels_for__find(std::string &str, std::string &vowels) {
    uint32_t count{};
    for (auto ch: str) {
        if (std::find(vowels.begin(), vowels.end(), ch) != vowels.end()) ++count;
    }
    return count;
}

uint32_t count_vowels_for__for(std::string &str, std::string &vowels){
    uint32_t count{};
    for(auto ch: str){
        for(auto vowel: vowels){
            if (ch == vowel) ++count;
        }
    }
    return count;

}


int main() {


    int *a = new int(5);
    int *b = new int(10);
    std::cout << "a = " << *a << " - " << a << "; b = " << *b << " - " << b << std::endl;
    swap(a, b);
    std::cout << "a = " << *a << " - " << a << "; b = " << *b << " - " << b << std::endl;
    std::cout << "\n";

    std::vector<int*> vector;
    vector.push_back(new int(5));
    vector.push_back(new int(18));
    vector.push_back(new int(3));
    vector.push_back(new int(8));
    vector.push_back(new int(1));
    vector.push_back(new int(12));
    for (const auto &val : vector) {
        std::cout << *val << " ";
    }
    std::cout << "\n";
    SortPointers(vector);
    for (const auto &val : vector) {
        std::cout << *val << " ";
    }
    std::cout << "\n\n";

    std::ifstream in;
    in.open("war.txt");
    std::string str;
    getline(in, str, '\0');
    std::string vowels{"aeiouyAEIOUY"};
    Timer timer("count_if find");


    std::cout << "vowel letters found:  " << count_vowels_count_if__find(str, vowels) << std::endl;
    timer.print();
    std::cout << "\n";
    timer.start("count_if for");
    std::cout << "vowel letters found:  " << count_vowels_count_if__for(str, vowels) << std::endl;
    timer.print();

    std::cout << "\n";
    timer.start("for find");
    std::cout << "vowel letters found:  " << count_vowels_for__find(str, vowels) << std::endl;
    timer.print();


    std::cout << "\n";
    timer.start("for for");
    std::cout << "vowel letters found:  " << count_vowels_for__find(str, vowels) << std::endl;
    timer.print();




    return 0;
}
