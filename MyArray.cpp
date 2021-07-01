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

MyArray::MyArray(int start_n, const int *arr) {
    this->start_n = start_n;
    this->post_processed_n = (start_n + 1) / 2;
    this->arr = new int[this->post_processed_n];
    for (int i = 0; i < start_n; i += 2) {
        this->arr[i / 2] = arr[i];
//        std::cout<<"write "<<(int)(i / 2)<<" "<<arr[i]<<"\t";
    }
}

void MyArray::pretty_print() {
    for (int i = 0; i < post_processed_n; i++) {
        std::cout<<arr[i]<<"\n";
    }
}

MyArray::~MyArray() {
    delete[] arr;
}

int MyArray::base_input(
        std::string inp_str,
        const std::function<bool(int)> filter = [](int num) { return true; }
) {

    std::string input_data;
    std::cout << inp_str;
    while (true) {
        try {
            std::cin.clear();
            std::getline(std::cin, input_data);
            int res = std::stoi(input_data);
            if (std::to_string(res) == input_data) {
                if (filter(res)) {
//                    std::cout << "-----** " << res << "\n";
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
}

#define MY_ARRAY
#endif