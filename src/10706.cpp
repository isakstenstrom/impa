#include <iostream>
#include <math.h>

using namespace std;

int sizeOfGroup(int k) {
    int size = 0;
    int minus = 1;
    while (k - minus +1 > 0) {
        size += k - minus +1;
        minus *= 10;
    }
    return size;
}

char getDigitInGroup(int i) {
    int j = 0;
    while(i >= 0) {
        j++;
        i -= to_string(j).length();
    }
    string str = to_string(j);
    return str[str.length() + i];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int i;
        cin >> i;
        i--;
        int j = 1;
        while (true) {
            int groupSize = sizeOfGroup(j);
            if (groupSize > i) break;
            i -= groupSize;
            j++;
        }
        cout << getDigitInGroup(i) << endl;
    }
    return 0;
}
