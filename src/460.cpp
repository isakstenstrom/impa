#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstring>

using namespace std;
     

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int x1l, y1l, x1u, y1u;
        int x2l, y2l, x2u, y2u;
        scanf("%d %d %d %d", &x1l, &y1l, &x1u, &y1u);
        scanf("%d %d %d %d", &x2l, &y2l, &x2u, &y2u);

        int xl = max(x1l, x2l);
        int yl = max(y1l, y2l);
        int xu = min(x1u, x2u);
        int yu = min(y1u, y2u);

        if (xl >= xu || yl >= yu) {
            cout << "No Overlap" << endl;
        }
        else {
            cout << xl;
            cout << " ";
            cout << yl;
            cout << " ";
            cout << xu;
            cout << " ";
            cout << yu;
            cout << endl;
        }

        if (n != 0) cout << endl;

    }
    return 0;
}