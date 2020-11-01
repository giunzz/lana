#include <bits/stdc++.h>
#define pb push_back
#define ii pair<int,int>
#define x first
#define y second

using namespace std;

const int N=1e5+2;
const int MOD=1e9+7;
const int bm=1;
int n,m,so;
int a[N];
long long kq,dem;

int main()
{
    ios_base::sync_with_stdio(0);
    //sinh();
    freopen("ARRANGE.inp","r",stdin);
    freopen("ARRANGE.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],dem+=a[i];
    so=dem%n,dem/=n;
    for(int i=1;i<=n;i++) a[i]-=(a[i]>dem&&so>0),so--;
    int j=1;
    for(int i=1;i<=n;i++)
        if ( a[i] > dem )
        {
            while( a[i] - dem >= dem - a[j] && j < i )
                a[i]-=dem-a[j],kq+=1ll*(dem-a[j])*(i-j),j++;
            if ( j == i ) kq+=a[i]-dem,a[i+1]+=a[i]-dem,j++;
            else if ( a[i] - dem < dem - a[j] )
                kq+=1ll*(a[i]-dem)*(i-j),a[i]=dem;
        }
    cout<<kq;
}
