#include <iostream>
#include <vector>

using namespace std;


int main() {
    int H_MAX = 1000001;
    vector<int> value((H_MAX-1)/4 + 1);
    for (int i = 0; i < value.size(); i++) {
        value.at(i) = 4*i +1;
    }
    vector<int> divisions((H_MAX-1)/4 + 1, 0);

    for (int i = 1; i < value.size(); i++) {
        int prime = 4*i +1;
        if (value.at(i) == prime && divisions.at(i) == 0) {
            for (int j = 2*prime; j < 4*value.size() +1; j += prime) {
                int index = (j-1)/4;
                while(value.at(index)%prime == 0 && value.at(index) != 1) {
                    value.at(index) = value.at(index) / prime;
                    divisions.at(index)++;
                }
            }
        }
    }

    
    while (true) {
        int h;
        cin >> h;
        if (h == 0) {
            break;
        }

        int sum = 0;
        for (int i = 2; i < (h-1)/4 + 1; i++) {
            if (value.at(i) == 1 && divisions.at(i) == 2) {
                sum++;
            }
        }
        cout << h << " " << sum << endl;
    }
    return 0;
}