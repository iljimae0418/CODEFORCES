#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int x[101];  
int main(){
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> x[i];  
	}
	sort(x,x+n); 
	int cnt = 1; 
	for (int i = 1; i < n; i++){
		if (i/cnt > x[i]) cnt++;  
	}
	cout << cnt << endl;
	return 0; 
}
