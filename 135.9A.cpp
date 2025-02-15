/* A. Die Roll
time limit per test1 second
memory limit per test64 megabytes
Yakko, Wakko and Dot, world-famous animaniacs, decided to rest from acting in
cartoons, and take a leave to travel a bit. Yakko dreamt to go to Pennsylvania,
his Motherland and the Motherland of his ancestors. Wakko thought about
Tasmania, its beaches, sun and sea. Dot chose Transylvania as the most
mysterious and unpredictable place.

But to their great regret, the leave turned to be very short, so it will be
enough to visit one of the three above named places. That's why Yakko, as the
cleverest, came up with a truly genius idea: let each of the three roll an
ordinary six-sided die, and the one with the highest amount of points will be
the winner, and will take the other two to the place of his/her dreams.

Yakko thrown a die and got Y points, Wakko — W points. It was Dot's turn. But
she didn't hurry. Dot wanted to know for sure what were her chances to visit
Transylvania.

It is known that Yakko and Wakko are true gentlemen, that's why if they have the
same amount of points with Dot, they will let Dot win.

Input
The only line of the input file contains two natural numbers Y and W — the
results of Yakko's and Wakko's die rolls.

Output
Output the required probability in the form of irreducible fraction in format
«A/B», where A — the numerator, and B — the denominator. If the required
probability equals to zero, output «0/1». If the required probability equals to
1, output «1/1».

Examples
InputCopy
4 2
OutputCopy
1/2
Note
Dot will go to Transylvania, if she is lucky to roll 4, 5 or 6 points.

*/

// Yakko - Pennsylvania
// Wakko - Tasmania
// Dot - Transylvania
// One with highest points on dice roll will win, hence choose his place to
// visit Yakko - Y points Wakko - W points Dot chance to visit, if Yakko and
// Wakko have same points then Dot wins log Dot chance in form of fraction
#include <algorithm>
#include <iostream>
#include <string>
std::string sol(int Y, int W) {

  /* first find which is greater Y or W
   * then find how many space set for D to win
   * then find probability of D to win
   * if probability is 0 then output 0/1
   * for Dot to win, output are 4,5,6*/

  if (Y < W) {
    Y = W;
  }
  // space set for D to win
  // say diff b/w Y and 6 is spaceset for D
  // return total D output, Y output for space set
  // nah, may give wrong

  // Constants and probability calculation
  const int numSides = 6;
  int numerator = numSides - Y + 1;
  int denominator = numSides;

  // Calculate GCD and simplify fraction
  int div = std::__gcd(numerator, denominator);
  numerator /= div;
  denominator /= div;

  // Return result as string
  return std::to_string(numerator) + "/" + std::to_string(denominator);
}
// int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }

int main() {
  int Y, W;
  std::cin >> Y >> W;
  // sol();  failes on 3rd testcase
  std::cout << sol(Y, W);

  std::cin.get();
}
// sub: https://codeforces.com/problemset/submission/9/306163737
