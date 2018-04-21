#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map> 
using namespace std; 
bool inRange(int n,int x){
	return x >= 1 && x <= n; 
}
int main(){	
	int n,x; 
	cin >> n >> x; 
	// prime factorize k 
	int cnt = 0, same = 0; 
	for (int i = 1; i*i <= x; i++){
		if (x%i == 0){
			if (inRange(n,i) && inRange(n,x/i)){
				cnt++;  
				if (i == x/i) same++; 
			}
		}
	}
	cout << 2*cnt-same << endl;
	return 0; 
}
