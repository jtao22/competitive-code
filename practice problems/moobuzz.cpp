#include <bits/stdc++.h> 
using namespace std;
int main(){
  freopen("moobuzz.in","r",stdin);
  freopen("moobuzz.out","w",stdout);
  int n,sum=0; cin >> n;
  int a = n%8;
  int arr[8] = {1,2,4,7,8,11,13,14};
  sum+=arr[a-1]+15*(n/8);
  cout << sum << endl;
}
