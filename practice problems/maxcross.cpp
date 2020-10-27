#include <bits/stdc++.h> 
using namespace std;
int sidewalk[100001];
int main(){
  freopen("maxcross.in","r",stdin);
  freopen("maxcross.out","w",stdout);
  int n,k,b,x,prevx = 1,count = 0; cin >> n >> k >> b;
  int input[b];
  for (int i = 0; i < b; i++){
    cin >> input[i];
  }
  sort(input,input+b);
  for (int i = 0; i < b; i++){
    for (int j = prevx; j < input[i]; j++){
      sidewalk[j] = count;
    }
    count++;
    sidewalk[input[i]] = count;
    prevx = input[i]+1;
  }
  int best = b, foo;
  for (int i = 1; i <= n-k; i++){
    foo = sidewalk[i+k]-sidewalk[i];
    if ( foo >= 0 && foo <= best){
      best = foo;
    }
  }
  cout << best << endl;
}
