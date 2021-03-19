#include <iostream>

using namespace std;
     
int main() {
    int s, p, y, j;
    while (scanf("%d %d %d %d", &s, &p, &y, &j) != EOF) {
        int Y = (j+12-p-y)/3;
        int P = (j+12-s-Y)/2;
        int S = (j+12-Y-P);
        cout << S << " " << P << " " << Y << endl;
    }
    return 0;
}