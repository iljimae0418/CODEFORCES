#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int main(){
	string s;
	cin >> s; 
	// find AB first, then find BA 
	int found = -1; 
	for (int i = 0; i < s.size()-1; i++){
		if (s[i] == 'A' && s[i+1] == 'B'){
			found = i;  
			break; 
		}
	}
	if (found != -1){
		int found2 = -1; 
		for (int i = found+2; i < s.size()-1; i++){
			if (s[i] == 'B' && s[i+1] == 'A'){
				found2 = i; 
				break; 
			}
		}
		if (found2 != -1){
			cout << "YES" << endl; 
			return 0; 
		}
	}
	// find BA first, then find AB
	found = -1; 
	for (int i = 0; i < s.size()-1; i++){
		if (s[i] == 'B' && s[i+1] == 'A'){
			found = i; 
			break; 
		}
	}
	if (found != -1){
		int found2 = -1; 
		for (int i = found+2; i < s.size()-1; i++){
			if (s[i] == 'A' && s[i+1] == 'B'){
				found2 = i;  
				break; 
			}
		}
		if (found2 != -1){
			cout << "YES" << endl; 
			return 0; 
		}
	}
	cout << "NO" << endl; 
	return 0; 
}
