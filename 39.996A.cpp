/*
https://codeforces.com/problemset/problem/996/A

A. Hit the Lottery
time limit per test1 second
memory limit per test256 megabytes
Allen has a LOT of money. He has 𝑛 dollars in the bank. For security reasons, he
wants to withdraw it in cash (we will not disclose the reasons here). The
denominations for dollar bills are 1, 5, 10, 20, 100. What is the minimum number
of bills Allen could receive after withdrawing his entire balance?

Input
The first and only line of input contains a single integer 𝑛 (1≤𝑛≤109).

Output
Output the minimum number of bills that Allen could receive.

Examples
InputCopy
125
OutputCopy
3

InputCopy
43
OutputCopy
5

InputCopy
1000000000
OutputCopy
10000000

Note
In the first sample case, Allen can withdraw this with a 100 dollar bill, a 20
dollar bill, and a 5 dollar bill. There is no way for Allen to receive 125
dollars in one or two bills.

In the second sample case, Allen can withdraw two 20 dollar bills and three 1
dollar bills.

In the third sample case, Allen can withdraw 100000000 (ten million!) 100 dollar
bills.

*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  // get minimum number of bills
  vector<int> v = {100, 20, 10, 5, 1};
  int count = 0;

  // what can we do, we can divide the money n by vector v max times, increase
  // count by 1
  // if we can't divide money by v like if not by v[6] then divide by v[5]
  // repeat till v[0]
  // return count

  // Greedy algorithm: use the largest denomination as much as possible
  for (int bill : v) {
    count += n / bill; // Add the number of bills of the current denomination
    n %= bill;         // Update the remaining amount
  }
  cout << count << endl;
  return 0;
}
