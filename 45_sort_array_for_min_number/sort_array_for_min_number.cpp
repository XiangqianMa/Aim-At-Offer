//
// Created by mxq on 2020/2/24.
//

#include "sort_array_for_min_number.h"


/**
 * @brief 把数组排列成最小的数
 * @param numbers
 * @return
 */
int SortArrayForMinNumber(const vector<int>& numbers){
    if (numbers.empty())
        return 0;
    // 为了处理大数问题，将numbers转换为字符串
    vector<string> string_numbers;
    string_numbers.reserve(numbers.size());
    for (auto number: numbers){
        string_numbers.push_back(to_string(number));
    }
    // 按照定义的比较规则，将string_numbers中的数从小到大进行排列
    sort(string_numbers.begin(), string_numbers.end(), CompareString);
    return CombineStringsToInteger(string_numbers);
}


/**
 * @brief 将string_numbers拼接为十进制数
 * @param string_numbers
 * @return
 */
int CombineStringsToInteger(const vector<string>& string_numbers){
    string result;
    for (auto& str: string_numbers){
        result += str;
    }
    return stoi(result);
}


/**
 * @brief 比较 str1 + str2 与 str2 + str1 的大小
 * @param str1
 * @param str2
 * @return
 */
bool CompareString(const string& str1, const string& str2){
    return str1 + str2 < str2 + str1;
}