#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

char ar1[100][100];
char ar2[100][100];

bool beats(char a, char b) {
    return ((a == 'R' && b == 'S') || (a == 'S' && b == 'P') || (a == 'P' && b == 'R'));
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c, n;
        cin >> r;
        cin >> c;
        cin >> n;
        auto arr1 = ar1;
        auto arr2 = ar2;

        for (int y = 0; y < r; y++) {
            for (int x = 0; x < c; x++) {
                char type;
                cin >> type;
                arr1[y][x] = type;
                arr2[y][x] = type;
            }   
        }

        for (int i = 0; i < n; i++) {
            for (int y = 0; y < r; y++) {
                for (int x = 0; x < c; x++) {
                    arr2[y][x] = arr1[y][x];
                    if (y-1 >= 0) {
                        if (beats(arr1[y-1][x], arr1[y][x])) arr2[y][x] = arr1[y-1][x];
                    }
                    
                    if (x-1 >= 0) {
                        if (beats(arr1[y][x-1], arr1[y][x])) arr2[y][x] = arr1[y][x-1];
                    }
                    
                    if (y+1 < r) {
                        // cout << arr1[y+1][x] << " " << arr1[y][x] << endl;
                        if (beats(arr1[y+1][x], arr1[y][x])) {
                            arr2[y][x] = arr1[y+1][x];
                        }
                    }
                    
                    if (x+1 < c) {
                        if (beats(arr1[y][x+1], arr1[y][x])) arr2[y][x] = arr1[y][x+1];
                    }
                }   
            }
            auto temp = arr1;
            arr1 = arr2;
            arr2 = temp;
        }

        for (int y = 0; y < r; y++) {
            for (int x = 0; x < c; x++) {
                cout << arr1[y][x];
            }
            cout << endl;
        }
        if (t > 0) cout << endl;
        // cout << endl;
    }
    return 0;
}