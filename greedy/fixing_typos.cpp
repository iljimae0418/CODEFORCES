#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std; 
vector<int> cnt; 
vector<char> character; 
int main(){
	string str; 
	cin >> str; 
	for (int i = 0; i < str.size(); i++){
		char candidate = str[i]; 
		int c = 1; 
		for (int j = i+1; j < str.size(); j++){
			if (candidate == str[j]){
				c++; 
			}else{
				break; 
			}
		}
		i += (c-1); 
		cnt.push_back(c); 
		character.push_back(candidate); 
	}
	for (int i = 0; i < cnt.size(); i++){
		if (cnt[i] >= 3) cnt[i] = 2;  
	}
	for (int i = 0; i < cnt.size()-1; i++){
		if (cnt[i] == 2 && cnt[i+1] == 2){
			cnt[i+1] = 1; 
		}
	}
	for (int i = 0; i < cnt.size(); i++){
		for (int j = 0; j < cnt[i]; j++){
			cout << character[i]; 
		}
	}
	cout << endl; 
	return 0; 
}
