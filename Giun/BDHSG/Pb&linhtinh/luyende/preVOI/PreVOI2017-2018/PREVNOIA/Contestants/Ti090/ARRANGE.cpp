#include <bits/stdc++.h>

using namespace std;

const int maxN=1e5+11;
const int oo=1e9+11;

int n;
long long a[maxN], b[maxN], s, res;
set<int> st;

int main()
{
    freopen("ARRANGE.INP", "r", stdin);
    freopen("ARRANGE.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        s+=a[i];
    }
    if (s%n==0)
    {
        s/=n;
        for (int i=1; i<=n; i++)
            if (a[i]>s) st.insert(i);
        for (int i=1; i<=n; i++)
            while (a[i]<s)
            {
                int l, r, pos;
                set<int>::iterator it=st.lower_bound(i);
                if (it==st.begin()) pos=*it;
                else pos=*(--it);
                st.erase(pos);
                if (s-a[i]<=a[pos]-s)
                {
                    res+=(s-a[i])*abs(i-pos);
                    a[pos]-=s-a[i];
                    a[i]=s;
                }
                else
                {
                    res+=(a[pos]-s)*abs(i-pos);
                    a[i]+=a[pos]-s;
                    a[pos]=s;
                }
                if (a[pos]>s) st.insert(pos);
            }
        cout<<res;
    }
    else
    {
        for (int i=1; i<=n; i++) b[i]=a[i];
        sort(b+1, b+n+1);
        s=b[n/2+1];
        s--;
        for (int i=1; i<=n; i++)
            if (a[i]>s) st.insert(i);
        for (int i=1; i<=n; i++)
            while (a[i]<s)
            {
                int l, r, pos;
                set<int>::iterator it=st.lower_bound(i);
                if (it==st.begin()) pos=*it;
                else pos=*(--it);
                st.erase(pos);
                if (s-a[i]<=a[pos]-s)
                {
                    res+=(s-a[i])*abs(i-pos);
                    a[pos]-=s-a[i];
                    a[i]=s;
                }
                else
                {
                    res+=(a[pos]-s)*abs(i-pos);
                    a[i]+=a[pos]-s;
                    a[pos]=s;
                }
                if (a[pos]>s) st.insert(pos);
            }
        cout<<res;
    }
    return 0;
}
