#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map> 
#include <vector>
#include <set> 
using namespace std; 
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
int main(){
	IOFAST(); 
	int n; 
	cin >> n; 
	map<string,int> mp; 
	set<string> db;
	string s;   
	for (int i = 0; i < n; i++){
		cin >> s; 
		if (!db.count(s)){
			db.insert(s); 
			cout << "OK" << endl; 
		}else{
			int append = ++mp[s]; 
			string t = ""; 
			while (append){
				t += char(append%10 + '0');  
				append /= 10;  
			}
			reverse(t.begin(),t.end());  
			s = s+t;  
			cout << s << endl; 
			db.insert(s);  
		}
	}
	return 0;  
}
