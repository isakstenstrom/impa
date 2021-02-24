#include <iostream>
#include <math.h>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

static const string ALPHABET = "abcdefghijklmnoprstuvwxyz"; // q is intentionally missing


int main() {
    int N;
    string str;
    scanf("%d", &N);
    getline(cin,str);
    while (N--) {
        // Create key
        char key[5][5];
        getline(cin, str);
        str.append(ALPHABET);
        set<char> usedLetters;
        usedLetters.insert(' ');
        usedLetters.insert('\n');
        usedLetters.insert('\r');
        for (int i = 0; i < str.length(); i++) {
            if (usedLetters.count(str.at(i)) == 1) {
                str.erase(i, 1);
                i--;
            }
            else usedLetters.insert(str.at(i));
        }
        // cout << str << endl;
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 5; x++) {
                key[y][x] = str.at(y*5 +x);
            }
        }

        // Encrypt message
        getline(cin, str);
        for (int i = 0; i < str.length(); i++) {
            if (str.at(i) == ' ' || str.at(i) == '\r') {
                str.erase(i, 1);
                i--;
            }
        }

        int i = 0;
        while (true) {
            if (i >= str.length()) break;

            if (i +1 == str.length() || str.at(i) == str.at(i +1)) {
                str.insert(i +1, "x");
            }

            int x0, y0, x1, y1;
            for (int y = 0; y < 5; y++) {
                for (int x = 0; x < 5; x++) {
                    if (key[y][x] == str.at(i)) {
                        x0 = x;
                        y0 = y;
                    }
                    if (key[y][x] == str.at(i+1)) {
                        x1 = x;
                        y1 = y;
                    }
                }
            }

            if (y0 == y1) {
                str.replace(i, 1, 1, key[y0][(x0 +1) % 5]);
                str.replace(i +1, 1, 1, key[y1][(x1 +1) % 5]);
            } else if (x0 == x1) {
                str.replace(i, 1, 1, key[(y0 +1) % 5][x0]);
                str.replace(i +1, 1, 1, key[(y1 +1) % 5][x1]);
            } else {
                str.replace(i, 1, 1, key[y0][x1]);
                str.replace(i +1, 1, 1, key[y1][x0]);
            }
            i += 2;

        }

        for(auto& x: str) x = toupper(x);
        cout << str << endl;
    }
    return 0;
}