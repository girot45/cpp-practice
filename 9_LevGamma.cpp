#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;

string LevGamma(unsigned num);
vector<int> ToBinary(unsigned num);
bool Test();

int main()
{
    unsigned num;
    cout << "Enter the number: ";
    cin >> num;
    cout << "Result: " << LevGamma(num) << endl;
    //Test();
    _getch();
    return 1;
}

string LevGamma(unsigned num)
{
    if (!num) return "0";
    vector<int> bin = ToBinary(num), result;
    int i = 0;
    for (i; i < bin.size() - 1; i++)
    {
        result.push_back(0);
        result.push_back(bin[i]);
    }
    result.push_back(bin[i]);
    string s = "";
    for (int i = 0; i < result.size(); i++)
        s += (int) result[i] + '0';
    return s;
}

vector<int> ToBinary(unsigned num)
{
    vector<int> result;
    while (num)
    {
        result.push_back(num % 2);
        num /= 2;
    }
    return result;
}
bool Test()
{
    if (
        LevGamma(0) == "0" &&
        LevGamma(1) == "1" &&
        LevGamma(2) == "001" &&
        LevGamma(3) == "011" &&
        LevGamma(4) == "00001" &&
        LevGamma(5) == "01001" &&
        LevGamma(13) == "0100011" &&
        LevGamma(63) == "01010101011" &&
        LevGamma(129) == "010000000000001"
        )
    {
        cout << "Test completed successfully" << endl;
        return true;
    }
    else cout << "Test failed" << endl;
    return false;
}
