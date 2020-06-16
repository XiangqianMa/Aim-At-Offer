//
// Created by mxq on 2020/2/9.
//

#ifndef AIM_AT_OFFER_REGULAR_EXPRESSION_MATCH_H
#define AIM_AT_OFFER_REGULAR_EXPRESSION_MATCH_H

#include <string>

using namespace std;

class RegularExpressionMatch {
public:
    bool isMatch(string s, string p) {
        return dfs(s, p, 0, 0);
    }

    bool dfs(const string& s, const string& p, int s_index, int p_index) {
        if (s_index == s.size() && p_index == p.size()) {
            return true;
        }
        if (s_index != s.size() && p_index == p.size()) {
            return false;
        }

        bool first_match = s_index != s.size() && (p[p_index] == s[s_index] || p[p_index] == '.');

        // 第二个字符为'*'
        if ((p_index + 1) < p.size() && p[p_index + 1] == '*') {
            return dfs(s, p, s_index, p_index + 2) ||
                   (first_match && dfs(s, p, s_index + 1, p_index));
        } else {
            return first_match && dfs(s, p, s_index + 1, p_index + 1);
        }
    }
};

#endif //AIM_AT_OFFER_REGULAR_EXPRESSION_MATCH_H
