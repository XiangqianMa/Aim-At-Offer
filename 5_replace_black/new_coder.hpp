class Solution {
public:
	void replaceSpace(char *str, int length) {
        int space_count = 0;
        for (int i = 0; i < length; i++) {
            if (str[i] == ' ') {
                space_count++;
            }
        }
        
        int new_length = length + 2 * space_count;
        int i = length - 1;
        int j = new_length - 1;
        while (i >= 0 && j >= 0) {
            if (str[i] == ' ') {
                str[j] = '0';
                j--;
                str[j] = '2';
                j--;
                str[j] = '%';
                j--;
                i--;
            } else {
                str[j] = str[i];
                j--;
                i--;
            }
        }
	}
};