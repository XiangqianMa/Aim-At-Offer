#include "include.h"

using namespace std;


int main() {
    vector<int> data = {1, 3, 5, 7, 2, 4, 6, 8};

    ReorderOddEven(data);
    for (auto i: data)
        cout << i << endl;
    return 0;
}