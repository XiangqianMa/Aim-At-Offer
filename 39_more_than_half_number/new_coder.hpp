#include <vector>

using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int mid = numbers.size() / 2;
        int start = 0;
        int end = numbers.size() - 1;
        int selected_index = partition(numbers, start, end);
        while (selected_index != mid) {
            if (selected_index > mid) {
                end = selected_index - 1;
            } else {
                start = selected_index + 1;
            }
            selected_index = partition(numbers, start, end);
        }
        
        int count = 0;
        for (auto num : numbers) {
            if (num == numbers[selected_index]) {
                count++;
            }
        }
        
        int result = numbers[selected_index];
        if (numbers.size() & 1) {
            if (count < (numbers.size() + 1) / 2) {
                result = 0;
            }
        } else {
            if (count <= numbers.size() / 2) {
                result = 0;
            }
        }
        
        return result;
    }
    
    int partition(vector<int>& numbers, int start, int end) {
        if (start == end) {
            return start;
        }
        
        int selected_index = end;
        int smaller = start - 1;
        for (int i = start; i < end; i++) {
            if (numbers[i] < numbers[end]) {
                smaller++;
                int temp = numbers[i];
                numbers[i] = numbers[smaller];
                numbers[smaller] = temp;
            }
        }
        
        smaller++;
        int temp = numbers[end];
        numbers[end] = numbers[smaller];
        numbers[smaller] = temp;
        return smaller;
    }
};