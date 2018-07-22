#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
string toLower(string s){
	for (int i = 0; i < s.size(); i++){
		s[i] |= (1<<5); 
	}
	return s; 
}
int main(){
	// -1 if first is less than second 
	// 1 if first is greater than second 
	// 0 if equal 
	string first,second; 
	cin >> first >> second; 
	first = toLower(first); 
	second = toLower(second); 
	if (first < second){
		cout << -1 << endl; 
	}else if (first > second){
		cout << 1 << endl; 
	}else{
		cout << 0 << endl; 
	}
	return 0;  
}
