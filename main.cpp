#include <iostream>
#include <vector>
#include "duplicate_number/duplicate.h"

using namespace std;


int main() {
    vector<int> numbers{2, 10, 1, 0, 11, 5, 3};
    int duplicate_number;
    bool result = duplicate(numbers, duplicate_number);
    if (result)
        cout << duplicate_number << endl;
    else
        cout << "no duplicate number" << endl;
    return 0;
}