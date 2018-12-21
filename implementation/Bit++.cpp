#include <iostream>
using namespace std; 
int main(){
	int t,ans = 0; 
	cin >> t; 
	while (t--){
		string s; 
		cin >> s;  
		if (s[0] == '+' || s[2] == '+'){
			ans++; 
		}else{
			ans--; 
		}
	}
	cout << ans << endl; 	
}
