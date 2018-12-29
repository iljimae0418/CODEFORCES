#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int main(){
	string s,t,part1,part2,ans; 
	bool negative = false; 
	cin >> s;  
	int dp = s.find('.'); // decimal point
	if (dp != -1){
		part2 = s.substr(dp,3); 
		t = s.substr(0,dp); 
	}else{
		part2 = ".00";   
		t = s;  
	}
	if (t[0] == '-'){
		t = t.substr(1); 
		negative = true; 
	}
	int cnt = 0; 
	for (int i = t.size()-1; i >= 0; i--){
		cnt++;  
		part1 += t[i];  
		if (cnt == 3 && i != 0){
			part1 += ",";  
			cnt = 0; 
		}
	}
	reverse(part1.begin(),part1.end());  
	while (part2.size() < 3){
		part2 += "0"; 
	}
	ans = part1+part2; 
	if (negative){
		cout << "($" << ans << ")\n"; 
	}else{
		cout << "$" << ans << "\n";  
	}
	return 0; 
}
