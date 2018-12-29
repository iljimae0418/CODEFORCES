#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <set> 
#include <sstream> 
using namespace std; 
const int MAX = 2e9;  
int toInt(string s){
	if (s[0] == '0') return -1; // ignore leading zero
	int n;  
	istringstream iss (s); 
	iss >> n; 
	return n;  
}
int main(){
	set<int> sq; 
	for (int i = 1; i*i <= MAX; i++){
		sq.insert(i*i); 
	}
	string s; 
	cin >> s;  
	int x = s.size(); 
	int minCnt = 12345;  
	for (int i = 1; i < (1<<x); i++){
		int cnt = 0; 
		string t = ""; 
		for (int j = 0; j < x; j++){
			if (i & (1<<j)){
				t += s[j]; 
				cnt++; 
			}
		}
		int k = toInt(t); 
		if (sq.count(k)){
			minCnt = min(minCnt,x-cnt); 
		}
	}
	cout << (minCnt == 12345 ? -1 : minCnt) << endl; 
	return 0; 
}	
