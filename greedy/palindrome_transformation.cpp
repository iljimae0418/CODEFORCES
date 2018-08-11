#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring> 
#include <vector> 
#include <set> 
using namespace std; 
#define IOFAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
int main(){
	IOFAST(); 
	int n,p,cnt = 0; 
	cin >> n >> p; 
	string s; 
	cin >> s; 
	p--; // we play with zero based indexing  
	// if p belongs to the first half, just play within the first half 
	// if p belongs to the second half, just play within the second half
	// note that we have to do a bit of branching so that we don't get to do 
	// any unnecessary searches  
	if (p <= s.size()/2-1){
		// checking procedure 
		bool l = true, r = true; 
		int lf = -1, rf = -1;  
		for (int i = p+1; i < s.size()/2; i++){
			if (s[i] != s[s.size()-i-1]){
				r = false; 
				rf = i; 
			}
		}
		for (int i = p; i >= 0; i--){
			if (s[i] != s[s.size()-i-1]){
				l = false;  
				lf = i;   
			}
		}
		// end of checking procedure and calculating cnt 
		if (!l && !r){
			int d1 = p-lf; 
			int d2 = rf-p;  
			if (d1 > d2){
				// go towards s.size()/2-1 then back to 0  
				for (int i = p; i <= rf; i++){
					if (s[i] != s[s.size()-i-1]){
						cnt += min(abs(s[i]-s[s.size()-i-1]),26-abs(s[i]-s[s.size()-i-1])); 
						s[i] = s[s.size()-i-1]; // actual switching 
					}
					if (i < rf) cnt++; // simulate moving right 
				}	
				// we are current at s.size()/2-1. Move back to 0 
				for (int i = rf; i >= lf; i--){
					if (s[i] != s[s.size()-i-1]){
						cnt += min(abs(s[i]-s[s.size()-i-1]),26-abs(s[i]-s[s.size()-i-1])); 
						s[i] = s[s.size()-i-1]; // actual switching 
					}
					if (i > lf) cnt++; // simulate moving left 
				}
			}else if (d1 <= d2){
				// go towards 0 then back to s.size()/2-1 
				for (int i = p; i >= lf; i--){
					if (s[i] != s[s.size()-i-1]){
						cnt += min(abs(s[i]-s[s.size()-i-1]),26-abs(s[i]-s[s.size()-i-1])); 
						s[i] = s[s.size()-i-1]; // actual switching 
					}
					if (i > lf) cnt++; // simulate moving left
				}
				// we are now at 0. We go to s.size()/2-1 
				for (int i = lf; i <= rf; i++){
					if (s[i] != s[s.size()-i-1]){
						cnt += min(abs(s[i]-s[s.size()-i-1]),26-abs(s[i]-s[s.size()-i-1])); 
						s[i] = s[s.size()-i-1]; // actual switching 
					}
					if (i < rf) cnt++; // simulate moving right
				}
			}
		}else if (!l && r){
			// it is unnecessary to look at the right of p 
			for (int i = p; i >= lf; i--){
				if (s[i] != s[s.size()-i-1]){
					cnt += min(abs(s[i]-s[s.size()-i-1]),26-abs(s[i]-s[s.size()-i-1]));  
					s[i] = s[s.size()-i-1]; // actual changing process 
				}
				if (i > lf) cnt++; // simulate moving left  
			}
		}else if (l && !r){
			// it is unnecessary to look at the left of p 
			for (int i = p; i <= rf; i++){
				if (s[i] != s[s.size()-i-1]){
					cnt += min(abs(s[i]-s[s.size()-i-1]),26-abs(s[i]-s[s.size()-i-1]));  
					s[i] = s[s.size()-i-1]; 
				}
				if (i < rf) cnt++; 
			}
		}else if (l && r){
			cnt += 0; // the string is already a palindrome 
		}
	}else if (p >= s.size()/2){ 
		bool l = true, r = true; 
		int lf = -1, rf = -1;  	
		for (int i = p+1; i < s.size(); i++){
			if (s[i] != s[s.size()-i-1]){
				//cout << s[i] << " " << s[s.size()-i-1] << endl; 
				r = false; 
				rf = i;  
			}
		}
		for (int i = p; i >= s.size()/2; i--){
			if (s[i] != s[s.size()-i-1]){
				l = false; 
				lf = i;  
			}
		}
		//cout << l << " " << r << endl; 
		if (!l && !r){
			int d1 = p-lf;  
			int d2 = rf-p;  
			if (d1 > d2){
				// go towards s.size() then back to s.size()/2 
				for (int i = p; i <= rf; i++){
					if (s[i] != s[s.size()-i-1]){
						cnt += min(abs(s[i]-s[s.size()-i-1]),26-abs(s[i]-s[s.size()-i-1]));  
						s[i] = s[s.size()-i-1];  
					}
					if (i < rf) cnt++; // simulate moving right 
				}
				// we are now at s.size()-1. Go back to s.size()/2 
				for (int i = rf; i >= lf; i--){
					if (s[i] != s[s.size()-i-1]){
						cnt += min(abs(s[i]-s[s.size()-i-1]),26-abs(s[i]-s[s.size()-i-1]));  
						s[i] = s[s.size()-i-1]; 
					}
					if (i > lf) cnt++; // simulate moving left 
				}
			}else{
				// go towards s.size()/2 then back to s.size() 
				for (int i = p; i >= lf; i--){
					if (s[i] != s[s.size()-i-1]){
						cnt += min(abs(s[i]-s[s.size()-i-1]),26-abs(s[i]-s[s.size()-i-1])); 
						s[i] = s[s.size()-i-1];  
					}
					if (i > lf) cnt++; // simulate moving left 
				}
				// we are currently at s.size()/2. We have to move to 
				// s.size() 
				for (int i = lf; i <= rf; i++){
					if (s[i] != s[s.size()-i-1]){
						cnt += min(abs(s[i]-s[s.size()-i-1]),26-abs(s[i]-s[s.size()-i-1])); 
						s[i] = s[s.size()-i-1]; 
					}
					if (i < rf) cnt++; // simulate moving right  
				}
			}
		}else if (!l && r){
			for (int i = p; i >= lf; i--){
				if (s[i] != s[s.size()-i-1]){
					cnt += min(abs(s[i]-s[s.size()-i-1]),26-abs(s[i]-s[s.size()-i-1])); 
					s[i] = s[s.size()-i-1]; 
				}
				if (i > lf) cnt++; // simulate moving left  
			}
		}else if (l && !r){
			for (int i = p; i <= rf; i++){
				if (s[i] != s[s.size()-i-1]){
					cnt += min(abs(s[i]-s[s.size()-i-1]),26-abs(s[i]-s[s.size()-i-1])); 
					s[i] = s[s.size()-i-1];  
				}
				if (i < rf) cnt++; // simulate moving right  
			}
		}else if (l && r){
			cnt += 0; 
		}
	}
	cout << cnt << endl; 
	return 0;  
}
