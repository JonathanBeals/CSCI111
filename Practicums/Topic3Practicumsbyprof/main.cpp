#include <iostream>


int main()
{

    double number;

    std::cout<<"Enter your score: ";
    std::cin>>number;

    if (number >= 90)
    {
        std::cout << "You got an A";
    }
    else if (number >= 75)
    {
        std::cout << "You got a B";
    }
    else if (number >=60)
    {
        std::cout << "You got a C";
    }
    else if (number >=50)
    {
        std::cout << "You got a D";
    }
    else
    {
        std::cout << "You got a F";
    }

    return 0;

}

#include <iostream>


int main()
{

    int a,b,c;

    std::cout<<"Enter lengths of triangle sides ";
    std::cin>>number;

    if (a==b && b==c)
    {
        std::cout << "Equalateral";
    }
    else if (a==b || b==c || a==c)
    {
        std::cout << "Isosceles";
    }
    else
    {
        std::cout << "Scalene";
    }
    return 0;

}
*/

#include <iostream>


int main()
{

    double number;

    std::cout<<"Enter your score: ";
    std::cin>>number;

    if (number >= 90)
    {
        std::cout << "You got an A";
    }
    else if (number >= 75)
    {
        std::cout << "You got a B";
    }
    else if (number >=60)
    {
        std::cout << "You got a C";
    }
    else if (number >=50)
    {
        std::cout << "You got a D";
    }
    else
    {
        std::cout << "You got a F";
    }

    return 0;

}
