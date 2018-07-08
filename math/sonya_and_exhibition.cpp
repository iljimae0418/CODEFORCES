#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std;
typedef pair<int,int> P;  
int main(){
	int n,m,l,r;
	cin >> n >> m; 
	for (int i = 0; i < m; i++){
		cin >> l >> r;  
	}
	string s;  
	for (int i = 0; i < n; i++){
		if (i%2 == 0) s += '1';  
		else s += '0'; 
	}
	cout << s << endl; 
	return 0; 	
}
