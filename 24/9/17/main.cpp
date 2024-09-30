#include <iostream>

void readNumbers(int numbers[], int size);
int findLargest(int numbers[], int size);
void display(int);
char temp;
void convertToBinary[int];

int main(int argc, const char * argv[])
{

    const int size = 10;
    int numbers[size]; //Array size of 10
    //read data from monkey
    readNumbers(numbers, size);
    //define variable to hold largest
    int largest = findLargest(numbers, size);
    //display findings
    display(largest);
    std::cout << "Would you like this largest number converted to binary: ";
    std::cin >> temp;
    if ('y' == temp || 'Y' == temp)
        convertToBinary(largest);
    return 0;
}

//read the size value number of integers from the user
void readNumbers(int numbers[], int size)
{
    for(int i =0; i < 10; i++)
    {
        std::cout << "Please enter a numberic number no decimal fractions: ";
        std::cin >> numbers[i];
    }
    return;
}

//Identifies the largest value in the list of numbers by
//sequential comparison
//requires a list of integers and its size
//returns a single integer being the largest value found

int findLargest(int numbers[], int size)
{

    int maximum = numbers[0];
    for(int i =1; i < 10; i++)
    {
        if(numbers[i]>maximum)
            maximum = numbers[i];
    }

    return maximum;
}

//outputs the maximum value stored
void display(int result)
{
    std::cout << "largest number provided by the monkey is: " << result << std::endl;
    return;
}

//Takes a decimal input and converts it to base 2 using floor and remainder
void convertToBinary(int decimal)
{
    std::string binary;
    std::cout <<"Binary bitpattern for " << decimal;
    while(decimal > 0)
    {
        binary += std::to_string(decimal%2)
        decimal/=2;
    }
    std::string reversed;
    for (int i = (int)binary.length()-1; i>= 0; i--)
        reversed += binary[i];
    std::cout <<" is: " << reversed << std::endl;
}



