// the three segments [1,i][i+1,j][j+1,n] 
// calculate accordingly using partial sum table 
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;  
struct info{
	int a,b; 
	info(){}
}; 
info psum[5005]; 
int main(){
	string s; 
	cin >> s; 
	for (int i = 0; i < s.size(); i++){
		psum[i+1].a = psum[i].a + (s[i] == 'a'); 
		psum[i+1].b = psum[i].b + (s[i] == 'b'); 
 	}
 	int n = s.size();  
 	// brute force  
 	int maxlen = 0;  
 	for (int i = 0; i <= n; i++){
 		for (int j = i; j <= n; j++){
 			maxlen = max(maxlen,psum[i].a+(psum[j].b-psum[i].b)+(psum[n].a-psum[j].a));  
 		}
 	}
 	cout << maxlen << endl; 
 	return 0; 
}
