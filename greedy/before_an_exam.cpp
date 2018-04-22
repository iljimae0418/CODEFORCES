#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <vector> 
#include <numeric> 
using namespace std; 
struct info{int minTime,maxTime;};
info a[50];  
int d,sumTime; 
int main(){
	cin >> d >> sumTime; 
	int sumMin = 0, sumMax = 0;  
	for (int i = 0; i < d; i++){
		cin >> a[i].minTime >> a[i].maxTime;  
		sumMin += a[i].minTime; 
		sumMax += a[i].maxTime; 
  	}
  	if (sumTime >= sumMin && sumTime <= sumMax){
  		cout << "YES" << endl; 
  		int diff = sumMax-sumTime;  
  		vector<int> v(d); 
  		for (int i = 0; i < d; i++){
  			v[i] = a[i].maxTime; 
  		}
  		int i = 0; 
  		while (diff){
  			if (a[i].maxTime-diff >= a[i].minTime){
  				v[i] = a[i].maxTime-diff;  
  				break; 
  			}else{
  				v[i] = a[i].minTime;  
  				diff -= a[i].maxTime-a[i].minTime;  
  			}
  			i++; 
  		}
  		for (int i = 0; i < d; i++){
  			cout << v[i] << " "; 
  		}
  		cout << endl; 
  	}else{
  		cout << "NO" << endl; 
  	}
  	return 0; 
}
