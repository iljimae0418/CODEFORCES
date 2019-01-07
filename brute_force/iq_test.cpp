#include <iostream>
#include <cstdlib>
#include <vector> 
using namespace std; 
int a[111]; 
int main(){
	int n, odd = 0, even = 0;
	vector<int> o,e;   
	cin >> n; 
	for (int i = 1; i <= n; i++){
		cin >> a[i]; 
		if (a[i]&1){
			odd++; 
			o.push_back(i); 
		}else{
			even++;
			e.push_back(i); 
		} 
 	}
 	cout << (odd == 1 ? o[0] : e[0]) << endl;
 	return 0; 
}
