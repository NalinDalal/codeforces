/*C. Sofia and the Lost Operations
time limit per test2 seconds
memory limit per test256 megabytes
Sofia had an array of 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
. One day she got bored with it, so she decided to sequentially apply 𝑚
 modification operations to it.

Each modification operation is described by a pair of numbers ⟨𝑐𝑗,𝑑𝑗⟩
 and means that the element of the array with index 𝑐𝑗
 should be assigned the value 𝑑𝑗
, i.e., perform the assignment 𝑎𝑐𝑗=𝑑𝑗
. After applying all modification operations sequentially, Sofia discarded the
resulting array.

Recently, you found an array of 𝑛
 integers 𝑏1,𝑏2,…,𝑏𝑛
. You are interested in whether this array is Sofia's array. You know the values
of the original array, as well as the values 𝑑1,𝑑2,…,𝑑𝑚 . The values 𝑐1,𝑐2,…,𝑐𝑚
 turned out to be lost.

Is there a sequence 𝑐1,𝑐2,…,𝑐𝑚
 such that the sequential application of modification operations
⟨𝑐1,𝑑1,⟩,⟨𝑐2,𝑑2,⟩,…,⟨𝑐𝑚,𝑑𝑚⟩ to the array 𝑎1,𝑎2,…,𝑎𝑛 transforms it into the array
𝑏1,𝑏2,…,𝑏𝑛
?

Input
The first line contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

Then follow the descriptions of the test cases.

The first line of each test case contains an integer 𝑛
 (1≤𝑛≤2⋅105
) — the size of the array.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the elements of the original array.

The third line of each test case contains 𝑛
 integers 𝑏1,𝑏2,…,𝑏𝑛
 (1≤𝑏𝑖≤109
) — the elements of the found array.

The fourth line contains an integer 𝑚
 (1≤𝑚≤2⋅105
) — the number of modification operations.

The fifth line contains 𝑚
 integers 𝑑1,𝑑2,…,𝑑𝑚
 (1≤𝑑𝑗≤109
) — the preserved value for each modification operation.

It is guaranteed that the sum of the values of 𝑛
 for all test cases does not exceed 2⋅105
, similarly the sum of the values of 𝑚
 for all test cases does not exceed 2⋅105
.

Output
Output 𝑡
 lines, each of which is the answer to the corresponding test case. As an
answer, output "YES" if there exists a suitable sequence 𝑐1,𝑐2,…,𝑐𝑚 , and "NO"
otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes",
"Yes" and "YES" will be recognized as a positive answer).

Example
InputCopy
7
3
1 2 1
1 3 2
4
1 3 1 2
4
1 2 3 5
2 1 3 5
2
2 3
5
7 6 1 10 10
3 6 1 11 11
3
4 3 11
4
3 1 7 8
2 2 7 10
5
10 3 2 2 1
5
5 7 1 7 9
4 10 1 2 9
8
1 1 9 8 7 2 10 4
4
1000000000 203 203 203
203 1000000000 203 1000000000
2
203 1000000000
1
1
1
5
1 3 4 5 1
OutputCopy
YES
NO
NO
NO
YES
NO
YES
*/

#include <iostream>
#include <unordered_multiset>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;

    std::vector<long> a(n);
    for (long p = 0; p < n; p++) {
      std::cin >> a[p];
    }

    std::unordered_multiset<long> msd;
    for (long p = 0; p < n; p++) {
      long x;
      std::cin >> x;
      if (x != a[p]) {
        msd.insert(x);
      }
    }

    long m;
    std::cin >> m;

    bool ans = true;
    long d;
    for (long p = 0; p < m; p++) {
      std::cin >> d;

      if (msd.size() > m - p || msd.empty()) {
        continue;
      }

      auto it = msd.find(d);
      if (it != msd.end()) {
        msd.erase(it);
      } else if (p + 1 == m) {
        bool tmp = false;
        for (long u = 0; u < n; u++) {
          if (d == a[u]) {
            tmp = true;
            break;
          }
        }
        ans = tmp;
      }
    }

    ans = ans && msd.empty();

    std::cout << (ans ? "YES\n" : "NO\n");
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1980/341489780
