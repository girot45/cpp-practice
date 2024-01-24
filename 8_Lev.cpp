#include <iostream>
#include <cmath>
#include <vector>
#include <conio.h>
using namespace std;

string Lev(unsigned num);
vector<bool> ToBinary(unsigned num);
bool Test();

int main()
{
    unsigned num;
    cout << "Enter the number: ";
    cin >> num;
    cout << "Result: " << Lev(num) << endl;
    _getch();
    return 1;
}

string Lev(unsigned num)
{
    if (!num) return "0";
    vector<bool> bin = ToBinary(num), result;
    int c = 1;
    while (bin.size())
    {
        for (int i = 0; i < bin.size(); i++)
            result.insert(result.begin(), bin[i]);
        num = floor(log2(num));
        bin = ToBinary(num);
        c++;
    }
    result.insert(result.begin(), 0);
    for (int i = c; i > 0; i--)
        result.insert(result.begin(), 1);
    string s = "";
    for (int i = 0; i < result.size(); i++)
        s += (int) result[i] + '0';
    return s;
}

vector<bool> ToBinary(unsigned num)
{
    vector<bool> result;
    while (num)
    {
        result.push_back(num % 2);
        num /= 2;
    }
    result.pop_back();
    return result;
}
bool Test()
{
    if (
        Lev(0) == "0" &&
        Lev(1) == "10" &&
        Lev(2) == "1100" &&
        Lev(3) == "1101" &&
        Lev(4) == "1110000" &&
        Lev(5) == "1110001" &&
        Lev(6) == "1110010" &&
        Lev(7) == "1110011" &&
        Lev(8) == "11101000" &&
        Lev(9) == "11101001" &&
        Lev(10) == "11101010" &&
        Lev(11) == "11101011" &&
        Lev(12) == "11101100" &&
        Lev(13) == "11101101" &&
        Lev(14) == "11101110" &&
        Lev(15) == "11101111" &&
        Lev(16) == "111100000000" &&
        Lev(17) == "111100000001" &&
        Lev(18) == "111100000010" &&
        Lev(19) == "111100000011" &&
        Lev(20) == "111100000100" &&
        Lev(21) == "111100000101" &&
        Lev(22) == "111100000110" &&
        Lev(23) == "111100000111" &&
        Lev(24) == "111100001000" &&
        Lev(31) == "111100001111" &&
        Lev(37) == "1111000100101"
        )
    {
        cout << "Test completed successfully" << endl;
        return true;
    }
    else cout << "Test failed" << endl;
    return false;
}