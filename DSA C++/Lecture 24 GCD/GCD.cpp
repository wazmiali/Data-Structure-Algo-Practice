// Greatest Common Divisor
#include <iostream>
using namespace std;

int gcd(int a, int b)
{

      if (a == 0)
            return b;

      if (b == 0)
            return a;

      while (a != b)
      {

            if (a > b)
            {
                  a = a - b;
            }
            else
            {
                  b = b - a;
            }
      }
      return a;
}

int main()
{

      int a, b;
      cout << "Enter the value of a and b" << endl;

      cin >> a >> b;

      int ans = gcd(a, b);

      cout << "The GCD of: " << a << " & " << b << " is " << ans << endl;

      return ans;

}

// Steps inside gcd(48, 18):

// 48 > 18 → 48 - 18 = 30 → (30, 18)

// 30 > 18 → 30 - 18 = 12 → (12, 18)

// 18 > 12 → 18 - 12 = 6 → (12, 6)

// 12 > 6 → 12 - 6 = 6 → (6, 6)

// Now both are equal → GCD = 6.

