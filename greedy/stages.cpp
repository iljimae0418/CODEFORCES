#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std; 
const int INF = (int)2e9 + 88; 
int main(){
	int n,k; 
	cin >> n >> k; 
	string s; 
	cin >> s; // n lowercase latin letters 
	sort(s.begin(),s.end()); 
	int minScore = INF; 
	for (int i = 0; i < s.size(); i++){
		string t; 
		t += s[i];  
		char prev = s[i];  
		for (int j = i+1; j < s.size(); j++){
			if (s[j]-prev >= 2 && t.size() < k){
				t += s[j]; 
				prev = s[j];  
			}
		}
		if (t.size() < k) continue; 
		int score = 0; 
		for (int j = 0; j < t.size(); j++){
			score += t[j]-'a'+1;  
		}
		minScore = min(minScore,score); 
	}
	if (minScore == INF) cout << -1 << endl; 
	else cout << minScore << endl; 
	return 0; 
}
