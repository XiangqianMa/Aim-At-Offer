#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        if (str.empty()) {
            return {};
        }
        
        sort(str.begin(), str.end());
        vector<bool> used(str.size(), false);
        dfs(str, used, "");
        return result;
    }
    
    void dfs(string str, vector<bool> used, string path) {
        if (path.size() == str.size()) {
            result.push_back(path);
            return;
        }
        
        vector<bool> seen(26, false);
        for (int i = 0; i < str.size(); i++) {
            if (!seen[str[i] - 'a'] && !used[i]) {
                auto temp = path + str[i];
                used[i] = true;
                dfs(str, used, temp);
                used[i] = false;
                seen[str[i] - 'a'] = true;
            }
        }
    }

private:
    vector<string> result;
};