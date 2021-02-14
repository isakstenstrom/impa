#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int k, n;

struct Box{
    int dimentions[10];
    bool encapulates[30];
    int nextBox;
    int level;
    
    bool fits(const Box &b) {
        for (int i = 0; i < n; i++) {
            if (dimentions[i] <= b.dimentions[i]) {
                return false;
            }
        }
        return true;
    }
};

struct Box boxes[30];

int getLevel(int box) {
    if (boxes[box].level != -1) return boxes[box].level;
    boxes[box].level = 0;
    for (int i = 0; i < k; i++) {
        if (boxes[box].encapulates[i]) {
            int level = getLevel(i);
            if (level >= boxes[box].level) {
                boxes[box].level = level +1;
                boxes[box].nextBox = i;
            }
        }
    }
    return boxes[box].level;
}

void printBox(int box, bool printSpace) {
    if (boxes[box].level != 0) {
        printBox(boxes[box].nextBox, true);
    }

    cout << box +1;
    if (printSpace) cout << " ";
}

int main() {
    while (scanf("%d %d", &k, &n) != EOF) {

        for (int i = 0; i < k; i++) {
            boxes[i].level = -1;
            boxes[i].nextBox = -1;
            memset(boxes[i].encapulates, false, sizeof(boxes[i].encapulates));
            for (int j = 0; j < n; j++) {
                scanf("%d", &boxes[i].dimentions[j]);
            }
            sort(boxes[i].dimentions, boxes[i].dimentions +n, greater<int>());
        }

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                boxes[i].encapulates[j] = boxes[i].fits(boxes[j]);
            }
        }

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                boxes[i].encapulates[j] = boxes[i].fits(boxes[j]);
            }
        }

        int maxLevel = -1;
        int maxBox;
        for (int i = 0; i < k; i++) {
            int level = getLevel(i);
            if (getLevel(i) > maxLevel) {
                maxLevel = level;
                maxBox = i;
            }
        }

        cout << maxLevel +1 << endl;
        printBox(maxBox, false);
        cout << endl;
    }
    return 0;
}