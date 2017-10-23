#include <iostream>
#include <cstdlib>
#include <set> 
#include <sstream> 
#include <algorithm>
using namespace std;  
string a[101]; 
string toStr(int i){
	stringstream ss; 
	ss << i; 
	return ss.str();  
}
int main(){
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
	}
	for (int i = 0; i <= 100; i++){
		for (int j = 0; j <= 100; j++){
			string P = toStr(i); 
			string V = toStr(j);  
			int Pcnt = 0, Vcnt = 0; 
			for (int k = 0; k < n; k++){
				if (a[k] == P){
					Pcnt++;  
					continue;  
				}
				if (a[k] == V){
					Vcnt++;  
					continue; 
				}
			}
			if (P != V && Pcnt+Vcnt == n && Pcnt == Vcnt){
				cout << "YES" << endl; 
				cout << P << " " << V << endl; 
				return 0;  
			}
		}
	}
	cout << "NO" << endl;
	return 0; 
}
