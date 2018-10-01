#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring> 
#include <vector> 
using namespace std;  
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
typedef long long ll;  
int main(){
	ll n,k,ans = 0;  
	cin >> n >> k;  
	if (k <= n){
		if (k%2 == 0) ans = max(ans,k/2 - 1);   
		else ans = max(ans,k/2); 
	}else if (k > n){
		if (k%2 == 0) ans = max(ans,(k/2 - 1)-(k-n)+1);  
		else ans = max(ans,(k/2)-(k-n)+1);   
	}
	cout << ans << endl; 
	return 0; 
}
