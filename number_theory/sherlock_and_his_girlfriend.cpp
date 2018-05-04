#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std; 
typedef long long ll; 
int prime[100005]; 
int main(){
	int n; 
	cin >> n; 
	if (n <= 2){
		cout << 1 << endl;
		for (int i = 2; i <= n+1; i++){
			cout << 1 << " "; 
		}
		cout << endl; 
		return 0;  
	}
	for (int i = 0; i < 100005; i++){
		prime[i] = 1; 
	}
	prime[1] = 0; 
	for (ll i = 2; i <= (ll)n+1; i++){
		if (prime[i]){
			for (ll j = i*i; j <= (ll)n+1; j += i){
				prime[j] = 0; 
			}
		}
	}
	cout << 2 << endl; 
	for (int i = 2; i <= n+1; i++){
		if (prime[i]) cout << 1 << " ";
		else cout << 2 << " "; 
	}
	cout << endl;
	return 0; 
}
