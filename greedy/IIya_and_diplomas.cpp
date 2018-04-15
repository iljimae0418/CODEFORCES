#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <vector> 
using namespace std; 
int main(){
	int n; 
	cin >> n; 
	int min1,max1,min2,max2,min3,max3;
	cin >> min1 >> max1 >> min2 >> max2 >> min3 >> max3; 
	vector<int> v; 
	for (int i = max1; i >= min1; i--){
		if (n-i >= min2+min3){
			v.push_back(i); 
			break; 
		}
	}
	n -= v[0]; 
	for (int i = max2; i >= min2; i--){
		if (n-i >= min3){
			v.push_back(i); 
			break; 
		}
	}
	n -= v[1]; 
	for (int i = max3; i >= min3; i--){
		if (n == i){
			v.push_back(i); 
			break; 
		}
	}
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << " "; 
	}
	cout << endl; 
	return 0; 
}
