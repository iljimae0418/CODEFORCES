// just simple implementation 
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;  
int main(){
	int n; 
	cin >> n;
	string s; 
	cin >> s; 
	int StoF = 0, FtoS = 0;  
	for (int i = 0; i < s.size()-1; i++){
		if (s[i] == 'F' && s[i+1] == 'S') FtoS++;  
		if (s[i] == 'S' && s[i+1] == 'F') StoF++;  
	}
	if (StoF > FtoS) cout << "YES" << endl; 
	else cout << "NO" << endl; 
	return 0;  
}
