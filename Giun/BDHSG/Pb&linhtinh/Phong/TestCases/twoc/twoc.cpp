#include <bits/stdc++.h>
using namespace std;
int n;
string s;
string del(string s,char c1, char c2)
{    
    for(char c='a';c<='z';c++)
    if(c!=c1 and c!=c2)
    {
        while(s.find(c)!=string::npos) s.erase(s.find(c),1);
    }
    return s;
}
int alternate(string s) 
{
    int ans=0;
    if(s.length()==1) return 0;
    for(char c1='a';c1<'z';c1++)
    for(char c2=c1+1;c2<='z';c2++)
    {
        string tmp=s;
        tmp=del(tmp,c1,c2);
        int ok=0;
        for(int i=0;i<tmp.length()-1 and tmp.length()>=2;i++)
            if(tmp[i]==tmp[i+1]) ok=1;
        if(ok==0) ans=max(ans,int(tmp.length()));
    }
    return ans;
}
int main()
{
    cin>>n;
    cin>>s;
    cout<<alternate(s);
    return 0;
}
