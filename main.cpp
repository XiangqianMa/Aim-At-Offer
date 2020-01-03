#include <iostream>
#include <vector>
#include "duplicate_number/duplicate.h"
#include "find_number_in_matrix/find_number_in_matrix.h"
#include "string/replace_black.h"

using namespace std;


int main() {
    // 查找数组中的重复数字
    vector<int> numbers{2, 3, 5, 4, 3, 2, 6, 7};
    int duplicate_number;
    bool result = get_duplicate(numbers, duplicate_number);
    if (result)
        cout << duplicate_number << endl;
    else
        cout << "No duplicate number" << endl;

    // 在二维有序数组中查找特定的元素
    vector<vector<int>> matrix{{1,2,8,9}, {2,4,9,12}, {4,7,10,13}, {6,8,11,15}};
    int number = 7;
    bool found = find_number(matrix, 4, 4, number);
    if (found)
        cout << "Find: " << number << endl;
    else
        cout << "No: " << number << endl;

    // 将字符串中的空格替换为"%20"
    char string[30] = "";
    bool replace_result = replace_blank(string, 30);
    if (replace_result)
        cout << string << endl;
    else
        cout << "Replace string failure." << endl;

    return 0;
}