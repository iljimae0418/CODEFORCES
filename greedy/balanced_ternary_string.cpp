#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <map> 
#include <vector> 
using namespace std; 
map<char,int> freq; 
int main(int argc,char **argv){
	int n; 
	cin >> n; 
	string s; 
	cin >> s;  
	for (int i = 0; i < s.size(); i++){
		freq[s[i]]++; 
	}
	int d[3] = {freq['0']-n/3,freq['1']-n/3,freq['2']-n/3}; 
	if (d[0] > 0){
		for (int i = s.size()-1; i >= 0; i--){
			if (s[i] == '0' && d[2] < 0 && d[0] > 0){
				s[i] = '2'; 
				d[2]++; 
				d[0]--;  
			}else if (s[i] == '0' && d[1] < 0 && d[0] > 0){
				s[i] = '1'; 
				d[1]++; 
				d[0]--;  
			}
		}
	}
	if (d[1] > 0){
		for (int i = 0; i < s.size(); i++){
			if (s[i] == '1' && d[0] < 0 && d[1] > 0){
				s[i] = '0';  
				d[0]++; 
				d[1]--;  
			}
		}
		for (int i = s.size()-1; i >= 0; i--){
			if (s[i] == '1' && d[2] < 0 && d[1] > 0){
				s[i] = '2'; 
				d[2]++; 
				d[1]--; 
			}
		}
	}
	if (d[2] > 0){
		for (int i = 0; i < s.size(); i++){
			if (s[i] == '2' && d[0] < 0 && d[2] > 0){
				s[i] = '0'; 
				d[0]++; 
				d[2]--; 
			}else if (s[i] == '2' && d[1] < 0 && d[2] > 0){
				s[i] = '1'; 
				d[1]++; 
				d[2]--; 
			}
		}
	}
	cout << s << endl; 
	return 0; 
}
