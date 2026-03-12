#include <bits/stdc++.h>
using namespace std;

long long gcdll(long long a,long long b){
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}

int main()
{
    int n,k;
    cin>>n>>k;

    vector<long long> x(n);
    for(int i=0;i<n;i++)
        cin>>x[i];

    for(int i=0;i<n;i++)
    {
        vector<long long> group;
        group.push_back(x[i]);

        for(int j=0;j<n;j++)
        {
            if(i==j) continue;

            if(gcdll(x[i],x[j])>1)
                group.push_back(x[j]);

            if(group.size()==k)
            {
                for(auto v:group)
                    cout<<v<<" ";
                return 0;
            }
        }
    }

    cout<<0;
}