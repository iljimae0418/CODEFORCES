#include <iostream>
#include <cstdlib>
#include <cstdio> 
#include <algorithm> 
#include <cstring> 
#include <vector> 
#include <set> 
using namespace std; 
const int INF = (int)1e9; 
const int MAXN = 22; 
int c[MAXN]; 
int main(int argc,char **argv){
	int n,l,r,x,cnt = 0; 
	scanf("%d %d %d %d",&n,&l,&r,&x); 
	for (int i = 0; i < n; i++){
		scanf("%d",c+i); 
	}
	// bitmask brute force 
	for (int i = 0; i < (1<<n); i++){
		int sum = 0, maxval = -INF, minval = INF;  
		for (int j = 0; j < n; j++){
			if (i&(1<<j)){
				sum += c[j]; 
				maxval = max(maxval,c[j]); 
				minval = min(minval,c[j]); 
			}
		}
		if (sum >= l && sum <= r && maxval-minval >= x){
			cnt++; 
		}
	}
	printf("%d\n",cnt); 
	return 0;  
}
