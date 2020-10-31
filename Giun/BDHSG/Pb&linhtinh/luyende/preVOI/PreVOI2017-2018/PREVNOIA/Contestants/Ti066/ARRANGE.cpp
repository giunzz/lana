#include <bits/stdc++.h>
#define Pii pair<int,int>
#define fi first
#define se second
#define MAXN 100005

using namespace std;

int n,a[MAXN];
long long s=0,mid,mid1,t=0;
//Pii b[MAXN];

int main()
{
    ifstream cin("ARRANGE.inp");
    ofstream cout("ARRANGE.out");
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        //b[i]=Pii(a[i],i);
        s+=a[i];
    }
    if(s%n==0){
        mid=s/n;
        for(int i=1; i<=n; i++){
            if(a[i]<mid) a[i+1]-=mid-a[i], t+=mid-a[i], a[i]=mid;
            if(a[i]>mid) a[i+1]+=a[i]-mid, t+=a[i]-mid, a[i]=mid;
        }
        cout << t;
    }
    else if(n>2000){
        cout << 0;
        return 0;
    }
    else{
        mid=s/n, mid1=mid+1;
        for(int i=1; i<=n; i++){
            if(a[i]<mid){
                int l=i-1,r=i+1;
                while(l>=1 && a[l]<=mid) l--;

                while(r<=n && a[r]<=mid) r++;
                if(l<=0){
                    a[r]-=mid-a[i];
                    t+=(mid-a[i])*abs(r-i);
                    a[i]=mid;
                }
                else if(r>n){
                    a[l]-=mid-a[i];
                    t+=(mid-a[i])*abs(l-i);
                    a[i]=mid;
                }
                else if(abs(l-i)<abs(r-i)){
                    a[l]-=mid-a[i];
                    t+=(mid-a[i])*abs(l-i);
                    a[i]=mid;
                }
                else{
                    a[r]-=mid-a[i];
                    t+=(mid-a[i])*abs(r-i);
                    a[i]=mid;
                }
            }
        }
        for(int i=1; i<=n; i++){
            if(a[i]>mid1){
                int l=i-1,r=i+1;
                while(a[i]>mid1){
                    while(l>=1 && a[l]>=mid1) l--;

                    while(r<=n && a[r]>=mid1) r++;

                    if(l>=1){
                        a[l]++;
                        a[i]--;
                        t+=abs(l-i);
                    }
                    if(a[i]==mid1) break;
                    if(r<=n){
                        a[r]++;
                        a[i]--;
                        t+=abs(r-i);
                    }
                }
            }
        }
        cout << t;
    }
    return 0;
}
