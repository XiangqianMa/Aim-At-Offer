#include "include.h"

using namespace std;


int main() {
    CharStatistic my_char_statistic;
    my_char_statistic.Insert('g');
    my_char_statistic.Insert('o');
    my_char_statistic.Insert('o');
    my_char_statistic.Insert('l');
    my_char_statistic.Insert('l');

    char result = my_char_statistic.FirstNotRepeatingChar();
    cout << result << endl;
}