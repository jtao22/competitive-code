#include<iostream>
#include<stdlib.h>
using namespace std;
int cost[10][10],i,j,k,n,stk[10],top,v,visit[10],visited[10],u;
 
int main()
{
	int m,c;
	cin >> n;
	cin >> m;
	for(k=1;k<=m;k++){
		cin >>i>>j>>c;
		cost[i][j]=c;
    cost[j][i] = c;
	}
	for(i=1;i<=n;i++){
	for(j=1;j<=n;j++){
		if(cost[i][j]==0){
		cost[i][j]=31999;
    }
  }
  }
	k=1;
	while(k<n){
		m=31999;
		if(k==1){
			for(i=1;i<=n;i++){
				for(j=1;j<=m;j++){
				if(cost[i][j]<m){
					m=cost[i][j];
					u=i;
				}
        }
      }
		}
		else{
			for(j=n;j>=1;j--){
			if(cost[v][j]<m && visited[j]!=1 && visit[j]!=1){
				visit[j]=1;
				stk[top]=j;
				top++;
				m=cost[v][j];
				u=j;
			}
      }
		}
		cost[v][u]=31999;
		v=u;
		cout<<v << " ";
		k++;
		visit[v]=0; visited[v]=1;
	}
}
#include<stdlib.h>using namespace std;int cost[10][10],i,j,k,n,stk[10],top,v,visit[10],visited[10];
int main(){
int m;cin >> n;cin >> m;
for(k=1;k<=m;k++){cin >>i>>j;cost[i][j]=1;}v = 1; cout << v <<" ";visited[v]=1;k=1;while(k<n){for(j=n;j>=1;j--)if(cost[v][j]!=0 && visited[j]!=1 && visit[j]!=1){visit[j]=1;stk[top]=j;top++;}v=stk[--top];cout<<v << " ";k++;visit[v]=0; visited[v]=1;}
}