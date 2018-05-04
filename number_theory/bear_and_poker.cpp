#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector> 
#include <map> 
using namespace std; 
typedef long long ll; 
ll a[100005]; 
int main(){
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i];  
		while (a[i]%2 == 0){
			a[i] /= 2; 
		}
		while (a[i]%3 == 0){
			a[i] /= 3; 
		}
	}
	for (int i = 0; i < n-1; i++){
		if (a[i] != a[i+1]){
			cout << "NO" << endl; 
			return 0; 
		}
	}
	cout << "YES" << endl; 
	return 0; 
}
