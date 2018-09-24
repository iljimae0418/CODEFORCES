#include <iostream>
#include <cstdlib>
#include <map>
using namespace std;  
int main(){
	int n,cnt=0; 
	cin >> n; 
	for (int i = 0; i< n; i++){
		int x; 
		cin >> x;  
		if (x == 1) cnt++; 
	}
	if (cnt > 0) cout << "HARD" << endl; 
	else cout << "EASY" << endl; 
	return 0;  
}
