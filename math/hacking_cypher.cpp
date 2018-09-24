#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
#define IOFAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
typedef long long ll;  
int rema[1000005]; 
int remb[1000005]; 
ll mod10[1000005];  
ll mod_pow(int a, int x, int mod){
	if (x == 0) return 1%mod; 
	ll res = mod_pow(a,x/2,mod);  
	if (x%2 == 0) return (res*res)%mod; 
	return (a*((res*res)%mod))%mod; // else 
}
int main(){
	IOFAST();  
	string s; 
	cin >> s;  
	ll a,b; 
	cin >> a >> b;  
	mod10[0] = 1%b;  
	for (int i = 1; i < 1000005; i++){
		mod10[i] = mod10[i-1]*10%b;  
	}
	// fill in rema first 
	rema[0] = (s[0]-'0')%a;  
	for (int i = 1; i < s.size(); i++){
		rema[i] = (rema[i-1]*10 + s[i]-'0')%a;  
	}
	// fill in remb next  
	remb[s.size()-1] = (s[s.size()-1]-'0')%b;  
	for (int i = s.size()-2; i >= 0; i--){
		remb[i] = (remb[i+1] + (s[i]-'0')*mod10[s.size()-1-i])%b;  
	} 
	// now search for answer   
	for (int i = 0; i < s.size()-1; i++){
		if (rema[i] == 0 && remb[i+1] == 0 && s[i+1] != '0'){
			cout << "YES" << endl; 
			cout << s.substr(0,i+1) << endl; 
			cout << s.substr(i+1) << endl; 
			return 0;  
		}
	}
	cout << "NO" << endl; 
	return 0;  
}
