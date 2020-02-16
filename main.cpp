#include "include.h"

using namespace std;


int main() {
    StackWithMin<int> my_stack;
    my_stack.push(0);
    my_stack.push(1);
    my_stack.push(4);
    my_stack.push(-1);
    cout << my_stack.min() << endl;
    my_stack.pop();
    cout << my_stack.min() << endl;
    my_stack.pop();
    cout << my_stack.min() << endl;
}