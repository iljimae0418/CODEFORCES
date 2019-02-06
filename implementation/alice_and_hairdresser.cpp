#include <iostream>
#include <cstdlib>
#include <cstdio> 
#include <algorithm>
#include <vector> 
#include <cstring> 
using namespace std;
typedef long long ll;  
const int MAXN = 100005;   
ll a[MAXN];  
int main(int argc,char **argv){
	int n,m; 
	ll l;  
	scanf("%d %d %lld",&n,&m,&l); 
	for (int i = 1; i <= n; i++){
		scanf("%lld",&a[i]);  
	}
	int segments = 0;  
	int i = 1; 
	while (i <= n){
		if (a[i] > l){
			segments++; 
			while (a[i] > l && i <= n){
				i++; 
			}
		}
		i++;  
	}
	while (m--){
		int q; 
		scanf("%d",&q); 
		if (q == 0){
			printf("%d\n",segments);  
		}else if (q == 1){
			int i; 
			ll d;  
			scanf("%d %lld",&i,&d); 
			if (a[i]+d > l && a[i] <= l){
				if (a[i-1] > l && a[i+1] > l){
					segments--;  
				}else if (a[i-1] <= l && a[i+1] <= l){
					segments++;  
				}
			}
			a[i] += d;  
		}
	}
	return 0; 
}
