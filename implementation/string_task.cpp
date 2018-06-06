#include <iostream>
#include <cstdlib> 
#include <vector>
using namespace std; 
bool isvowel(char x){
	int k = (int)x; 
	k &= ~(1<<5); 
	x = (char)k;  
	return x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U' || x == 'Y';  
}
int main(){
	string s; 
	cin >> s; 
	vector<char> v; 
	for (int i = 0; i < s.size(); i++){
		if (isvowel(s[i])) continue;  
		v.push_back(s[i]); 
	}
	for (int i = 0; i < v.size(); i++){
		cout << "."; 
		if (v[i] >= 'A' && v[i] <= 'Z'){
			v[i] = (char)(v[i]+32); 
		}
		cout << v[i];  
	}
	cout << endl; 
	return 0; 
}
