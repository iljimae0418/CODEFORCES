#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int main(){
	int k,n,w; 
	cin >> k >> n >> w;  
	int need = k*w*(w+1)/2;  
	if (need <= n){
		cout << 0 << endl; 
	}else{
		cout << need-n << endl; 
	}
	return 0; 
}
