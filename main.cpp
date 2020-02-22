#include "include.h"

using namespace std;


int main() {
    DynamicArray<int> my_array;
    my_array.Insert(0);
    my_array.Insert(1);
    my_array.Insert(2);
    my_array.Insert(3);
    my_array.Insert(-1);

    int median = my_array.GetMedian();
    cout << median << endl;
}