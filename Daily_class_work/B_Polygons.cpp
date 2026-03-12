#include <bits/stdc++.h>
using namespace std;

struct Point{
    long long x,y;
};

long long cross(Point a, Point b, Point c)
{
    long long x1=b.x-a.x;
    long long y1=b.y-a.y;
    long long x2=c.x-a.x;
    long long y2=c.y-a.y;
    return x1*y2 - y1*x2;
}

bool insideConvex(vector<Point>& A, Point p)
{
    int n=A.size();

    if(cross(A[0],A[1],p)>=0) return false;
    if(cross(A[0],A[n-1],p)<=0) return false;

    int l=1,r=n-1;

    while(r-l>1)
    {
        int mid=(l+r)/2;

        if(cross(A[0],A[mid],p)<0)
            l=mid;
        else
            r=mid;
    }

    long long c = cross(A[l],A[l+1],p);

    if(c>=0) return false;

    return true;
}

int main()
{
    int n;
    cin>>n;

    vector<Point>A(n);

    for(int i=0;i<n;i++)
        cin>>A[i].x>>A[i].y;

    int m;
    cin>>m;

    vector<Point>B(m);

    for(int i=0;i<m;i++)
        cin>>B[i].x>>B[i].y;

    for(int i=0;i<m;i++)
    {
        if(!insideConvex(A,B[i]))
        {
            cout<<"NO";
            return 0;
        }
    }

    cout<<"YES";
}