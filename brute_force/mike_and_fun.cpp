#include <iostream>
#include <cstdlib>
#include <cstdio> 
#include <algorithm>
#include <set> 
using namespace std;  
int a[555][555]; 
int foo[555]; // contains max score of each row 
int main(int argc,char **argv){
	int n,m,q,x,y,maxval = 0;  
	scanf("%d %d %d",&n,&m,&q);  
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			scanf("%d",&a[i][j]);  
		}
	}
	for (int i = 1; i <= n; i++){
		int localMax = 0, cnt = 0; 
		for (int j = 1; j <= m; j++){
			if (a[i][j] == 1){
				cnt++;  
			}else{
				localMax = max(localMax,cnt);  
				cnt = 0; 
			}
		}
		localMax = max(localMax,cnt);  
		foo[i] = localMax;  
	}
	while (q--){
		scanf("%d %d",&x,&y);  
		a[x][y] = !a[x][y];
		int localMax = 0, cnt = 0; 
		for (int i = 1; i <= m; i++){
			if (a[x][i] == 1){
				cnt++;  
			}else{
				localMax = max(localMax,cnt); 
				cnt = 0; 
			}
		}
		localMax = max(localMax,cnt); 
		foo[x] = localMax;  
		maxval = 0; 
		for (int i = 1; i <= n; i++){
			maxval = max(maxval,foo[i]); 
		}
		printf("%d\n",maxval); 
	}
	return 0; 
}
