/*E. Nearly Shortest Repeating Substring
time limit per test2 seconds
memory limit per test256 megabytes
You are given a string 𝑠
 of length 𝑛
 consisting of lowercase Latin characters. Find the length of the shortest
string 𝑘 such that several (possibly one) copies of 𝑘 can be concatenated
together to form a string with the same length as 𝑠 and, at most, one different
character.

More formally, find the length of the shortest string 𝑘
 such that 𝑐=𝑘+⋯+𝑘𝑥 times
 for some positive integer 𝑥
, strings 𝑠
 and 𝑐
 has the same length and 𝑐𝑖≠𝑠𝑖
 for at most one 𝑖
 (i.e. there exist 0
 or 1
 such positions).

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤103
) — the number of test cases.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤2⋅105
) — the length of string 𝑠
.

The second line of each test case contains the string 𝑠
, consisting of lowercase Latin characters.

The sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print the length of the shortest string 𝑘
 satisfying the constraints in the statement.

Example
InputCopy
5
4
abaa
4
abba
13
slavicgslavic
8
hshahaha
20
stormflamestornflame
OutputCopy
1
4
13
2
10
Note
In the first test case, you can select 𝑘=𝚊
 and 𝑘+𝑘+𝑘+𝑘=𝚊𝚊𝚊𝚊
, which only differs from 𝑠
 in the second position.

In the second test case, you cannot select 𝑘
 of length one or two. We can have 𝑘=𝚊𝚋𝚋𝚊
, which is equal to 𝑠
.
*/

/*Given a string s of length n, find the shortest string k such that:

You can concatenate multiple copies of k to get a string c of length n.

c and s differ in at most one position.

We need the length of the shortest k, not the string itself.
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back

int main() {
  int test;
  cin >> test;

  vector<vector<int>> div(200005);

  for (int i = 1; i <= 200000; i++) {
    for (int j = i; j <= 200000; j += i)
      div[j].pb(i);
  }

  while (test--) {
    int n;
    string s;
    cin >> n >> s;

    for (auto e : div[n]) {
      int cnt = 0;

      for (int i = e; i < n && cnt <= 1; i++)
        cnt += (s[i] != s[i % e]);

      if (cnt <= 1) {
        cout << e << "\n";
        break;
      }

      cnt = 0;

      for (int i = 2 * e; i < n && cnt <= 1; i++)
        cnt += (s[i] != s[e + i % e]);
      for (int i = 0; i < e && cnt <= 1; i++)
        cnt += (s[i] != s[e + i % e]);

      if (cnt <= 1) {
        cout << e << "\n";
        break;
      }
    }
  }
}
// sub: https://codeforces.com/problemset/submission/1950/339825865
