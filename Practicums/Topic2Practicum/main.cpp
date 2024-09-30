#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // Declare names/salary

    double firstName, lastName, updatedSalary, m, g, s;
    string miller, green, sethi;

    // Read Data.txt

    ifstream ifs;
    ifs.open("Data.txt");
    char temp = ifs.peek();
    ifs.get(temp);

    // Calculate salaries

    m = 65789.87;
    g = 75892.56;
    s = 74900.50;

    miller = (m * 0.05);
    green = (g * 0.06);
    sethi = (s * 0.061);

    cout << miller, green, sethi;
    // Write new data to Data.txt

    //


    /* cout << temp;
    ifs.get(temp);
    cout << temp;
    ifs.get(temp);
    cout << temp;
    ifs.get(temp);
    cout << temp;
    ifs.get(temp);
    cout << temp;

    ifs.close();  */

    /*  ostream ofs;
    ofs.open("Data.txt")
    ofs << "It was not a cat, rather a mongoose \n now you know \n"<<endl;
    ofs.close();    */
    return 0;
}
