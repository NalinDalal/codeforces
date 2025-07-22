/*C. Left and Right Houses
time limit per test2 seconds
memory limit per test256 megabytes
In the village of Letovo, there are 𝑛
 houses. The villagers decided to build a big road that will divide the village
into left and right sides. Each resident wants to live on either the right or
the left side of the street, which is described as a sequence 𝑎1,𝑎2,…,𝑎𝑛 , where
𝑎𝑗=0 if the resident of the 𝑗 -th house wants to live on the left side of the
street; otherwise, 𝑎𝑗=1
.

The road will pass between two houses. The houses to the left of it will be
declared the left-side, and the houses to the right will be declared the
right-side. More formally, let the road pass between houses 𝑖 and 𝑖+1 . Then the
houses at positions between 1 and 𝑖 will be on the left side of the street, and
at positions between 𝑖+1 and 𝑛 will be on the right side. The road also may pass
before the first and after the last house; in this case, the entire village is
declared to be either the right or left side, respectively.

To make the design fair, it was decided to lay the road so that at least half of
the residents on each side of the village are satisfied with the choice. That
is, among 𝑥 residents on one side, at least ⌈𝑥2⌉ should want to live on that
side, where ⌈𝑥⌉ denotes rounding up a real number 𝑥
.

To the left of the road, there will be 𝑖
 houses, among the corresponding 𝑎𝑗
 there must be at least ⌈𝑖2⌉
 zeros. To the right of the road, there will be 𝑛−𝑖
 houses, among the corresponding 𝑎𝑗
 there must be at least ⌈𝑛−𝑖2⌉
 ones.
Determine after which house 𝑖
 the road should be laid in order to satisfy the described condition and be as
close to the middle of the village as possible. Formally, among all suitable
positions 𝑖 , minimize ∣∣𝑛2−𝑖∣∣
.

If there are multiple suitable positions 𝑖
 with the minimum ∣∣𝑛2−𝑖∣∣
, output the smaller one.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤2⋅104
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (3≤𝑛≤3⋅105
). The next line of each test case contains a string 𝑎
 of length 𝑛
, consisting only of 0
 and 1
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 3⋅105
.

Output
For each test case, output a single number 𝑖
 — the position of the house after which the road should be laid (if it should
be laid before the first house, output 0
). We can show that the answer always exists.

Example
InputCopy
7
3
101
6
010111
6
011001
3
000
3
110
3
001
4
1100
OutputCopy
2
3
2
3
0
1
0
Note
Let's consider the first example of input data.

If we lay the road after the first house, there will be one house 𝑎1=1
 on the left side of the street, the resident of which would like to live on the
right side of the street. Then 0 out of 1 residents on the even side will be
satisfied with the choice, which means that the road cannot be laid after house
1
.

If we lay the road after the second house, 1
 out of 2
 residents on the left side (with preferences 𝑎1=1
, 𝑎2=0
) and 1
 out of 1
 resident on the right side (with preference 𝑎3=1
) will be satisfied with the choice. More than half of the residents on each
side are satisfied with the choice, which means that the road can be laid after
house 2 . We can show that this is the optimal answer.




*/

#include <iostream>
#include <vector>

int main() {

  std::ios_base::sync_with_stdio(false);
  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<long> vl(n + 1, 0), vr(n + 1, 0);
    for (long p = 1; p <= n; p++) {
      vl[p] = vl[p - 1] + (s[p - 1] == '0');
    }
    for (long p = n - 1; p >= 0; p--) {
      vr[p] = vr[p + 1] + (s[p] == '1');
    }

    long idx(-1);
    float mindist(n + 7);
    for (long p = 0; p <= n; p++) {
      if (2 * vl[p] < p) {
        continue;
      }
      if (2 * vr[p] < (n - p)) {
        continue;
      }
      float dist = 0.5 * n - p;
      if (dist < 0) {
        dist = -dist + 0.1;
      }
      if (dist < mindist) {
        mindist = dist;
        idx = p;
      }
    }

    std::cout << idx << std::endl;
  }
}
// sub: https://codeforces.com/problemset/submission/1945/330391517
