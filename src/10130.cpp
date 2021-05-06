#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Product{
    int price;
    int weight;
    double ppw;
    Product(int p, int w, double v) {
        price = p;
        weight = w;
        ppw = v;
    }
};


bool ProductComp(const Product& lhs, const Product& rhs) {
    return lhs.ppw>rhs.ppw;
}


void take(vector<Product> &vec, int MW, int W, int index, int &MP, int P) {
    if (index >= vec.size()) return;
    if (P + (MW - W) * vec.at(index).ppw > MP) {
        if (W + vec.at(index).weight <= MW) {
            MP = max(MP, P + vec.at(index).price);
            take(vec, MW, W + vec.at(index).weight, index+1, MP, P + vec.at(index).price);
        }
        take(vec, MW, W, index +1, MP, P);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<Product> vec;
        vec.reserve(N);
        for (int i = 0; i < N; i++) {
            int P, W;
            cin >> P;
            cin >> W;
            float PPW = ((double)P)/W;
            vec.emplace_back(P, W, PPW);
        }

        sort(vec.begin(), vec.end(), ProductComp);

        int G;
        cin >> G;
        int sum = 0;
        for (int i = 0; i < G; i++) {
            int MW;
            cin >> MW;
            int MP = 0;
            take(vec, MW, 0, 0, MP, 0);
            sum += MP;
        }
        cout << sum << endl;
    }
    return 0;
}
