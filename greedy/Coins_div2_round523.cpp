#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set> 
using namespace std; 
int main(){
	int n,S; 
	cin >> n >> S; 
	if (S%n == 0){
		cout << S/n << endl; 
	}else{
		cout << S/n + 1 << endl; 
	}
	return 0; 
}
