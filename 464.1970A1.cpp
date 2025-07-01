/*A1. Balanced Shuffle (Easy)
time limit per test2 seconds
memory limit per test256 megabytes
A parentheses sequence is a string consisting of characters "(" and ")", for
example "(()((".

A balanced parentheses sequence is a parentheses sequence which can become a
valid mathematical expression after inserting numbers and operations into it,
for example "(()(()))".

The balance of a parentheses sequence is defined as the number of opening
parentheses "(" minus the number of closing parentheses ")". For example, the
balance of the sequence "(()((" is 3.

A balanced parentheses sequence can also be defined as a parentheses sequence
with balance 0 such that each of its prefixes has a non-negative balance.

We define the balanced shuffle operation that takes a parentheses sequence and
returns a parentheses sequence as follows: first, for every character of the
input sequence, we compute the balance of the prefix of the sequence before that
character and write those down in a table together with the positions of the
characters in the input sequence, for example:

Prefix balance	0	1	2	1	2	3	2	1
Position	1	2	3	4	5	6	7	8
Character	(	(	)	(	(	)	)	)
Then, we sort the columns of this table in increasing order of prefix balance,
breaking ties in decreasing order of position. In the above example, we get:

Prefix balance	0	1	1	1	2	2	2	3
Position	1	8	4	2	7	5	3	6
Character	(	)	(	(	)	(	)	)
The last row of this table forms another parentheses sequence, in this case
"()(()())". This sequence is called the result of applying the balanced shuffle
operation to the input sequence, or in short just the balanced shuffle of the
input sequence.

You are given a balanced parentheses sequence. Print its balanced shuffle.

Input
The only line of input contains a string 𝑠
 consisting only of characters "(" and ")". This string is guaranteed to be a
non-empty balanced parentheses sequence with its length not exceeding 500000
.

Output
Print the parentheses sequence 𝑡
 — the balanced shuffle of 𝑠
.

Example
InputCopy
(()(()))
OutputCopy
()(()())


*/

#include <algorithm>
#include <iostream>
#include <vector>

bool cmp(std::pair<long, long> a, std::pair<long, long> b) {
  if (a.first == b.first) {
    return a.second > b.second;
  } else {
    return a.first < b.first;
  }
}

int main() {

  std::string s;
  std::cin >> s;
  std::vector<std::pair<long, long>> v(s.size());
  long cnt(0);
  for (long p = 0; p < s.size(); p++) {
    v[p] = std::make_pair(cnt, p);
    cnt += (s[p] == '(') - (s[p] == ')');
  }

  sort(v.begin(), v.end(), cmp);

  std::string t(s.size(), '.');
  for (long p = 0; p < v.size(); p++) {
    t[p] = s[v[p].second];
  }
  std::cout << t << std::endl;

  return 0;
}
// sub: https://codeforces.com/problemset/submission/1970/326921086
