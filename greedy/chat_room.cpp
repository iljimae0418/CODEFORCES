#include <iostream>
#include <algorithm>
using namespace std;  
int main(){
	string s; 
	cin >> s; 
	int idx = 0;  
	for (int i = 0; i < s.size(); i++){
		if (s[i] == 'h' && idx == 0) idx++; 
		else if (s[i] == 'e' && idx == 1) idx++;  
		else if (s[i] == 'l' && idx == 2) idx++; 
		else if (s[i] == 'l' && idx == 3) idx++; 
		else if (s[i] == 'o' && idx == 4) idx++; 
	}
	if (idx == 5) cout << "YES" << endl; 
	else cout << "NO" << endl; 
	return 0; 
}
