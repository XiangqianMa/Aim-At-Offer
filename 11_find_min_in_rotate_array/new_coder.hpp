#include <vector>

using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int left = 0;
        int right = rotateArray.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (rotateArray[left] >= rotateArray[right]) {
                if (rotateArray[mid] <= rotateArray[right]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else {
                right = mid;
            }
        }
        return rotateArray[left];
    }
};