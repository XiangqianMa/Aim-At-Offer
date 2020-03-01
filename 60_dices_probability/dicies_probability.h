//
// Created by mxq on 2020/3/1.
//

#ifndef AIM_AT_OFFER_DICIES_PROBABILITY_H
#define AIM_AT_OFFER_DICIES_PROBABILITY_H

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

void ProbabilityRecursiveCore(int min_sum, int current_dice, int sum, vector<int>& sum_times, const int dice_max_value);
void Probability(const int dices_number, vector<int>& sum_times, const int dice_max_value);
void PrintProbability(const int& dices_number, const int& dice_max_value);
void PrintProbabilityIterate(const int& dices_number, const int& dice_max_value);
#endif //AIM_AT_OFFER_DICIES_PROBABILITY_H
