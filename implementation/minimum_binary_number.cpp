#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int main(){
	int n; 
	cin >> n; 
	string s; 
	cin >> s; 	
	if (s == "0" || s == "1"){
		cout << s << endl; 
		return 0; 
	}
	int zerocnt = 0; 
	for (int i = 0; i < n; i++){
		if (s[i] == '0') zerocnt++; 
	}
	cout << "1"; 
	for (int i = 0; i < zerocnt; i++){
		cout << "0"; 
	}
	cout << endl; 
	return 0; 
}
