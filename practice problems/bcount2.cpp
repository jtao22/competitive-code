#include <bits/stdc++.h> 
#include<iostream> 
#include<stdlib.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n,q;
int psum[4][100001];
int arr[1000001];
int main(){
  freopen("bcount.in","r",stdin);
  freopen("bcount.out","w",stdout);
  cin >> n >> q; 
  for (int i = 1; i < 4; i++){
    psum[i][0] = 0;
  }
  for (int i = 1; i <= n; i++){
    for (int j = 1; j < 4; j++){
      psum[j][i] = psum[j][i-1];
    }
    cin >> arr[i];
    psum[arr[i]][i]++;
  }
  int a,b;
  for (int i = 0; i < q; i++){
    cin >> a >> b;
    cout << psum[1][b] - psum[1][a-1];
    for (int j = 2; j < 4; j++){
      cout << " " << psum[j][b]-psum[j][a-1];
    }
    cout << "" << endl;
  }
}