#include <iostream>

using namespace std;


int main() {
    while (true) {
        int start, c1, c2, c3;
        scanf("%d %d %d %d", &start, &c1, &c2, &c3);
        if (start == 0 && c1 == 0 && c2 == 0 && c3 == 0) {
            break;
        }
        int setps = 40 * 3;
        setps += (40 + start - c1) % 40;
        setps += (40 + c2 - c1) % 40;
        setps += (40 + c2 - c3) % 40;
        cout << setps *9 << endl;
    }
    return 0;
}
