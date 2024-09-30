#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(int argc, const char * argv[])
{
    //Part A:

    cout << "Part A: Compute e using limit expression\n"
    << "----------------------------------------\n";

    for (int n = 100 ; n <= 1000000 ; n *= 10)
    {
        double e_limit = pow(1 + 1.0 /n , n);
        cout << "For n = " << n << ", e = "<< fixed << setprecision(9) << e_limit << endl;
    }
    cout << endl;


    //Part B:
    cout << "Part B: Compute e using approximation formula B\n"
         << "-----------------------------------------------\n";

    for(int n:{4,8,10,12})
        {
            double e_approx_b = 1.0, factorial = 1.0;

            for(int i = 1; i <= n; ++i)
            {
                factorial *= i;
                e_approx_b +=1.0/factorial;
            }
            cout << "for n = " << n << "e = " << fixed << setprecision(9) << e_approx_b << endl;

        }
    cout << endl;

    //part C:

    cout << "Part C: Compute e using approximation formula C\n"
         << "------------------------------------------------\n";

         for(int n:{3,5,10,50,100})
        {
            double e_approx_c = 0.0, factorial = 1.0;
            for (int i = 0; <= n; ++i)
            {
                if (i == 0)
                    e_approx_c += 1.0;
                else
                {
                    factorial *= i;
                    e_approx_c += 1.0/factorial;
                }
                cout << "for n = " << n << "e =" fixed << setprecision(9) << e_approx_c << endl;
            }
    return 0;
}
