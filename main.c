#include <stdio.h>
#include <string.h>
#include <limits.h>

int myAtoi(char* s) {
    int i, len = strlen(s);
    int val = 0;
    int sign = 1, check = 0;
    
    for (i = 0; i < len; i++) {
        if (check == 0 && (s[i] == '+' || s[i] == '-')) {
            check = 1;
            sign = s[i] == '+' ? 1 : -1;
            continue;
        }

        if (check == 0 && s[i] == ' ') {
            continue;
        }

        if (s[i] >= '0' && s[i] <= '9') {
            check = 1;

            if (val > 214748364 || (val == 214748364 && s[i] > '7')) {
                if (sign == 1) {
                    return INT_MAX;
                }
                else {
                    return INT_MIN;
                }
            }

            val = val * 10 + (s[i] - '0');
        }
        else {
            break;
        }
    }

    return sign * val;
}

// Test function to demonstrate the solution
void test(const char* input) {
    printf("Input: \"%s\"\n", input);
    printf("Output: %d\n\n", myAtoi(input));
}

int main() {
    // Test cases from the problem description
    test("42");
    test(" -042");
    test("1337c0d3");
    test("0-1");
    test("words and 987");
    
    // Additional test cases
    test("   +0 123");
    test("-91283472332"); // Should return INT_MIN
    test("2147483648");   // Should return INT_MAX
    
    return 0;
}
