#include "include.h"

using namespace std;

int main() {
    string txt = "";
    string pattern = "";

    bool result = RegularExpressionMatch(txt, pattern);
    cout << result << endl;
    return 0;
}