#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
struct info{
	int beforesale; 
	int aftersale; 
}; 
info a[200005]; 
bool cmp(info &i1,info &i2){
	return i1.beforesale-i1.aftersale < i2.beforesale-i2.aftersale;  
}
int main(){
	int n,k,total = 0; 
	cin >> n >> k; 
	for (int i = 0; i < n; i++){
		cin >> a[i].beforesale; 
	}
	for (int i = 0; i < n; i++){
		cin >> a[i].aftersale; 
	}
	sort(a,a+n,cmp); 
	for (int i = 0, x = 0; i < n; i++){
		if (a[i].beforesale-a[i].aftersale < 0){
			// we must buy this before sale 
			total += a[i].beforesale;
			x++;   
		}else if (x >= k && a[i].beforesale-a[i].aftersale > 0){
			// we should buy this after sale 
			total += a[i].aftersale;  
		}else{
			// buy before sale price 
			total += a[i].beforesale;  
			x++;  
		}
	}
	cout << total << endl; 
	return 0; 
}
