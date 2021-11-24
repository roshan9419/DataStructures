#include <bits/stdc++.h>
using namespace std;

bool isEqual(string s1, string s2) {
  int i = 0, j = 0, n = s1.size();
  while (i < n) {
    if (s1[i++] != s2[j++]) return false;
  }
  return true;
}

string solve(string s1, string s2) {
  int cnt = 0;
  int n = s1.size();
  while(!isEqual(s1, s2)) {
    cnt++;
    if (cnt == n) return "NO";
    s2 = s2.substr(1) + s2[0];
    // cout << s1 << " - " << s2 << endl;
  }
  return "YES";
}

int main() {
  
  string s1 = "AAAZ";
  string s2 = "AAZA";
  
  if (s1.size() != s2.size()) {
    cout << "NO";
  } else {
    cout << solve(s1, s2);
  }
  
  return 0;
}
