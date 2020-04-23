#include <iostream>
#include <stdio.h>
#include <string>
#include <ctime>
using namespace std;
int stack[(int)1e7 + 7], top = -1;
char s;

/*bool IsFull(int capacity){
    if(top >= capacity - 1){
        return true;
    }else{
        return false;
    }
}*/
 
/*bool IsEmpty(){
    if(top == -1){
        return true;
    }else{
        return false;
    }
}*/
 
void Push(int value){
    ++top;
    stack[top] = value;
}
 
void Pop(){
    --top;
}
 
 
int Top(){
    return stack[top];
}
 
int Size(){
    return top + 1;
}

void sol(){
    int i = 0, vt; //cp = s.length() - 1, vt;
    while(!feof(stdin)){
        s = getchar();
        ++i;
        if (s == '(') Push(i);
        else if (s == ')') {
            vt = Top();
            Pop();
            cout << vt << " " << i << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("ngoac.inp", "r", stdin);
    freopen("ngoac.out", "w", stdout);
    //cin >> s;
    //cerr << clock() << "ms";
    //s = "0" + s;
    sol();
    //cerr << s.length();
    return 0;
}