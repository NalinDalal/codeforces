/* A. Black Square
time limit per test1 second
memory limit per test256 megabytes
Quite recently, a very smart student named Jury decided that lectures are
boring, so he downloaded a game called "Black Square" on his super cool
touchscreen phone.

In this game, the phone's screen is divided into four vertical strips. Each
second, a black square appears on some of the strips. According to the rules of
the game, Jury must use this second to touch the corresponding strip to make the
square go away. As Jury is both smart and lazy, he counted that he wastes
exactly ai calories on touching the i-th strip.

You've got a string s, describing the process of the game and numbers
a1, a2, a3, a4. Calculate how many calories Jury needs to destroy all the
squares?

Input
The first line contains four space-separated integers a1, a2, a3, a4
(0 ≤ a1, a2, a3, a4 ≤ 104).

The second line contains string s (1 ≤ |s| ≤ 105), where the і-th character of
the string equals "1", if on the i-th second of the game the square appears on
the first strip, "2", if it appears on the second strip, "3", if it appears on
the third strip, "4", if it appears on the fourth strip.

Output
Print a single integer — the total number of calories that Jury wastes.

Examples
InputCopy
1 2 3 4
123214
OutputCopy
13
InputCopy
1 5 3 2
11221
OutputCopy
13
*/
#include <iostream>
#include <string>
#include <vector>

int main() {
  const int N = 4;
  std::vector<long> a(N, 0);
  std::vector<long> freq(N, 0);

  // Read the array
  for (int k = 0; k < N; k++) {
    std::cin >> a[k];
  }

  std::cin.ignore(); // Ignore the newline after reading numbers
  std::string input;
  std::getline(std::cin, input);

  // Count occurrences of '1', '2', '3', '4'
  for (char ch : input) {
    if (ch >= '1' && ch <= '4') {
      ++freq[ch - '1'];
    }
  }

  // Compute the total sum
  long total = 0;
  for (int k = 0; k < N; k++) {
    total += a[k] * freq[k];
  }

  std::cout << total << std::endl;
  return 0;
}
// sub: https://codeforces.com/problemset/submission/431/306445648
