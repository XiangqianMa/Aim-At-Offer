#include "include.h"

using namespace std;


int main() {
    vector<vector<int>> gifts = {{1, 10, 3, 8}, {12, 2, 9, 6}, {5, 7, 4, 11}, {3, 7, 16, 5}};
    int result = GetMaxValueOfGiftsSolution2(gifts, 4, 4);
    cout << result << endl;
}