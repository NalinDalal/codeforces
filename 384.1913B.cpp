/* B. Swap and Delete
time limit per test1 second
memory limit per test256 megabytes
You are given a binary string 𝑠
 (a string consisting only of 0-s and 1-s).

You can perform two types of operations on 𝑠
:

delete one character from 𝑠
. This operation costs 1
 coin;
swap any pair of characters in 𝑠
. This operation is free (costs 0
 coins).
You can perform these operations any number of times and in any order.

Let's name a string you've got after performing operations above as 𝑡
. The string 𝑡
 is good if for each 𝑖
 from 1
 to |𝑡|
 𝑡𝑖≠𝑠𝑖
 (|𝑡|
 is the length of the string 𝑡
). The empty string is always good. Note that you are comparing the resulting
string 𝑡 with the initial string 𝑠
.

What is the minimum total cost to make the string 𝑡
 good?

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases. Then 𝑡
 test cases follow.

The only line of each test case contains a binary string 𝑠
 (1≤|𝑠|≤2⋅105
; 𝑠𝑖∈{
0, 1}
) — the initial string, consisting of characters 0 and/or 1.

Additional constraint on the input: the total length of all strings 𝑠
 doesn't exceed 2⋅105
.

Output
For each test case, print one integer — the minimum total cost to make string 𝑡
 good.

Example
InputCopy
4
0
011
0101110001
111100
OutputCopy
1
1
0
4
Note
In the first test case, you have to delete a character from 𝑠
 to get the empty string 𝑡
. Only then 𝑡
 becomes good. One deletion costs 1
 coin.

In the second test case, you can, for example, delete the second character from
𝑠 to get the string 01, and then swap the first and second characters to get the
string 𝑡
 =
 10. String 𝑡
 is good, since 𝑡1≠𝑠1
 and 𝑡2≠𝑠2
. The total cost is 1
 coin.

In the third test case, you can, for example, swap 𝑠1
 with 𝑠2
, swap 𝑠3
 with 𝑠4
, swap 𝑠5
 with 𝑠7
, 𝑠6
 with 𝑠8
 and 𝑠9
 with 𝑠10
. You'll get 𝑡
 =
 1010001110. All swap operations are free, so the total cost is 0
.


*/

#include <iostream>

int main() {

  std::ios_base::sync_with_stdio(false);
  long t;
  std::cin >> t;
  while (t--) {
    std::string s;
    std::cin >> s;
    long z(0), a(0);
    for (long p = 0; p < s.size(); p++) {
      z += (s[p] == '0');
      a += (s[p] == '1');
    }

    long ans(0);
    for (long p = 0; !ans && p < s.size(); p++) {
      if (s[p] == '1') {
        if (z > 0) {
          --z;
        } else {
          ans = s.size() - p;
          break;
        }
      } else if (s[p] == '0') {
        if (a > 0) {
          --a;
        } else {
          ans = s.size() - p;
          break;
        }
      }
    }

    std::cout << ans << std::endl;
  }
}
// sub: https://codeforces.com/problemset/submission/1913/322398870
