#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
// we can remove digits but forbidden to rearrange them 
// numbers are divisible by 8 iff the last three digits of a number 
// are also divisible by 8. 
int main(){
	string s; 
	cin >> s;  
	// check all one digit numbers
	for (int i = 0; i < s.size(); i++){
		if ((s[i]-'0')%8 == 0){
			cout << "YES" << endl; 
			cout << s[i] << endl; 
			return 0;  
		}
	}
	// check all two digit numbers 
	for (int i = 0; i < s.size(); i++){
		for (int j = i+1; j < s.size(); j++){
			int a = s[i]-'0', b = s[j]-'0'; 
			int no = a*10+b; 
			if (no%8 == 0){
				cout << "YES" << endl; 
				cout << no << endl; 
				return 0; 
			}
		}
	}
	// check all three digit numbers
	for (int i = 0; i < s.size(); i++){
		for (int j = i+1; j < s.size(); j++){
			for (int k = j+1; k < s.size(); k++){
				int a = s[i]-'0', b = s[j]-'0', c = s[k]-'0'; 
				int no = a*100+b*10+c; 
				if (no%8 == 0){
					cout << "YES" << endl; 
					cout << no << endl; 
					return 0; 
				}
			}
		}
	}
	cout << "NO" << endl; 
	return 0;  
}
