#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map> 
using namespace std; 
int main(){
	int n,k,tot = 0,cpy; 
	cin >> n >> k; 
	cpy = n;  
	map<int,int> f; 
	for (int i = 2; i*i <= n; i++){
		while (n%i == 0){
			n /= i;  
			f[i]++; 
		}
		tot += f[i];  
	}
	if (n != 1){
		f[n]++;  
		tot++;  
	} 
	if (k > tot) cout << -1 << endl; 
	else if (k == tot){
		for (map<int,int>::iterator it = f.begin(); it != f.end(); it++){
			for (int j = 0; j < it->second; j++){
				cout << it->first << " "; 
			}
		}
		cout << endl; 
	}else if (k < tot){
		int prod = 1; 
		for (map<int,int>::iterator it = f.begin(); it != f.end(); it++){
			if (k == 1) break; 
			for (int j = 0; j < min(it->second,k-1); j++){
				prod *= it->first; 
				cout << it->first << " ";  
			}
			k -= min(it->second,k-1);  
		}
		cout << cpy/prod << endl; 
	}
	return 0; 
}
