#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <vector> 
using namespace std; 

int main(){
	int n; 
	string s; 
	cin >> n; 
	cin >> s;  
	vector<int> d; 
	for (int i = 1; i*i <= n; i++){
		if (n%i == 0){
			if (n/i == i){
				d.push_back(n/i); 
			}else{
				d.push_back(n/i); 
				d.push_back(i); 
			}
		}
	}
	sort(d.begin(),d.end());  
	// iterate from 1 to n 
	for (int i = 0; i < d.size(); i++){
		int x = d[i]; 
		reverse(s.begin(),s.begin()+x); 
	}
	cout << s << endl; 
	return 0;  
}
