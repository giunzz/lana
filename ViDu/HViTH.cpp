#include<bits/stdc++.h>

using namespace std;
int n , k , a[20] , dd [20] ={0};

void print_answer(){
   for (int i = 1; i <= n; i++) cout << a[i] << " ";
   cout << endl;
}

void LK (int vt){
    for (int  i = 1; i <= n; i++){
        if (!dd[i] ){
            a[vt] = i ;
            dd[i] = 1;
            if (vt == n) print_answer(); 
            else LK(vt + 1) ;
            dd[i] = 0;
        }
    }    
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
	cin >> n ;
	LK(1);	
}