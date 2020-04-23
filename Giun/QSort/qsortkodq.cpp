#include <bits/stdc++.h>
using namespace std;
int n, a[(int)1e7];

int partition(int lo, int hi){
    int left_ = lo, right_ = hi - 1, pi = a[hi];

    while(true) 
    {
        while (left_ < hi && a[left_] < pi)
            left_++;
        while (right_ > lo && a[right_] >= pi)
            right_--;
        if (left_ < right_) //>= thi da chuyen het so
            swap(a[left_++],a[right_--]);// left_++, right_--;
        else break;
    }

    swap(a[left_],a[hi]);
    return left_;
}

void qsort(int lo, int hi){
    // Create an auxiliary stack 
    int stack[hi - lo + 1]; 
  
    // initialize top of stack 
    int top = -1; 
  
    // push initial values of l and h to stack 
    stack[++top] = lo; 
    stack[++top] = hi; 
  
    // Keep popping from stack while is not empty 
    while (top >= 0) { 
        // Pop h and l 
        hi = stack[top--]; 
        lo = stack[top--]; 
  
        // Set pivot element at its correct position 
        // in sorted array 
        int p = partition(lo, hi); 
  
        // If there are elements on left side of pivot, 
        // then push left side to stack 
        if (p - 1 > lo) { 
            stack[++top] = lo; 
            stack[++top] = p - 1; 
        } 
  
        // If there are elements on right side of pivot, 
        // then push right side to stack 
        if (p + 1 < hi) { 
            stack[++top] = p + 1; 
            stack[++top] = hi; 
        } 
    } 
} 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("DATA.INP", "r", stdin);
    freopen("DATA.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    qsort(1, n);
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
}