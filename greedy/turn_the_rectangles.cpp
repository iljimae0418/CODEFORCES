#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
pair<int,int> a[100005]; 
int b[100005];  
int main(){
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i].first >> a[i].second; 
	}
	int maxval = max(a[0].first,a[0].second); 
	b[0] = maxval; 
	for (int i = 1; i < n; i++){
		if (max(a[i].first,a[i].second) <= b[i-1]){
			b[i] = max(a[i].first,a[i].second); 
		}else if (min(a[i].first,a[i].second) <= b[i-1]){
			b[i] = min(a[i].first,a[i].second); 
		}else if (min(a[i].first,a[i].second) > b[i-1]){
			cout << "NO" << endl; 
			return 0;  
		}
	}
	cout << "YES" << endl; 
	return 0; 
}
