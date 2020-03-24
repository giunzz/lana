#include <iostream>
#include <fstream>

using namespace std;

ifstream readf;

void dt(short int i)
{
    unsigned int N, m;
    unsigned long int product = 1;
    readf >> N;
    for (unsigned int i = 1; i <= N; i++)
    {
        readf >> m;
        product *= m;
    }
}

int main()
{
    readf.open("WC1.INP");
    short int T;
    readf >> T;
    for (short int i = 1; i <= T; i++) dt(i);
    readf.close();
    int test[10000];
    return 0;
}
