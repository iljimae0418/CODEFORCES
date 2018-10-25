#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;  
int a[3][3];  
int main(){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			cin >> a[i][j]; 
		}
	}
	if (a[0][0] == 0 && a[1][1] == 0 && a[2][2] == 0){
		int x1 = (2*a[2][0]+a[2][1]-a[0][1])/2;  
		int x3 = a[0][2]+a[2][0]-x1;  
		int x2 = a[0][1]+a[0][2]+x1-a[0][1]-a[2][1];
		a[0][0] = x1; 
		a[1][1] = x2; 
		a[2][2] = x3;    
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				cout << a[i][j] << " ";  
			}
			cout << endl; 
		}
	}else if (a[0][2] == 0 && a[1][1] == 0 && a[2][0] == 0){
		int x1 = (2*a[2][2]+a[2][1]-a[0][1])/2;
		int x3 = a[0][0]+a[2][2]-x1;  
		int x2 = a[0][0]+a[0][1]+x1-a[1][0]-a[1][2]; 
		a[0][2] = x1; 
		a[1][1] = x2; 
		a[2][0] = x3; 
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				cout << a[i][j] << " "; 
			}
			cout << endl; 
		}  
	}
	return 0;  
}
