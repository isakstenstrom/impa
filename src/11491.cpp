#include <iostream>
#include <math.h>

using namespace std;


int main() {
    while (true) {
        int N, D;
        cin >> N;
        cin >> D;
        if (N == 0 && D == 0) {
            break;
        }
        string str;
        cin >> str;

        int i = 0;
        int d = D;
        while (d > 0) {
            if (i + d +1 > str.length()) {
                break;
            }
            int maxDigit = -1;
            int digitPos = 0;
            for (int j = 0; j <= d; j++) {
                int digit = str.at(i + j) - '0';
                if (digit > maxDigit) {
                    maxDigit = digit;
                    digitPos = j;
                }
            }
            str.erase(i, digitPos);
            d -= digitPos;
            i++;
        }
        cout << str.substr(0, N - D) << endl;
    }
    return 0;
}
