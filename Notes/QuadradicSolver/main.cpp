#include <iostream>
#include <cmath>

using namespace std;

int main()

{
    double a, b , c;

    int answerPositive, answerNegative;

    cout << "Please enter an a value: " << endl;
    cin >> a;

    cout << "Now let's have the b value: " << endl;
    cin >> b;

    cout << "Lastly I need the c value: " << endl;
    cin >> c;


    answerPositive = (-b + pow((b * b) - (4 * a *c), 0.5)) / (2 * a);

    answerNegative = (-b + pow(b * b - 4 * a *c, 0.5)) / (2 * a);

    cout << "Your positive answer is: " << answerPositive << endl;
    cout << "Your negative answer is: " << answerNegative;


    return 0;

}
