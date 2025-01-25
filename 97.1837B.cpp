/* https://codeforces.com/problemset/problem/1837/B
B. Comparison String
time limit per test2 seconds
memory limit per test512 megabytes
You are given a string 𝑠 of length 𝑛, where each character is either < or >.

An array 𝑎 consisting of 𝑛+1 elements is compatible with the string 𝑠 if, for
every 𝑖 from 1 to 𝑛, the character 𝑠𝑖 represents the result of comparing 𝑎𝑖 and
𝑎𝑖+1, i. e.:

𝑠𝑖 is < if and only if 𝑎𝑖<𝑎𝑖+1;
𝑠𝑖 is > if and only if 𝑎𝑖>𝑎𝑖+1.
For example, the array [1,2,5,4,2] is compatible with the string <<>>.
There are other arrays with are compatible with that string, for example,
[13,37,42,37,13].

The cost of the array is the number of different elements in it. For example,
the cost of [1,2,5,4,2] is 4; the cost of [13,37,42,37,13] is 3.

You have to calculate the minimum cost among all arrays which are compatible
with the given string 𝑠.

Input
The first line contains one integer 𝑡 (1≤𝑡≤500) — the number of test cases.

Each test case consists of two lines:

the first line contains one integer 𝑛 (1≤𝑛≤100);
the second line contains the string 𝑠, consisting of 𝑛 characters. Each
character of 𝑠 is either < or >. Output For each test case, print one integer —
the minimum cost among all arrays which are compatible with the given string 𝑠.

Example
InputCopy
4
4
<<>>
4
>><<
5
>>>>>
7
<><><><
OutputCopy
3
3
6
2
Note
In the first test case of the example, the array can be [13,37,42,37,13].
In the second test case of the example, the array can be [42,37,13,37,42].
*/

#include <iostream>
#include <string>
using namespace std;

int solve(string s) {
  // for array of size n+1.
  // si is result of a[i],a[i+1]
  // if(a[i]<a[i+1])si='<';
  // if(a[i]>a[i+1])si='>'
  int cnt = 1, cur = 1;
  for (int p = 1; p < s.size(); p++) {
    if (s[p] == s[p - 1]) {
      cur++;
    } else {
      cur = 1;
    }
    cnt = max(cnt, cur);
  }
  return cnt;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int cost = solve(s);
    cout << cost + 1 << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1837/302882811
