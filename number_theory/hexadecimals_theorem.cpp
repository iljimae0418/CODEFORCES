#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std; 
typedef long long ll;  
int main(){
	ll n; 
	cin >> n; 
	vector<ll> v; 
	ll a = 0LL, b = 1LL; 
	v.push_back(a); 
	v.push_back(b); 
	while (a+b <= n){
		ll temp = b; 
		b = a+b;  
		a = temp; 
		v.push_back(b);  
	}
	for (int i = 0; i < v.size(); i++){
		for (int j = 0; j < v.size(); j++){
			for (int k = 0; k < v.size(); k++){
				if (v[i]+v[j]+v[k] == n){
					cout << v[i] << " " << v[j] << " " << v[k] << endl; 
					return 0; 
				}
			}
		}
	}
	cout << "I'm too stupid to solve this problem" << endl; 
	return 0; 
}
