/* https://codeforces.com/problemset/problem/1607/B
B. Odd Grasshopper
time limit per test1 second
memory limit per test256 megabytes
The grasshopper is located on the numeric axis at the point with coordinate 𝑥0.

Having nothing else to do he starts jumping between integer points on the axis.
Making a jump from a point with coordinate 𝑥 with a distance 𝑑 to the left moves
the grasshopper to a point with a coordinate 𝑥−𝑑, while jumping to the right
moves him to a point with a coordinate 𝑥+𝑑.

The grasshopper is very fond of positive integers, so for each integer 𝑖
starting with 1 the following holds: exactly 𝑖 minutes after the start he makes
a jump with a distance of exactly 𝑖. So, in the first minutes he jumps by 1,
then by 2, and so on.

The direction of a jump is determined as follows: if the point where the
grasshopper was before the jump has an even coordinate, the grasshopper jumps to
the left, otherwise he jumps to the right.

For example, if after 18 consecutive jumps he arrives at the point with a
coordinate 7, he will jump by a distance of 19 to the right, since 7 is an odd
number, and will end up at a point 7+19=26. Since 26 is an even number, the next
jump the grasshopper will make to the left by a distance of 20, and it will move
him to the point 26−20=6.

Find exactly which point the grasshopper will be at after exactly 𝑛 jumps.

Input
The first line of input contains an integer 𝑡 (1≤𝑡≤104) — the number of test
cases.

Each of the following 𝑡 lines contains two integers 𝑥0 (−1014≤𝑥0≤1014) and 𝑛
(0≤𝑛≤1014) — the coordinate of the grasshopper's initial position and the number
of jumps.

Output
Print exactly 𝑡 lines. On the 𝑖-th line print one integer — the answer to the
𝑖-th test case — the coordinate of the point the grasshopper will be at after
making 𝑛 jumps from the point 𝑥0.

Example
InputCopy
9
0 1
0 2
10 10
10 99
177 13
10000000000 987654321
-433494437 87178291199
1 0
-1 1
OutputCopy
-1
1
11
110
190
9012345679
-87611785637
1
0
Note
The first two test cases in the example correspond to the first two jumps from
the point 𝑥0=0. Since 0 is an even number, the first jump of length 1 is made to
the left, and the grasshopper ends up at the point 0−1=−1.

Then, since −1 is an odd number, a jump of length 2 is made to the right,
bringing the grasshopper to the point with coordinate −1+2=1.
*/

#include <iostream>

typedef long long ll;

int main() {

  ll t;
  std::cin >> t;
  while (t--) {
    ll x, n;
    std::cin >> x >> n;
    ll res = x, s = (x % 2 ? 1 : -1);
    if (n % 4 == 1) {
      res += s * n;
    } else if (n % 4 == 2) {
      res -= s;
    } else if (n % 4 == 3) {
      res -= s * (n + 1);
    }
    std::cout << res << std::endl;
  }
  return 0;
}

// sub: https://codeforces.com/problemset/submission/1607/304440870
