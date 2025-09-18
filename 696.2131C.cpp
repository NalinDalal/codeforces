/*C. Make it Equal
time limit per test2 seconds
memory limit per test256 megabytes
Given two multisets 𝑆
 and 𝑇
 of size 𝑛
 and a positive integer 𝑘
, you may perform the following operations any number (including zero) of times
on 𝑆
:

Select an element 𝑥
 in 𝑆
, and remove one occurrence of 𝑥
 in 𝑆
. Then, either insert 𝑥+𝑘
 into 𝑆
, or insert |𝑥−𝑘|
 into 𝑆
.
Determine if it is possible to make 𝑆
 equal to 𝑇
. Two multisets 𝑆
 and 𝑇
 are equal if every element appears the same number of times in 𝑆
 and 𝑇
.

Input
Each test contains multiple test cases. The first line contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases. The description of the test cases follows.

The first line contains two integers 𝑛
 and 𝑘
 (1≤𝑛≤2⋅105
, 1≤𝑘≤109
) — the size of 𝑆
 and the constant, respectively.

The second line contains 𝑛
 integers 𝑆1,𝑆2,…,𝑆𝑛
 (0≤𝑆𝑖≤109
) — the elements in 𝑆
.

The third line contains 𝑛
 integers 𝑇1,𝑇2,…,𝑇𝑛
 (0≤𝑇𝑖≤109
) — the elements in 𝑇
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output "YES" if it is possible to make 𝑆
 equal to 𝑇
, and "NO" otherwise.

You can output the answer in any case (upper or lower). For example, the strings
"yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
5
1 3
1
2
1 8
4
12
3 5
6 2 9
8 4 11
2 7
2 8
2 9
3 2
0 1 0
1 0 1
OutputCopy
YES
YES
YES
NO
NO
Note
In the first test case, we can remove one occurrence of 1
 from 𝑆
 and insert |1−𝑘|=|1−3|=2
 into 𝑆
, making 𝑆
 equal to 𝑇
.

In the second test case, we can remove one occurrence of 4
 from 𝑆
 and insert 4+𝑘=4+8=12
 into 𝑆
, making 𝑆
 equal to 𝑇
.

In the last test case, we can show that it is impossible to make 𝑆
 equal to 𝑇
.*/

/*(t--){
 n,k
 vector<int> S(n),T(n)
 cin>>S;
 cin>>T

select x from S
x=x+k or x=abs(x-k)

if S can be made equal to T return true
else return false

Any number of operations allowed:
From x you can reach values with same canonical residue:
   r = x % k
   if (r > k-r) r = k-r

Build a map of all T with freq.

For each S[i], compute its canonical residue.
If it exists in T’s map, decrement freq.
Else return NO.

If all matched, return YES.
  }
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> K;
    vector<int> S(n), T(n);
    for (int i = 0i; < n; i++)
      cin >> S[i];
    for (int i = 0; i < n; i++)
      cin >> T[i];

    multiset<int> mt(T.begin(), T.end());
    bool possible = true;

    for (int i = 0; i < n; i++) {
      int a = S[i] + k;
      int b = abs(S[i] - k);

      if (mt.find(a) != mt.end()) {
        mt.erase(mt.find(a));
      } else if (mt.find(b) != mt.end()) {
        mt.erase(mt.find(b));
      } else {
        possible = false;
        break;
      }
    }

    cout << (possible ? "YES\n" : "NO\n");
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2131/339194037
