#include <iostream>
#include <cstdlib>
#include <vector> 
#include <algorithm>
using namespace std; 
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
int main(){
	IOFAST(); 
	string s; 
	cin >> s; 	
	vector<int> v; 
	for (int i = 0; i < s.size(); i++){
		if (s[i] != '+'){
			v.push_back(s[i]-'0');  
		}
	}
	sort(v.begin(),v.end());  
	for (int i = 0; i < v.size(); i++){
		if (i == v.size()-1){
			cout << v[i] << endl; 
		}else{
			cout << v[i] << "+";  
		}
	}
	return 0;  
}
