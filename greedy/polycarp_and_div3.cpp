#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std; 
int psum[200005]; 
int a[200005]; 
int main(){
	string s; 
	cin >> s; 
	int cnt[3] = {0,0,0};  
	int sum = 0,ans = 0,now = -1;  
	for (int i = 0; i < s.size(); i++){
		a[i+1] = s[i]-'0';
	}
	for (int i = 1; i <= s.size(); i++){	
		now = a[i]; 
		sum += a[i]; 
		cnt[now%3]++;
		if (now%3 == 0 || sum%3 == 0 || cnt[3-(now%3)] > 0){
			ans++; 
			sum = 0; 
			cnt[0] = cnt[1] = cnt[2] = 0; 
		} 
	}
	cout << ans << endl; 
	return 0; 
}
