#include <iostream>
#include <vector>
#include "duplicate_number/duplicate.h"

using namespace std;


int main() {
    vector<int> numbers{2, 3, 5, 4, 3, 2, 6, 7};
    int duplicate_number;
    bool result = get_duplicate(numbers, duplicate_number);
    if (result)
        cout << duplicate_number << endl;
    else
        cout << "no duplicate number" << endl;
    return 0;
}