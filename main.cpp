#include "include.h"

using namespace std;


int main() {
    vector<int> data = {};
    vector<int> result = FindMaxInSlidingWindow(data, 3);
    for (auto num: result)
        cout << num << ' ' << endl;
}