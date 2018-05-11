#include <iostream>
#include <cstdlib>
#include <set>
using namespace std; 
int main(){
	string s; 
	getline(cin,s);
	set<char> distinct; 
	for (int i = 1; i < s.size()-1; i++){
		if (s[i] >= 'a' && s[i] <= 'z'){
			// if it is a small english letter 
			distinct.insert(s[i]);  
		}
	}
	cout << distinct.size() << endl; 
	return 0; 
}
