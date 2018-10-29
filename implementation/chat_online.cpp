#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;  
int possible[1005];  
int a[55],b[55],c[55],d[55]; 
bool overlap(int u1,int u2,int v1,int v2){
	if (u1 <= v1 && v2 <= u2) return true; 
	if (v1 <= u1 && u2 <= v2) return true; 
	if (u2 == v1 || u1 == v2) return true;  
	if (u1 >= v1 && u1 <= v2) return true; 
	if (u2 >= v1 && u2 <= v2) return true; 
	if (v1 >= u1 && v1 <= u2) return true; 
	if (v2 >= u1 && v2 <= u2) return true; 
	return false;  
}
int main(){
	int p,q,l,r; 
	cin >> p >> q >> l >> r;  
	for (int i = 0; i < p; i++){
		cin >> a[i] >> b[i]; 
	}
	for (int i = 0; i < q; i++){
		cin >> c[i] >> d[i];  
	}
	for (int t = l; t <= r; t++){
		for (int i = 0; i < q; i++){
			for (int j = 0; j < p; j++){
				if (overlap(c[i]+t,d[i]+t,a[j],b[j])){
					possible[t] = 1; 
				}
			}
		}
	}
	int cnt = 0; 
	for (int i = l; i <= r; i++){
		cnt += possible[i]; 
	}
	cout << cnt << endl; 
	return 0; 
}
