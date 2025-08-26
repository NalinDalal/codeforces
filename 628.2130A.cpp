/*A. Submission is All You Need
time limit per test1 second
memory limit per test256 megabytes
For a multiset 𝑇
 consisting of non-negative integers, we define:

sum(𝑇)
 is the sum of all elements in 𝑇
. For example, if 𝑇={0,1,1,3}
, then sum(𝑇)=0+1+1+3=5
.

mex(𝑇)
 is the smallest non-negative integer not in 𝑇
. For example, if 𝑇={0,1,1,3}
, then mex(𝑇)=2
 because 2
 is the smallest non-negative integer not present in 𝑇
.
You are given a multiset 𝑆
 of size 𝑛
 consisting of non-negative integers. At first, your score is 0
. You can perform the following operations any number of times in any order
(possibly zero): Select a subset 𝑆′⊆𝑆 (i.e., 𝑆′ contains some of the elements
currently in 𝑆
), add sum(𝑆′)
 to your score, and then remove 𝑆′
 from 𝑆
.
Select a subset 𝑆′⊆𝑆
, add mex(𝑆′)
 to your score, and then remove 𝑆′
 from 𝑆
.
Find the maximum possible score that can be obtained.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤103
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤50
).

The second line of each test case contains 𝑛
 integers 𝑆1,𝑆2,…,𝑆𝑛
 (0≤𝑆𝑖≤50
).

Output
For each test case, print a single integer — the maximum possible score that can
be obtained.

Example
InputCopy
2
3
0 1 1
3
1 2 3
OutputCopy
3
6
Note
In the first test case, a possible optimal strategy is as follows:

Select 𝑆′={0,1}
, add mex(𝑆′)=mex({0,1})=2
 to your score, and then remove 𝑆′
 from 𝑆
. Currently, your score is 2
 and 𝑆={1}
.
Select 𝑆′={1}
, add sum(𝑆′)=sum({1})=1
 to your score, and then remove 𝑆′
 from 𝑆
. Currently, your score is 3
 and 𝑆=∅
.
After that, you cannot do any further operations. It can be proven that 3
 is the maximum possible score that can be obtained.
*/

/*Count frequency of each number.

Compute mex(S) of the whole set. Call it m1.

Compute second mex (the next missing integer after m1). Call it m2.

Because we can split the set cleverly, the max gain is always m1 + m2.

So the answer is m1 + m2.


trick:

If a number x appears at least twice, then both m1 and m2 move past it.

If it appears once, then only one moves past.
*/

#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long t;
  cin >> t;
  while (t--) {
    long n;
    cin >> n;
    long s = 0;
    for (long p = 0; p < n; p++) {
      long x;
      cin >> x;
      s += (x > 1 ? x : 1);
    }
    cout << s << "\n";
  }

  return 0;
}

// sub: https://codeforces.com/problemset/submission/2130/335537325
