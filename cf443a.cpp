// simple greedy method 
#include <iostream>
#include <cstdlib>
#include <vector> 
#include <set> 
#include <algorithm> 
using namespace std; 
int main(){
	int n; 
	cin >> n; 
	vector< pair<int,int> > v; 
	for (int i = 0; i < n; i++){
		int s,d; 
		cin >> s >> d; 
		v.push_back(make_pair(s,d)); 
	}
	// has to visit in the prescribed order 
	int cur = v[0].first;  
	for (int i = 1; i < n; i++){
		for (int k = 0;;k++){
			if (v[i].first+k*v[i].second > cur){
				cur = v[i].first + k*v[i].second; 
				break; 
			}
		}
	}
	cout << cur << endl; 
	return 0; 
}
