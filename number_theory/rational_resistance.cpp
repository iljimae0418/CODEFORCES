#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
typedef long long ll;  
int main(){
	ll a,b,ans = 0; 
	cin >> a >> b; 
	while (b){
		ans += a/b; 
		a %= b; 
		swap(a,b);  
	}
	cout << ans << endl; 
	return 0; 
}
