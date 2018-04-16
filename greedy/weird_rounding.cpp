#include <iostream>
#include <algorithm>
#include <vector> 
#include <cmath> 
#include <sstream> 
using namespace std; 
int digitLen(int x){
	if (x == 0) return 1; 
	int cnt = 0; 
	while (x){
		x /= 10; 
		cnt++; 
	}
	return cnt; 
}
string toStr(int x){
	stringstream ss; 
	ss << x; 
	return ss.str(); 
}
int main(){
	int n,k; 
	cin >> n >> k;  
	if (pow(10,k) > n){	
		cout << digitLen(n)-1 << endl; 
	}else{
		int ans = 0,z = 0; // z: number of zeroes seen so far
		string s = toStr(n);  
		bool done = false;  
		for (int i = s.size()-1; i >= 0; i--){
			if (z == k){
				// we have found enough zeroes 
				done = true; 
				cout << ans << endl; 
				break; 
			}
			if (s[i] == '0') z++; 
			else ans++; 
		}
		if (!done){
			cout << s.size()-1 << endl; 
		}
	}
	return 0;  
}
