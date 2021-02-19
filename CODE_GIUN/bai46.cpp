#include<bits/stdc++.h>

using namespace std;

int main(){
    string chi [12] , can[10] , st;
    int  n , ti = -1 ,ta = -1 , ans = 0 , c , t = 0 ,t1 = 0;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("bai46.inp","r",stdin);
   // freopen("bai46.out","w",stdout);

    cin >> n;
    cin >> st; 
    
    chi[0] = "THAN" ; chi[1] = "DAU"; chi[2] ="TUAT"; chi[3]  = "HOI"; chi[4] ="TI"  ; chi[5] ="SUU"; chi[6] ="DAN" ; chi[7] ="MAO" ; chi[8] ="THIN"; chi[9] ="TY" ; chi[10] ="NGO"; chi[11] ="MUI" ;
    can[0] = "CANH" ; can[1] = "TAN"; can[2] ="NHAM"; can[3]  = "QUY"; can[4] ="GIAP"; can[5] ="AT" ; can[6] ="BINH"; can[7] ="DINH"; can[8] ="MAU" ; can[9] = "KY";
    
    
    for (int  i = 0 ; i <= 11 ; i++ ){
            if (st == chi[i] ) {
                ti = n % 12 ;
                c = i;  
                break; 
            }
            else if (st == can[i] ){ 
                c = i ;
                ta = n % 10; 
                break; 
            }
    }
    
    if (ti != -1) {
        t  =  n - abs( c - ti )  ;
        t1 =  n + abs( c - ti )  ;
        if ( ( t % 12 == c ) && (  t  < t1   ) ) ans =  t;
        else ans = t1 ;
    }
    if (ta != -1 ) {
        t  =  n - abs( c - ta )  ;
        t1 =  n + abs( c - ta )  ;
        if ( ( t % 10 == c ) && ( t  < t1   ) ) ans =  t;
        else ans = t1 ;
  }
    
    cout << ans;
    return 0;
}
