#include <bits/stdc++.h> 
using namespace std;
int gcd(int a, int b){
  if (min(a,b) != 0){
    return gcd(min(a,b), max(a,b)-min(a,b));
  }
  return max(a,b);
}
int main() {
  int a,b; cin >> a >> b;
  cout << gcd(a,b) << endl;
}