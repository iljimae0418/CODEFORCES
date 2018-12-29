#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring> 
#include <cmath> 
using namespace std; 
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
int main(int argc,char **argv){
	IOFAST(); 
	typedef long long ll; 
	ll a,m; 
	cin >> a >> m; 
	ll mult = 0;  
	ll cnt = 0;  
	while (cnt < 500){
		a += (a%m);  
		mult += (a%m);  
		if (a%m == 0){
			cout << "Yes" << endl; 
			return 0; 
		}
		if (mult%m == 0){
			cout << "No" << endl; 
			return 0; 
		}
		cnt++; 
	}
	cout << "No" << endl; 
	return 0; 
}
