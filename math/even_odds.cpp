#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;  
int main(int argc,char **argv){
	ll n,k; 
	cin >> n >> k; 
	if (n%2 == 0){
		if (k <= n/2){
			// we get kth odd number
			cout << 2LL*k - 1LL << endl; 
		}else if (k > n/2){
			// get (k-n/2)th even number  
			cout << 2LL*(k-n/2) << endl; 
		}
	}else{
		if (k <= (n+1)/2){
			cout << 2LL*k - 1LL << endl; 
		}else if (k > (n+1)/2){
			cout << 2LL*(k-(n+1)/2) << endl; 
		}
	}
	return 0;  
}
