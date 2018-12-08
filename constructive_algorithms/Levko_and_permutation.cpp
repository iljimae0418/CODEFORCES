#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std; 
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);  
int ans[111111];  
int main(int argc,char **argv){
	int n,k; 
	cin >> n >> k;  
	if (n == 1 && k == 0){
		cout << 1 << endl; 
		return 0; 
	}
	if (k > n-1){
		cout << -1 << endl; 
	}else{
		int i = 2, cnt = 1; 
		for (; i <= n && k > 0; i++,k--,cnt++){
			ans[i] = i;  
		}
		if (i == n+1){
			i = 1; 
		}
		ans[i] = 1; 
		i++; 
		cnt++; 
		while (ans[i] == 0){
			if (i == n+1) i = 1;  
			ans[i] = cnt++; 
			i++; 
		}
		for (int i = 1; i <= n; i++){
			cout << ans[i] << " "; 
		}
		cout << endl; 
	}
	return 0;  
}
