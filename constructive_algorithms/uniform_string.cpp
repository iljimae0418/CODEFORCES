#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector> 
using namespace std;  
int main(){
	int t; 
	cin >> t;  
	while (t--){
		int n,k; 
		cin >> n >> k;  
		string s;  
		char c = 'a'; 
		vector<char> v;  
		for (int i = 1; i <= k; i++){
			v.push_back(c);  
			s += string(1,c); 
			c++;  
		}
		int idx = 0;  
		for (int i = k+1; i <= n; i++){
			s += string(1,v[idx]);  
			idx = (idx+1)%v.size();  
		}
		cout << s << endl; 
	}
	return 0; 
}
