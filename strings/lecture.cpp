#include <iostream>
#include <cstdlib>
#include <map> 
#include <algorithm>
using namespace std; 
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
int main(){
	int n,m; 
	cin >> n >> m; 
	map<string,string> mp; 
	for (int i = 0; i < m; i++){
		string a,b; 
		cin >> a >> b; 
		mp[a] = b;  
 	}
 	for (int i = 0; i < n; i++){
 		string s; 
 		cin >> s;  
 		if (mp[s].size() < s.size()){
 			cout << mp[s] << " "; 
 		}else if (mp[s].size() >= s.size()){
 			cout << s << " "; 
 		}
 	}
 	cout << endl; 
 	return 0;  
}
