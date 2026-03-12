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
        for(int i=0;i<n;i++) cin>>a[i];

        vector<int>freq(n+1,0);
        for(int x:a) freq[x]++;

        vector<int>good(n+1,0);

        for(int l=0;l<n;l++)
        {
            int sum=a[l];

            for(int r=l+1;r<n;r++)
            {
                sum+=a[r];

                if(sum>n) break;

                good[sum]=1;
            }
        }

        int ans=0;

        for(int i=1;i<=n;i++)
        {
            if(good[i]) ans+=freq[i];
        }

        cout<<ans<<"\n";
    }
}