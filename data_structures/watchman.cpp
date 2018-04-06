#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map> 
using namespace std;  
typedef pair<int,int> P; 
P a[200005]; 
int main(){
	int n; 
	cin >> n; 
	map<int,int> mpx,mpy;
	map<P,int> mpp;    
	for (int i = 0; i < n; i++){
		int x,y; 
		cin >> x >> y; 
		mpx[x]++; 
		mpy[y]++; 
		mpp[P(x,y)]++;  
	}
	int ans = 0; 
	for (map<int,int>::iterator it = mpx.begin(); it != mpx.end(); it++){
		if (it->second >= 2) ans += (it->second)*(it->second - 1)/2;  
	}
	for (map<int,int>::iterator it = mpy.begin(); it != mpy.end(); it++){
		if (it->second >= 2) ans += (it->second)*(it->second - 1)/2; 
	}
	for (map<P,int>::iterator it = mpp.begin(); it != mpp.end(); it++){
		if (it->second > 1) ans -= (it->second)*(it->second - 1)/2;  
	}
	cout << ans << endl; 
	return 0;  
}
