#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    vector<int>prime;
    vector<int>isPrime(n+1,1);

    isPrime[0]=isPrime[1]=0;

    for(int i=2;i<=n;i++)
    {
        if(isPrime[i])
        {
            prime.push_back(i);
            for(long long j=1LL*i*i;j<=n;j+=i)
                isPrime[j]=0;
        }
    }

    int cnt=0;

    for(int i=0;i+1<prime.size();i++)
    {
        int x = prime[i] + prime[i+1] + 1;

        if(x<=n && isPrime[x])
            cnt++;
    }

    if(cnt>=k) cout<<"YES";
    else cout<<"NO";
}