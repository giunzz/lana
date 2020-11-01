#include <bits/stdc++.h>
using namespace std;
ifstream fi("GIFTS.inp");
ofstream fo("GIFTS.out");
int64_t n,k;
int64_t a[10006],man=1e18,dd[10006];
multiset<int64_t> s;
multiset<int64_t>::iterator it;
int main()
{
    fi>>n>>k;
    for(int i=1;i<=n;i++) {fi>>a[i];a[i]+=a[i-1];if(i>=k) {s.insert(a[i]-a[i-k]);}}
    for(int i=k;i<=n;i++) {
            int tam=i;while(tam-k>=0&&tam>=i-k)
            {if(!s.empty()&&dd[tam]!=1){s.erase(s.find(a[tam]-a[tam-k]));dd[tam]=1;}tam--;}
    tam=i-k+1;
    while(tam<i&&tam+k<=n)
        {if(!s.empty()&&dd[tam+k]!=1){s.erase(s.find(a[tam+k]-a[tam]));dd[tam+k]=1;}tam++;}
    if(i-k*2>=0) {s.insert(a[i-k]-a[i-k*2]);}
    if(!s.empty()){man=min(*s.rbegin(),man);}
    else man=0;
    }
    fo<<man;
}
