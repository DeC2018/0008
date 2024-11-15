#include <string>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        trim(s);
        if (s.empty())
            return 0;

        const int sign = s[0] == '-' ? -1 : 1;
        if (s[0] == '+' || s[0] == '-')
            s = s.substr(1);

        long num = 0;

        for (const char c : s) {
            if (!isdigit(c))
                break;
            num = num * 10 + (c - '0');
            if (sign * num < INT_MIN)
                return INT_MIN;
            if (sign * num > INT_MAX)
                return INT_MAX;
        }

        return sign * num;
    }

private:
    void trim(string& s) {
        s.erase(0, s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ') + 1);
    }
};

// Test function to demonstrate the solution
void test(const string& input) {
    Solution solution;
    cout << "Input: \"" << input << "\"" << endl;
    cout << "Output: " << solution.myAtoi(input) << endl << endl;
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
