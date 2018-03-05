#include <iostream>
#include <cstdlib> 
#include <algorithm>
using namespace std;  
int cnt[2];  
int main(){	
	int n; 
	char c;  
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> c; 
		cnt[c-'0']++;     
	}
	cout << n-2*min(cnt[0],cnt[1]) << endl; 
	return 0; 
}
