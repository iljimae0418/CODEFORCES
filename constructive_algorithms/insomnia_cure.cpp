#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std; 
int attack[4]; 
int dragons[100005]; 
int main(){
	for (int i = 0; i < 4; i++){
		cin >> attack[i]; 
	}
	int d; 
	cin >> d;  
	for (int i = 0; i < 4; i++){
		for (int j = attack[i]; j <= d; j += attack[i]){
			dragons[j] = 1; 
		}
	}
	int cnt = 0; 
	for (int i = 1; i <= d; i++){
		cnt += dragons[i]; 
	}
	cout << cnt << endl;
	return 0; 
}
