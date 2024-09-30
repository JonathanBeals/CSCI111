#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    // Part A compute e using limits
    cout << "Part A: compute limit\n";
    cout << "-----------------------\n";

    for (int n = 100; n <= 1000000; n *= 10)
    {
        double e_limit = pow(1+ 1.0/n, n);
        cout << "For n = " << n << ", e = " << fixed << setprecision(9) << e_limit << endl;
    }

    //Part B
    cout << "Part B; compute e using approximation formula\n";
    cout << "---------------------------------------------\n";

    for (int n : {4, 8, 10, 12})
        {
            double e_approx_b = 1.0;
            double factorial = 1.0;
            for (int i = 1; i <= n; ++i);
            {
                factorial *= i;
                e_approx_b = += 1.0/ factorial;
            }
            cout << "For n = " << n << ", e = " << fixed << setprecision(9) << e_approx_b << endl;
        }

    //Part C: Compute e using approximation formula C\n
    cout << "Part C: Compute e using approximation formula C\n";
    cout << "-----------------------------------------------\n";

    for (int n : {3,5,10,50,100})
        {
            double e_approx_c = 0.0;
            double factorial = 1.0;

            for (int i = 0; i<=n; ++i)
            {
                if  (i == 0)
                e_approx_c += 1.0;
                else
                {
                    factorial *= i;
                    e_approx_c += 1.0 / factorial;
                }
            }
            cout << "For n = " << n << ", e = " << fixed << setprecision(9) << e_approx_b << endl;
        }

    return 0;
}
