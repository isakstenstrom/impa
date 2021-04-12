#include <iostream>

using namespace std;


int main() {
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        int score = 0;
        int sum = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.at(i) == 'O') {
                score++;
                sum += score;
            }
            else {
                score = 0;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
