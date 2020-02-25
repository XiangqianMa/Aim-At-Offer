//
// Created by mxq on 2020/2/25.
//

#ifndef AIM_AT_OFFER_FIND_FIRST_NOT_REPEATING_CHAR_IN_STREAM_H
#define AIM_AT_OFFER_FIND_FIRST_NOT_REPEATING_CHAR_IN_STREAM_H

#include <vector>


class CharStatistic{
public:
    CharStatistic(): occurrence(256, -1), current_index(0) {};
    ~CharStatistic() = default;
    // 向流中插入新的字符
    void Insert(char insert_char){
        if (occurrence[insert_char] == -1)
            occurrence[insert_char] = current_index;
        else if (occurrence[insert_char] >= 0)
            occurrence[insert_char] = -2;
        current_index++;
    }

    char result = '\0';
    // 找到流中第一个不重复的字符
    char FirstNotRepeatingChar(){
        unsigned int min_index = 0xFFFFFFFF;
        for (unsigned int index = 0; index < occurrence.size(); index++){
            if (occurrence[index] >= 0 && occurrence[index] < min_index){
                min_index = occurrence[index];
                result = static_cast<char>(index);
            }
        }
        return result;
    }

private:
    std::vector<int> occurrence;
    unsigned int current_index;
};

#endif //AIM_AT_OFFER_FIND_FIRST_NOT_REPEATING_CHAR_IN_STREAM_H
