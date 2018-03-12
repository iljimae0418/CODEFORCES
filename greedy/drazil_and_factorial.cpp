#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <vector>
#include <map> 
using namespace std; 
map<char,string> mp; 
int main(){
	int n; 
	cin >> n; 
	string s,t = ""; 
	cin >> s; 
	mp['0'] = "";  
	mp['1'] = ""; 
	mp['2'] = "2"; 
	mp['3'] = "3"; 
	mp['4'] = "322"; 
	mp['5'] = "5"; 
	mp['6'] = "53";  
	mp['7'] = "7";  
	mp['8'] = "7222"; 
	mp['9'] = "7332"; 
	for (int i = 0; i < n; i++){
		t += mp[s[i]];  
	}
	sort(t.begin(),t.end(),greater<char>()); 
	cout << t << endl;
	return 0; 
 }
