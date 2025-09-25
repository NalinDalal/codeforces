/*C. Update Queries
time limit per test2 seconds
memory limit per test256 megabytes
Let's consider the following simple problem. You are given a string 𝑠
 of length 𝑛
, consisting of lowercase Latin letters, as well as an array of indices 𝑖𝑛𝑑
 of length 𝑚
 (1≤𝑖𝑛𝑑𝑖≤𝑛
) and a string 𝑐
 of length 𝑚
, consisting of lowercase Latin letters. Then, in order, you perform the update
operations, namely, during the 𝑖 -th operation, you set 𝑠𝑖𝑛𝑑𝑖=𝑐𝑖 . Note that you
perform all 𝑚 operations from the first to the last.

Of course, if you change the order of indices in the array 𝑖𝑛𝑑
 and/or the order of letters in the string 𝑐
, you can get different results. Find the lexicographically smallest string 𝑠
 that can be obtained after 𝑚
 update operations, if you can rearrange the indices in the array 𝑖𝑛𝑑
 and the letters in the string 𝑐
 as you like.

A string 𝑎
 is lexicographically less than a string 𝑏
 if and only if one of the following conditions is met:

𝑎
 is a prefix of 𝑏
, but 𝑎≠𝑏
;
in the first position where 𝑎
 and 𝑏
 differ, the symbol in string 𝑎
 is earlier in the alphabet than the corresponding symbol in string 𝑏
.
Input
Each test consists of several sets of input data. The first line contains a
single integer 𝑡 (1≤𝑡≤104 ) — the number of sets of input data. Then follows
their description.

The first line of each set of input data contains two integers 𝑛
 and 𝑚
 (1≤𝑛,𝑚≤105
) — the length of the string 𝑠
 and the number of updates.

The second line of each set of input data contains a string 𝑠
 of length 𝑛
, consisting of lowercase Latin letters.

The third line of each set of input data contains 𝑚
 integers 𝑖𝑛𝑑1,𝑖𝑛𝑑2,…,𝑖𝑛𝑑𝑚
 (1≤𝑖𝑛𝑑𝑖≤𝑛
) — the array of indices 𝑖𝑛𝑑
.

The fourth line of each set of input data contains a string 𝑐
 of length 𝑚
, consisting of lowercase Latin letters.

It is guaranteed that the sum of 𝑛
 over all sets of input data does not exceed 2⋅105
. Similarly, the sum of 𝑚
 over all sets of input data does not exceed 2⋅105
.

Output
For each set of input data, output the lexicographically smallest string 𝑠
 that can be obtained by rearranging the indices in the array 𝑖𝑛𝑑
 and the letters in the string 𝑐
 as you like.

Example
InputCopy
4
1 2
a
1 1
cb
4 4
meow
1 2 1 4
zcwz
7 4
abacaba
1 3 5 7
damn
7 10
traktor
7 6 5 4 3 2 1 6 4 2
codeforces
OutputCopy
b
cwoz
abdcmbn
ccdeefo
Note
In the first set of input data, you can leave the array 𝑖𝑛𝑑
 and the string 𝑐
 unchanged and simply perform all operations in that order.

In the second set of input data, you can set the array 𝑖𝑛𝑑=[1,1,4,2]
 and 𝑐=
 "zczw". Then the string 𝑠
 will change as follows: 𝑚𝑒𝑜𝑤→𝑧𝑒𝑜𝑤→𝑐𝑒𝑜𝑤→𝑐𝑒𝑜𝑧→𝑐𝑤𝑜𝑧
.

In the third set of input data, you can leave the array 𝑖𝑛𝑑
 unchanged and set 𝑐=
 "admn". Then the string 𝑠
 will change as follows: 𝑎𝑏𝑎𝑐𝑎𝑏𝑎→𝑎𝑏𝑎𝑐𝑎𝑏𝑎→𝑎𝑏𝑑𝑐𝑎𝑏𝑎→𝑎𝑏𝑑𝑐𝑚𝑏𝑎→𝑎𝑏𝑑𝑐𝑚𝑏𝑛
.
*/

/*(t--){
 int m,n
string s(n);
vector<int> a(m)
string c(m);


lexicographically smallest string 𝑠
 that can be obtained by rearranging the indices in the array 𝑖𝑛𝑑
 and the letters in the string 𝑐
 as you like.
  }
*/
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {

  std::ios_base::sync_with_stdio(false);

  long t;
  std::cin >> t;
  while (t--) {
    long n, m;
    std::cin >> n >> m;
    std::string s;
    std::cin >> s;
    std::set<long> t;
    for (long p = 0; p < m; p++) {
      long x;
      std::cin >> x;
      t.insert(--x);
    }
    std::string r;
    std::cin >> r;
    sort(r.begin(), r.end());

    long idx(0);
    for (std::set<long>::iterator it = t.begin(); it != t.end(); it++) {
      long pos = *it;
      s[pos] = r[idx++];
    }

    std::cout << s << std::endl;
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1986/340286912
