#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <vector> 
#include <map> 
using namespace std; 
int a[100005]; 
int main(){
	int n; 
	cin >> n; 
	map<int,int> mp; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
		mp[a[i]]++; 
	}
	int cnt = mp.size(); 
	if (mp.count(0)) cnt--; 
	cout << cnt << endl; 
	return 0; 
}
