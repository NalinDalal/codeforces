/*C. Sort
time limit per test5 seconds
memory limit per test256 megabytes
You are given two strings 𝑎
 and 𝑏
 of length 𝑛
. Then, you are (forced against your will) to answer 𝑞
 queries.

For each query, you are given a range bounded by 𝑙
 and 𝑟
. In one operation, you can choose an integer 𝑖
 (𝑙≤𝑖≤𝑟
) and set 𝑎𝑖=𝑥
 where 𝑥
 is any character you desire. Output the minimum number of operations you must
perform such that 𝚜𝚘𝚛𝚝𝚎𝚍(𝚊[𝚕..𝚛])=𝚜𝚘𝚛𝚝𝚎𝚍(𝚋[𝚕..𝚛]) . The operations you perform
on one query does not affect other queries.

For an arbitrary string 𝑐
, 𝚜𝚘𝚛𝚝𝚎𝚍(𝚌[𝚕..𝚛])
 denotes the substring consisting of characters 𝑐𝑙,𝑐𝑙+1,...,𝑐𝑟
 sorted in lexicographical order.

Input
The first line contains 𝑡
 (1≤𝑡≤1000
) – the number of test cases.

The first line of each test case contains two integers 𝑛
 and 𝑞
 (1≤𝑛,𝑞≤2⋅105
) – the length of both strings and the number of queries.

The following line contains 𝑎
 of length 𝑛
. It is guaranteed 𝑎
 only contains lowercase latin letters.

The following line contains 𝑏
 of length 𝑛
. It is guaranteed 𝑏
 only contains lowercase latin letters.

The following 𝑞
 lines contain two integers 𝑙
 and 𝑟
 (1≤𝑙≤𝑟≤𝑛
) – the range of the query.

It is guaranteed the sum of 𝑛
 and 𝑞
 over all test cases does not exceed 2⋅105
.

Output
For each query, output an integer, the minimum number of operations you need to
perform in a new line.

Example
InputCopy
3
5 3
abcde
edcba
1 5
1 4
3 3
4 2
zzde
azbe
1 3
1 4
6 3
uwuwuw
wuwuwu
2 4
1 3
1 6
OutputCopy
0
1
0
2
2
1
1
0
Note
For the first query, 𝚜𝚘𝚛𝚝𝚎𝚍(𝚊[𝟷..𝟻])=
 abcde and 𝚜𝚘𝚛𝚝𝚎𝚍(𝚋[𝟷..𝟻])=
 abcde, so no operations are necessary.

For the second query, you need to set 𝑎1=
 e. Then, 𝚜𝚘𝚛𝚝𝚎𝚍(𝚊[𝟷..𝟺])=𝚜𝚘𝚛𝚝𝚎𝚍(𝚋[𝟷..𝟺])=
 bcde.
*/

#include <iostream>
#include <vector>

int main() {

  std::ios_base::sync_with_stdio(false);
  long t;
  std::cin >> t;
  while (t--) {
    long n, q;
    std::cin >> n >> q;
    std::string a, b;
    std::cin >> a >> b;

    std::vector<std::vector<long>> va(n + 1, std::vector<long>(26, 0));
    for (long p = 0; p < n; p++) {
      for (long u = 0; u < 26; u++) {
        va[p + 1][u] = va[p][u];
      }
      ++va[p + 1][a[p] - 'a'];
    }

    std::vector<std::vector<long>> vb(n + 1, std::vector<long>(26, 0));
    for (long p = 0; p < n; p++) {
      for (long u = 0; u < 26; u++) {
        vb[p + 1][u] = vb[p][u];
      }
      ++vb[p + 1][b[p] - 'a'];
    }

    while (q--) {
      long left, right;
      std::cin >> left >> right;
      long total(0);
      for (long p = 0; p < 26; p++) {
        long ca = va[right][p] - va[left - 1][p];
        long cb = vb[right][p] - vb[left - 1][p];
        long diff = cb - ca;
        if (diff < 0) {
          diff = -diff;
        }
        total += diff;
      }

      std::cout << (total / 2) << std::endl;
    }
  }
}
// sub: https://codeforces.com/problemset/submission/1996/329954591
