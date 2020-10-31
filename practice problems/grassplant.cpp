#include <bits/stdc++.h> 
using namespace std;
int arr[100001];
int main(){
	int n,a,b,ans=0;cin >> n;
	for(int i = 0; i < n-1; i++){
		cin >> a >> b;
		arr[a]++; arr[b]++;
	}
	for(int i = 1; i <= n; i++){
		if (arr[i] > ans){
      ans = arr[i];
    }
}
	cout << ans+1 << endl;
}