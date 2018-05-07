// O(n^2) solution
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std; 
int main(){
	string a,b; 
	cin >> a >> b; 	
	vector<string> v; 
	for (int i = 1; i <= a.size(); i++){
		for (int j = 1; j <= b.size(); j++){
			string s1 = a.substr(0,i); 
			string s2 = b.substr(0,j); 
			string s = s1+s2; 
			v.push_back(s); 
		}
	}
	sort(v.begin(),v.end()); 
	cout << v[0] << endl;
	return 0;  
}
