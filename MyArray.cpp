#ifndef MY_ARRAY


#include <iostream>
#include <memory>
#include <functional>
#include "MyArray.h"

using namespace std;

MyArray::MyArray() {
    arr = nullptr;
    start_n = 0;
    post_processed_n = 0;
}

MyArray::MyArray(int start_n, const int *arr) {
    this->start_n = start_n;
    this->post_processed_n = (start_n + 1) / 2;
    this->old_arr = arr;
    this->arr = new int[this->post_processed_n];
    for (int i = 0; i < start_n; i += 2) {
        this->arr[i / 2] = arr[i];
    }
}

void MyArray::pretty_print(int len, const int *arr) {
    cout << "\n#########################\n";
    cout << "| index\t|   element\t|\n";
    cout << "#########################\n";
    for (int i = 0; i < len; i++) {
        cout << "| " << i << "\t|   " << arr[i] << "\t\t|\n";
    }
    cout << "#########################\n";
}

MyArray::~MyArray() {
    delete[] arr;
}

int MyArray::base_input(
        string inp_str,
        const function<bool(int)> filter = [](int num) { return true; }
) {

    string input_data;
    cout << inp_str;
    while (true) {
        try {
            getline(cin, input_data);
            int res = stoi(input_data);
            if (to_string(res) == input_data) {
                if (filter(res)) {
                    return res;
                }
            }

            cout << "Error! No correct number! Repeat please:";
        }
        catch (invalid_argument e) {
            cout << "Error! input must be is integer! Repeat please:";
        }
    }
}

unique_ptr<MyArray> MyArray::read_array_from_stdin() {
    int n = MyArray::base_input(
            "Input array length:",
            [](int n) { return n > 0; }
    );
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = MyArray::base_input("Input next element of array:");
    }
    return make_unique<MyArray>(n, a);
}


void MyArray::print_size() {
    cout << "\nResult array length is " << post_processed_n << "\n";
}

void MyArray::print_new_arr() {
    cout << "\n\tResult array\n";
    MyArray::pretty_print(post_processed_n, arr);
}

void MyArray::print_old_arr() {
    cout << "\n\tStart array\n";
    MyArray::pretty_print(start_n, old_arr);
}

#define MY_ARRAY
#endif