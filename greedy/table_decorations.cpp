#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
typedef long long ll; 
ll a[3]; 
int main(){
	cin >> a[0] >> a[1] >> a[2]; 
	sort(a,a+3); 
	if (a[0]+a[1] <= a[2]/2LL){
		cout << a[0]+a[1] << endl; 
	}else{
		cout << (a[0]+a[1]+a[2])/3 << endl; 
	}
	return 0; 
}
