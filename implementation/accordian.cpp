#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <stack> 
#include <vector> 
using namespace std; 
int main(int argc,char **argv){
	string s;  
	cin >> s; 
	// first find the position of the leftmost [
	// and rightmost ] 
	int left_bracket = -1, right_bracket = -1; 
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '[' && left_bracket == -1){
			left_bracket = i;  
		}else if (s[i] == ']'){
			right_bracket = i;  
		}
	}
	if (left_bracket == -1 || right_bracket == -1){
		cout << -1 << endl; 
		return 0;  
	}
	// we then find the position of the leftmost and 
	// rightmost colons such that their positions are 
	// between left_bracket and right_bracket. 
	int left_colon = -1, right_colon = -1;  
	for (int i = left_bracket+1; i < s.size(); i++){
		if (s[i] == ':' && left_colon == -1){
			left_colon = i;  
		}else if (s[i] == ':' && i < right_bracket){
			right_colon = i;  
		}
	}
	if (left_colon == -1 || right_colon == -1){
		cout << -1 << endl; 
		return 0; 
	}
	// finally compute the valid length between the two colons
	int cnt = 0; 
	for (int i = left_colon+1; i < right_colon; i++){
		if (s[i] == '|') cnt++; 
	}
	cout << cnt+4 << endl; 
	return 0; 
}
