#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std; 
int main(){
	int n,cnt = 0; 
	cin >> n; 
	for (int i = 1; i <= n; i++){
		int x = i;  
		map<int,int> mp; 
		for (int j = 2; j*j <= x; j++){
			while (x%j == 0){
				mp[j]++;  
				x /= j; 
			}
		}
		if (x != 1) mp[x]++; 
		if (mp.size() == 2) cnt++; 
	}
	cout << cnt << endl; 
	return 0;  
}
