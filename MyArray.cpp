#ifndef MY_ARRAY

#include "MyArray.h"
#include <iostream>
#include <limits>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <memory>
#include <functional>


const std::set<char> MyArray::control_chars{'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-'};


MyArray::MyArray() {
    arr = nullptr;
    start_n = 0;
    post_processed_n = 0;
}

MyArray::MyArray(int start_n, int *arr) {
    this->start_n = start_n;
    this->arr = arr;
}

MyArray::~MyArray() {
    delete[] arr;
}

int MyArray::base_input(
        std::string inp_str,
        const std::function<bool(int)> filter = [](int num) { return true; }
) {

    std::string input_data;
    std::cout << "" << inp_str;
    while (true) {
        try {
            std::cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой
//            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, input_data);
//            const char* c_inp = input_data.c_str();
//            int res = std::atoi(c_inp);
            int res = std::stoi(input_data);
            if (std::to_string(res) == input_data) {
                if (filter(res)) {
                    std::cout << "-----** " << res << "\n";
                    return res;
                }
            }

            std::cout << "Error! No correct number! Repeat please:";
        }
        catch (std::invalid_argument e) {
            std::cout << "Error! input must be is integer! Repeat please:";
        }
    }
}

std::unique_ptr<MyArray> MyArray::read_array_from_stdin() {
    int n = MyArray::base_input(
            "Input array length:",
            [](int n) { return n > 0; }
    );
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = MyArray::base_input("Input next element of array:");
    }
    return std::make_unique<MyArray>(n, a);

//    std::cout << "\nВведите количество элементов";
//    int n;
//    std::string as_number;
//    std::set<char> res;
//    std::cin >> n;
//    int *a = new int[n];
//    for (int i = 0; i < n; i++) {
//        std::cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой
//        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//        std::cout << "\nВведите элемент " << i << "\t:";
//        std::cin >> as_number;
//
//        std::getline(std::cin, as_number);
//        std::set<char> test_set;
//        for (const auto &ch: as_number) {
//            test_set.insert(ch);
//        }
//        std::set_difference(test_set.begin(), test_set.end(),
//                            control_chars.begin(), control_chars.end(),
//                            std::inserter(res, res.end()));
//        if (res.begin() == res.end()) {
//            // see: https://arduinoplus.ru/preobrazovanie-stroki-string-v-czeloe-chislo-int-v-c/
//            a[i] = stoi(as_number);
//        } else {
//            i--;
//            std::cout << "\nВы ввели некоректное значение! Значения могут быть только целыми числами!";
//        }
//    }


}

#define MY_ARRAY
#endif