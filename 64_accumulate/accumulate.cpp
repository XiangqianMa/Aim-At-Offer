//
// Created by mxq on 2020/3/2.
//

#include "accumulate.h"


/**
 * @brief 采用构造函数计算累加和
 * @param n
 * @return
 */
unsigned int SumSolution1(unsigned int n){
    Temp::Reset();
    Temp *a = new Temp[n];
    delete[] a;
    a = nullptr;

    return Temp::GetSum();
}


/**
 * @brief 借助继承时虚函数的特性实现递归求解
 * @param n
 * @return
 */
unsigned int SumSolution2(unsigned int n){
    A a;
    B b;
    Array[0] = &a;
    Array[1] = &b;

    unsigned int result = Array[1]->Sum(n);
    return result;
}


/*
 * 使用函数指针实现
 */
unsigned int SumSolution3Teminator(unsigned int n){
    return 0;
}


unsigned int SumSolution3(unsigned int n){
    static fun f[2] = {SumSolution3Teminator, SumSolution3};
    return f[n != 0](n - 1) + n;
}


/*
 * 利用模板特性实现
 */
template <unsigned int n> struct SumSolution4
{
    enum Value { N = SumSolution4<n - 1>::N + n};
};


template <> struct SumSolution4<1>{
    enum Value {N = 1};
};