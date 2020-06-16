#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int cutRope(int number) {
        if (number <= 3) {
            return number - 1;
        }
        
        vector<int> dp_table(number + 1, 0);
        for (int i = 1; i <= 4; i++) {
            dp_table[i] = i;
        }
        
        for (int i = 5; i <= number; i++) {
            for (int j = 1; j < i; j++) {
                dp_table[i] = max(dp_table[i], j * dp_table[i - j]);
            }
        }
        return dp_table[number];
    }
};