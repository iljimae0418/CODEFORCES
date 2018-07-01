#include <iostream>
#include <algorithm>
using namespace std; 
pair<int,int> a[11]; 
int main(){
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i].first; 
		a[i].second = i;  
	}
	if (n == 1) cout << -1 << endl; 
	else if (n == 2){
		if (a[0].first != a[1].first){
			cout << 1 << endl; 
			cout << a[0].second+1 << endl; 
		}else{
			cout << -1 << endl; 
		}
	}else{
		sort(a,a+n);  
		cout << n-1 << endl; 
		for (int i = 1; i < n; i++){
			cout << a[i].second+1 << " "; 
		}
		cout << endl; 
	}
	return 0; 
}
