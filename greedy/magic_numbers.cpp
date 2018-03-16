#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set> 
using namespace std; 
// can be made of 1,14,144 
int main(){
	string s; 
	cin >> s; 
	bool isMagicNumber = true;  // 114114
	for (int i = 0; i < s.size(); i++){
		if (i == 0 && s[i] != '1'){
			isMagicNumber = false; 
		}else if (i > 0 && s[i] == '1'){
			continue; 
		}else if (i > 0 && s[i] == '4'){
			if (i-1 >= 0 && s[i-1] == '1') continue;  
			else if (i-2 >= 0 && s[i-1] == '4' && s[i-2] == '1') continue; 
			else isMagicNumber = false; 
		}else if (i == 0 && s[i] == '1'){
			continue; 
		}else{
			isMagicNumber = false;
		}
	}
	if (isMagicNumber) cout << "YES" << endl; 
	else cout << "NO" << endl; 
	return 0;  
}
