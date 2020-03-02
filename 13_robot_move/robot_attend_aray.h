//
// Created by mxq on 20-1-13.
//

#ifndef AIM_AT_OFFER_ROBOT_ATTEND_ARAY_H
#define AIM_AT_OFFER_ROBOT_ATTEND_ARAY_H


int RobotMovingCount(int threshold, int rows, int cols);
int RobotMovingCountCore(int threshold, int rows, int cols, int row, int col, bool *visited);
bool CheckArrived(int rows, int cols, int row, int col, int threshold, bool *visited);
int GetDigitSum(int number);

#endif //AIM_AT_OFFER_ROBOT_ATTEND_ARAY_H
