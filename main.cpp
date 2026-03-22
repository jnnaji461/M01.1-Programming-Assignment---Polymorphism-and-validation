/* Program Name:Roman numeral converter.cpp
* Author: Judith Nnaji
* Date:03/20/2026
* Purpose:The programme convert Roman numeral to Decimal
*/


#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class romanType
{
private:
    string romanNum;
    int decimalNum;

    int valueOf(char romanChar)
    {
        switch (toupper(romanChar))
        {
        case 'M': return 1000;
        case 'D': return 500;
        case 'C': return 100;
        case 'L': return 50;
        case 'X': return 10;
        case 'V': return 5;
        case 'I': return 1;
        default:  return 0;
        }
    }

public:
    romanType()
    {
        romanNum = "";
        decimalNum = 0;
    }

    romanType(string roman)
    {
        romanNum = roman;
        convertToDecimal();
    }

    void setRoman(string roman)
    {
        romanNum = roman;
        convertToDecimal();
    }

    void convertToDecimal()
    {
        decimalNum = 0;

        for (int i = 0; i < romanNum.length(); i++)
        {
            int current = valueOf(romanNum[i]);

            if (i < romanNum.length() - 1)
            {
                int next = valueOf(romanNum[i + 1]);

                if (current < next)
                    decimalNum -= current;
                else
                    decimalNum += current;
            }
            else
            {
                decimalNum += current;
            }
        }
    }

    void printRoman() const
    {
        cout << "Roman Numeral: " << romanNum << endl;
    }

    void printDecimal() const
    {
        cout << "Decimal Value: " << decimalNum << endl;
    }
};

int main()
{
    string input;
    char choice;
    char again;

    cout << "Roman Numeral to Decimal Converter" << endl;
    cout << "----------------------------------" << endl;

    do
    {
        cout << "\nEnter a Roman numeral: ";
        cin >> input;

        romanType userRoman(input);

        cout << "\nChoose what to display:" << endl;
        cout << "R - Print Roman numeral" << endl;
        cout << "D - Print Decimal value" << endl;
        cout << "B - Print Both" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        cout << endl;

        switch (toupper(choice))
        {
        case 'R':
            userRoman.printRoman();
            break;

        case 'D':
            userRoman.printDecimal();
            break;

        case 'B':
            userRoman.printRoman();
            userRoman.printDecimal();
            break;

        default:
            cout << "Invalid choice." << endl;
        }

        cout << "\nDo you want to enter another Roman numeral? (Y/N): ";
        cin >> again;

    } while (toupper(again) == 'Y');

    cout << "\nRequired Test Cases" << endl;
    cout << "-------------------" << endl;

    romanType test1("MCXIV");
    romanType test2("CCCLIX");
    romanType test3("MDCLXVI");

    test1.printRoman();
    test1.printDecimal();
    cout << endl;

    test2.printRoman();
    test2.printDecimal();
    cout << endl;

    test3.printRoman();
    test3.printDecimal();
    cout << endl;

    cout << "Program ended." << endl;

    return 0;
}