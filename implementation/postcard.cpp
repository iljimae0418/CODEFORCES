// ? : letter before can be removed or left 
// * : letter before can be removed or left or repeated 
#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std; 
int main(){
	string s; 
	int k; 
	cin >> s >> k;  
	int charCnt = 0, qCnt = 0, sCnt = 0;  
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '?') qCnt++;  
		else if (s[i] == '*') sCnt++; 
		else charCnt++;  
	}
	if (charCnt == k){
		for (int i = 0; i < s.size(); i++){
			if (s[i] != '?' && s[i] != '*'){
				cout << s[i]; 
			}
		}
		cout << endl; 
	}else if (charCnt != k && qCnt == 0 && sCnt == 0){
		cout << "Impossible" << endl; 
	}else{
		string ans; 
		if (charCnt < k){ 
			if (sCnt == 0){ 
				cout << "Impossible" << endl; 
			}else if (sCnt > 0){
				for (int i = 0; i < s.size(); i++){
					if (s[i] == '?' || s[i] == '*') continue; 
					else if (i+1 < s.size() && s[i+1] == '*' && charCnt < k){
						for (int j = 0; j <= k-charCnt; j++){
							ans += s[i]; 
						}
						charCnt = k;  
					}else{
						ans += s[i]; 
					}
				}
				if (ans.size() == k) cout << ans << endl; 
				else cout << "Impossible" << endl;  
			}
		}else if (charCnt > k){
 			for (int i = 0; i < s.size(); i++){
				if (i+1 < s.size() && (s[i+1] == '?' || s[i+1] == '*') && 
					charCnt > k){
					charCnt--;  
				}else if (s[i] == '?' || s[i] == '*'){
					continue; 
				}else{
					ans += s[i]; 
				}
			}
			if (ans.size() == k){
				cout << ans << endl; 
			}else{
				cout << "Impossible" << endl; 
			}
		}
	}
	return 0;  
}
