#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;


int main() {
    int p, a, b, c, d, n;
    while (scanf("%d %d %d %d %d %d", &p, &a, &b, &c, &d, &n) != EOF) {
        double maxValue = 0;
        double maxDecline = 0;
        for (int k = 1; k <= n; k++) {
            double price = p * (sin(a*k+b) + cos(c*k+d) + 2);
            maxValue = max(maxValue, price);
            maxDecline = max(maxDecline, maxValue - price);
        }
        printf("%.8lf\n",maxDecline);
    }
    return 0;
}