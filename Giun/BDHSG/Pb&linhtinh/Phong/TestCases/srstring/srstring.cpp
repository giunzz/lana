#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int ok=1;
    while(ok==1)
    {
        ok=0;
        int i=0;
        while(i<s.length()-1 and s.length()>=2)
            if(s[i]==s[i+1])
            {
                ok=1;
                s.erase(i,2);
            } else i++;
    }
    if(s.length()==0) cout<<"Empty String";
    else cout<<s;
    return 0;
}
