#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+10;
int n , a[MAXN];
set<pair<int , int> > s;
long long ans=  0 , sum[MAXN];
long long dp[2010][2010] , minv[2010][2010] , le , ri;

inline void refine(int type)
{
    vector<int> v1 , v2;
    v1.push_back(0);
    v2.push_back(0);
    memset(dp , 0x3f , sizeof(dp));
    memset(minv , 0x3f , sizeof(minv));
    for(int i = 1 ; i<=n ; i++)
    {
        if(type == 1)
        {
            if(a[i] == le) v1.push_back(i);
            if(a[i] > ri) v2.push_back(i);
        }
        if(type == 2)
        {
            if(a[i] == ri) v1.push_back(i);
            if(a[i] < le) v2.push_back(i);
        }
    }

    for(int i = 1 ; i<v1.size() ; i++)
        sum[i] = sum[i-1] + v1[i];

    for(int i = 0 ; i<=v1.size() ;i++)
        minv[0][i] = dp[0][i] = 0 ;

    for(int i  =1 ; i < v2.size() ; i++)
    {
        int x ;
        if(type == 1) x = a[v2[i]] - ri;
        else x = le - a[v2[i]];
        for(int j = x ; j < v1.size() ; j++)
        {
            int l = j - x + 1 , r = j;
            int left = l , right = r;
            //cerr<<minv[i-1][left-1]<<" "<<i-1<<" "<<left-1<<endl;
            if(minv[i-1][left-1] > 1e18) continue;
            while(l < r)
            {
                int mid = (l + r)/2;
                if(v1[mid] >= v2[i]) r = mid;
                else l = mid+1;
            }
            if(v1[l] < v2[i]) l = right+1;
            long long cost = ((long long)v2[i] * (long long)(l-left)) - (sum[l-1] - sum[left-1]);
            cost += (sum[right] - sum[l-1]) - (long long) v2[i] * (long long) (right - l + 1);
            dp[i][j] = minv[i-1][left-1] + cost;
        }
        for(int j  =1 ; j<v1.size() ; j++)
            minv[i][j] = min(minv[i][j-1] , dp[i][j]);
    }
    long long res = 1e18;
    for(int i = 1 ; i < v1.size() ; i++)
        res = min(res , dp[v2.size()-1][i]);
    ans += res;
}

int main()
{
    freopen("ARRANGE.inp" , "r" , stdin);
    freopen("ARRANGE.out" , "w" , stdout);
    scanf("%d",&n);
    long long sum = 0;
    for(int i = 1 ; i<=n ; i++)
    {
        scanf("%d",&a[i]);
        sum += a[i];
    }

    le = sum/n;
    ri = (sum +n - 1)/n;

    for(int i = 1 ; i<=n ; i++)
        if(a[i] > ri) s.insert(make_pair(i , a[i]));

    int ok  =1;
    for(int i = 1 ; i<=n ; i++)
        while(a[i] <le)
        {
            if(s.size() == 0)
            {
                ok = 0;
                break;
            }
            int pos = s.begin()->first  , val = s.begin()->second;
            long long x = min(le - a[i] , val - le);
            a[i] += x;
            //cerr<<x<<endl;
            a[pos] -= x;
            ans += x*(long long)abs(pos - i);
            s.erase(s.begin());
            if(a[pos] > ri) s.insert(make_pair(pos , a[pos]));
            //cerr<<i<<" "<<a[i]<<endl;
        }

    if(s.size() > 0 && n <= 2000) refine(1);
    if(ok == 0) refine(2);

    printf("%lld",ans);

    return 0;
}
