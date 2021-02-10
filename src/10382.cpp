#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

bool compareSprinklers(const pair<double, double> &a, const pair<double, double> &b) {
    return a.first < b.first;
}

int main() {
    int n, length, width;
    while (scanf("%d %d %d", &n, &length, &width) != EOF) {
        double halfWidth = width*width/4.0;

        vector<pair<double, double>> sprinklers;
        sprinklers.reserve(n);
        for (int i = 0; i < n; i++) {
            int pos, radius;
            scanf("%d %d", &pos, &radius);
            if (radius * 2 > width) {
                double offset = sqrt((double)radius*radius - halfWidth);
                sprinklers.emplace_back(pos-offset, pos+offset);
            }
        }

        sort(sprinklers.begin(), sprinklers.end(), compareSprinklers);

        bool done = false;
        int numberOfSprinklers = 0;
        double lowerBound = 0;
        while (true) {
            if (lowerBound >= length) {
                done = true;
                break;
            }

            double upperBound = lowerBound;
            for (int i = 0; i < sprinklers.size(); i++){
                if (sprinklers.at(i).first <= lowerBound && upperBound < sprinklers.at(i).second) {
                    upperBound = sprinklers.at(i).second;
                }
            }

            if (upperBound == lowerBound) break;
            else {
                numberOfSprinklers++;
                lowerBound = upperBound;
            }
        }

        if (!done) cout << "-1" << endl;
        else cout << numberOfSprinklers << endl;
    }
    return 0;
}