#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<pair<long long,long long>> events;

    for(int i=0;i<n;i++)
    {
        long long l,r;
        cin>>l>>r;

        events.push_back({l,1});
        events.push_back({r+1,-1});
    }

    sort(events.begin(),events.end());

    vector<long long>cnt(n+1,0);

    long long cur=0;
    long long prev=events[0].first;

    for(auto e:events)
    {
        long long pos=e.first;

        if(pos>prev)
        {
            cnt[cur]+=pos-prev;
            prev=pos;
        }

        cur+=e.second;
    }

    for(int i=1;i<=n;i++)
        cout<<cnt[i]<<" ";
}