#include <iostream>

int main()
{
    {
        int age;
        int day;
        int rating;
        double price = 10.00;
        bool isWeekend = (day == 6 || day == 7);

        std::cout << "enter age:";
        std::cin >> age;

        std::cout << "Enter day of the week (1-7, where 1 is Monday):";
        std::cin >> day;


        std::cout << "Enter movie rating (1-5)";
        std::cin >> rating;

        if (age < 5)
        {
            std::cout << "Free admision for children under 5!\n";

            return 0;
        }
        if (age >= 60)
        {
            price *= 0.8; // 20% discount for seniors
        }
        else if (age < 18 && age > 12) && isWeekend && (rating >3 );
                    {
                        price *= 0.9; //10 discount for teens on weekend for highly rated
                    }
        switch(rating)
        {
        case 5:
                switch (day)
            {
         case 1:
         case 2:
                switch (age)
                {
                case 18 ... 25:
                    price *= 0.85; // discount for young adults on low traffic days
                    break;
                default:
                    break;
                }

            }

                default:
                    break;

                case 1:
                case 2:
                    price *=0.95;
                default:
                    break;
        }


        }
std::cout << "Ticket price $ " << price << std::endl;


    return 0;
}
