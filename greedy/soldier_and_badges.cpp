#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map> 
#include <vector> 
using namespace std; 
void print(map<int,int> &mp, int x,int n){
	cout << "Trial " << x << ":" << endl; 
	for (int i = 1; i <= n; i++){
		cout << i << ": " << mp[i] << endl;  
	}
}
int main(){
	int n; 
	cin >> n; 
	map<int,int> mp; 
	for (int i = 0; i < n; i++){
		int x; 
		cin >> x; 
		mp[x]++; 
	}
	int cnt = 0;  
	for (int i = 1; i <= n; i++){
		if (mp[i] >= 2 && i < n){
			mp[i+1] += (mp[i]-1);  
			cnt += (mp[i]-1);  
			mp[i] = 1;  
		}
	}
	cnt += (mp[n]-1)*(mp[n])/2;  
	cout << cnt << endl; 
	return 0; 
}
