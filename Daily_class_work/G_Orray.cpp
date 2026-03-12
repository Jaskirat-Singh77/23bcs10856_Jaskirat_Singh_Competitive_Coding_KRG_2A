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

        vector<long long>a(n);
        for(int i=0;i<n;i++) cin>>a[i];

        vector<int>used(n,0);
        vector<long long>ans;

        long long cur=0;

        for(int step=0;step<n;step++)
        {
            long long best=cur;
            int idx=-1;

            for(int i=0;i<n;i++)
            {
                if(!used[i])
                {
                    if((cur | a[i]) > best)
                    {
                        best = cur | a[i];
                        idx = i;
                    }
                }
            }

            if(idx==-1) break;

            used[idx]=1;
            ans.push_back(a[idx]);
            cur |= a[idx];
        }

        for(int i=0;i<n;i++)
        {
            if(!used[i]) ans.push_back(a[i]);
        }

        for(auto x:ans) cout<<x<<" ";
        cout<<"\n";
    }
}