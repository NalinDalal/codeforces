/*D. Distinct Split
time limit per test2 seconds
memory limit per test256 megabytes
Let's denote the 𝑓(𝑥)
 function for a string 𝑥
 as the number of distinct characters that the string contains. For example
𝑓(𝚊𝚋𝚌)=3 , 𝑓(𝚋𝚋𝚋𝚋𝚋)=1 , and 𝑓(𝚋𝚊𝚋𝚊𝚌𝚊𝚋𝚊)=3
.

Given a string 𝑠
, split it into two non-empty strings 𝑎
 and 𝑏
 such that 𝑓(𝑎)+𝑓(𝑏)
 is the maximum possible. In other words, find the maximum possible value of
𝑓(𝑎)+𝑓(𝑏) such that 𝑎+𝑏=𝑠 (the concatenation of string 𝑎 and string 𝑏 is equal
to string 𝑠
).

Input
The input consists of multiple test cases. The first line contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer 𝑛
 (2≤𝑛≤2⋅105
) — the length of the string 𝑠
.

The second line contains the string 𝑠
, consisting of lowercase English letters.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer  — the maximum possible value of
𝑓(𝑎)+𝑓(𝑏) such that 𝑎+𝑏=𝑠
.

Example
InputCopy
5
2
aa
7
abcabcd
5
aaaaa
10
paiumoment
4
aazz
OutputCopy
2
7
2
10
3
Note
For the first test case, there is only one valid way to split 𝚊𝚊
 into two non-empty strings 𝚊
 and 𝚊
, and 𝑓(𝚊)+𝑓(𝚊)=1+1=2
.

For the second test case, by splitting 𝚊𝚋𝚌𝚊𝚋𝚌𝚍
 into 𝚊𝚋𝚌
 and 𝚊𝚋𝚌𝚍
 we can get the answer of 𝑓(𝚊𝚋𝚌)+𝑓(𝚊𝚋𝚌𝚍)=3+4=7
 which is maximum possible.

For the third test case, it doesn't matter how we split the string, the answer
will always be 2.
*/

/*given string s
 * break into 2 non-empty string a,b
 * f(str)-> returns total distinct chars in str
 * maximise f(a)+f(b)
 */

// count distinct chars in string
/*int f(string s) {
  int count = 0;
  sort(s.begin(), s.end());
  for (int i = 0; i < s.size(); i++) {
    if (i == 0 || s[i] != s[i - 1])
      count++;
  }
  return count;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string a, b;
    // now logic to break s into a,b
    // say divide at n/2
    // a=s[0:n/2-1]
    // b=s[n/2:n]
    a = s.substr(0, s.size() / 2); // start from index 0, have total
                                   // s.size()/2-1 chars in it
    b = s.substr(s.size() / 2);    // start from mid index, have
                                   // a size of s.size()/2-1 chars in it
    cout << f(a) + f(b) << endl;
  }
  return 0;
}*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// break s into s1,s2 so that s=s1+s2
// count unique chars in s1,s2
// sum s1.count(),s2.count()
// maximise this sum
// unique chars in (logn) or O(n)
// take a map, put string into map, chars with count <int,int>,
// originally all in right map, now travserse, and put in left map, remove from
// right

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    unordered_map<int, int> right;
    for (int i = 0; i < n; i++)
      right[s[i]]++;
    unordered_map<int, int> left;
    int ans = INT_MIN;
    for (int i = 0; i < n - 1; i++) {
      left[s[i]]++;
      right[s[i]]--;
      if (right[s[i]] == 0)
        right.erase(s[i]);
      int l = left.size();
      int r = right.size();
      ans = max(ans, l + r);
    }
    cout << ans << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1791/330607359
