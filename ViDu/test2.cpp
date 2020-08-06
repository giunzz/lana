#include<bits/stdc++.h>
using namespace std;
vector<string> a1;
vector<string> findDifferent(string s1, string s2)
{
    vector<string> ans;
    string t1="",t2 ="",t="";
    int d1[300]={0},d2[300]={0};
    for (int i = 0 ; i < (int)s1.length() ; i++) d1[s1[i]-'0'] = 1;
    for (int i = 0 ; i < (int)s2.length() ; i++) d2[s2[i]-'0'] = 1;
    for (int i = 0 ; i < (int)s2.length() ; i++)
    {
        if (d1[s2[i]-'0'] == 0 ) t2+=s2[i];  
    }
    for (int i = 0 ; i < (int)s1.length() ; i++)
    {
        if (d2[s1[i]-'0'] == 0 ) t1+= s1[i];
    }
    sort(t1.begin() , t1.end());
    sort(t2.begin() , t2.end());
    t = t1+t2;
    if (t.length() == 0 )  ans.push_back("-1");
    else 
    {
        if (t1.length() != 0 ) ans.push_back(t1); 
        if (t2.length() != 0 ) ans.push_back(t2);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("giun.inp","r",stdin);freopen("giun.out","w",stdout);
	string a,b;
    cin >> a >> b;
    a1 = findDifferent(a,b);
    for (int i = 0 ; i < (int) a1.size() ; i++) cout << a1[i];
}