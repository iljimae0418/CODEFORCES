#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <map> 
#include <set> 
using namespace std; 
int a[100001];  
int main(){
	int n,x; 
	cin >> n >> x;	
	set<int> s;  
	map<int,set<int> > k;   
	for (int i = 0; i < n; i++){
		cin >> a[i];  
		s.insert(a[i]);  
		k[a[i]].insert(i); 
	}
	if (s.size() < n){
		cout << 0 << endl; 
		return 0; 
	}
	for (int i = 0; i < n; i++){
		if (k.count(a[i]&x) && ((k[a[i]&x].count(i) && k[a[i]&x].size() > 1) || !k[a[i]&x].count(i))){
			cout << 1 << endl;
			return 0;  
		}
	}	
	s.clear(); 
	for (int i = 0; i < n; i++){
		a[i] &= x; 
		s.insert(a[i]);  
	}
	if (s.size() == n) cout << -1 << endl; 
	else cout << 2 << endl; 
	return 0; 
}
