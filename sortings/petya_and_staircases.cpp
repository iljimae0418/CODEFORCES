#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;  
int d[3333];  
int main(){
	int n,m; 
	cin >> n >> m; 
	for (int i = 0; i < m; i++){
		cin >> d[i]; 
	}
	sort(d,d+m); 
	if (d[0] == 1 || d[m-1] == n){
		cout << "NO" << endl; 
	}else{
		for (int i = 0; i < m-2; i++){
			if (d[i+1] == d[i]+1 && d[i+2] == d[i]+2){
				cout << "NO" << endl; 
				return 0; 
			}
		}
		cout << "YES" << endl; 
	}
	return 0;  
}
