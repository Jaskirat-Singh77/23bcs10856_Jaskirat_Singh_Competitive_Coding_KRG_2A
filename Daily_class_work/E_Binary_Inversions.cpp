#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<int>a(n);

        for(int i=0;i<n;i++)
            cin>>a[i];

        vector<int>zeros_after(n,0);

        int zeros=0;
        for(int i=n-1;i>=0;i--)
        {
            zeros_after[i]=zeros;
            if(a[i]==0) zeros++;
        }

        long long inv=0;
        long long ones=0;

        for(int i=0;i<n;i++)
        {
            if(a[i]==1) ones++;
            else inv+=ones;
        }

        long long best=0;
        ones=0;

        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
            {
                long long gain = zeros_after[i] - ones;
                best=max(best,gain);
            }
            else
            {
                long long gain = ones - zeros_after[i];
                best=max(best,gain);
                ones++;
                continue;
            }

            if(a[i]==1) ones++;
        }

        cout<<inv+best<<"\n";
    }
}