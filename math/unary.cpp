#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map> 
using namespace std; 
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
const long long mod = 1e6+3;
long long mod_pow(long long a,long long x){
	long long res = 1LL; 
	while (x > 0){
		if (x&1) res = (res*a)%mod; 
		a = (a*a)%mod;  
		x >>= 1;   
	}
	return res; 
}
int main(){
	IOFAST(); 
	map<string,string> mp; 
	mp[">"] = "1000"; 
	mp["<"] = "1001"; 
	mp["+"] = "1010"; 
	mp["-"] = "1011";  
	mp["."] = "1100"; 
	mp[","] = "1101"; 
	mp["["] = "1110"; 
	mp["]"] = "1111";  
	string s,t; 
	cin >> s;  
	for (int i = 0; i < s.size(); i++){
		t += mp[string(1,s[i])]; 
	}
	reverse(t.begin(),t.end()); 
	long long ans = 0; 
	for (int i = 0; i < t.size(); i++){
		if (t[i] == '1'){
			ans += mod_pow(2LL,i);  
			ans %= mod;  
		}
	}
	cout << ans << endl; 
	return 0; 
}
