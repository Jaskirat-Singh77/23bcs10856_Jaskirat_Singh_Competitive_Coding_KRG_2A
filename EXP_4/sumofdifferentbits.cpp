#include <iostream>
#include <vector>
using namespace std;

long long calc(const vector<int>& v) {
    int m = v.size();
    long long ans = 0;

    for (int b = 0; b < 32; b++) {
        int c1 = 0;

        for (int x : v) {
            if (x & (1 << b)) c1++;
        }

        int c0 = m - c1;
        ans += 2LL * c1 * c0;
    }

    return ans;
}

int main() {
    vector<int> a = {1, 3, 5};
    vector<int> b = {2, 3};

    cout << calc(a) << endl;
    cout << calc(b) << endl;

    return 0;
}
