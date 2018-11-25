#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
typedef long long ll;  
ll n,m; // rows, columns 
bool overlap(ll x1,ll y1,ll x2,ll y2,
	ll x3,ll y3,ll x4,ll y4){
	if (x2 < x3 || x1 > x4) return false; 
	if (y2 < y3 || y1 > y4) return false; 
	return true; 
}
ll mceil(ll x,ll y){
	return (x+y-1LL)/y;  
}
ll mfloor(ll x,ll y){
	return (x/y); 
}
ll w(ll a,ll b){
	return mceil(a,2LL)*mceil(b,2LL) + mfloor(a,2LL)*mfloor(b,2LL);  
}
ll W(ll x1,ll y1,ll x2,ll y2){
	return w(x2,y2)-w(x1-1LL,y2)-w(x2,y1-1LL)+w(x1-1LL,y1-1LL); 
}
ll B(ll x1,ll y1,ll x2,ll y2){
	return (y2-y1+1LL)*(x2-x1+1LL)-W(x1,y1,x2,y2); 
}
int main(){
	IOFAST(); 
	int t; 
	cin >> t;
	while (t--){
		cin >> n >> m; 
		ll x1,y1,x2,y2;  
		ll x3,y3,x4,y4; 
		cin >> x1 >> y1 >> x2 >> y2; 
		cin >> x3 >> y3 >> x4 >> y4; 
		ll white = W(1,1,m,n); 
		ll black = B(1,1,m,n);  
		// first draw white rectangle 
		white += B(x1,y1,x2,y2); 
		black -= B(x1,y1,x2,y2);  
		// next draw black rectangle  
		white -= W(x3,y3,x4,y4); 
		black += W(x3,y3,x4,y4); 
		// consider overlap 
		if (overlap(x1,y1,x2,y2,x3,y3,x4,y4)){
			white -= B(max(x1,x3),max(y1,y3),min(x2,x4),min(y2,y4));  
			black += B(max(x1,x3),max(y1,y3),min(x2,x4),min(y2,y4)); 
		}
		cout << white << " " << black << "\n"; 
	}
	return 0; 
}
