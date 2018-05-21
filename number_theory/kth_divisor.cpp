#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm> 
using namespace std; 
int main(){
	long long n,k; 
	cin >> n >> k; 
	vector<long long> factors; 
	for (long long i = 1; i*i <= n; i++){
		if (n%i == 0){
			if (n/i == i) factors.push_back(n/i); 
			else{
				factors.push_back(i); 
				factors.push_back(n/i); 
			}
		}
	}
	sort(factors.begin(),factors.end()); 
	if (factors.size() < k) cout << -1 << endl; 
	else cout << factors[k-1] << endl; 
	return 0; 
}
