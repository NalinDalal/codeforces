/*
 https://codeforces.com/problemset/problem/469/A

A. I Wanna Be the Guy
time limit per test1 second
memory limit per test256 megabytes
There is a game called "I Wanna Be the Guy", consisting of n levels. Little X
and his friend Little Y are addicted to the game. Each of them wants to pass the
whole game.

Little X can pass only p levels of the game. And Little Y can pass only q levels
of the game. You are given the indices of levels Little X can pass and the
indices of levels Little Y can pass. Will Little X and Little Y pass the whole
game, if they cooperate each other?

Input
The first line contains a single integer n (1 ≤  n ≤ 100).

The next line contains an integer p (0 ≤ p ≤ n) at first, then follows p
distinct integers a1, a2, ..., ap (1 ≤ ai ≤ n). These integers denote the
indices of levels Little X can pass. The next line contains the levels Little Y
can pass in the same format. It's assumed that levels are numbered from 1 to n.

Output
If they can pass all the levels, print "I become the guy.". If it's impossible,
print "Oh, my keyboard!" (without the quotes).

Examples
InputCopy
4
3 1 2 3
2 2 4
OutputCopy
I become the guy.
InputCopy
4
3 1 2 3
2 2 3
OutputCopy
Oh, my keyboard!
Note
In the first sample, Little X can pass levels [1 2 3], and Little Y can pass
level [2 4], so they can pass all the levels both.

In the second sample, no one can pass level 4.
*/

#include <iostream>
#include <set>

using namespace std;
// number of levels=n

// p integer
// a[] array of size p
// input the array to
// if both x,y can pass print "I become the guy"
// else print "Oh, my keyboard!"

/* Use a set to store the levels both players can pass. Since set only keeps
unique values, adding levels from both players will automatically handle
duplicates. If the size of the set is equal to n, it means they can pass all
levels. Otherwise, there are levels they can't pass.
*/

int main() {
  int n; // Total number of levels
  cin >> n;

  set<int> levels; // To store unique levels passed by both players

  // Input levels Little X can pass
  int p;
  cin >> p;
  for (int i = 0; i < p; i++) {
    int level;
    cin >> level;
    levels.insert(level);
  }

  // Input levels Little Y can pass
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int level;
    cin >> level;
    levels.insert(level);
  }

  // Check if they can pass all levels
  if (levels.size() == n) {
    cout << "I become the guy." << endl;
  } else {
    cout << "Oh, my keyboard!" << endl;
  }

  return 0;
}
