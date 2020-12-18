#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n;

int main(){
  freopen("pairup.in","r",stdin);
  freopen("pairup.out","w",stdout);
  cin >> n;
  pii arr[n];
  int count = 0;
  for (int i = 0; i < n; i++){
    cin >> arr[i].second >> arr[i].first;
    count+=arr[i].second;
  }
  sort(arr,arr+n);
  int left = 0, right = n-1,decrease,topsum = 0;
  while (left <= right){
    if (left == right){
      topsum = max(topsum,arr[left].first*2);
      break;
    }
    decrease=min(arr[left].second,arr[right].second);
    arr[left].second-=decrease;
    arr[right].second-=decrease;
    topsum = max(topsum,arr[left].first + arr[right].first);
    if(arr[left].second == 0){
      left++;
    }
    if (arr[right].second == 0){
      right--;
    }
  }
  cout << topsum << endl;
}