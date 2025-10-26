/*C. Move Brackets
time limit per test1 second
memory limit per test256 megabytes
You are given a bracket sequence 𝑠
 of length 𝑛
, where 𝑛
 is even (divisible by two). The string 𝑠
 consists of 𝑛2
 opening brackets '(' and 𝑛2
 closing brackets ')'.

In one move, you can choose exactly one bracket and move it to the beginning of
the string or to the end of the string (i.e. you choose some index 𝑖 , remove
the 𝑖 -th character of 𝑠 and insert it before or after all remaining characters
of 𝑠
).

Your task is to find the minimum number of moves required to obtain regular
bracket sequence from 𝑠 . It can be proved that the answer always exists under
the given constraints.

Recall what the regular bracket sequence is:

"()" is regular bracket sequence;
if 𝑠
 is regular bracket sequence then "(" + 𝑠
 + ")" is regular bracket sequence;
if 𝑠
 and 𝑡
 are regular bracket sequences then 𝑠
 + 𝑡
 is regular bracket sequence.
For example, "()()", "(())()", "(())" and "()" are regular bracket sequences,
but ")(", "()(" and ")))" are not.

You have to answer 𝑡
 independent test cases.

Input
The first line of the input contains one integer 𝑡
 (1≤𝑡≤2000
) — the number of test cases. Then 𝑡
 test cases follow.

The first line of the test case contains one integer 𝑛
 (2≤𝑛≤50
) — the length of 𝑠
. It is guaranteed that 𝑛
 is even. The second line of the test case containg the string 𝑠
 consisting of 𝑛2
 opening and 𝑛2
 closing brackets.

Output
For each test case, print the answer — the minimum number of moves required to
obtain regular bracket sequence from 𝑠 . It can be proved that the answer always
exists under the given constraints.

Example
InputCopy
4
2
)(
4
()()
8
())()()(
10
)))((((())
OutputCopy
1
0
1
3
Note
In the first test case of the example, it is sufficient to move the first
bracket to the end of the string.

In the third test case of the example, it is sufficient to move the last bracket
to the beginning of the string.

In the fourth test case of the example, we can choose last three openning
brackets, move them to the beginning of the string and obtain "((()))(())".
*/
/*(t--){
 bal=0,min_bal=0;
 for(int i: s){
    if(i=='(')bal++
    else bal--;
    min_bal = min(min_bal, bal)
 }
 ans-=min_bal;

  }
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    int bal = 0, min_bal = 0;
    for (char c : s) {
      if (c == '(')
        bal++;
      else
        bal--;
      min_bal = min(min_bal, bal);
    }
    cout << -min_bal << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/1374/345916095
