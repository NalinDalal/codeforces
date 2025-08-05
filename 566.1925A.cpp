/*A. We Got Everything Covered!
time limit per test1 second
memory limit per test256 megabytes
You are given two positive integers 𝑛
 and 𝑘
.

Your task is to find a string 𝑠
 such that all possible strings of length 𝑛
 that can be formed using the first 𝑘
 lowercase English alphabets occur as a subsequence of 𝑠
.

If there are multiple answers, print the one with the smallest length. If there
are still multiple answers, you may print any of them.

Note: A string 𝑎
 is called a subsequence of another string 𝑏
 if 𝑎
 can be obtained by deleting some (possibly zero) characters from 𝑏
 without changing the order of the remaining characters.

Input
The first line of input contains a single integer 𝑡
 (1≤𝑡≤676
) denoting the number of test cases.

Each test case consists of a single line of input containing two integers 𝑛
 (1≤𝑛≤26
) and 𝑘
 (1≤𝑘≤26
).

Output
For each test case, print a single line containing a single string 𝑠
 which satisfies the above property. If there are multiple answers, print the
one with the smallest length. If there are still multiple answers, you may print
any of them.

Example
InputCopy
4
1 2
2 1
2 2
2 3
OutputCopy
ab
aa
baab
abcbac
Note
For the first test case, there are two strings of length 1
 which can be formed using the first 2
 lowercase English alphabets, and they are present in 𝑠
 as a subsequence as follows:

𝚊:𝚊𝚋
𝚋:𝚊𝚋
For the second test case, there is only one string of length 2
 which can be formed using the first lowercase English alphabet, and it is
present in 𝑠 as a subsequence as follows:

𝚊𝚊:𝚊𝚊
For the third test case, there are 4
 strings of length 2
 which can be formed using the first 2
 lowercase English alphabets, and they are present in 𝑠
 as a subsequence as follows:

𝚊𝚊:𝚋𝚊𝚊𝚋
𝚊𝚋:𝚋𝚊𝚊𝚋
𝚋𝚊:𝚋𝚊𝚊𝚋
𝚋𝚋:𝚋𝚊𝚊𝚋
For the fourth test case, there are 9
 strings of length 2
 which can be formed using the first 3
 lowercase English alphabets, and they are present in 𝑠
 as a subsequence as follows:

𝚊𝚊:𝚊𝚋𝚌𝚋𝚊𝚌
𝚊𝚋:𝚊𝚋𝚌𝚋𝚊𝚌
𝚊𝚌:𝚊𝚋𝚌𝚋𝚊𝚌
𝚋𝚊:𝚊𝚋𝚌𝚋𝚊𝚌
𝚋𝚋:𝚊𝚋𝚌𝚋𝚊𝚌
𝚋𝚌:𝚊𝚋𝚌𝚋𝚊𝚌
𝚌𝚊:𝚊𝚋𝚌𝚋𝚊𝚌
𝚌𝚋:𝚊𝚋𝚌𝚋𝚊𝚌
𝚌𝚌:𝚊𝚋𝚌𝚋𝚊𝚌


*/

#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  const std::string ab = "abcdefghijklmnopqrstuvwxyz";

  while (t--) {
    int n, k;
    std::cin >> n >> k;

    // Repeat the first k letters, n times
    for (int i = 0; i < n; ++i) {
      std::cout << ab.substr(0, k);
    }
    std::cout << '\n';
  }

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1925/332448729
