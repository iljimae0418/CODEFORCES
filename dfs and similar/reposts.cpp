#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map> 
#include <set> 
using namespace std; 
set<string> visited; 
map<string,vector<string> > mp; 
string tolowercase(string &t){
	for (int i = 0; i < t.size(); i++){
		t[i] |= (1<<5); 
	}
	return t;  
}
int len(string name){
	if (mp[name].empty()) return 1;  
	int ret = -99999999;  
	for (int i = 0; i < mp[name].size(); i++){
		if (!visited.count(mp[name][i])){
			visited.insert(mp[name][i]); 
			ret = max(ret,1+len(mp[name][i])); 
		}
	}
	return ret; 
}
int main(){
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		string a,b,c; 
		cin >> a >> b >> c; 
		// draw an edge from c to a 
		c = tolowercase(c); 
		a = tolowercase(a);
		mp[c].push_back(a); 
	}
	int ans = len("polycarp"); 
	cout << ans << endl; 
	return 0; 
}
