#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>

using namespace std;


int main() {
    int N;
    scanf("%d\n", &N);
    for (int n = 1; n <= N; n++) {
        int B, SG, SB;
        scanf("%d %d %d\n", &B, &SG, &SB);

        multiset<int, greater<int>> greenArmy;
        for (int i = 0; i < SG; i++) {
            int lemming;
            scanf("%d", &lemming);
            greenArmy.insert(lemming);
        }

        multiset<int, greater<int>> blueArmy;
        for (int i = 0; i < SB; i++) {
            int lemming;
            scanf("%d", &lemming);
            blueArmy.insert(lemming);
        }
        
        while (true) {
            if (greenArmy.size() == 0 && blueArmy.size() == 0) {
                cout << "green and blue died" << endl;
                break;
            }
            else if (greenArmy.size() == 0) {
                cout << "blue wins" << endl;
                for (int lemming : blueArmy) {
                    cout << lemming << endl;
                }
                break;
            }
            else if (blueArmy.size() == 0) {
                cout << "green wins" << endl;
                for (int lemming : greenArmy) {
                    cout << lemming << endl;
                }
                break;
            }

            multiset<int, greater<int>> greenSurviors;
            multiset<int, greater<int>> blueSurviors;

            int battleSize = min(B, (int)min(greenArmy.size(), blueArmy.size()));
            multiset<int, greater<int>>::iterator g = greenArmy.begin();
            multiset<int, greater<int>>::iterator b = blueArmy.begin();
            for (int i = 0; i < battleSize; i++) {
                if (*g - *b > 0) greenSurviors.insert(*g - *b); 
                if (*b - *g > 0) blueSurviors.insert(*b - *g);
                g = greenArmy.erase(g);
                b = blueArmy.erase(b); 
            }

            for (int lemming : greenSurviors) greenArmy.insert(lemming);
            for (int lemming : blueSurviors) blueArmy.insert(lemming);

        }
        if (n != N) cout << endl;
    }
    return 0;
}
