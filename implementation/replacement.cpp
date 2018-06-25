#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;  
int main(){
	int n,m; 
	string s; 
	cin >> n >> m >> s;  
	int ret = 0;  
	for (int i = 1; i < s.size(); i++){
		if (s[i] == '.' && s[i-1] == '.') ret++;  
	}
	for (int i = 0; i < m; i++){
		int idx;
		char c; 
		cin >> idx >> c;  
		idx--; 
		if (c == '.' && s[idx] != '.'){
			if (idx > 0 && s[idx-1] == '.') ret++;  
			if (idx < s.size()-1 && s[idx+1] == '.') ret++;  
 		}else if (c != '.' && s[idx] == '.'){
 			if (idx > 0 && s[idx-1] == '.') ret--; 
 			if (idx < s.size()-1 && s[idx+1] == '.') ret--; 
 		}
 		cout << ret << endl; 
 		s[idx] = c; 
	}
	return 0; 
}
