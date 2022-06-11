#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define ll long long
using namespace std;

bool check(string t, string s) {
    if(s == t) return true;
    int n = s.length();
    int m = t.length();
    int j = 0;
    for(int i = 0; i < n; i++){
        if(t[j] == s[i]) {
            j++;
        }
        if(j == t.length()) return true;
    }
    return false;
}

int findLUSlength(vector<string>& strs) {
    int m = -1;

    for(int i = 0; i < strs.size(); i++){
        bool ok = true;
        for(int j = 0; j < strs.size(); j++){
            if(i == j) continue;

            if(check(strs[i], strs[j])){
                ok = false;
                break;
            }
        }

        if(ok == true){
            int l = strs[i].length();
            if(l > m) m = l;
        }
    }

    return m;
}


int main() {
	vector<string> temp = {"aabbcc", "aabbcc","cb"};
	cout << findLUSlength(temp);
	return 0;
}
