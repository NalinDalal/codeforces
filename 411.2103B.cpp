/*B. Binary Typewriter
time limit per test1.5 seconds
memory limit per test256 megabytes

You are given a binary string 𝑠
 of length 𝑛
 and a typewriter with two buttons: 0 and 1. Initially, your finger is on the
button 0. You can do the following two operations:

Press the button your finger is currently on. This will type out the character
that is on the button. Move your finger to the other button. If your finger is
on button 0, move it to button 1, and vice versa. The cost of a binary string is
defined as the minimum number of operations needed to type the entire string.

Before typing, you may reverse at most one substring∗
 of 𝑠
. More formally, you can choose two indices 1≤𝑙≤𝑟≤𝑛
, and reverse the substring 𝑠𝑙…𝑟
, resulting in the new string 𝑠1𝑠2…𝑠𝑙−1𝑠𝑟𝑠𝑟−1…𝑠𝑙𝑠𝑟+1…𝑠𝑛
.

Your task is to find the minimum possible cost among all strings obtainable by
performing at most one substring reversal on 𝑠
.

∗
A string 𝑎
 is a substring of a string 𝑏
 if 𝑎
 can be obtained from 𝑏
 by the deletion of several (possibly, zero or all) characters from the
beginning and several (possibly, zero or all) characters from the end.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (1≤𝑛≤2⋅105
) — the length of the binary string 𝑠
.

The second line of each test case contains a binary string 𝑠1𝑠2…𝑠𝑛
 (𝑠𝑖=𝟶
 or 𝑠𝑖=𝟷
) — the characters of the binary string 𝑠
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output the minimum cost of string 𝑠
 after performing at most one substring reversal.

Example
InputCopy
6
3
000
3
111
3
011
3
100
5
10101
19
1101010010011011100
OutputCopy
3
4
4
4
8
29
Note
In the first test case, we can choose not to reverse any substrings. We can do
operation 1 three times to type 000.

In the second test case, we can choose not to reverse any substrings. We can do
operation 2 to move our finger to button 1. Then, we do operation 1 three times
to type 111.

In the third test case, we can choose not to reverse any substring. We can do
operation 1 to type 0. Then, we do operation 2 to move our finger to button 1.
Finally, we do operation 1 two times to type 11, resulting in the final string
011 using only 4 operations.

In the fourth test case, we can reverse the substring 𝑠1…3
, resulting in the string 001. We can do operation 1
 two times to type 00. Then we do operation 2
 to move our finger to button 1. Finally, we do operation 1
 once to type 1, resulting in the final string 001 using only 4
 operations.

In the fifth test case, we can reverse the substring 𝑠2…3
, resulting in the string 11001. The cost of the string is 8
 as we can do the following sequence of operations:

Do operation 2
 to move our finger to button 1.
Do operation 1
 two times to type 11.
Do operation 2
 to move our finger to button 0.
Do operation 1
 two times to type 00.
Do operation 2
 to move our finger to button 1.
Do operation 1
 once to type 1.
In the sixth test case, we can reverse the substring 𝑠5…17
, resulting in the string 1101111011001001000. It can be proven that the minimum
number of operations needed to type the binary string is 29
.



*/

#include <iostream>
int main() {

  std::ios_base::sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    long inv(s[0] == '1');
    for (long p = 1; p < s.size(); p++) {
      inv += (s[p - 1] != s[p]);
    }
    if (inv == 2) {
      inv = 1;
    } else if (inv > 2) {
      inv -= 2;
    }
    std::cout << (s.size() + inv) << std::endl;
  }
}
// sub: https://codeforces.com/problemset/submission/2103/323984999
