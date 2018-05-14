#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std; 
int a[100005]; 
int main(){
	int n,n1,n2; 
	cin >> n >> n1 >> n2; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
	}
	sort(a,a+n); 
	int i = 0; 
	if (n1 < n2){
		vector<int> v1,v2; 
		for (i = n-1; i > (n-1)-n1; i--){
			v1.push_back(a[i]); 
		}
		for (i = (n-1)-n1; i > (n-1)-n1-n2; i--){
			v2.push_back(a[i]);  
		}
		double sum1 = 0, sum2 = 0; 
		for (int j = 0; j < v1.size(); j++){
			sum1 += (double)v1[j]; 
		}
		for (int j = 0; j < v2.size(); j++){
			sum2 += (double)v2[j]; 
		}
		sum1 /= (double)n1; 
		sum2 /= (double)n2; 
		cout.setf(ios::fixed); 
		cout.setf(ios::showpoint);  
		cout.precision(10);  
		cout << sum1+sum2 << endl; 
	}else{
		vector<int> v1,v2; 
		for (i = n-1; i > (n-1)-n2; i--){
			v2.push_back(a[i]); 
		}
		for (i = n-1-n2; i > (n-1)-n2-n1; i--){
			v1.push_back(a[i]); 
		}
		double sum1 = 0, sum2 = 0; 
		for (int j = 0; j < v1.size(); j++){
			sum1 += (double)v1[j]; 
		}
		for (int j = 0; j < v2.size(); j++){
			sum2 += (double)v2[j]; 
		} 
		sum1 /= n1; 
		sum2 /= n2; 
		cout.setf(ios::fixed); 
		cout.setf(ios::showpoint);  
		cout.precision(10);  
		cout << sum1+sum2 << endl; 
	}
	return 0; 
}
