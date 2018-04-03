#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std; 
bool ok(int x){
	int sum = 0;  
	while (x){
		sum += (x%10); 
		x /= 10; 
	}
	return sum == 10; 
}
int main(){
	int k; 
	cin >> k; 
	for (int i = 0,cnt = 0;; i++){
		if (ok(i)){
			cnt++; 
		}  
		if (cnt == k){
			cout << i << endl;
			break; 
		}
	}
	return 0; 
}	
