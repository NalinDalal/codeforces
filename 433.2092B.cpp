/*B. Lady Bug
time limit per test1 second
memory limit per test256 megabytes
As soon as Dasha Purova crossed the border of France, the villain Markaron
kidnapped her and placed her in a prison under his large castle. Fortunately,
the wonderful Lady Bug, upon hearing the news about Dasha, immediately ran to
save her in Markaron's castle. However, to get there, she needs to crack a
complex password.

The password consists of two bit strings 𝑎
 and 𝑏
, each of which has a length of 𝑛
. In one operation, Lady Bug can choose any index 2≤𝑖≤𝑛
 and perform one of the following actions:

swap(𝑎𝑖
, 𝑏𝑖−1
) (swap the values of 𝑎𝑖
 and 𝑏𝑖−1
), or
swap(𝑏𝑖
, 𝑎𝑖−1
) (swap the values of 𝑏𝑖
 and 𝑎𝑖−1
).
Lady Bug can perform any number of operations. The password is considered
cracked if she can ensure that the first string consists only of zeros. Help her
understand whether or not she will be able to save the unfortunate Dasha.

Input
Each test consists of several test cases. The first line of the input data
contains one integer 𝑡 (1≤𝑡≤104 ) — the number of test cases. The description of
the test cases follows.

The first line of each test case contains one integer 𝑛
 (2≤𝑛≤2⋅105
) — the length of the bit strings of the password.

The next two lines contain the bit strings of length 𝑛
, 𝑎
 and 𝑏
, which represent the password. Each of the strings contains only the characters
0 and '1'.

It is guaranteed that the sum of 𝑛
 across all test cases does not exceed 2⋅105
.

Output
For each test case, output "YES" if Lady Bug can crack the password after any
number of operations; otherwise, output "NO".

You can output each letter in any case (lowercase or uppercase). For example,
the strings "yEs", "yes", "Yes", and "YES" will be accepted as a positive
answer.

Example
InputCopy
4
3
000
000
6
010001
010111
5
10000
01010
2
11
00
OutputCopy
YES
YES
NO
YES
Note
In the first test case, the string 𝑎
 immediately consists only of zeros.

In the second test case, a possible sequence of operations is:

swap(𝑎2, 𝑏1)

𝟶𝟷𝟶𝟶𝟶𝟷

𝟶𝟷𝟶𝟷𝟷𝟷

swap(𝑏5, 𝑎4)

𝟶𝟶𝟶𝟶𝟶𝟷

𝟷𝟷𝟶𝟷𝟷𝟷

swap(𝑎4, 𝑏3)

𝟶𝟶𝟶𝟷𝟶𝟷

𝟷𝟷𝟶𝟷𝟶𝟷

swap(𝑎5, 𝑏4)

𝟶𝟶𝟶𝟶𝟶𝟷

𝟷𝟷𝟷𝟷𝟶𝟷



*/

#include <iostream>

int main() {

  long t;
  std::cin >> t;
  while (t--) {
    long n;
    std::cin >> n;
    std::string a, b;
    std::cin >> a >> b;
    long zva(0), zvb(0), zda(0), zdb(0);
    for (size_t p = 0; p < n; p++) {
      if (p % 2) {
        zda += (a[p] == '0');
        zdb += (b[p] == '0');
      } else {
        zva += (a[p] == '0');
        zvb += (b[p] == '0');
      }
    }

    bool ans = ((zva + zdb) >= (n + 1) / 2) && (zda + zvb >= n / 2);
    std::cout << (ans ? "YES" : "NO") << std::endl;
  }
}
// sub: https://codeforces.com/problemset/submission/2092/325313998
