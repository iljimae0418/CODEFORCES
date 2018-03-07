#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std; 
struct info{
	int q,p;  
	info(){} 
	info(int _q,int _p): q(_q),p(_p){}
};  
info a[100005]; 
int main(){
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i].q >> a[i].p;  
	}
	int idx = 0, cost = 0; 
	while (idx < n){
		int p = a[idx].p;  
		int tot = a[idx].q;  
		while (idx+1 < n && p <= a[idx+1].p){
			tot += a[idx+1].q; 
			idx++;  
		}
		cost += (tot*p); 
		idx++;   
	}
	cout << cost << endl; 
	return 0; 
}
