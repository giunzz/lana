// long long %I64d


/*#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define err(variable) cerr << variable << " "
#define errl(variable) cerr << variable << "\n"
#define loop(variable, valuegan, valuebehonbang) for(long long variable = valuegan; variable <= valuebehonbang; variable++)
#define loopd(variable, valuegan, valuelonhonbang) for(long long variable = valuegan; variable >= valuelonhonbang; variable--)
#define loopdk(variable, valuegan, conditions, thaydoi) for(long long variable = valuegan; conditions; thaydoi) 
#define pp(type) pair<type, type>
#define vec(type) vector<type>
#define vecite(type) vector<type>::iterator
using namespace std;
const string tenfile = "SOLO";
#define fi freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

int t, n, num, k, q;

void fastscan(int &number) 
{ 
    bool negative = false; 
    register int c; 
  
    number = 0; 
    c = getchar(); 
    if (c == ' ') fastscan(number);
    if (c=='-') 
    { 
        negative = true; 
        c = getchar(); 
    } 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
    if (negative) 
        number *= -1; 
} 

int main(){
    //opt;
    fi;
    fastscan(t);
    int ans;
    for (int i = 1; i <= t; i++){
        fastscan(n); 
        fastscan(k);
        fastscan(q);
        if (!q){
            ans = -1;
            loop(j, 1, n){
                fastscan(num);
                ans = max(ans, num);
            }
        }
        else{
            ans = INT_MAX;
            loop(j, 1, n){
                fastscan(num);
                ans = min(ans, num);
            }
        }
        printf("%d\n", ans);
    }
}*/
#include<bits/stdc++.h>

using namespace std;dhdhdh
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

int main()
{
    balabalo;
	int b,i;
	float salary,heso;
	//printf("please enter seniority work: ");
	scanf("%d ",&b);
	i = 650000;
	if(b<12){
		heso=1,92;}
	else if(b>=12 && b<36 ){
		heso=2,34;
		}
	else if(b>=36 && b<60){
		heso=3;
		}
	else{
		heso=4,5;
		}
		salary=heso*i;
	printf("salary = %f",salary);
return 0;
}