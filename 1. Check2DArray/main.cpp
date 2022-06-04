#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#define ll long long
#include <fstream>
using namespace std;

bool compare(vector<int> Vec, int size){
	for(int i = 0; i < size - 1; i++){
		if (Vec[i] != Vec[i + 1]) return false;
	}
	return true;
}

int main(){
	ofstream ofs("OUT.txt");
	ifstream ifs("INP.txt");
	
	vector<vector<int> > MyVec;
	int n;
	ifs >> n;
	for(int i = 0; i < n; i++){
		vector<int> temp;
		int x;
		for(int j = 0; j < n; j++){
			ifs >> x;
			temp.push_back(x);
		}
		
		MyVec.push_back(temp);
	}
	
	/*
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			ofs << MyVec[i][j] << " ";
		}
		ofs << '\n';
		
	}
	*/
	
	vector<int> compareVec;
	for(int i = 0; i < n; i++){
		int sum = 0;
		for(int j = 0; j < n; j++){
			sum += MyVec[i][j];
		}
		
		compareVec.push_back(sum);		
	}
	
	if (!compare(compareVec, n)) ofs << "NO";
	else{
		int count = compareVec[0];
		ofs << "YES\n";
		int idx = 0;
		while(count--){
			ofs << "THE #" << idx + 1 << " STEP: ";
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					if (MyVec[i][j] != 0){
						ofs << j;
						MyVec[i][j] --;
						for(int k = 0; j < n; k++){
							if (MyVec[i][k] != 0){
								ofs << " ";
								break;
							}
						}
						
						break;
					}
				}
			}
			
			ofs << '\n';
			idx++;
		}
	}
	
	return 0;
}
