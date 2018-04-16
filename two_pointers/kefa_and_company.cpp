#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
struct info{ int m,s; };  
bool cmp(info &i1,info &i2){
	return i1.m < i2.m;  
}
info a[100005]; 
int main(){
	int n,d; 
	cin >> n >> d; 
	for (int i = 0; i < n; i++){
		cin >> a[i].m >> a[i].s; 
	}
	sort(a,a+n,cmp); 
	long long ans = -2e17; 
	long long sum = 0; 
	int i = 0, j = 0; 
	while (i < n && j < n){
		if (a[j].m-a[i].m < d){
			sum += a[j].s;  
			j++; 
		}else{
			ans = max(ans,sum);  
			sum -= a[i].s; 
			i++; 
		}
	}
	ans = max(ans,sum); 
	cout << ans << endl;
	return 0;  
}
