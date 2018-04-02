#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int main(){
	string s; 
	cin >> s; 
	int skip = s.size()-1;  
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '0'){
			skip = i; 
			break; 
		}
	}
	for (int i = 0; i < s.size(); i++){
		if (i == skip) continue; 
		cout << s[i]; 
	}
	cout << endl; 
	return 0; 
}
