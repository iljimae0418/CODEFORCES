#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <map> 
#include <vector> 
using namespace std; 
int a[120005];  
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	int n; 
	cin >> n; 
	map<int,int> f; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
		f[a[i]]++; 
	}
	vector<int> d; 
	int x = 1;  
	for (int i = 1; i <= 30; i++){
		d.push_back(x*2); 
		x *= 2;  
	}
	int cnt = 0;  
	for (int i = 0; i < n; i++){
		bool good = false; 
		for (int j = 0; j < d.size(); j++){
			if (f.count(d[j]-a[i])){
				if (d[j]-a[i] != a[i]) good = true;  
				else if (d[j]-a[i] == a[i] && f[a[i]] > 1) good = true; 
			}
		}
		if (!good) cnt++;  
	}
	cout << cnt << endl; 
	return 0; 
}
