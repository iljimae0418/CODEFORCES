#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std; 
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
typedef long long ll;  
const ll INF = 1e9+88;  
int a[1001]; 
int psum[1001];  
int main(){
	int n,w; 
	cin >> n >> w;  
	for (int i = 1; i <= n; i++){
		cin >> a[i]; 
	}
	for (int i = 1; i <= n; i++){
		if (a[i] > w){
			cout << 0 << endl; 
			return 0; 
		}
	}
	int minval = INF, maxval = -INF;  
	for (int i = 1; i <= n; i++){
		psum[i] = psum[i-1]+a[i]; 
		minval = min(minval,psum[i]); 
		maxval = max(maxval,psum[i]);  
	}
	if (abs(minval) > w || abs(maxval) > w){
		cout << 0 << endl;
		return 0;  
	}
	int l = -1, r = -1; 
	if (minval >= 0 && maxval >= 0){
		l = 0, r = w-maxval;  
	}else if (minval < 0 && maxval >= 0){
		l = -minval, r = w-maxval; 
	}else if (minval < 0 && maxval < 0){
		l = -minval, r = w; 
	}
	int ans = r-l+1;  
	if (ans < 0) cout << 0 << endl; 
	else cout << ans << endl; 
	return 0; 
}
