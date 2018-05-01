#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std; 
const int INF = 2e9;  
int a[101],b[101]; 
int main(){
	int n,m; 
	cin >> n >> m; 
	int lb = -1,ub = INF;  
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
	}
	sort(a,a+n); 
	lb = max(2*a[0],a[n-1]); 
	for (int i = 0; i < m; i++){
		cin >> b[i];
		ub = min(ub,b[i]);   
	}
	if (lb < ub){
		cout << lb << endl; 
	}else{
		cout << -1 << endl; 
	}
	return 0; 
}
