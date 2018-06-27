#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <set> 
#include <map> 
using namespace std; 
int open[1000005]; 
typedef pair<int,int> P;  
int main(){
	int n,k; 
	string s; 
	cin >> n >> k >> s; 
	set<char> alph; // get all the unique alphabets appearing 
	for (int i = 0; i < s.size(); i++){
		alph.insert(s[i]);  
	}
	map<char,P> mp; // (char, (first index,last index))
	for (set<char>::iterator it = alph.begin(); it != alph.end(); it++){
		char c = *it;  
		int lastIdx = -1,firstIdx = -1;  
		bool first = true; 
		for (int i = 0; i < s.size(); i++){
			if (s[i] == c && first){
				first = false; 
				firstIdx = i;  
				lastIdx = i;  
			}else if (s[i] == c && !first){
				lastIdx = i;  
			}
		}	
		mp[c] = P(firstIdx,lastIdx);   
	}
	for (int i = 0; i < n; i++){
		for (set<char>::iterator it = alph.begin(); it != alph.end(); it++){
			if (mp[*it].first <= i && mp[*it].second >= i) open[i]++; 
		}
		if (open[i] > k){
			// door was unguarded at this time 
			cout << "YES" << endl; 
			return 0;  
		}
	}
	cout << "NO" << endl; 
	return 0; 
}
