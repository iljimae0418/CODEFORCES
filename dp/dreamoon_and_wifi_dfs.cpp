#include <iostream> 
#include <algorithm> 
#include <cstdlib>
#include <vector> 
#include <map> 
using namespace std; 
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
string s1,s2; 
int score;   
int power(int x){
	// calculates 2^x 
	if (x == 0) return 1; 
	if (x == 1) return 2; 
	return power(x/2)*power(x/2)*power(x%2); 
}	
int chk(string t){
	map<char,int> mp; 
	for (int i = 0; i < t.size(); i++){
		mp[t[i]]++; 
	}
	return mp['+']-mp['-'];  
}
int solve(int i){
	if (i == s2.size()){ // base case 
		if (chk(s2) == score) return 1; 
		return 0; 
	}
	int ret = 0;  
	if (s2[i] == '+' || s2[i] == '-') ret += solve(i+1); 
	else if (s2[i] == '?'){
		s2[i] = '+';  
		ret += solve(i+1); 
		s2[i] = '-';  
		ret += solve(i+1);  
		s2[i] = '?';  
	}
	return ret;  
}
int main(){
	cin >> s1 >> s2; 
	int cnt = 0; 
	for (int i = 0; i < s1.size(); i++){
		score += (s1[i] == '+' ? 1 : -1); 
	}
	for (int i = 0; i < s2.size(); i++){
		if (s2[i] == '?') cnt++;   
	}	
	int cases = solve(0);  
	cout.setf(ios::fixed); 
	cout.setf(ios::showpoint); 
	cout.precision(12); 
	double ans = (double)cases/(double)power(cnt);  
	cout << ans << endl; 
	return 0; 
}
