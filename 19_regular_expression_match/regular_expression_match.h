//
// Created by mxq on 2020/2/9.
//

#ifndef AIM_AT_OFFER_REGULAR_EXPRESSION_MATCH_H
#define AIM_AT_OFFER_REGULAR_EXPRESSION_MATCH_H

#include <string>

using namespace std;

bool MatchCore(const string& txt, const string& pattern, int txt_index, int pattern_index);
bool RegularExpressionMatch(const string& txt, const string& pattern);
#endif //AIM_AT_OFFER_REGULAR_EXPRESSION_MATCH_H
