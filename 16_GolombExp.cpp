
#include <iostream>
#include <vector>
#include <cmath>
#include <conio.h>
using namespace std;

string GolombExp(unsigned num, unsigned k);
vector<bool> ToBinary(unsigned num);
bool Test();

int main()
{
    unsigned num, k;
    cout << "Enter N: ";
    cin >> num;
    cout << "Enter K: ";
    cin >> k;
    cout << "Result: " << GolombExp(num, k) << endl;
    //Test();
    _getch();
    return 1;
}

string GolombExp(unsigned num, unsigned k)
{
    vector<bool> bin, result;
    int w = 1 + floor(num / pow(2, k)), f = floor(log2(1 + num / pow(2, k)));

    for (int i = 0; i < f; i++)
        result.push_back(1);
    result.push_back(0);

    bin = ToBinary(w);
    bin.resize(f);
    for (int i = bin.size() - 1; i >= 0; i--)
        result.push_back(bin[i]);

    bin = ToBinary(num);
    bin.resize(k);
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
        GolombExp(0, 0) == "0" &&
        GolombExp(0, 1) == "00" &&
        GolombExp(0, 2) == "000" &&
        GolombExp(0, 3) == "0000" &&
        GolombExp(0, 4) == "00000" &&
        GolombExp(0, 5) == "000000" &&
        GolombExp(0, 6) == "0000000" &&

        GolombExp(1, 0) == "100" &&
        GolombExp(1, 1) == "01" &&
        GolombExp(1, 2) == "001" &&
        GolombExp(1, 3) == "0001" &&
        GolombExp(1, 4) == "00001" &&
        GolombExp(1, 5) == "000001" &&
        GolombExp(1, 6) == "0000001" &&

        GolombExp(2, 0) == "101" &&
        GolombExp(2, 1) == "1000" &&
        GolombExp(2, 2) == "010" &&
        GolombExp(2, 3) == "0010" &&
        GolombExp(2, 4) == "00010" &&
        GolombExp(2, 5) == "000010" &&
        GolombExp(2, 6) == "0000010" &&

        GolombExp(3, 0) == "11000" &&
        GolombExp(3, 1) == "1001" &&
        GolombExp(3, 2) == "011" &&
        GolombExp(3, 3) == "0011" &&
        GolombExp(3, 4) == "00011" &&
        GolombExp(3, 5) == "000011" &&
        GolombExp(3, 6) == "0000011" &&

        GolombExp(4, 0) == "11001" &&
        GolombExp(4, 1) == "1010" &&
        GolombExp(4, 2) == "10000" &&
        GolombExp(4, 3) == "0100" &&
        GolombExp(4, 4) == "00100" &&
        GolombExp(4, 5) == "000100" &&
        GolombExp(4, 6) == "0000100" &&

        GolombExp(5, 0) == "11010" &&
        GolombExp(5, 1) == "1011" &&
        GolombExp(5, 2) == "10001" &&
        GolombExp(5, 3) == "0101" &&
        GolombExp(5, 4) == "00101" &&
        GolombExp(5, 5) == "000101" &&
        GolombExp(5, 6) == "0000101" &&

        GolombExp(6, 0) == "11011" &&
        GolombExp(6, 1) == "110000" &&
        GolombExp(6, 2) == "10010" &&
        GolombExp(6, 3) == "0110" &&
        GolombExp(6, 4) == "00110" &&
        GolombExp(6, 5) == "000110" &&
        GolombExp(6, 6) == "0000110" &&

        GolombExp(7, 0) == "1110000" &&
        GolombExp(7, 1) == "110001" &&
        GolombExp(7, 2) == "10011" &&
        GolombExp(7, 3) == "0111" &&
        GolombExp(7, 4) == "00111" &&
        GolombExp(7, 5) == "000111" &&
        GolombExp(7, 6) == "0000111" &&

        GolombExp(8, 0) == "1110001" &&
        GolombExp(8, 1) == "110010" &&
        GolombExp(8, 2) == "10100" &&
        GolombExp(8, 3) == "100000" &&
        GolombExp(8, 4) == "01000" &&
        GolombExp(8, 5) == "001000" &&
        GolombExp(8, 6) == "0001000" &&

        GolombExp(9, 0) == "1110010" &&
        GolombExp(9, 1) == "110011" &&
        GolombExp(9, 2) == "10101" &&
        GolombExp(9, 3) == "100001" &&
        GolombExp(9, 4) == "01001" &&
        GolombExp(9, 5) == "001001" &&
        GolombExp(9, 6) == "0001001" &&

        GolombExp(10, 0) == "1110011" &&
        GolombExp(10, 1) == "110100" &&
        GolombExp(10, 2) == "10110" &&
        GolombExp(10, 3) == "100010" &&
        GolombExp(10, 4) == "01010" &&
        GolombExp(10, 5) == "001010" &&
        GolombExp(10, 6) == "0001010" &&

        GolombExp(11, 0) == "1110100" &&
        GolombExp(11, 1) == "110101" &&
        GolombExp(11, 2) == "10111" &&
        GolombExp(11, 3) == "100011" &&
        GolombExp(11, 4) == "01011" &&
        GolombExp(11, 5) == "001011" &&
        GolombExp(11, 6) == "0001011" &&

        GolombExp(12, 0) == "1110101" &&
        GolombExp(12, 1) == "110110" &&
        GolombExp(12, 2) == "1100000" &&
        GolombExp(12, 3) == "100100" &&
        GolombExp(12, 4) == "01100" &&
        GolombExp(12, 5) == "001100" &&
        GolombExp(12, 6) == "0001100" &&

        GolombExp(13, 0) == "1110110" &&
        GolombExp(13, 1) == "110111" &&
        GolombExp(13, 2) == "1100001" &&
        GolombExp(13, 3) == "100101" &&
        GolombExp(13, 4) == "01101" &&
        GolombExp(13, 5) == "001101" &&
        GolombExp(13, 6) == "0001101" &&

        GolombExp(14, 0) == "1110111" &&
        GolombExp(14, 1) == "11100000" &&
        GolombExp(14, 2) == "1100010" &&
        GolombExp(14, 3) == "100110" &&
        GolombExp(14, 4) == "01110" &&
        GolombExp(14, 5) == "001110" &&
        GolombExp(14, 6) == "0001110" &&

        GolombExp(15, 0) == "111100000" &&
        GolombExp(15, 1) == "11100001" &&
        GolombExp(15, 2) == "1100011" &&
        GolombExp(15, 3) == "100111" &&
        GolombExp(15, 4) == "01111" &&
        GolombExp(15, 5) == "001111" &&
        GolombExp(15, 6) == "0001111" &&

        GolombExp(16, 0) == "111100001" &&
        GolombExp(16, 1) == "11100010" &&
        GolombExp(16, 2) == "1100100" &&
        GolombExp(16, 3) == "101000" &&
        GolombExp(16, 4) == "1000000" &&
        GolombExp(16, 5) == "010000" &&
        GolombExp(16, 6) == "0010000"
        )
    {
        cout << "Test completed successfully" << endl;
        return true;
    }
    else cout << "Test failed" << endl;
    return false;
}