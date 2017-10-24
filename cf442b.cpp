#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int psum_a[5005]; // the count of 'a' up to i (i = 1,2,...,s.size())
int psum_b[5005]; // the count of 'b' up to i (i = 1,2,...,s.size())
int main(){
	string s; 
	cin >> s;  
	psum_a[1] = (s[0] == 'a'); 
	psum_b[1] = (s[0] == 'b'); 
	for (int i = 1; i < s.size(); i++){
		psum_a[i+1] = psum_a[i]+(s[i] == 'a'); 
		psum_b[i+1] = psum_b[i]+(s[i] == 'b');  
	}
	int ans = 0; 
	int len_idx = s.size();  
	for (int i = 0; i <= s.size(); i++){
		for (int j = i; j <= s.size(); j++){
			// [0...i] is a, [i+1,...,j] is b, [j+1,...,s.size()] is a 
			// to get prefix sum we do psum_a[i], psum_b[j]-psum_b[(i+1)-1], psum_a[s.size()]-psum_a[(j+1)-1] respectively 
			int eval = psum_a[i]+(psum_b[j]-psum_b[i])+(psum_a[len_idx]-psum_a[j]); 
			ans = max(ans,eval); 
		}
	}
	cout << ans << endl; 
	return 0; 
}
