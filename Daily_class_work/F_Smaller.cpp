#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int q;
        cin>>q;

        long long sa=1, ta=1;
        bool sOther=false, tOther=false;

        while(q--)
        {
            int d,k;
            string x;
            cin>>d>>k>>x;

            bool hasOther=false;
            long long countA=0;

            for(char c:x)
            {
                if(c=='a') countA++;
                else hasOther=true;
            }

            if(d==1)
            {
                sa += countA * k;
                if(hasOther) sOther=true;
            }
            else
            {
                ta += countA * k;
                if(hasOther) tOther=true;
            }

            if(tOther)
                cout<<"YES\n";
            else if(sOther)
                cout<<"NO\n";
            else if(sa < ta)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
}