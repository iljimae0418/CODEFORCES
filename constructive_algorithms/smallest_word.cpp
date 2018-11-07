#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring> 
using namespace std; 
int chk[1005];  
int main(){
	string s; 
	cin >> s;
	for (int i = 1; i < s.size(); i++){
		if (s[i] == 'a'){
			chk[i-1] ^= 1;  
			chk[i] = 1;  
		}
	}
	for (int i = 0; i < s.size(); i++){
		cout << chk[i] << " "; 
	}
	cout << endl; 
	return 0; 
}
