//
// Created by mxq on 2020/2/4.
//

#include "print_1_to_max_of_n_digits.h"

/*
 * @brief: 采用字符串表示的方法打印从1到最大的N位数
 * @param: n: 数字的位数
 */
void Print1ToMaxOfNDigits(int n){
    if (n<=0)
        return;
    string number(n, '0');
    while (!IncrementNumber(number)){
        PrintNumber(number);
    }
}


/*
 * @brief: 对由字符串表示的数字加1
 * @number: 由字符串表示的数字
 */
bool IncrementNumber(string &number){
    unsigned int length = number.size();

    bool overflow = false;
    int take_over = 0;
    for (int index=length-1; index>=0; index--){
        int add_num = number[index] - '0' + take_over;
        if (index == length-1)
            add_num++;
        if (add_num >= 10){
            if (index == 0){
                overflow = true;
            }else{
                add_num -= 10;
                take_over = 1;
                number[index] = '0' + add_num;
            }
        }else{
            number[index] = '0' + add_num;
            break;
        }
    }
    return overflow;
}


/*
 * @brief: 使用递归的方式打印从1到最大的N位数
 * @param: n: 位数
 */
void Print1ToMaxOfNDigitsRecursively(int n){
    if (n <= 0)
        return;
    string number(n, '0');
    unsigned int index = 0;
    for (int i = 0; i < 10; i++){
        number[index] = '0' + i;
        Print1ToMaxOfNDigitsRecursivelyCore(number, index);
    }
}


void Print1ToMaxOfNDigitsRecursivelyCore(string &number, unsigned int index){
    // 如果到达最低位，则打印并返回
    if (index == number.size() - 1){
        PrintNumber(number);
        return;
    }
    // 对下一个下标位置的数字进行排列
    index++;
    for (int i = 0; i < 10; i++){
        number[index] = '0' + i;
        Print1ToMaxOfNDigitsRecursivelyCore(number, index);
    }
}


void PrintNumber(const string &number){
    bool start_print = false;
    for (auto single_number: number){
        if (single_number != '0')
            start_print = true;
        if (start_print){
            cout << single_number;
        }
    }
    cout << endl;
}