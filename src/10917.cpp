#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;


struct Intersection{
    int distance = -1;
    int numberOfPaths = -1;
    vector<pair<int, int>> paths;
};


int calculatePaths(vector<Intersection> &inters, int node) {
    if (node == 2) return 1;
    if (inters.at(node).numberOfPaths != -1) {
        return inters.at(node).numberOfPaths;
    }
    else {
        int sum = 0;
        int thisCost = inters.at(node).distance;
        for (pair<int, int> path : inters.at(node).paths) {
            if (inters.at(path.first).distance < thisCost) {
                sum += calculatePaths(inters, path.first);
            }
        }
        inters.at(node).numberOfPaths = sum;
        return sum;
    }
}


int main() {
    while (true) {
        vector<Intersection> inters;
        int N, M;
        cin >> N;
        if (N == 0) break;
        cin >> M;
        inters.resize(N+1);
        while (M--) {
            int a, b, d;
            cin >> a;
            cin >> b;
            cin >> d;
            inters.at(a).paths.emplace_back(b, d);
            inters.at(b).paths.emplace_back(a, d);
        }

        auto cmp = [](pair<int, int> left, pair<int, int> right) { return left.second>right.second; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> queue(cmp);

        queue.emplace(2, 0);
        while (!queue.empty()) {
            pair<int, int> a = queue.top();
            vector<Intersection>::iterator node = inters.begin();
            advance(node, a.first);
            int cost = a.second;
            queue.pop();

            if (node->distance != -1 && node->distance <= cost) continue;
            node->distance = cost;

            int sum = 0;
            for (pair<int, int> path : node->paths) {
                queue.emplace(path.first, cost + path.second);
            }
        }

        cout << calculatePaths(inters, 1) << endl;
    }
    return 0;
}
