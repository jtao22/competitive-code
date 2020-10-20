#include <bits/stdc++.h> 
using namespace std;
int n,min,max,mid,q,a,b;
	int check(int arr[], int limit) {
		if(arr[0] > limit) {
			return 0;
		}
		int min = 0;
		int max = n-1;
    
		while(min != max) {
			mid = (min+max+1)/2;
			if(arr[mid] <= limit) {
				min = mid;
			}
			else {
				max = mid-1;
			}
		}
		return min+1;
	}
int main(){
  //freopen("haybales.in","r",stdin);
  //freopen("haybales.out","w",stdout);
  cin >> n >> q;
  int arr[n];
  for (int i = 0; i < n; i++){
    cin >> arr[i];
  }
  sort(arr,arr+n);
  for (int i = 0; i < q; i++){
    cin >> a >> b;
    cout << check(arr,b) - check(arr,a-1) << endl;
  }
}