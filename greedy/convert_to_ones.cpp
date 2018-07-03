#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;  
typedef long long ll; 
int main(){
	ll n,x,y; 
	cin >> n >> x >> y;  
	string s; 
	cin >> s;  
	ll p = 0,zero_group = 0; 
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '0'){
			zero_group = 1; 
			if (i == s.size()-1) p++;  
		}else if (s[i] == '1'){
			if (zero_group) p++;  
			zero_group = 0;  
		}
	}
	if (p == 0) cout << 0 << endl; 
	else cout << (p-1)*min(x,y)+y << endl; 
	return 0; 
}
