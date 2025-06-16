/* A2. Gardener and the Capybaras (hard version)
time limit per test1 second
memory limit per test256 megabytes
This is an hard version of the problem. The difference between the versions is
that the string can be longer than in the easy version. You can only do hacks if
both versions of the problem are passed.

Kazimir Kazimirovich is a Martian gardener. He has a huge orchard of binary
balanced apple trees.

Recently Casimir decided to get himself three capybaras. The gardener even came
up with their names and wrote them down on a piece of paper. The name of each
capybara is a non-empty line consisting of letters "a" and "b".

Denote the names of the capybaras by the lines 𝑎
, 𝑏
, and 𝑐
. Then Casimir wrote the nonempty lines 𝑎
, 𝑏
, and 𝑐
 in a row without spaces. For example, if the capybara's name was "aba", "ab",
and "bb", then the string the gardener wrote down would look like "abaabbb".

The gardener remembered an interesting property: either the string 𝑏
 is lexicographically not smaller than the strings 𝑎
 and 𝑐
 at the same time, or the string 𝑏
 is lexicographically not greater than the strings 𝑎
 and 𝑐
 at the same time. In other words, either 𝑎≤𝑏
 and 𝑐≤𝑏
 are satisfied, or 𝑏≤𝑎
 and 𝑏≤𝑐
 are satisfied (or possibly both conditions simultaneously). Here ≤
 denotes the lexicographic "less than or equal to" for strings. Thus, 𝑎≤𝑏
 means that the strings must either be equal, or the string 𝑎
 must stand earlier in the dictionary than the string 𝑏
. For a more detailed explanation of this operation, see "Notes" section.

Today the gardener looked at his notes and realized that he cannot recover the
names because they are written without spaces. He is no longer sure if he can
recover the original strings 𝑎 , 𝑏 , and 𝑐 , so he wants to find any triplet of
names that satisfy the above property.


Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The only line of a test case contains the string 𝑠
 (3≤|𝑠|≤2⋅105
) — the names of the capybaras, written together. The string consists of English
letters 'a' and 'b' only.

It is guaranteed that the sum of string lengths over all test cases does not
exceed 4⋅105
.

Output
For each test case, print three strings 𝑎
, 𝑏
 and 𝑐
 on a single line, separated by spaces — names of capybaras, such that writing
them without spaces results in a line 𝑠 . Either 𝑎≤𝑏 and 𝑐≤𝑏 , or 𝑏≤𝑎 and 𝑏≤𝑐
 must be satisfied.

If there are several ways to restore the names, print any of them. If the names
cannot be recovered, print ":(" (without quotes).

Example
InputCopy
5
bbba
aba
aaa
abba
abbb
OutputCopy
b bb a
a b a
a a a
ab b a
a bb b
Note
A string 𝑥
 is lexicographically smaller than a string 𝑦
 if and only if one of the following holds:

𝑥
 is a prefix of 𝑦
, but 𝑥≠𝑦
;
in the first position where 𝑥
 and 𝑦
 differ, the string 𝑥
 has the letter 'a', and the string 𝑦
 has the letter 'b'.
Now let's move on to the examples.

In the first test case, one of the possible ways to split the line 𝑠
 into three lines —is "b", "bb", "a".

In the third test case, we can see that the split satisfies two conditions at
once (i.e., 𝑎≤𝑏 , 𝑐≤𝑏 , 𝑏≤𝑎 and 𝑏≤𝑐 are true simultaneously).



*/

#include <iostream>

int main() {

  std::ios_base::sync_with_stdio(false);
  long t;
  std::cin >> t;
  while (t--) {
    std::string s;
    std::cin >> s;
    std::string x = "", y = "", z = "";
    if (s[0] == s.back()) {
      x = s[0];
      y = s.substr(1, s.size() - 2);
      z = s.back();
    } else if (s[1] == 'a') {
      x = s[0];
      y = s[1];
      z = s.substr(2, s.size() - 2);
    } else {
      x = s[0];
      y = s.substr(1, s.size() - 2);
      z = s.back();
    }

    std::cout << x << " " << y << " " << z << std::endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1775/324579098
