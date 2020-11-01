#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define LL long long
using namespace std;
int n,nmax ;
int cm50,cm1,cm2;
int mu3[17] ;
int kq = 0;
int main()
{
     ios::sync_with_stdio(0) ;
     cin.tie(0) ; cout.tie(0) ;
     freopen("ICECREAM.INP","r",stdin);
     freopen("ICECREAM.OUT","w",stdout);

     cin >> n >> nmax;
     cin >> cm50 >> cm1 >> cm2;
     mu3[0] = 1;
     FOR(i,1,15) mu3[i] = mu3[i-1]*3;
     int sl = mu3[n] - 1;
     // 0 : 50 cent
     // 1 : 1 USD
     // 2 : 2 USD
     FOR(mask,0,sl)
     {
         int m50 = cm50 , m1=cm1,m2=cm2;
         bool ok = true;
         for(int i=n-1;i>=0;i--)
            {
              int t = (mask/ mu3[i] )%3;
              //cerr<< t;
              if(t==0 ) {
                    m50++;
                    if(m50 > nmax) {ok = false ; break;}
              }
              if(t==1 ) {
                  if(m50==0) {
                      ok = false; break;
                  }
                  m50--;
                  m1++;
                  if(m1> nmax) {ok = false ; break;}
              }
              if(t==2) {
                  if(m50<3 &&(m1==0||m50 ==0)) { ok= false; break;}
                  if(m1>0 && m50 >0) m1--,m50--;
                  else m50-=3;
                  m2++;
                  if(m2>nmax) {ok = false ; break;}
              }
          }
          if(ok) kq++;
     }
     cout << kq;
}
