//
// Created by mxq on 2020/2/9.
//

#include "regular_expression_match.h"


/**
 * @brief 正则表达式匹配
 * @param txt
 * @param pattern
 * @return bool 匹配成功或失败
 */
bool RegularExpressionMatch(const string& txt, const string& pattern){
    if (txt.empty() || pattern.empty())
        return false;

    return MatchCore(txt, pattern, 0, 0);
}


/**
 * @brief 匹配的核心函数
 * @param txt 字符串
 * @param pattern 正则模式串
 * @param txt_index 字符串中待处理的字符的索引
 * @param pattern_index 模式串中待处理的字符的索引
 * @return bool 匹配成功或失败
 */
bool MatchCore(const string& txt, const string& pattern, int txt_index, int pattern_index){
    // 匹配同时到达末尾，则匹配成功
    if (txt_index == txt.size() && pattern_index == pattern.size())
        return true;
    // 两者中只有一个到达末尾，则失败
    else if (txt_index == txt.size() || pattern_index == pattern.size())
        return false;

    // '*'的情况
    if (pattern[pattern_index + 1] == '*'){
        if (pattern[pattern_index] == txt[txt_index] || pattern[pattern_index] == '.'){
            return MatchCore(txt, pattern, txt_index + 1, pattern_index + 2) // '*'只匹配一个字符
                    || MatchCore(txt, pattern, txt_index, pattern_index+2) // '*' 匹配0个字符
                    || MatchCore(txt, pattern, txt_index + 1, pattern_index); // '*'匹配多个字符
        }
        return false;
    }

    // 字符或'.'的情况
    if (pattern[pattern_index] == txt[txt_index] || pattern[pattern_index] == '.')
        return MatchCore(txt, pattern, txt_index + 1, pattern_index + 1);

    return false;
}