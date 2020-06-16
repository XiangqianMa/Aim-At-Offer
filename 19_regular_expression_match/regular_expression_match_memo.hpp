#ifndef REGULAR_EXPRESSION_MATCH_MEMO
#define REGULAR_EXPRESSION_MATCH_MEMO

#include <vector>
#include <string>

using namespace std;

// 带记忆的回溯法，速度更快
class RegularExpressionMatchMemo {
public:
    bool isMatch(string s, string p) {
        memo = vector<vector<int>>(s.size() + 1, vector<int>(p.size() + 1, -1));
        return dfs(s, p, 0, 0);
    }

    bool dfs(const string& s, const string& p, int s_index, int p_index) {
        if (s_index == s.size() && p_index == p.size()) {
            return true;
        }
        if (s_index != s.size() && p_index == p.size()) {
            return false;
        }

        if (memo[s_index][p_index] != -1) {
            return memo[s_index][p_index] == 1;
        }

        bool first_match = s_index != s.size() && (p[p_index] == s[s_index] || p[p_index] == '.');

        bool result;
        // 第二个字符为'*'
        if ((p_index + 1) < p.size() && p[p_index + 1] == '*') {
            result = dfs(s, p, s_index, p_index + 2) ||
                   (first_match && dfs(s, p, s_index + 1, p_index));
        } else {
            result = first_match && dfs(s, p, s_index + 1, p_index + 1);
        }

        memo[s_index][p_index] = result? 1 : 2;
        return result;
    }
private:
    vector<vector<int>> memo;
};

#endif