//Header
#include <iostream>
#include <cmath> //More complex math
#include <string> //to use strings
#include <limits> // INT_MIN, INT_MAX, LONG_MIN, LONG_MAX
#include <cfloat> // FLT_MIN, FLT_MAX, DBL_MIN, DBL_MAX
#include <ctime> // Time
using namespace std;

//body
int main()
{
    int x;  //will round up or down one, no decimals
    x = 1

    double x;  // for use with decimals, more precicse
    x = 1.0

    const double PI = 3.1415926 // constants will always be uppercase, declare above int main() (think declaring globally in python).

    const int MAX = 45  // There are int that are constant.

    short (2 bytes), int (4 bytes), long (8 bytes) (signed or unsigned) //All integer type, each is either signed or unsigned.

    short int i = 2; is the same as short i = 2;

    sizeof (int), sizeof (long), sizeof (double) // returns the number of bytes for int, long, double.

    sizeof (area), sizeof (age) // number of bytes for area and age

    //Numeric operators

    //Operator  name            example         result
        +       addition        34 + 1          35
        -       subtraction     34.0 - 0.1      33.9
        *       multiplication  300 * 30        9000
        /       division        1.0 / 2.0       0.5 //one of the operands must be floating point
        %       remainder       20 % 3          2   //think of 20 / 3 = 1 (remainder 2)


        // <cmath> operators

    //operator      name        example         result
    pow(a , b)  exponent        pow(3.0 , 2)      9


    time(0) // UNIX epoch (January 1, 1970)
        // example of how to program current time

        int totalSeconds = time(0); //totalSeconds
        totalSeconds % 60 // = 26 seconds
        totalMinutes % 60 // to get minutes
        totalMinutes % 60 // = 31 minutes

    return 0;
}
