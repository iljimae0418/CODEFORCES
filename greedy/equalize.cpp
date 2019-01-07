#include <iostream>
#include <cstdlib>
using namespace std; 
int main(){
	int n,cost = 0; 
	cin >> n; 
	string a,b; 
	cin >> a >> b;  
	for (int i = 0; i < n; i++){
		if (a[i] != b[i]){
			if (i+1 < n && a[i] == b[i+1] && 
				a[i+1] == b[i]){
				a[i] = b[i];  
				a[i+1] = b[i+1]; 
				cost++; 
			}else{
				a[i] = b[i]; 
				cost++;  
			}
		}
	}
	cout << cost << "\n";
	return 0;  
}
