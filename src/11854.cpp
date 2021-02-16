#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    while (true) {
        unsigned long long a, b, c;
        scanf("%llu %llu %llu", &a, &b, &c);
        if (a == 0 && b == 0 && c == 0) break;
        a = a*a;
        b = b*b;
        c = c*c;

        if (a+b==c || a+c==b || b+c==a) {
            cout << "right" << endl;
        } else {
            cout << "wrong" << endl;
        }
    }
    return 0;
}