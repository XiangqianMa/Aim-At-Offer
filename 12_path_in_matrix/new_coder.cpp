#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int str_len = strlen(str);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (*(matrix + i * cols + j) == *str) {
                    visited[i][j] = true;
                    bool result = dfs(i, j, rows, cols, 1, str_len, visited, matrix, str);
                    visited[i][j] = false;
                    if (result) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
    
    bool dfs(int row, int col, int rows, int cols, int index, int len, vector<vector<bool>> visited, char* matrix, char* str) {
        if (index == len) {
            return true;
        }
        
        vector<int> row_diffs = {-1, 1, 0, 0};
        vector<int> col_diffs = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++) {
            int next_row = row + row_diffs[i];
            int next_col = col + col_diffs[i];
            if (next_row >= 0 && next_row < rows && next_col >= 0 && next_col < cols &&
               !visited[next_row][next_col] && *(matrix + next_row * cols + next_col) == *(str + index)) {
                visited[next_row][next_col] = true;
                bool result = dfs(next_row, next_col, rows, cols, index + 1, len, visited, matrix, str);
                visited[next_row][next_col] = false;
                if (result) {
                    return true;
                }
            }
        }
        return false;
    }
};