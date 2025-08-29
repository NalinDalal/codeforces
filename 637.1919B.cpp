/*B. Plus-Minus Split
time limit per test1 second
memory limit per test256 megabytes
You are given a string 𝑠
 of length 𝑛
 consisting of characters "+" and "-". 𝑠
 represents an array 𝑎
 of length 𝑛
 defined by 𝑎𝑖=1
 if 𝑠𝑖=
 "+" and 𝑎𝑖=−1
 if 𝑠𝑖=
 "-".

You will do the following process to calculate your penalty:

Split 𝑎
 into non-empty arrays 𝑏1,𝑏2,…,𝑏𝑘
 such that 𝑏1+𝑏2+…+𝑏𝑘=𝑎†
, where +
 denotes array concatenation.
The penalty of a single array is the absolute value of its sum multiplied by its
length. In other words, for some array 𝑐 of length 𝑚 , its penalty is calculated
as 𝑝(𝑐)=|𝑐1+𝑐2+…+𝑐𝑚|⋅𝑚
.
The total penalty that you will receive is 𝑝(𝑏1)+𝑝(𝑏2)+…+𝑝(𝑏𝑘)
.
If you perform the above process optimally, find the minimum possible penalty
you will receive.

†
 Some valid ways to split 𝑎=[3,1,4,1,5]
 into (𝑏1,𝑏2,…,𝑏𝑘)
 are ([3],[1],[4],[1],[5])
, ([3,1],[4,1,5])
 and ([3,1,4,1,5])
 while some invalid ways to split 𝑎
 are ([3,1],[1,5])
, ([3],[],[1,4],[1,5])
 and ([3,4],[5,1,1])
.

Input
Each test contains multiple test cases. The first line contains a single integer
𝑡 (1≤𝑡≤1000 ) — the number of test cases. The description of the test cases
follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤5000
) — the length of string 𝑠
.

The second line of each test case contains string 𝑠
 (𝑠𝑖∈{+,−}
, |𝑠|=𝑛
).

Note that there are no constraints on the sum of 𝑛
 over all test cases.

Output
For each test case, output a single integer representing the minimum possible
penalty you will receive.

Example
InputCopy
5
1
+
5
-----
6
+-+-+-
10
--+++++++-
20
+---++++-+++++---++-
OutputCopy
1
5
0
4
4
Note
In the first test case, we have 𝑎=[1]
. We can split array 𝑎
 into ([1])
. Then, the sum of penalties of the subarrays is 𝑝([1])=1
.

In the second test case, we have 𝑎=[−1,−1,−1,−1,−1]
. We can split array 𝑎
 into ([−1],[−1],[−1],[−1],[−1])
. Then, the sum of penalties of the subarrays is
𝑝([−1])+𝑝([−1])+𝑝([−1])+𝑝([−1])+𝑝([−1])=1+1+1+1+1=5
.

In the third test case, we have 𝑎=[1,−1,1,−1,1,−1]
. We can split array 𝑎
 into ([1,−1,1,−1],[1,−1])
. Then, the sum of penalties of the subarrays is 𝑝([1,−1,1,−1])+𝑝([1,−1])=0+0=0
.
*/

#include <iostream>

int main() {

  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    long cnt(0);
    for (long p = 0; p < n; p++) {
      cnt += (s[p] == '+') - (s[p] == '-');
    }
    cnt = (cnt > 0) ? cnt : -cnt;
    std::cout << cnt << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1919/336075774
