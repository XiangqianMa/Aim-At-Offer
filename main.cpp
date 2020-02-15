#include "include.h"

using namespace std;


int main() {
    int **matrix = new int*[1];
    for (int i = 0; i < 4; i++)
        matrix[i] = new int[1];
    for (int i=0; i<1; i++){
        for (int j=0; j<1; j++)
            matrix[i][j] = i * 4 + j + 1;
    }
    PrintMatrixClockwisely(matrix, 1, 1);
    return 0;
}