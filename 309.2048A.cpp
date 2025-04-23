/* A. Kevin and Combination Lock
time limit per test1 second
memory limit per test256 megabytes
Kevin is trapped in Lakeside Village by Grace. At the exit of the village, there
is a combination lock that can only be unlocked if Kevin solves it.

The combination lock starts with an integer 𝑥
. Kevin can perform one of the following two operations zero or more times:

If 𝑥≠33
, he can select two consecutive digits 3
 from 𝑥
 and remove them simultaneously. For example, if 𝑥=13323
, he can remove the second and third 3
, changing 𝑥
 to 123
.
If 𝑥≥33
, he can change 𝑥
 to 𝑥−33
. For example, if 𝑥=99
, he can choose this operation to change 𝑥
 to 99−33=66
.
When the value of 𝑥
 on the combination lock becomes 0
, Kevin can unlock the lock and escape from Lakeside Village. Please determine
whether it is possible for Kevin to unlock the combination lock and escape.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
).

The only line of each test case contains a positive integer 𝑥
 (1≤𝑥≤109
).

Output
For each test case, output "YES" or "NO" (without quotes) in one line,
representing whether Kevin can unlock the combination lock and escape. You can
output the answer in any case (upper or lower). For example, the strings "yEs",
"yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
5
165
6369
666
114514
133333332
OutputCopy
YES
YES
NO
NO
YES
Note
For the first test case, 165−→−−33132−→−−3399−→−−3366−→−−3333−→−−330
.

For the second test case, 6369−→−−336336−→−−−−−−remove "33"66−→−−3333−→−−330
.

For the third test case, it can be proven that, regardless of the operations
performed, 666 cannot be transformed into 0
.


*/

#include <iostream>
using namespace std;

/*bool solution(int num) {
  if (num == 0)
    return true;
  else if (num < 33)
    return false;
  else if (!num % 33)
    return true;
  else
    solution(num - 33);
}
int sol(int x) {
  // do like if(num>=33)either subtract 33 from num
  // or select 2 consecutive 3 and revome them, like convert to string, remove
  // 2 occurences of 3, again convert to int
  // if x can be reduced to 0 return YES
  // else return NO
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    int ans = sol(x);
    solution(ans) ? cout << "YES" << endl : cout << "NO" << endl;
  }
  return 0;
}*/

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << (n % 33 ? "NO" : "YES") << endl;
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2048/316765935
