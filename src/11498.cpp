#include <iostream>
#include <math.h>

using namespace std;


int main() {
    while (true) {
        int K;
        cin >> K;
        if (K == 0) {
            break;
        }
        int N, M;
        cin >> N;
        cin >> M;
        for (int i = 0; i < K; i++) {
            int X, Y;
            cin >> X;
            cin >> Y;
            if (X == N ||Y == M) {
                cout << "divisa" << endl;
            }
            else if (X > N) {
                if (Y > M) {
                    cout << "NE" << endl;
                }
                else {
                    cout << "SE" << endl;
                }

            }
            else {
                if (Y > M) {
                    cout << "NO" << endl;
                }
                else {
                    cout << "SO" << endl;
                }
            }
        }
        

    }
    return 0;
}
