#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std; 
bool islucky(int x){
	while (x){
		if ((x%10) == 4 || (x%10) == 7) x /= 10; 
		else return false; 
	}
	return true;  
}
int main(){
	int n; 
	cin >> n; 
	if (islucky(n)){
		cout << "YES" << endl; 
		return 0;  
	}
	vector<int> factors; 
	for (int i = 1; i*i <= n; i++){
		if (n%i == 0){
			if (i == n/i){
				factors.push_back(i);  
			}else{
				factors.push_back(i); 
				factors.push_back(n/i);  
			}
		}
	}
	bool passed = false;  
	for (int i = 0; i < factors.size(); i++){
		if (islucky(factors[i])){
			passed = true; 
			break; 
		}
	}
	if (passed) cout << "YES" << endl;
	else cout << "NO" << endl;  
	return 0;  
}
