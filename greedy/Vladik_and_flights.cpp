#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
// we are going from a to b 
char s[100005]; 
int main(){
	int n,a,b; 
	cin >> n >> a >> b;  
	for (int i = 1; i <= n; i++){
		cin >> s[i];  
	}
	if (s[a] == s[b]){
		cout << 0 << endl; 
	}else{
		cout << 1 << endl; 
	}
	return 0; 
}
