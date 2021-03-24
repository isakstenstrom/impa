#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int sum = 0;
        for (int i = 0; i < 4; i++) {
            string str;
            cin >> str;
            for (int j = 0; j < 4; j++) {
                int number = stoi(str.substr(j, 1));
                if (j % 2 == 0) {
                    number = number * 2;
                }
                sum += number / 10;
                sum += number % 10;
            }
        }
        if (sum % 10 == 0) {
            cout << "Valid" << endl;
        }
        else {
            cout << "Invalid" << endl;
        }
    }
}