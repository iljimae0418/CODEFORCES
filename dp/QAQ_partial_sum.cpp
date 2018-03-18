#include <iostream>
using namespace std; 
int psum[105]; 
int main(){
	string s;
	cin >> s; 
	psum[0] = (s[0] == 'Q'); 
	for (int i = 1; i < s.size(); i++){
		psum[i] = psum[i-1]+(s[i] == 'Q'); 
	} 
	int ans = 0; 
	for (int i = 0; i < s.size(); i++){
		if (s[i] == 'A' && i-1 >= 0){
			ans += psum[i-1]*(psum[s.size()-1]-psum[i]); 
		}
	}
	cout << ans << endl; 
	return 0; 
}
