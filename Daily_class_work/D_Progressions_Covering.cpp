#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,k;
    cin>>n>>k;

    vector<long long>b(n+2);
    for(int i=1;i<=n;i++) cin>>b[i];

    vector<long long>endAdd(n+2,0), endSum(n+2,0);

    long long add=0;
    long long sum=0;
    long long ans=0;

    for(long long i=1;i<=n;i++)
    {
        add+=endAdd[i];
        sum+=endSum[i];

        long long cur = add*i - sum;

        if(cur < b[i])
        {
            long long need = b[i] - cur;
            ans += need;

            add += need;
            sum += need*(i-1);

            if(i+k <= n)
            {
                endAdd[i+k] -= need;
                endSum[i+k] -= need*(i-1);
            }
        }
    }

    cout<<ans;
}