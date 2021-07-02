#include "MyArray.h"

using namespace std;

int main() {

    auto test_arr = MyArray::read_array_from_stdin();
    test_arr->print_old_arr();
    test_arr->print_size();
    test_arr->print_new_arr();
    return 0;
}