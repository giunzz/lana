#include <bits/stdc++.h>
#define maxn 65
using namespace std;
int a,b,n,k,x[maxn];
string k1="";
string nhan(string s, int i)
{
    string kq="";
    int temp=0;
    for(int j=s.length()-1;j>=0;j--)
    {
        temp=((int)s[j]-48)*i+temp;
        kq.insert(0,1,temp%10+48);
        temp=temp/10;
    }
    while(temp!=0)
    {
        kq.insert(0,1,temp%10+48);
        temp=temp/10;
    }
    if(kq.length()>k1.length()) k1.insert(0,kq.length()-k1.length(),48);
        else kq.insert(0,k1.length()>kq.length(),48);
    string kq2="";
    temp=0;
    for(int j=kq.length()-1;j>=0;j--)
    {
        int a=(int)kq[j]-48;
        int b=(int)k1[j]-48;
        temp=((int)kq[j]-48)+((int)k1[j]-48)+temp;
        kq2.insert(0,1,temp%10+48);
        temp=temp/10;
    }
    while(temp!=0)
    {
        kq2.insert(0,1,temp%10+48);
        temp=temp/10;
    }
    return kq2;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("MODULO.INP","r",stdin);
    freopen("MODULO.OUT","w",stdout);
    cin >> a >> b;
    cin >> n >> k;
    long long p=pow(2,n);
    string s="";
    while(p!=0)
    {
        s.insert(0,1,p%10+48);
        p=p/10;
    }
    while(k!=0)
    {
        k1.insert(0,1,k%10+48);
        k=k/10;
    }
    int i=1;
    while(2>1)
    {
        string s1=nhan(s,i);
        i++;
        if(s1.length()>n)
        {
            cout <<-1;
            return 0;
        }
        if(s1.length()==n)
            {
            bool kt=true;
            for(int j=0;j<s1.length();j++)
                if(s1[j]!=a+48 && s1[i]!=b+48)
                {
                    kt=false;
                    break;
                }
            if(kt==true)
            {
                cout << s1;
                return 0;
            }
        }
    }
}
