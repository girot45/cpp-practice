#include <iostream>
#include <vector>
#include <cmath>
#include <conio.h>
using namespace std;

string Rayas(unsigned num, unsigned m);
vector<bool> ToBinary(unsigned num);
bool Test();

int main()
{
    unsigned num, k;
    cout << "Enter N: ";
    cin >> num;
    cout << "Enter K: ";
    cin >> k;
    cout << "Result: " << Rayas(num, k) << endl;
    //Test();
    _getch();
    return 1;
}

string Rayas(unsigned num, unsigned k)
{
    vector<bool> bin = ToBinary(num), result;
    int m = pow(2, k);
    for (int i = 0; i < num / m; i++)
        result.push_back(1);
    result.push_back(0);

    bin = ToBinary(num % m);
    bin.resize(floor(num / m) + k + 1 - result.size());
    for (int i = bin.size() - 1; i >= 0; i--)
        result.push_back(bin[i]);
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
    return result;
}
bool Test()
{
    if (
        Rayas(0, 0) == "0" &&
        Rayas(0, 1) == "00" &&
        Rayas(0, 2) == "000" &&
        Rayas(0, 3) == "0000" &&
        Rayas(0, 4) == "00000" &&

        Rayas(1, 0) == "10" &&
        Rayas(1, 1) == "01" &&
        Rayas(1, 2) == "001" &&
        Rayas(1, 3) == "0001" &&
        Rayas(1, 4) == "00001" &&

        Rayas(2, 0) == "110" &&
        Rayas(2, 1) == "100" &&
        Rayas(2, 2) == "010" &&
        Rayas(2, 3) == "0010" &&
        Rayas(2, 4) == "00010" &&

        Rayas(3, 0) == "1110" &&
        Rayas(3, 1) == "101" &&
        Rayas(3, 2) == "011" &&
        Rayas(3, 3) == "0011" &&
        Rayas(3, 4) == "00011" &&

        Rayas(4, 0) == "11110" &&
        Rayas(4, 1) == "1100" &&
        Rayas(4, 2) == "1000" &&
        Rayas(4, 3) == "0100" &&
        Rayas(4, 4) == "00100" &&

        Rayas(5, 0) == "111110" &&
        Rayas(5, 1) == "1101" &&
        Rayas(5, 2) == "1001" &&
        Rayas(5, 3) == "0101" &&
        Rayas(5, 4) == "00101" &&

        Rayas(6, 0) == "1111110" &&
        Rayas(6, 1) == "11100" &&
        Rayas(6, 2) == "1010" &&
        Rayas(6, 3) == "0110" &&
        Rayas(6, 4) == "00110" &&

        Rayas(7, 0) == "11111110" &&
        Rayas(7, 1) == "11101" &&
        Rayas(7, 2) == "1011" &&
        Rayas(7, 3) == "0111" &&
        Rayas(7, 4) == "00111" &&

        Rayas(8, 0) == "111111110" &&
        Rayas(8, 1) == "111100" &&
        Rayas(8, 2) == "11000" &&
        Rayas(8, 3) == "10000" &&
        Rayas(8, 4) == "01000" &&

        Rayas(9, 0) == "1111111110" &&
        Rayas(9, 1) == "111101" &&
        Rayas(9, 2) == "11001" &&
        Rayas(9, 3) == "10001" &&
        Rayas(9, 4) == "01001" &&

        Rayas(10, 0) == "11111111110" &&
        Rayas(10, 1) == "1111100" &&
        Rayas(10, 2) == "11010" &&
        Rayas(10, 3) == "10010" &&
        Rayas(10, 4) == "01010" &&

        Rayas(11, 0) == "111111111110" &&
        Rayas(11, 1) == "1111101" &&
        Rayas(11, 2) == "11011" &&
        Rayas(11, 3) == "10011" &&
        Rayas(11, 4) == "01011" &&

        Rayas(12, 0) == "1111111111110" &&
        Rayas(12, 1) == "11111100" &&
        Rayas(12, 2) == "111000" &&
        Rayas(12, 3) == "10100" &&
        Rayas(12, 4) == "01100" &&

        Rayas(13, 0) == "11111111111110" &&
        Rayas(13, 1) == "11111101" &&
        Rayas(13, 2) == "111001" &&
        Rayas(13, 3) == "10101" &&
        Rayas(13, 4) == "01101" &&

        Rayas(14, 0) == "111111111111110" &&
        Rayas(14, 1) == "111111100" &&
        Rayas(14, 2) == "111010" &&
        Rayas(14, 3) == "10110" &&
        Rayas(14, 4) == "01110" &&

        Rayas(15, 0) == "1111111111111110" &&
        Rayas(15, 1) == "111111101" &&
        Rayas(15, 2) == "111011" &&
        Rayas(15, 3) == "10111" &&
        Rayas(15, 4) == "01111" &&

        Rayas(16, 0) == "11111111111111110" &&
        Rayas(16, 1) == "1111111100" &&
        Rayas(16, 2) == "1111000" &&
        Rayas(16, 3) == "110000" &&
        Rayas(16, 4) == "100000" &&

        Rayas(17, 0) == "111111111111111110" &&
        Rayas(17, 1) == "1111111101" &&
        Rayas(17, 2) == "1111001" &&
        Rayas(17, 3) == "110001" &&
        Rayas(17, 4) == "100001" &&

        Rayas(18, 0) == "1111111111111111110" &&
        Rayas(18, 1) == "11111111100" &&
        Rayas(18, 2) == "1111010" &&
        Rayas(18, 3) == "110010" &&
        Rayas(18, 4) == "100010" &&

        Rayas(19, 0) == "11111111111111111110" &&
        Rayas(19, 1) == "11111111101" &&
        Rayas(19, 2) == "1111011" &&
        Rayas(19, 3) == "110011" &&
        Rayas(19, 4) == "100011" &&

        Rayas(20, 0) == "111111111111111111110" &&
        Rayas(20, 1) == "111111111100" &&
        Rayas(20, 2) == "11111000" &&
        Rayas(20, 3) == "110100" &&
        Rayas(20, 4) == "100100"
        )
    {
        cout << "Test completed successfully" << endl;
        return true;
    }
    else cout << "Test failed" << endl;
    return false;
}
