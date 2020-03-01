//
// Created by mxq on 2020/3/1.
//

#include "max_stock_profit.h"


/**
 * @brief 计算股票的最大利润
 * @param stock
 * @return
 */
int GetMaxStockProfit(const vector<int>& stock){
    if (stock.size() <= 1)
        return -1;

    int min_stack_price = stock[0];
    int max_profit = stock[1] - min_stack_price;

    for (int index = 1; index < stock.size(); index++){
        if (stock[index] - min_stack_price > max_profit)
            max_profit = stock[index] - min_stack_price;
        if (stock[index] < min_stack_price)
            min_stack_price = stock[index];
    }
    return max_profit;
}