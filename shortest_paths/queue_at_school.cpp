#include <iostream>
#include <vector> 
using namespace std; 

int main(){
	int n,t; 
	cin >> n >> t; 
	string s; 
	cin >> s;  
	while (t--){
		vector<int> sidx;  
		for (int i = 0; i < s.size()-1; i++){
			if (s[i] == 'B' && s[i+1] == 'G'){
				sidx.push_back(i);  
			}
		}
		for (int i = 0; i < sidx.size(); i++){
			swap(s[sidx[i]],s[sidx[i]+1]); 
		}
	}
	cout << s << endl; 
	return 0; 
}
