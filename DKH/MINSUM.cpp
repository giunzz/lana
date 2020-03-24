#include <bits/stdc++.h>
using namespace std;
//int ma1, ma2, mi1, mi2, m, n;
long long m, n, a[100007], num, mas = 1e12, vt, k; 

/*void enter(int t, int& mi, int& ma){
    int b;
    cin >> b;
    mi = b, ma = b; // mi >= 0, ma < 0
    for (int i = 2; i <= t; i++){
        cin >> b;
        if (b >= 0){
            if (mi < 0) mi = b;
            else mi = min(mi, b);
        }
        if (b < 0){
            if (ma >= 0) ma = b;
            else ma = max(ma, b);
        }
    }
}*/

void enter(){
    for (int i = 1; i <= m; i++) cin >> a[i];
    sort(a + 1, a + 1 + m);
    int i = 1;
    while (a[i] < 0 && i <= m) i++;
    k = --i;
    //cerr << k << endl << endl;
    //for (int i = 1; i <= m; i++) cerr << a[i] << " ";
}

/*void cnp(long long l, long long r){
    //static long long mas;
    long long s, mid = (l + r) / 2;
    s = abs(a[mid] + t);
    if ()
}*/

void find(int i, int j){
    int chot, numn = -num;
    while (true){
        chot = (i + j) / 2;
        //if (num == -7)cerr << i << " " << j << endl;
        if (a[chot] == numn || i == j){
            vt = chot;
            break;   
        }
        if (j - i == 1){
            if (numn > a[j]) vt = j;
            else if (numn < a[i]) vt = i;
            else if(abs(a[i] + num) >= abs(a[j] + num)) vt = j;
            else vt = i;
            //if (num == -1) cerr << i << " " << j;
            break;
        }
        if (numn > a[chot]) i = chot;
        else j = chot;
    }
}

void sol(){
    long long s1, s2;
    if (k != 0 && k != m){
        if (num < 0){
            s1 = abs(num + a[k]);
            find(k + 1, m);
            s2 = abs(num + a[vt]);
            mas = min(mas, min(s1, s2));
        }
        else {
            s1 = abs(a[k + 1] + num);
            find(1, k);
            s2 = abs(num + a[vt]);
            mas = min(mas, min(s1, s2)); 
        }
    }
    else if (k == 0){
        if (num >= 0) mas = min(mas, abs(num + a[1]));
        else{
            find(1, m);
            s1 = abs(num + a[vt]);
            mas = min(mas, s1);
        }
    }
    else{
        if (num < 0) mas = min(mas, abs(num + a[m]));
        else {
            find(1, m);
            s1 = abs(num + a[vt]);
            mas = min(mas, s1);            
        }
    }
    //if (num == -7) cerr << s1 << " " << s2 << " " << k << " " << vt << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("minsum.inp", "r", stdin);
    freopen("minsum.out", "w", stdout);
    cin >> m >> n;
    enter();
    //cerr << k;
    for (int i = 1; i <= n; i++){
        cin >> num;
        //cerr << k;
        sol();
        //cerr << mas << endl;
    }
    cout << mas;
    //cerr << k;
    //enter();
    //cerr << mi1 << " " << ma1 << " " << m << endl;
    //cerr << mi2 << " " << ma2 << " " << n << endl;
    //sol();
    //cout << min(abs(mi1 + mi2), min(abs(mi1 + ma2), min(abs(ma1 + mi2), abs(ma1 + ma2))));
    return 0;
}