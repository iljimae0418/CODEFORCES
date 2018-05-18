#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std; 
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
struct info{
	int first,second,idx;  
	info(){} 
}; 
info a[300005]; 
bool cmp(info &i1,info &i2){
	return ((i1.first < i2.first) || (i1.first == i2.first && i1.second > i2.second)); 
}
int main(){
	IOFAST(); 
	int n; 
	cin >> n; 
	for (int i = 1; i <= n; i++){
		cin >> a[i].first >> a[i].second; 
		a[i].idx = i;  
	}
	sort(a+1,a+n+1,cmp); 
	int maxRight = a[1].first, idx = 1;  
	bool found = false;  
	for (int i = 2; i <= n; i++){
		if (a[i].first >= a[idx].first && a[i].second <= a[idx].second){
			found = true; 
			// a[i].idx is enclosed by a[idx].idx 
			cout << a[i].idx << " " << a[idx].idx << endl; 
			break; 
		}else if (a[i].second > maxRight){
			maxRight = a[i].second; 
			idx = i; 
		}
	}
	if (!found) cout << -1 << " " << -1 << endl; 
	return 0; 
}
