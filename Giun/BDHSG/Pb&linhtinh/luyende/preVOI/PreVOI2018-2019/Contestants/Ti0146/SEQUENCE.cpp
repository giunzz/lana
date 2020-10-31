#include <bits/stdc++.h>
using namespace std;
int m,n,k;
int a[3003],b[3003];
string c;
string xau(int t)
{
    string s;
    while(t!=0)
    {
        s=char(t%10+'0')+s;
        t/=10;
    }
    return s;
}

int main()
{
    ifstream cin("SEQUENCE.inp");
    ofstream cout("SEQUENCE.out");
    cin>>m>>n>>k;
    for(int i(1); i<=m; ++i)
    {
        cin>>a[i];
    }
    for(int j(1); j<=n; ++j)
        cin>>b[j];
    int gh=m+n-k;
    for(int i(1),j(1),xoa(0);;)
    {

        string A=xau(a[i]),B=xau(a[i+1]),C=xau(b[j]),D=xau(b[j+1]);
        if(A<=B&&A<=D&&A==C&&D>B)
        {
            c=c+A+" ";
            ++i;
        }
        else if(C==A&&C<=B&&C<=D&&D<B)
        {
            c=c+C+" ";
            ++j;
        }
        else if(A<=B&&A<=D&&A<=C)
        {
            c=c+A+" ";
            ++i;
        }
        else if(C<=A&&C<=B&&C<=D)
        {
            c=c+C+" ";
            ++j;
        }
        else
        {
            if(xoa==gh)
            {
                while(i<=m||j<=n)
                {
                    string A=xau(a[i]),B=xau(a[i+1]),C=xau(b[j]),D=xau(b[j+1]);
                    if(j>n)
                    {
                        c=c+A+" ";
                        ++i;
                    }
                    else if(i>m)
                    {
                        c=c+C+" ";
                        ++j;
                    }
                    else if(A==C&&D>B)
                    {
                        c=c+A+" ";
                        ++i;
                    }
                    else if(A==C)
                    {
                        c=c+C+" ";
                        ++j;
                    }
                    else if(A>C)
                    {
                        c=c+A+" ";
                        ++i;
                    }
                    else
                    {
                        c=c+C+" ";
                        ++j;
                    }
                }
                break;
                }
                xoa++;
                if(B>D)++j;
                if(D>B)++i;
                if(B==D&&A>C)++j;
                if(B==D&&A<C)++i;
        }
    }
    cout<<c;
}
