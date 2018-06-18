#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
#include <map> 
using namespace std; 
typedef long long ll; 
ll hcnt[1000005]; 
ll mcnt[1000005]; 
int main(){
	string s; 
	cin >> s;  		
	ll ans = 0; 
	hcnt[0] = hcnt[1] = hcnt[2] = hcnt[3] = 0;  
	for (int i = 4; i < s.size(); i++){
		string t; 
		for (int j = i-4; j <= i; j++){
			t += s[j]; 
		}
		if (t == "heavy"){
			hcnt[i] = 1;  
		}
	}
	mcnt[0] = mcnt[1] = mcnt[2] = mcnt[3] = 0; 
	for (int i = 4; i < s.size(); i++){
		string t; 
		for (int j = i-4; j <= i; j++){
			t += s[j];  
		}
		mcnt[i] = mcnt[i-1]+(t == "metal" ? 1 : 0); 
	}
	for (int i = 4; i < s.size(); i++){
		if (hcnt[i]){
			ans += mcnt[s.size()-1]-mcnt[i]; 
		}
	}
	cout << ans << endl; 
	return 0;  
}
