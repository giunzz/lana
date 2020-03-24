#include <iostream>
#include <cmath>
using namespace std;
 
int main() {
  int sum = 0;
  float mi = 1e9 - 1e5;
  for (float i = mi; i <= 1e9; i++) sum += (int)sqrt(i);
  cout <<sum;
}
 