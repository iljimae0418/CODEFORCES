#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int main(){
	int n; 
	cin >> n; 
	string s; 
	cin >> s; 
	int cnt = 0;  
	for (int i = 0; i <= n-3; i++){
		if (s[i] == 'x' && s[i+1] == 'x' && s[i+2] == 'x'){
			cnt++;  
		} 
	}
	cout << cnt << endl;
	return 0; 
}
