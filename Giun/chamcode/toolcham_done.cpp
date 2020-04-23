#include <bits/stdc++.h>
#include "source_done.h"p
using namespace std;
const long long maxtime = 2000, testdau = 0, testcuoi = 10; //ms
 
ifstream test;
ifstream code;
ofstream fi;
char name[225] = "msub", fol[225] = "msub\\test00\\"; 
/* ten chuong trinh & foldertest\\dinhdangbotest00\\ */
long long sttbotest, timerun1, timerun2, timerunct, vt = 10;
/* vt: vi tri so thu tu cuoi cung cua ten bo test trong fol[] */ 
char loai1[100] = ".inp", loai2[100] = ".out", link[100] = "", kytuthu1[100] = "", kytuthu2[225] = "";
char kytuthu3[100] = "";
codesol ctest[testcuoi + 7];

void ghep(long long type){
    if(type == 1) strcpy(kytuthu3, loai1);
    else strcpy(kytuthu3, loai2);
    strcpy(kytuthu2, name);strcpy(kytuthu1, fol);
    strcat(kytuthu1, strcat(kytuthu2, kytuthu3));
    strcpy(link, kytuthu1); 
    strcpy(kytuthu1, "");strcpy(kytuthu2, "");strcpy(kytuthu3, "");
}

void ghepout(){
    strcpy(kytuthu2, loai2);strcpy(kytuthu1, name);
    strcat(kytuthu1, kytuthu2);
    strcpy(link, kytuthu1);
    strcpy(kytuthu1, "");strcpy(kytuthu2, "");
}

void xuli(){
    long long l = sttbotest, n = vt;
    while (l != 0){
        fol[n--] = l % 10 + '0';
        l /= 10;
    }
}

void cham(){
    long long q1 = 0, q2 = 0, x;
    ghep(2);
    test.open(link);
    fi << link;
    strcpy(link, "");
    ghepout();
    code.open(link);
    strcpy(link, "");
    if (!test.is_open()){
        fi << ": LOI MO FILE TEST";
        return;
    }
    if (!code.is_open()){
        fi << ": LOI MO FILE CODE";
        return;
    }
    long long COUNT_ANS = 0;
    while (test >> q1){
        code >> q2;
        ++COUNT_ANS;
        if (q1 != q2) {
            fi << ": WRONG " << q1 << " " << q2 << " vi tri sai: " << COUNT_ANS;
            return;
        }
    }
    q1 = 0, q2 = 0;
    while (test >> x){q1 = 1;}
    while (code >> x){q2 = 1;}
    if (q1 == q2) fi << ((timerunct <= maxtime) ? ": ACCEPT " : ": TLE ") << COUNT_ANS << " time: " << timerunct << " ms";
    else fi << ": ERROR ";
}

void runfile(){
    ghep(1);
    fi << link << ": ";
    timerun1 = clock();
    ctest[sttbotest].run(link);
    timerun2 = clock();    
    fi << "Run Successed!\n";
    strcpy(link, "");
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fi.open("ketquacham.txt");
    for (sttbotest = testdau; sttbotest <= testcuoi; sttbotest++){
        if (sttbotest == 2) continue;
        xuli();
        runfile();
        code.close();
        test.close();
        timerunct = timerun2 - timerun1;
        cham();
        fi << endl;
    }
}