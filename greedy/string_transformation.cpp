#include <iostream>
#include <algorithm> 
#include <cstdlib>
#include <map> 
using namespace std; 
int main(){
	string s; 
	cin >> s; 
	char c = 'a'; 
	bool can = false;  
	for (int i = 0; i < s.size(); i++){
		if (s[i] == c){
			c = char(c+1); 
		}else if (s[i] < c){
			s[i] = c; 
			c = char(c+1);  
		}
		if (c > 'z'){
			can = true; 
			break; 
		}
	}
	if (can){
		cout << s << endl; 
	}else{
		cout << -1 << endl; 
	}
	return 0; 
}
