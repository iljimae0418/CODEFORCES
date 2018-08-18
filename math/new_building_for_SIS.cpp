#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int main(){
	int n,h,a,b,k; 
	cin >> n >> h >> a >> b >> k;  
	while (k--){
		int ta,fa,tb,fb,t = 0;
		cin >> ta >> fa >> tb >> fb; 
		if (tb < ta){
			swap(ta,tb);  
			swap(fa,fb);  
		}
		if (ta == tb){
			t += abs(fa-fb); 
		}else if (fa < a){
			t += a-fa; 
			t += tb-ta;  
			t += abs(fb-a); 
		}else if (fa > b){
			t += fa-b; 
			t += tb-ta;  
			t += abs(fb-b);  
		}else{	
			t += tb-ta;  
			t += abs(fb-fa);  
		}
		cout << t << endl; 
	}
	return 0;  
}
