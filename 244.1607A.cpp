/*
A. Linear Keyboard
time limit per test1 second
memory limit per test256 megabytes
You are given a keyboard that consists of 26
 keys. The keys are arranged sequentially in one row in a certain order. Each
key corresponds to a unique lowercase Latin letter.

You have to type the word 𝑠
 on this keyboard. It also consists only of lowercase Latin letters.

To type a word, you need to type all its letters consecutively one by one. To
type each letter you must position your hand exactly over the corresponding key
and press it.

Moving the hand between the keys takes time which is equal to the absolute value
of the difference between positions of these keys (the keys are numbered from
left to right). No time is spent on pressing the keys and on placing your hand
over the first letter of the word.

For example, consider a keyboard where the letters from 'a' to 'z' are arranged
in consecutive alphabetical order. The letters 'h', 'e', 'l' and 'o' then are on
the positions 8 , 5 , 12 and 15 , respectively. Therefore, it will take
|5−8|+|12−5|+|12−12|+|15−12|=13 units of time to type the word "hello".

Determine how long it will take to print the word 𝑠
.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

The next 2𝑡
 lines contain descriptions of the test cases.

The first line of a description contains a keyboard — a string of length 26
, which consists only of lowercase Latin letters. Each of the letters from 'a'
to 'z' appears exactly once on the keyboard.

The second line of the description contains the word 𝑠
. The word has a length from 1
 to 50
 letters inclusive and consists of lowercase Latin letters.

Output
Print 𝑡
 lines, each line containing the answer to the corresponding test case. The
answer to the test case is the minimal time it takes to type the word 𝑠 on the
given keyboard.

Example
InputCopy
5
abcdefghijklmnopqrstuvwxyz
hello
abcdefghijklmnopqrstuvwxyz
i
abcdefghijklmnopqrstuvwxyz
codeforces
qwertyuiopasdfghjklzxcvbnm
qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq
qwertyuiopasdfghjklzxcvbnm
abacaba
OutputCopy
13
0
68
0
74

*/
#include <bits/stdc++.h>
using namespace std;
#define __FAST__                                                               \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(nullptr);
#define vin(a)                                                                 \
  for (ll &i : a)                                                              \
    cin >> i;
#define vout(a)                                                                \
  for (ll i : a)                                                               \
    cout << i << " ";
typedef long long ll;
typedef vector<ll> vll;
void solve() {
  map<char, int> idx;
  string s, t;
  cin >> t;

  for (int i = 0; i < 26; i++) {
    idx[t[i]] = i;
  }
  cin >> s;
  ll ans = 0;
  int n = s.length();
  for (int i = 1; i < n; i++) {
    ans += abs(idx[s[i]] - idx[s[i - 1]]);
  }
  cout << ans << endl;
}
int main() {
  __FAST__
  int t;
  cin >> t;
  while (t--)
    solve();
}
// sub: https://codeforces.com/problemset/submission/1607/311374242
