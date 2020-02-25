//
// Created by mxq on 2020/2/25.
//

#include "translate_numbers_to_strings.h"


int GetTranslationCount(int number){
    if (number < 0)
        return 0;
    string number_string = to_string(number);
    return GetTranslationCountDp(number_string);
}


int GetTranslationCountDp(const string& number_string){
    auto length = number_string.size();
    int count = 0;
    vector<int> counts(length);
    for (int i = length - 1; i >= 0; i--){
        // 将当前单个数字翻译为字符
        if (i == length - 1)
            count = 1;
        else
            count = counts[i + 1];

        // 将当前数字和下一个数字组合翻译为字符
        if (i < length - 1){
            string two_digits = string(number_string.begin() + i, number_string.begin() + i + 2);
            int two_digits_converted = stoi(two_digits);
            if (two_digits_converted >= 10 && two_digits_converted <= 26){
                if (i < length - 2)
                    count += counts[i + 2];
                else
                    count += 1;
            }
        }
        counts[i] = count;
    }
    return counts[0];
}