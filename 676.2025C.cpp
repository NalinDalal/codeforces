/*C. New Game
time limit per test2 seconds
memory limit per test512 megabytes
There's a new game Monocarp wants to play. The game uses a deck of 𝑛
 cards, where the 𝑖
-th card has exactly one integer 𝑎𝑖
 written on it.

At the beginning of the game, on the first turn, Monocarp can take any card from
the deck. During each subsequent turn, Monocarp can take exactly one card that
has either the same number as on the card taken on the previous turn or a number
that is one greater than the number on the card taken on the previous turn.

In other words, if on the previous turn Monocarp took a card with the number 𝑥
, then on the current turn he can take either a card with the number 𝑥
 or a card with the number 𝑥+1
. Monocarp can take any card which meets that condition, regardless of its
position in the deck.

After Monocarp takes a card on the current turn, it is removed from the deck.

According to the rules of the game, the number of distinct numbers written on
the cards that Monocarp has taken must not exceed 𝑘
.

If, after a turn, Monocarp cannot take a card without violating the described
rules, the game ends.

Your task is to determine the maximum number of cards that Monocarp can take
from the deck during the game, given that on the first turn he can take any card
from the deck.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains two integers 𝑛
 and 𝑘
 (1≤𝑘≤𝑛≤200000
) — the number of cards in the deck and the maximum number of distinct numbers
that can be written on the cards that Monocarp takes.

The second line contains a sequence of integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
), where 𝑎𝑖
 is the number written on the 𝑖
-th card.

Additional constraint of the input: the sum of 𝑛
 over all test cases doesn't exceed 200000
.

Output
For each test case, print the maximum number of cards that Monocarp can take
from the deck during the game, given that on the first turn he can take any card
from the deck.

Example
InputCopy
4
10 2
5 2 4 3 4 3 4 5 3 2
5 1
10 11 10 11 10
9 3
4 5 4 4 6 5 4 4 6
3 2
1 3 1
OutputCopy
6
3
9
2
Note
In the first example, Monocarp needs to take any of the cards with the number 3
. On the next two turns, he needs to take the two remaining cards with the
number 3 . On the next three turns, he needs to take three cards with the number
4 . After that, Monocarp will not be able to take any more cards from the deck,
and he will have 6 cards.
*/
/*Restate the rules

Monocarp starts with any number.

Each next number can only be same or +1 from the previous.

Total distinct numbers used ≤ k.

Goal: maximize total cards taken.

Find a contiguous block of at most k distinct consecutive numbers that maximizes
the sum of their frequencies.

Count how many times each number appears (freq[x]).

Collect all unique numbers, sort them.

Use a sliding window across the sorted numbers:
    - Maintain two pointers L and R.
    - Keep adding freq[nums[R]] to current sum.
    - Ensure the window is valid:
        - nums[R] - nums[L] == (R - L) → the numbers are consecutive.
        - (R - L + 1) ≤ k → at most k distinct numbers.
    - If invalid, move L forward and subtract its frequency.

Track the maximum sum over all valid windows.
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];

    // Count frequencies
    unordered_map<ll, ll> freq;
    freq.reserve(n * 2);
    for (ll x : a)
      freq[x]++;

    // Put unique values into vector and sort
    vector<pair<ll, ll>> vals;
    vals.reserve(freq.size());
    for (auto &p : freq)
      vals.push_back(p);
    sort(vals.begin(), vals.end()); // by number

    int m = vals.size();
    ll ans = 0, curSum = 0;
    int L = 0;

    for (int R = 0; R < m; R++) {
      curSum += vals[R].second;

      // Ensure the window is consecutive
      while (vals[R].first - vals[L].first > R - L || R - L + 1 > k) {
        curSum -= vals[L].second;
        L++;
      }

      ans = max(ans, curSum);
    }

    cout << ans << "\n";
  }
  return 0;
}
// sub: https://codeforces.com/problemset/submission/2025/338028367
