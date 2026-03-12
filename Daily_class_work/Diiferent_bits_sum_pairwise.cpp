#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A) {

    const long long MOD = 1e9+7;
    long long n = A.size();
    long long ans = 0;

    for(int bit=0; bit<32; bit++)
    {
        long long ones = 0;

        for(int x : A)
        {
            if(x & (1<<bit))
                ones++;
        }

        long long zeros = n - ones;

        ans = (ans + (2LL * ones * zeros) % MOD) % MOD;
    }

    return ans;
}