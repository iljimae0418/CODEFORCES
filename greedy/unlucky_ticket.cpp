#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;  
bool all_less(vector<int> &a,vector<int> &b){
	// all elements of a strictly less than all elements of b?  
	for (int i = 0; i < a.size(); i++){
		if (a[i] >= b[i]) return false;  
	}
	return true; 
}
bool all_greater(vector<int> &a,vector<int> &b){
	// all elements of a strictly greater than all elements of b? 
	for (int i = 0; i < b.size(); i++){
		if (a[i] <= b[i]) return false; 
	}
	return true; 
}
int main(){
	int n; 
	cin >> n; 
	vector<int> a(n),b(n); 
	char c; // for input 
	for (int i = 0; i < n; i++){
		cin >> c; 
		a[i] = c-'0';   
	}
	for (int i = 0; i < n; i++){
		cin >> c; 
		b[i] = c-'0'; 
	}
	sort(a.begin(),a.end()); 
	sort(b.begin(),b.end()); 
	if (all_less(a,b) || all_greater(a,b)){
		cout << "YES" << endl; 
	}else{
		cout << "NO" << endl; 
	}
	return 0; 
}
