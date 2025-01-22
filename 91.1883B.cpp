/* https://codeforces.com/problemset/problem/1883/B
B. Chemistry
time limit per test2 seconds
memory limit per test256 megabytes
You are given a string s of length 𝑛, consisting of lowercase Latin letters, and
an integer 𝑘.

You need to check if it is possible to remove exactly 𝑘 characters from the
string 𝑠 in such a way that the remaining characters can be rearranged to form a
palindrome. Note that you can reorder the remaining characters in any way.

A palindrome is a string that reads the same forwards and backwards. For
example, the strings "z", "aaa", "aba", "abccba" are palindromes, while the
strings "codeforces", "reality", "ab" are not.

Input
Each test consists of multiple test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤104) — the number of the test cases. This is followed by their
description.

The first line of each test case contains two integers 𝑛 and 𝑘 (0≤𝑘<𝑛≤105) — the
length of the string 𝑠 and the number of characters to be deleted.

The second line of each test case contains a string 𝑠 of length 𝑛, consisting of
lowercase Latin letters.

It is guaranteed that the sum of 𝑛 over all test cases does not exceed 2⋅105.

Output
For each test case, output "YES" if it is possible to remove exactly 𝑘
characters from the string 𝑠 in such a way that the remaining characters can be
rearranged to form a palindrome, and "NO" otherwise.

You can output the answer in any case (uppercase or lowercase). For example, the
strings "yEs", "yes", "Yes", and "YES" will be recognized as positive answers.

Example
InputCopy
14
1 0
a
2 0
ab
2 1
ba
3 1
abb
3 2
abc
6 2
bacacd
6 2
fagbza
6 2
zwaafa
7 2
taagaak
14 3
ttrraakkttoorr
5 3
debdb
5 4
ecadc
5 3
debca
5 3
abaac
OutputCopy
YES
NO
YES
YES
YES
YES
NO
NO
YES
YES
YES
YES
NO
YES
Note
In the first test case, nothing can be removed, and the string "a" is a
palindrome.

In the second test case, nothing can be removed, but the strings "ab" and "ba"
are not palindromes.

In the third test case, any character can be removed, and the resulting string
will be a palindrome.

In the fourth test case, one occurrence of the character "a" can be removed,
resulting in the string "bb", which is a palindrome.

In the sixth test case, one occurrence of the characters "b" and "d" can be
removed, resulting in the string "acac", which can be rearranged to the string
"acca".

In the ninth test case, one occurrence of the characters "t" and "k" can be
removed, resulting in the string "aagaa", which is a palindrome.

*/
#include <iostream>
#include <string>

using namespace std;

string sol() {
  int n,
      k; // length of the string 𝑠 and the number of characters to be deleted.
  string s; // string s of size n
  cin >> n >> k;
  cin >> s;
  const int B = 26;

  // remove k char from string s so that resulting s is palindrome
  // if possible, return YES
  // else return NO
  // make helping function to check if string s is palindrome
  int freq[B] = {0}; // Frequency array for characters
  for (long p = 0; p < s.size(); p++) {
    ++freq[s[p] - 'a'];
  }

  long oddCount(0);
  for (long p = 0; p < B; p++) {
    oddCount += freq[p] % 2;
  }

  // Check if the string can be rearranged into a palindrome after removing k
  // characters
  puts(oddCount <= k + 1 ? "YES" : "NO");

  // now if it can be made palindrome, then also return yes
  // else return no is all other cases
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << sol() << endl;
  }
  return 0;
}

/* submitted code:
#include <iostream>
#include <string> // Explicitly include string header

int main() {
    const int B = 26;
    std::ios_base::sync_with_stdio(false);

    long t;
    std::cin >> t;
    while (t--) {
        long n, k;
        std::cin >> n >> k;
        std::string s;
        std::cin >> s;
        int v[B] = {0};
        for (long p = 0; p < s.size(); p++) {
            ++v[s[p] - 'a'];
        }
        long cnt(0);
        for (long p = 0; p < B; p++) {
            cnt += v[p] % 2;
        }
        puts(cnt <= k + 1 ? "YES" : "NO");
    }
    return 0;
}
*/

// sub: https://codeforces.com/problemset/submission/1883/302487037
