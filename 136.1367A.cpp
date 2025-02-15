/* A. Short Substrings
time limit per test2 seconds
memory limit per test256 megabytes
Alice guesses the strings that Bob made for her.

At first, Bob came up with the secret string 𝑎 consisting of lowercase English
letters. The string 𝑎 has a length of 2 or more characters. Then, from string 𝑎
he builds a new string 𝑏 and offers Alice the string 𝑏 so that she can guess the
string 𝑎.

Bob builds 𝑏 from 𝑎 as follows: he writes all the substrings of length 2 of the
string 𝑎 in the order from left to right, and then joins them in the same order
into the string 𝑏.

For example, if Bob came up with the string 𝑎="abac", then all the substrings of
length 2 of the string 𝑎 are: "ab", "ba", "ac". Therefore, the string
𝑏="abbaac".

You are given the string 𝑏. Help Alice to guess the string 𝑎 that Bob came up
with. It is guaranteed that 𝑏 was built according to the algorithm given above.
It can be proved that the answer to the problem is unique.

Input
The first line contains a single positive integer 𝑡 (1≤𝑡≤1000) — the number of
test cases in the test. Then 𝑡 test cases follow.

Each test case consists of one line in which the string 𝑏 is written, consisting
of lowercase English letters (2≤|𝑏|≤100) — the string Bob came up with, where
|𝑏| is the length of the string 𝑏. It is guaranteed that 𝑏 was built according
to the algorithm given above.

Output
Output 𝑡 answers to test cases. Each answer is the secret string 𝑎, consisting
of lowercase English letters, that Bob came up with.

Example
InputCopy
4
abbaac
ac
bccddaaf
zzzzzzzzzz
OutputCopy
abac
ac
bcdaf
zzzzzz
Note
The first test case is explained in the statement.

In the second test case, Bob came up with the string 𝑎="ac", the string 𝑎 has a
length 2, so the string 𝑏 is equal to the string 𝑎.

In the third test case, Bob came up with the string 𝑎="bcdaf", substrings of
length 2 of string 𝑎 are: "bc", "cd", "da", "af", so the string 𝑏="bccddaaf".
*/

#include <iostream>
#include <string>
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    std::string b;
    std::cin >> b;
    std::string ans;
    // ans.append(b[0]);
    ans += b[0];
    for (int i = 2; i + 1 < b.size() - 1; i = i + 2) {
      // ans.append(b([i]));
      ans += b[i];
    }
    ans += b.back();
    std::cout << ans << std::endl;
  }
  return 0;
}

// say a is a string 'abac' then all sub str of length 2 are -> ab,ba,ac
// so b string therefore is-> `abbaac`
// b is provided, find original string a
// to isko eese kro ki, b me 2 size ka pointer iterate krwa ke usko string ans
// me append krwa do, cause like abbaac h to wo original h abac string 2 length
// ki window lelo
// return ans
// sub: https://codeforces.com/problemset/submission/1367/306166320
