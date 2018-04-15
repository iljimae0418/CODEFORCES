#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map> 
using namespace std; 
char tolower(char x){ // uppercase to lower case: add 32
	return char(x | 32); 
}
int main(){
	int n; 
	cin >> n; 
	string s; 
	cin >> s; 
	int cnt = 0; 
	map<char,int> keys;  
	for (int i = 0; i < s.size()-1; i += 2){
		if (s[i] == tolower(s[i+1])){
			continue;  
		}else if (keys[tolower(s[i+1])] > 0){
			keys[tolower(s[i+1])]--;  
			keys[s[i]]++;  
		}else{
			cnt++; // we must buy the key for the door s[i+1] 
			keys[s[i]]++; // we may use this key later 
		}
	}
	cout << cnt << endl;
	return 0; 
}
