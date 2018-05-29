#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int main(){
	int n;
	cin >> n; 
	string s;   
	cin >> s; 
	int ans = -1; 
	int rcnt = 0, bcnt = 0;  
	// compare with rbrbrb...
	for (int i = 0; i < n; i++){
		if (i%2 == 0 && s[i] == 'b') bcnt++; 
		else if (i%2 == 1 && s[i] == 'r') rcnt++; 
	} 
	ans = min(bcnt,rcnt) + (max(bcnt,rcnt)-min(bcnt,rcnt)); 
	// compare with brbrbr... 
	rcnt = bcnt = 0; 
	for (int i = 0; i < n; i++){
		if (i%2 == 0 && s[i] == 'r') rcnt++; 
		else if (i%2 == 1 && s[i] == 'b') bcnt++; 
	}
	ans = min(ans,min(bcnt,rcnt)+(max(bcnt,rcnt)-min(bcnt,rcnt))); 
	cout << ans << endl; 
	return 0; 
}
