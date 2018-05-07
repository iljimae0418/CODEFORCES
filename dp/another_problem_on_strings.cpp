#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <map> 
using namespace std;  
long long a[1000005]; 
int main(){
	int k,n; 
	cin >> k;  
	string s; 
	cin >> s;  
	for (int i = 0; i < s.size(); i++){
		a[i+1] = s[i]-'0';  
	}
	n = s.size(); 
	long long sum = 0, ans = 0; 
	map<long,long> mp; 
	mp[0LL] = 1LL; 
	for (int i = 1; i <= n; i++){
		sum += a[i]; 
		ans += mp[sum-k]; 
		mp[sum]++; 
	}
	cout << ans << endl; 
	return 0; 
}
