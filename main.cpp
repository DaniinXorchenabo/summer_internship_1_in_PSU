#include <iostream>
#include <cstdlib> // для system
#include <iostream>
#include <limits>
#include <set>
#include <unordered_set>
#include <algorithm>
#include "MyArray.h"

using namespace std;

int main() {

    auto test_arr = MyArray::read_array_from_stdin();
    test_arr->pretty_print();
//    set<char> correct_ch{'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-',};
//    set<char> res;
//    int n;
//
//    std::string as_number;
//
//    std::cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой
//    std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
//    std::cout << "\ninput element\t:";
//    std::getline(std::cin, as_number);
//    std::set<char> test_set;
//    for (const auto &ch: as_number) {
//        test_set.insert(ch);
//    }
//    std::set_difference(test_set.begin(), test_set.end(),
//                        correct_ch.begin(), correct_ch.end(),
//                        std::inserter(res, res.end()));
//    if (res.begin() == res.end()) {
//        std::cout << "\n******  good\t:";
//    } else {
//        std::cout << "\nbad\t\n";
//    }
//    for(auto i: res){
//        cout<<i<<" ";
//    }


    return 0;
}