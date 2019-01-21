#include <iostream>
#include <algorithm> 
#include <map> 
#include <set> 
#include <vector> 
using namespace std; 
int a[101]; 
int main(){
	map<int,int> mp; 
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
		mp[a[i]]++; 
	}
	vector<int> v;   
	for (int i = 0; i < n; i++){
		if (mp[a[i]] == 1) v.push_back(a[i]); 
	}
	if (v.size() == n && n%2 == 1){
		cout << "NO" << endl; 
	}else{
		set<int> A,B;  
		for (int i = 0; i < v.size()/2; i++){
			A.insert(v[i]); 
		}
		for (int i = v.size()/2; i < v.size(); i++){
			B.insert(v[i]); 
		}
		if (A.size() == B.size()){
			cout << "YES" << endl; 
			for (int i = 0; i < n; i++){
				if (B.count(a[i])){
					cout << "B"; 
				}else{
					cout << "A"; 
				}
			}
			cout << endl; 
		}else{
			bool put = false; 
			int pivot = -1;  
			for (int i = 0; i < n; i++){
				if (mp[a[i]] > 2){
					pivot = a[i]; 
					break; 
				}
			}
			if (pivot == -1){
				cout << "NO" << endl; 
				return 0; 
			}
			cout << "YES" << endl; 
			if (A.size() < B.size()){	
				for (int i = 0; i < n; i++){
					if (a[i] == pivot && !put){
						cout << "A"; 
						put = true;	
					}else if (A.count(a[i])){
						cout << "A"; 
					}else{
						cout << "B"; 
					}
				}
			}else if (A.size() > B.size()){
				for (int i = 0; i < n; i++){
					if (a[i] == pivot && !put){
						cout << "B"; 
						put = true; 
					}else if (B.count(a[i])){
						cout << "B"; 
					}else{
						cout << "A"; 
					}
				}
			}
			cout << endl; 
		}
	}
	return 0; 
}
