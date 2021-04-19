#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct CarMaker{
    string name;
    int low;
    int high;
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        vector<CarMaker> makers;
        int D;
        cin >> D;
        makers.resize(D);
        for (int i = 0; i < D; i++){
            cin >> makers.at(i).name;
            cin >> makers.at(i).low;
            cin >> makers.at(i).high;
        }

        int Q;
        cin >> Q;
        while (Q--) {
            int P;
            cin >> P;

            string makerName = "";
            for (CarMaker maker : makers) {
                if ((maker.low <= P) && (P <= maker.high)) {
                    if (makerName == "") {
                        makerName = maker.name;
                    }
                    else {
                        makerName = "";
                        break;
                    }
                }
            }
            
            if (makerName == "") cout << "UNDETERMINED" << endl;
            else cout << makerName << endl;

        }
        if (T != 0) {
            cout << endl;
        }
    }
    return 0;
}
