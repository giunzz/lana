#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
int n, a[maxn], madi, tma, tmi, v1, v2, vmin, vmax;

sol(int l, int r, int& maxdi, int& ma, int& mi, int& va, int& vi, int& vad, int& vid){ //chinh sang chi so
    int mid, mad1, mav1, miv1, mad2, mav2, miv2, va1, vi1, va2, vi2, vad1, vid1, vad2, vid2;
    if (l == r) maxdi = 0, ma = a[r], mi = a[r], va = r, vi = r, vad = r, vid = r;
    else {
        mid = (l + r) / 2;
        sol(l, mid, mad1, mav1, miv1, va1, vi1, vad1, vid1);
        //vt[1] = vi1, vt[2] = va1;
        sol(mid + 1, r, mad2, mav2, miv2, va2, vi2, vad2, vid2);
        //vt[3] = vi2, vt[4] = va2;
        maxdi = mav2 - miv1, vad = va2, vid = vi1; //ma = mav2, mi = miv1;
        //vmin = vi1, vmax = va2, best = va1;
        if (maxdi < mad1) maxdi = mad1, vad = vad1, vid = vid1;//, ma = mav1, mi = miv1;
        if (maxdi < mad2) maxdi = mad2, vad = vad2, vid = vid2;//, ma = mav2, mi = miv2;
        if (mav1 > mav2) ma = mav1, va = va1;
        else ma = mav2, va = va2;
        if (miv1 < miv2) mi = miv1, vi = vi1;
        else mi = miv2, vi = vi2;
        //cerr << mad1 << " " << miv1 << " " << mav1 << " " << mad2 << " " << miv2 << " " << mav2 << endl;
        //cerr << mid << "   " << maxdi << " " << mi << " " << ma << endl;
    }
}

void enter(){
	cin >> n;
	char c;
	for (int i = 1; i <= n; i++){
		cin >> c >> a[i];
		if (c == 'L') a[i] = a[i - 1] - a[i];
		else a[i] += a[i - 1];
	}
	//for (int i = 1; i <= n; i++) cerr << a[i] << " ";
	//cerr << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("game.inp", "r", stdin);
	freopen("game.out", "w", stdout);
	enter();
    sol(0, n, madi, tma, tmi, v1, v2, vmax, vmin);
	//if (madi == 0) cout << a[best] - a[best - 1] << endl << best << " " << best;
	cout << madi << "\n" << vmin + 1 << " " << vmax;
	//cerr << clock() << " ms";	
	return 0;
}