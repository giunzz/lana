#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define LL long long
using namespace std;
//-----------------------------------------
const int N = 3005 ;
typedef pair<int,int> ii;
int m,n,k;
int a[N],b[N] ;
vector<int> Ga[N] , Gb[N] ;
int tmp[2*N],tmp1[2*N] ;
string ans;
// x phan tu day a ; k-x phan tu day b
void adda(int x){
     vector<int> ok;
     FOR(i,1,m) tmp[i] = 0;
     tmp[0] = -1; tmp[m+1] = -1;
     if(x>m) return;
     int sz = 0;
     FOR(i,1,3000) if(Ga[i].size()>0){
         for(auto x:Ga[i]) if(sz<x){
            sz++;
            tmp[x] = i ;

         }
         break;
     }
     FOR(i,0,m) if(tmp[i]!=0) ok.push_back(i);
     //for(auto x:ok) cerr<< x<<" ";cerr<<'\n';
     for(int i=(int) ok.size()-1;i>=1;i--){
         int R = ok[i];
         int L = ok[i-1] ;
         R--;L++;
         priority_queue<ii,vector<ii>, greater_equal<ii> > Heap;
         FOR(i,L,R) Heap.push({a[i],i}) ;
         while(!Heap.empty() && sz<x){
             ii o = Heap.top();Heap.pop();
          //   cerr<< o.second<<" ";
             tmp[o.second] = o.first;
             sz++;
         }
     }
    // FOR(i,1,m) if(tmp[i]>0) cerr<< tmp[i]<<" ";cerr<<'\n';
}
void addb(int x){

     vector<int> ok;
     FOR(i,1,n) tmp1[i] = 0;
     tmp1[0] = -1; tmp1[n+1] = -1;
     if(x>n) return;
     int sz = 0;
     FOR(i,1,3000) if(Gb[i].size()>0){
         for(auto x:Gb[i]) if(sz<x){
            sz++;
            tmp1[x] = i ;

         }
         break;
     }
     FOR(i,0,n) if(tmp1[i]!=0) ok.push_back(i);
     for(int i=(int) ok.size()-1;i>=1;i--){
         int R = ok[i];
         int L = ok[i-1] ;
         R--;L++;
         priority_queue<ii,vector<ii>, greater_equal<ii> > Heap;
         FOR(i,L,R) Heap.push({b[i],i}) ;
         while(!Heap.empty() && sz<x){
             ii o = Heap.top();Heap.pop();
          //   cerr<< o.second<<" ";
             tmp1[o.second] = o.first;
             sz++;
         }
     }
    // FOR(i,1,n) if(tmp1[i]>0) cerr<< tmp1[i]<<" ";cerr<<'\n';
}
string chuyen(int x)
{
    string kq="";
    while(x>0)
    {
        kq = char(x%10+48)+kq;
        x/=10;
    }
    return kq;
}
void Tron()
{
      vector<int> kq;
      vector<int> A,B;
    //  if(A.size()+B.size()!=k) return ;
      FOR(i,1,m) if(tmp[i]!=0) A.push_back(tmp[i]); A.push_back(1e9);
      FOR(i,1,n) if(tmp1[i]!=0) B.push_back(tmp1[i]); B.push_back(1e9);
    if(A.size()+B.size()!=k+2) return ;

      int La=0,Lb=0;
      while(La<A.size()&& Lb<B.size()){
          while( A[La]<B[Lb] ) kq.push_back(A[La]),La++;
          while( A[La]>B[Lb] ) kq.push_back(B[Lb]),Lb++;
          int ok = 0;
          if(A[La]==B[Lb])
          {
              int ta = La,tb = Lb;
              int pa,pb;
              FOR(t,0,3000)  {
                  if(La+t>A.size()||Lb+t>B.size()) break;
                  if( A[La+t] < B[Lb+t] ) ok = 1 , pa = La+t;
                  if( A[La+t] > B[Lb+t] ) ok = 2,pb = Lb+t;
                  if(ok!=0) break;
              }
              FOR(i,La,pa) kq.push_back(A[i]);
              FOR(i,Lb,pb) kq.push_back(B[i]);
              La = pa+1;Lb = pb+1;
          }
      }
     kq.pop_back();
     kq.pop_back();
      string tmp = "";
      for(auto x:kq) tmp = tmp+ chuyen(x) +" ";
      if(tmp<ans) ans = tmp;
     // for(auto x:kq) cerr<< x<<" ";cerr<<'\n';
}
int main()
{
     ios::sync_with_stdio(0) ;
     cin.tie(0) ; cout.tie(0) ;
     freopen("SEQUENCE.INP","r",stdin);
     freopen("SEQUENCE.OUT","w",stdout);
     cin >> m >> n >> k;
     FOR(i,1,m)  {
         cin >> a[i];
         Ga[a[i]].push_back(i);
     }
     FOR(i,1,n)  {
         cin >> b[i] ;
         Gb[b[i]].push_back(i);
     }

     FOR(i,1,k) ans = ans+ chuyen(9999) +" ";
     FOR(i,0,k){
         adda(i) ;
         addb(k-i) ;
         Tron();
     }
     cout << ans;

}
