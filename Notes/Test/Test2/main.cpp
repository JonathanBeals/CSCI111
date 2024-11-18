#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double point1, point2, point3, point4, point5, point6, s, side1, side2, side3, area;

    cout << "Enter x1: ";
    cin >> point1;

    cout << "Enter y1: ";
    cin >> point2;

    cout << "Enter x2: ";
    cin >> point3;

    cout << "Enter y2: ";
    cin >> point4;

    cout << "Enter x3: ";
    cin >> point5;

    cout << "Enter y3: ";
    cin >> point6;

    side1 = pow((point3 - point1) * (point3 - point1) + (point4 - point2) * (point4 - point2), 0.5);
    side2 = pow((point5 - point3) * (point5 - point3) + (point6 - point4) * (point6 - point4), 0.5);
    side3 = pow((point1 - point5) * (point1 - point5) + (point2 - point6) * (point2 - point6), 0.5);

    s = ( side1 + side2 + side3 ) / 2;

    area = pow(s * ( s-side1 ) * ( s - side2 ) * ( s- side3 ), 0.5);

    cout << "The area of the triangle is equal to " << area << endl;

    return 0;
}
