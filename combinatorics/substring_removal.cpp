#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
typedef long long ll;  
const ll mod = 998244353LL; 
int main(){
	int n; 
	cin >> n; 
	string s; 
	cin >> s;  
	char l = s[0]; 
	int i = 0; 
	for (;i < s.size(); i++){
		if (s[i] != l) break;  
	}
	int lstart = 0, lend = i-1;  
	char r = s[s.size()-1];  
	int j = s.size()-1;  
	for (; j >= i; j--){
		if (s[j] != r) break; 
	}
	int rstart = j+1, rend = s.size()-1;  
	ll lsize = lend-lstart+1;  
	ll rsize = rend-rstart+1;  
	ll ans = 1LL;  
	ans += lsize; 
	ans %= mod; 
	ans += rsize; 
	if (l == r){
		ans += lsize*rsize;  
		ans %= mod; 
	}
	cout << ans << "\n"; 
	return 0; 
}
