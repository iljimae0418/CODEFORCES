#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map> 
#include <vector>
using namespace std;  
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
int main(){
	IOFAST(); 
	string s; 
	cin >> s; 
	if (s.size() < 3){
		cout << "No" << endl; 
		return 0; 
	}
	bool exists = false; 
	for (int i = 0; i <= s.size()-3; i++){
		map<char,int> mp; 
		for (int j = i; j < i+3; j++){
			mp[s[j]]++; 
		}
		if (mp.count('A') && mp.count('B') && mp.count('C')){
			exists = true; 
			cout << "Yes" << endl; 
			break; 
		}
	}
	if (!exists){
		cout << "No" << endl; 
	}
	return 0;  
}
