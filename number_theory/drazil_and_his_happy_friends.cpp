#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int happyb[111];  
int happyg[111]; 
int main(){
	int n,m,b,g,x; 
	cin >> n >> m;  
	cin >> b; 
	for (int i = 0; i < b; i++){
		cin >> x;  
		happyb[x] = 1; 
	}
	cin >> g; 
	for (int i = 0; i < g; i++){
		cin >> x; 
		happyg[x] = 1;  
	}
	int unhappy = n+m-(b+g); 
	int i = 0;  
	while (1){
		/*cout << "DAY " << i << endl; 
		cout << "BOYS" << endl; 
		for (int j = 0; j < n; j++){
			cout << happyb[j] << " ";  
		}
		cout << endl; 
		cout << "GIRLS" << endl; 
		for (int j = 0; j < m; j++){
			cout << happyg[j] << " "; 
		}
		cout << endl; */ 
		if (unhappy <= 0){
			cout << "Yes" << endl;
			return 0; 
		}
		int curb = i%n; 
		int curg = i%m;  
		if (i == 2*n*m){
			cout << "No" << endl; 
			return 0; 
		}
		if (happyb[curb] && !happyg[curg]){
			happyg[curg] = 1; 
			unhappy--; 
		}else if (!happyb[curb] && happyg[curg]){
			happyb[curb] = 1; 
			unhappy--; 
		}
		i++;  
	}
	return 0; 
}
