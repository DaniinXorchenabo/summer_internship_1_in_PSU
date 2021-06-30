#ifndef MY_ARRAY_H
#define MY_ARRAY_H

#include <set>
#include <iostream>
#include <memory>

class MyArray {
private:
    int *arr;
    int start_n;
    int post_processed_n;
    const static std::set<char> control_chars;

public:
    MyArray();

    MyArray(int start_n, int *arr);

    ~MyArray();

    static std::unique_ptr<MyArray> read_array_from_stdin();

    void pretty_print();
};

#endif