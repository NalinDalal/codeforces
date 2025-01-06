/* https://codeforces.com/problemset/problem/1881/A
A. Don't Try to Count
time limit per test2 seconds
memory limit per test256 megabytes
Given a string 𝑥 of length 𝑛 and a string 𝑠 of length 𝑚 (𝑛⋅𝑚≤25), consisting of
lowercase Latin letters, you can apply any number of operations to the string 𝑥.

In one operation, you append the current value of 𝑥 to the end of the string 𝑥.
Note that the value of 𝑥 will change after this.

For example, if 𝑥="aba", then after applying operations, 𝑥 will change as
follows: "aba" → "abaaba" → "abaabaabaaba".

After what minimum number of operations 𝑠 will appear in 𝑥 as a substring? A
substring of a string is defined as a contiguous segment of it.

Input
The first line of the input contains a single integer 𝑡 (1≤𝑡≤104) — the number
of test cases.

The first line of each test case contains two numbers 𝑛 and 𝑚 (1≤𝑛⋅𝑚≤25) — the
lengths of strings 𝑥 and 𝑠, respectively.

The second line of each test case contains the string 𝑥 of length 𝑛.

The third line of each test case contains the string 𝑠 of length 𝑚.

Output
For each test case, output a single number — the minimum number of operations
after which 𝑠 will appear in 𝑥 as a substring. If this is not possible, output
−1.

Example
InputCopy
12
1 5
a
aaaaa
5 5
eforc
force
2 5
ab
ababa
3 5
aba
ababa
4 3
babb
bbb
5 1
aaaaa
a
4 2
aabb
ba
2 8
bk
kbkbkbkb
12 2
fjdgmujlcont
tf
2 2
aa
aa
3 5
abb
babba
1 19
m
mmmmmmmmmmmmmmmmmmm
OutputCopy
3
1
2
-1
1
0
1
3
1
0
2
5
Note
In the first test case of the example, after 2 operations, the string will
become "aaaa", and after 3 operations, it will become "aaaaaaaa", so the answer
is 3.

In the second test case of the example, after applying 1 operation, the string
will become "eforceforc", where the substring is highlighted in red.

In the fourth test case of the example, it can be shown that it is impossible to
obtain the desired string as a substring.
*/

// 1. s appear in x as a substring; original length of x is n
//  after k operation length of x is 2^k.n
//  We want 𝑠 to appear as a substring in 𝑥.
//  since x doubles eveytime, length a/f k opr=2^k.n
//  2^k.n>=m     =>  k>=log2(m/n)
//
//  2. After each doubling, check if 𝑠 is a substring of 𝑥.
// 3. if(s) return k else return -1
// Start with the string x and check if s is a substring of x.
// If not, repeatedly concatenate x to itself (up to 6 times) and check again
// each time. If s is found, print the number of concatenations required. If
// after 6 concatenations s is not found, print -1.
#include <iostream>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ios                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);
using namespace std;

int main() {
  ios;
#ifndef ONLINE_JUDGE
  freopen("input1.txt", "r", stdin);
  freopen("/Users/sreejith/Desktop/output.txt", "w", stdout);
#endif
  ll t;
  cin >> t;
  while (t--) {
    ll n, m, cnt = 6, f = 0, res = 0;
    string x, s;
    cin >> n >> m;
    cin >> x >> s;
    while (cnt--) {
      if (x.find(s) != string::npos) {
        f = 1;
        break;
      }
      res++;
      x += x;
    }
    if (f == 1)
      cout << res;
    else
      cout << -1;
    cout << endl;
  }
  return 0;
}
