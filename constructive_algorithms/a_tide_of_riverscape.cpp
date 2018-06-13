#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring> 
using namespace std; 
int main(){
	int n,p; 
	string s;  
	cin >> n >> p; 
	cin >> s;  
	bool canMake = false;  
	for (int i = 0; i+p < s.size(); i++){
		if (s[i] != '.' && s[i] != s[i+p]){
			canMake = true; 
		}
		if (s[i] == '.' || s[i+p] == '.'){
			canMake = true; 
		}	
	}
	if (!canMake){
		cout << "No" << endl; 
	}else{
		for (int i = 0; i+p < s.size(); i++){
			if (s[i] == '.' && s[i+p] == '.'){
				s[i] = '1'; 
				s[i+p] = '0'; 
			}else if (s[i] == '.' && s[i+p] != '.'){
				s[i] = (s[i+p] == '1' ? '0' : '1');  
			}else if (s[i] != '.' && s[i+p] == '.'){
				s[i+p] = (s[i] == '1' ? '0' : '1'); 
			}
		}
		for (int i = 0; i < s.size(); i++){
			// these positions are not affected by the periodicity rule 
			if (s[i] == '.') s[i] = '1';  
		}
		cout << s << endl; 
	}
	return 0;  
}
