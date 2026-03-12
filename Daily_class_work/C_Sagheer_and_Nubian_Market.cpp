#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long S;
    cin>>n>>S;

    vector<long long>a(n+1);

    for(int i=1;i<=n;i++)
        cin>>a[i];

    int l=0,r=n;
    long long bestCost=0;
    int bestK=0;

    while(l<=r)
    {
        int k=(l+r)/2;

        vector<long long>cost(n);

        for(int i=1;i<=n;i++)
            cost[i-1]=a[i]+1LL*i*k;

        sort(cost.begin(),cost.end());

        long long sum=0;

        for(int i=0;i<k;i++)
            sum+=cost[i];

        if(sum<=S)
        {
            bestK=k;
            bestCost=sum;
            l=k+1;
        }
        else
            r=k-1;
    }

    cout<<bestK<<" "<<bestCost;
}