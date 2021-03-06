#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <tuple>

using namespace std;

static const double degreeToRadian = 3.14159265358979323846/180.0;

double distanceBetween(tuple<double, double, double, double, double> a, tuple<double, double, double, double, double> b) {
    return sqrt((get<2>(a)-get<2>(b))*(get<2>(a)-get<2>(b)) 
        + (get<3>(a)-get<3>(b))*(get<3>(a)-get<3>(b))
        + (get<4>(a)-get<4>(b))*(get<4>(a)-get<4>(b)));
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        vector<tuple<double, double, double, double, double>> airports;
        double lat, lon;
        while(n--) {
            scanf("%lf %lf", &lat, &lon);
            double x = cos(lat * degreeToRadian) * cos(lon * degreeToRadian);
            double y = cos(lat * degreeToRadian) * sin(lon * degreeToRadian);
            double z = sin(lat * degreeToRadian);

            airports.emplace_back(tuple<double, double, double, double, double>(lat, lon, x, y, z));
        }

        double min_len = 1e+40;
        pair<double, double> hub;
        for (int i = 0; i < airports.size(); i++) {
            double max_len = 0;
            for (int j = 0; j < airports.size(); j++) {
                max_len = max(max_len, distanceBetween(airports.at(i), airports.at(j)));
            }
            if (max_len - 1e-6 <= min_len) {
                min_len = max_len;
                hub = pair<double, double>(get<0>(airports.at(i)), get<1>(airports.at(i)));
            }
        }
        printf("%.2lf %.2lf\n", hub.first, hub.second);
    }
    return 0;
}