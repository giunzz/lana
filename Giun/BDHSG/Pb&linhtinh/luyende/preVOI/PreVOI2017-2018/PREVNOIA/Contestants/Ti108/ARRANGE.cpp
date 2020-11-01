#include <bits/stdc++.h>
#define maxn 100000
using namespace std;
int n,vtmax,vtmin,c;
int ma=-1e9,mi=1e9, ans=0;
long long sum=0LL;
int a[maxn];

void xetl(int x){
    int l,r;
    l=r=x;
    for(int i=x-1;i>0;i--){
        if(a[i]<c){
            l=i;
            break;
        }
    }
    for(int i=x+1;i<=n;i++){
        if(a[i]<c){
            r=i;
            break;
        }
    }
    if(x-l<=r-x){
        if(l!=x){
            int q;
            q= min(a[x]-c,c-a[l]);
            ans+=q*(x-l);
            a[x]-=q;
            a[l]+=q;
        }
        else if(r!=x){
            int q;
            q= min(a[x]-c,c-a[r]);
            ans+=q*(r-x);
            a[x]-=q;
            a[r]+=q;
        }
    }
    else{
        if(r!= x){
            int q;
            q= min(a[x]-c,c-a[r]);
            ans+=q*(r-x);
            a[x]-=q;
            a[r]+=q;
        }
        else if(l!=x){
            int q;
            q= min(a[x]-c,c-a[l]);
            ans+=q*(x-l);
            a[x]-=q;
            a[l]+=q;
        }
    }
}
void xetn(int x){
    int l,r;
    l=r=x;
    for(int i=x-1;i>0;i--){
        if(a[i]>c){
            l=i;
            break;
        }
    }
    for(int i=x+1;i<=n;i++){
        if(a[i]>c){
            r=i;
            break;
        }
    }
    if(x-l<=r-x){
        if(l!=x){
            int q;
            q= min(c-a[x],a[l]-c);
            ans+=q*(x-l);
            a[x]+=q;
            a[l]-=q;
        }
        else if(r!=x){
            int q;
            q= min(a[r]-c,c-a[x]);
            ans+=q*(r-x);
            a[x]+=q;
            a[r]-=q;
        }
    }
    else{
        if(r!=x){
            int q;
            q= min(a[r]-c,c-a[x]);
            ans+=q*(r-x);
            a[x]+=q;
            a[r]-=q;
        }
        else{
            if(l!= x){
                int q;
                q= min(c-a[x],a[l]-c);
                ans+=q*(x-l);
                a[x]+=q;
                a[l]-=q;
            }
        }
    }
}
int main()
{
    freopen("ARRANGE.INP","r",stdin);
    freopen("ARRANGE.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+= a[i];
    }
    c = sum/n;
    for(int i=1;i<=n;i++){
        if(a[i] != c){
            if(a[i]>c){xetl(i);}
            else xetn(i);
        }
    }
    cout<<ans;
    return 0;
}
