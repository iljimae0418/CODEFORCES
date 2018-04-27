#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <sstream> 
using namespace std; 
int main(){
	string s; 
	cin >> s;
	if (s.size() == 1){
		if (s == "0" || s == "4" || s == "8") cout << 4 << endl; 
		else cout << 0 << endl; 
	}else{
		// extract last two digits of s 
		string t = s.substr(s.size()-2); 
		int k = (t[0]-'0')*10 + (t[1]-'0'); 
		if (k%4 == 0){
			// s is a multiple of four 
			cout << 4 << endl;
		}else{
			cout << 0 << endl; 
		}
	}
	return 0; 
}
