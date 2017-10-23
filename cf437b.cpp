// basically, we have to set N to some value
// then we have to list M denominations that could make M 
// using A different ways. 
// solution: let N = 2*A-1. Then let there be only 2 denominations, 
// {1,2}. This way, there are A ways of choosing 2 (we can have 0 2s, 1 2s,..,(A-1) 2s)
// and the rest would be all 1s. 
#include <iostream>
#include <cstdlib>
using namespace std;  
int main(){
	int A; 
	cin >> A; 
	int N = 2*A-1; 
	int M = 2;  
	cout << N << " " << M << endl; 
	cout << 1 << " " << 2 << endl; 
	return 0;  
}  
