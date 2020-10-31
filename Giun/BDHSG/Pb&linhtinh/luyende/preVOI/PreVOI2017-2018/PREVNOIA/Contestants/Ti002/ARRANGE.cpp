#include <bits/stdc++.h>
#define forr(i, a, b) for(long i= a; i<= b; i++)
#define mn 100001
using namespace std;
long n, a[mn], tbd, tbt, maxx= 0, minn= 1e9+ 7;
long long S, res= 0;
bool check(long mid)
{
    vector< long> vtri;
    long ans= 0, f[mn];
    memset(f, 0, sizeof(f));
    /*forr(i, 1, n){
        if(a[i]<= tbd) ans+= (tbd- a[i]);
        else _ans+= (a[i]- tbt);
    }
    if(ans<= mid&& _ans<= mid&& _ans>= ans) return true;
    return false;*/
    forr(i, 1, n)
    {
        if(a[i]<= tbd) f[i]= a[i]- tbd;
        else{
            f[i]= a[i]- tbt;
            vtri.push_back(i);
        }
    }
    for(int i= 0; i< vtri.size(); i++)
    {
        long id= vtri[i], trai= id- 1, phai= id+ 1;
        //while(f[id]>= 0){
            while(trai>= 1){
                f[id]+= f[trai];
                if(f[trai]< 0&& f[id]>= 0){
                    long dd= f[trai];
                    f[trai]= min((long) 0, f[trai]+ f[id]);
                    f[id]= max((long) 0, dd+ f[id]);
                    ans+= f[trai];
                    //trai--;
                }
                trai--;
            }
            while(phai<= n){
                f[id]+= f[phai];
                if(f[phai]< 0&& f[id]>= 0){
                    long dd= f[phai];
                    f[phai]= min((long) 0, f[phai]+ f[id]);
                    f[id]= max((long) 0, dd+ f[id]);
                    ans+= f[phai];
                    //++phai;
                }
                phai++;
            }
    }
    forr(i, 1, n){
      if(f[i]< 0) return false;
      if(f[i]>= 1) ans+= (f[i]- 1)*(f[i]- 2)/ 2;
    }
    return ans<= mid;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("arrange.inp", "r", stdin);
    freopen("arrange.out", "w", stdout);
    cin>> n;
    forr(i, 1, n){
        cin>> a[i], S+= a[i];
        maxx= max(maxx, a[i]);
        minn= min(minn, a[i]);
    }
    if(S% n== 0){
        long long tb= S/ n;
        forr(i, 1, n) res+= abs(a[i]- tb);
        cout<< res/ 2;
        return 0;
    }
    tbd= S/ n, tbt= tbd+ 1;
    long Const= max(tbt- minn, maxx- tbd);
    long l= 0, r= (n* Const)/ 2;
    //check(8);
    while(r- l> 1){
        long mid= (l+ r)/ 2;
        if(check(mid)) r= mid;
        else l= mid;
    }
    cout<< r;
    return 0;
}
