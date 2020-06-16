## 回溯法
注意：访问过的位置不能被重复访问，因而需要进行标记。
```c++
class Solution {
public:
    int movingCount(int threshold, int rows, int cols) {
        vector<vector<bool>> is_valid(rows, vector<bool>(cols, false));
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (bitSum(i, j) <= threshold) {
                    is_valid[i][j] = true;
                }
            }
        }
        
        if (is_valid[0][0]) {
            visited[0][0] = true;
            dfs(0, 0, rows, cols, is_valid, visited);
        }
        return count;
    }
    
    void dfs(int row, int col, int rows, int cols, vector<vector<bool>>& is_valid, vector<vector<bool>>& visited) {
        vector<int> row_diffs = {-1, 1, 0, 0};
        vector<int> col_diffs = {0, 0, -1, 1};
        
        count++;
        for (int i = 0; i < 4; i++) {
            int next_row = row + row_diffs[i];
            int next_col = col + col_diffs[i];
            if (next_row >= 0 && next_row < rows && next_col >= 0 && next_col < cols && 
                is_valid[next_row][next_col] && !visited[next_row][next_col]) {
                visited[next_row][next_col] = true;
                dfs(next_row, next_col, rows, cols, is_valid, visited);
            }
        }
    }
    
    int bitSum(int num1, int num2) {
        int result = 0;
        while (num1 > 0) {
            result += num1 % 10;
            num1 /= 10;
        }
        
        while (num2 > 0) {
            result += num2 % 10;
            num2 /= 10;
        }
        return result;
    }
 
private:
    int count = 0;
};
```