#include<bits/stdc++.h>

using namespace std;

int t ,n , m , vis[2510][2510];
vector<int> v;

/*int gcd(int n , int m)
{
    while(n||m)
    {
        if(n > m) n%=m;
        else m %= n;
    }
    return n + m;
}*/

inline void fact(int &x)
{
    int c = x;
    int newV = 1;
    for(int i = 2 ; i<= (int) sqrt(x) ; i++)
        if(c%i == 0)
    {
        int cnt = 0;
        while(c %i == 0) c/=i , cnt++;
        cnt%=2;
        if(cnt) v.push_back(i) , newV *= i;
    }

    if(c>1)
    {
        v.push_back(c);
        newV*=c;
    }


    x = newV;
}

inline void sub1()
{
    memset(vis , 0 , sizeof(vis));
    queue<pair<int , int> > q;
    q.push(make_pair(n , m));
    int ans = n + m , p1 = n, p2 =m;
    while(!q.empty())
    {
        int x = q.front().first , y = q.front().second;q.pop();
        //ans = min(ans , x+y);
        if(ans > x+y)
        {
            ans = x + y;
            p1= x;
            p2 = y;
        }
        for(int i = 2 ; i<=sqrt(x) ; i++)
            if(x % i == 0)
            {
                if(!vis[x/i][y*i])
                {
                    vis[x/i][y*i] = 1;
                    q.push(make_pair(x/i , y*i));
                }
                if(!vis[i][y*(x/i)])
                {
                    vis[i][y*(x/i)] = 1;
                    q.push(make_pair(i , y*(x/i)));
                }
                if(y%i == 0 && !vis[x/i][y/i])
                {
                    vis[x/i][y/i] = 1;
                    q.push(make_pair(x/i , y/i));
                }
                if(y%(x/i) == 0 && !vis[i][y/(x/i)])
                {
                    vis[i][y/(x/i)] = 1;
                    q.push(make_pair(i , y/(x/i)));
                }
            }
        if(!vis[y][x])
        {
            vis[y][x] = 1;
            q.push(make_pair(y  ,x));
        }
    }
    printf("%d %d\n",p1 , p2);
}

int main()
{
    freopen("MINSUM.inp" , "r" , stdin);
    freopen("MINSUM.out" , "w" , stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        int d = __gcd(n , m);
        n /= d;
        m /= d;
        v.clear();
        fact(n);
        fact(m);
        sort(v.begin() , v.end());
        long long ans = n+ m;
        long long n1 = n , m1 = m;
        for(int tus = 0 ; tus < (1<<(v.size())) ; tus++)
        {
            long long v1 =1, v2=1;
            for(int i = 0  ;i<v.size() ; i++)
                if(((tus>>i)&1)) v1*=v[i];
                else v2 *= v[i];
            if(ans > v1 + v2)
            {
                ans = v1+v2;
                n1 = v1;
                m1 = v2;
            }
        }
        printf("%lld %lld\n",n1 , m1);
    }
    return 0;
}
