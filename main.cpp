#include "include.h"

using namespace std;

int main() {
    char matrix[12] = {'a', 'b', 't', 'g', 'c', 'f', 'c', 's', 'j', 'd', 'e', 'h'};
    char path[4] = {'b', 'f', 'c', 'l'};
    bool has_path = HasPath(matrix, 3, 4, path, 4);

    return 0;
}