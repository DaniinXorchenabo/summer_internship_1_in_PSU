#ifndef MY_ARRAY_H
#define MY_ARRAY_H

#include <set>
#include <iostream>
#include <memory>
#include <functional>

using namespace std;

class MyArray {
private:
    int *arr;
    const int *old_arr;
    int start_n;
    int post_processed_n;

    int static base_input(std::string inp_str, const function<bool(int)> filter);

public:
    MyArray();

    MyArray(int start_n, const int *arr);

    ~MyArray();

    static unique_ptr<MyArray> read_array_from_stdin();

    static void pretty_print(int len, const int *arr);

    void print_size();

    void print_new_arr();

    void print_old_arr();
};

#endif