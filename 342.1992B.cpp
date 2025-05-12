/* B. Angry Monk
time limit per test2 seconds
memory limit per test256 megabytes
To celebrate his recovery, k1o0n has baked an enormous 𝑛
 metres long potato casserole.

Turns out, Noobish_Monk just can't stand potatoes, so he decided to ruin k1o0n's
meal. He has cut it into 𝑘 pieces, of lengths 𝑎1,𝑎2,…,𝑎𝑘 meters.

k1o0n wasn't keen on that. Luckily, everything can be fixed. In order to do
that, k1o0n can do one of the following operations:

Pick a piece with length 𝑎𝑖≥2
 and divide it into two pieces with lengths 1
 and 𝑎𝑖−1
. As a result, the number of pieces will increase by 1
;
Pick a slice 𝑎𝑖
 and another slice with length 𝑎𝑗=1
 (𝑖≠𝑗
) and merge them into one piece with length 𝑎𝑖+1
. As a result, the number of pieces will decrease by 1
.
Help k1o0n to find the minimum number of operations he needs to do in order to
merge the casserole into one piece with length 𝑛
.

For example, if 𝑛=5
, 𝑘=2
 and 𝑎=[3,2]
, it is optimal to do the following:

Divide the piece with length 2
 into two pieces with lengths 2−1=1
 and 1
, as a result 𝑎=[3,1,1]
.
Merge the piece with length 3
 and the piece with length 1
, as a result 𝑎=[4,1]
.
Merge the piece with length 4
 and the piece with length 1
, as a result 𝑎=[5]
.
Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
).

Description of each test case consists of two lines. The first line contains two
integers 𝑛 and 𝑘 (2≤𝑛≤109 , 2≤𝑘≤105 ) — length of casserole and the number of
pieces.

The second line contains 𝑘
 integers 𝑎1,𝑎2,…,𝑎𝑘
 (1≤𝑎𝑖≤𝑛−1
, ∑𝑎𝑖=𝑛
) — lengths of pieces of casserole, which Noobish_Monk has cut.

It is guaranteed that the sum of 𝑘
 over all 𝑡
 test cases doesn't exceed 2⋅105
.

Output
For each test case, output the minimum number of operations K1o0n needs to
restore his pie after the terror of Noobish_Monk.

Example
InputCopy
4
5 3
3 1 1
5 2
3 2
11 4
2 3 1 5
16 6
1 6 1 1 1 6
OutputCopy
2
3
9
15

*/

#include <algorithm>
#include <iostream>

int main() {
  long t;
  std::cin >> t;
  while (t--) {
    long n, k;
    std::cin >> n >> k;

    long total = 0, mx = 0;
    for (long p = 0; p < k; ++p) {
      long x;
      std::cin >> x;
      mx = std::max(mx, x);
      total += (2 * x - 1);
    }

    total -= (2 * mx - 1);
    std::cout << total << "\n";
  }

  return 0;
}

// sub: https://codeforces.com/problemset/submission/1992/319428266
