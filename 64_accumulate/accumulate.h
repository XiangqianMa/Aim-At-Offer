//
// Created by mxq on 2020/3/2.
//

#ifndef AIM_AT_OFFER_ACCUMULATE_H
#define AIM_AT_OFFER_ACCUMULATE_H


class Temp
{
public:
    Temp(){
        n++;
        sum += n;
    }

    static void Reset(){
        n = 0;
        sum = 0;
    }

    static unsigned int GetSum(){
        return sum;
    }

private:
    static unsigned int n;
    static unsigned int sum;
};


/*
 * 借助虚函数的特性实现递归
 */


class A
{
public:
    virtual unsigned int Sum(unsigned int n){
        return 0;
    }
};


A* Array[2];

class B: public A
{
public:
    virtual unsigned int Sum(unsigned int n){
        return Array[n != 0]->Sum(n - 1) + n;
    }
};


typedef unsigned int (*fun)(unsigned int);

#endif //AIM_AT_OFFER_ACCUMULATE_H
