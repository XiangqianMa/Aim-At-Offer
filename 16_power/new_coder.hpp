class Solution {
public:
    double Power(double base, int exponent) {
        if (base == 0) {
            return 0;
        }
        
        if (exponent == 0) {
            return 1;
        }
        
        if (exponent < 0) {
            return 1 / Power(base, -exponent);
        }
        
        if (exponent & 1) {
            return base * Power(base, exponent - 1);
        }
        
        return Power(base * base, exponent / 2);
    }
};