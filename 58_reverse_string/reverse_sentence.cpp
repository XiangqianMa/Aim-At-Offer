//
// Created by mxq on 2020/2/29.
//

#include "reverse_sentence.h"


/**
 * @brief 反转句子，但不反转单词
 * @param sentence
 */
void ReverseSentence(string& sentence){
    if (sentence.empty())
        return;
    auto begin = sentence.begin();
    auto end = sentence.end() - 1;

    // 将整个句子反转
    Reverse(begin, end);

    // 将句子中的每个单词反转回去
    auto word_begin = sentence.begin();
    auto word_end = sentence.begin();
    while (true){
        // 确定单词的结尾
        while (*(word_end + 1) != ' ' && (word_end + 1) != sentence.end()){
            word_end++;
        }
        Reverse(word_begin, word_end);
        if ((word_end + 1) == sentence.end())
            break;
        // 跳转到下一个单词的起始位置
        word_end += 2;
        word_begin = word_end;
    }
}


/**
 * @brief 反转字符串
 * @param begin
 * @param end
 */
void Reverse(string::iterator begin, string::iterator end){
    if (begin == end)
        return;
    while (begin < end){
        auto temp = *begin;
        *begin = *end;
        *end = temp;
        begin++;
        end--;
    }
}