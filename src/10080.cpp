#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

struct Point{
    double x, y;

    double distanceTo(const Point &p) {
        return sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y));
    }
};

bool increaseFlow(int g, int m, bool arr[100][100], int gopherInHole[100], bool visited[100]) {
    for (int h = 0; h < m; h++) {
        if (arr[g][h] && !visited[h]) {
            visited[h] = true;

            if (gopherInHole[h] == -1 || increaseFlow(gopherInHole[h], m, arr, gopherInHole, visited)) {
                gopherInHole[h] = g;
                return true;
            }
        }
    }
    return false;
}


int main() {
    bool arr[100][100];
    int n, m, s, v;
    while (scanf("%d %d %d %d", &n, &m, &s, &v) != EOF) {

        double d = s*v;

        vector<Point> gophers;
        for (int i = 0; i < n; i++) {
            gophers.push_back(Point());
            scanf("%lf %lf", &(gophers.at(i).x), &(gophers.at(i).y));
        }

        vector<Point> holes;
        for (int i = 0; i < m; i++) {
            holes.push_back(Point());
            scanf("%lf %lf", &(holes.at(i).x), &(holes.at(i).y));
        }

        for (int g = 0; g < n; g++) {
            for (int h = 0; h < m; h++) {
                arr[g][h] = (gophers.at(g).distanceTo(holes.at(h)) <= d);
            }
        }

        int gopherInHole[100];
        memset(gopherInHole, -1, sizeof(gopherInHole));

        int vulnerableGophers = n;
        for (int g = 0; g < n; g++) {
            bool visited[100];
            memset(visited, false, sizeof(visited));
            if (increaseFlow(g, m, arr, gopherInHole, visited)) {
                vulnerableGophers--;
            }
        }
        cout << vulnerableGophers << endl;
    }
    return 0;
}