#include<bits/stdc++.h>
using namespace std;

int Min(int a[], int n){
    int res =  1e6;
    for(int i = 1; i <= n; ++i){
        res = min(res, a[i]);
    }
    return res;
}

#define point pp(ll, ll)
#define X first
#define Y second

point getvector(point a, point b){
    return {b.X - a.X, b.Y - a.Y};
}

ll area(point a, point b, point c){
    point ba = getvector(b, a), bc = getvector(b, c);
    return ba.X * bc.Y - ba.Y * bc.X;
}

#define point pp(ll, ll)
#define X first
#define Y second

point getvector(point a, point b){
    return {b.X - a.X, b.Y - a.Y};
}

ll area(point a, point b, point c){
    point ba = getvector(b, a), bc = getvector(b, c);
    return ba.X * bc.Y - ba.Y * bc.X;
}

int main(){
<<<<<<< HEAD
    int b[10], m;
    cin >> m;
    for(int i = 1; i <= m; ++i) cin >> b[i];
    cout << Min(b, m);
=======
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
<<<<<<< HEAD
<<<<<<< HEAD
    
>>>>>>> 13a6ce689109a891d46ecbc2404059ebb495755f
=======
    point a = {4, 6}, b = {6, 4}, c = {7, 4};
    cerr << area(a, b, c);
>>>>>>> ec6431b24522386091bc17b0ee3e6e1995030402
=======
    point a = {4, 6}, b = {6, 4}, c = {7, 4};
    cerr << area(a, b, c);
>>>>>>> ec6431b24522386091bc17b0ee3e6e1995030402
}