//
// Created by mxq on 2020/3/1.
//

#include "continuous_cards.h"


/**
 * @brief 判断卡牌是否为顺子
 * @param cards
 * @return
 */
bool IsContinuousCards(vector<int> cards){
    if (cards.empty())
        return false;
    sort(cards.begin(), cards.end());
    // 统计0的个数
    int zero_count = 0;
    for (auto card: cards){
        if (card == 0)
            zero_count++;
    }

    // 统计间隔数
    int gap_count = 0;
    bool duplicate_flag = false;
    for (int i = zero_count; i < cards.size() - 1; i++){
        if (cards[i] == cards[i + 1]){
            duplicate_flag = true;
            break;
        } else if (cards[i + 1] - cards[i] > 1)
            gap_count += cards[i + 1] - cards[i] - 1;
    }

    bool result = false;
    // 不存在重复卡牌且大小王的数目与间隔数相等
    if (!duplicate_flag && zero_count == gap_count)
        result = true;
    return result;
}