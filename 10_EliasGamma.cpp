#include <iostream>
#include <vector>
#include <conio.h>
#include <cmath>
using namespace std;

string EliasGamma(unsigned num);
vector<int> ToBinary(unsigned num);
int ToDec (string k, unsigned num);
bool Test();

int main()
{
    unsigned num;
    cout << "Введите число: ";
    cin >> num;
    while(num!=0)
    {
    	cout << "Результат: " << EliasGamma(num) << ' ' << "Декодирование:" << ToDec(EliasGamma(num),num) << endl;
        cout << "Введите 0 если хотите закончить. Иначе ввдите число больше 0" << ' ';
        cin >> num;
    }                                                                
    getch();
    return 0;
}

string EliasGamma(unsigned num)
{
    if (!num) return "Число должно быть больше 0";
    vector<int> bin = ToBinary(num), result;
    for (int i = 0; i < bin.size() - 1; i++)
        result.push_back(0);
    for (int i = bin.size() - 1; i >= 0; i--)
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

int ToDec (string k, unsigned num)
{
    vector<int> gro;
    int res=0;
    int len=EliasGamma(num).length();
    for (int i=0;i<len;i++)
    {
    	if(EliasGamma(num)[i] == '0')
    	gro.push_back(0);
 	else gro.push_back(1); 
    }
    for (int i=0;i<gro.size();i++)
    {
    	if (gro[i]==1)
    	res+=pow(2,len-i);
    }
    return res/2;
}

bool Test()
{
    if (
        EliasGamma(1) == "1" &&
        EliasGamma(2) == "010" &&
        EliasGamma(3) == "011" &&
        EliasGamma(4) == "00100" &&
        EliasGamma(5) == "00101" &&
        EliasGamma(6) == "00110" &&
        EliasGamma(7) == "00111" &&
        EliasGamma(8) == "0001000" &&
        EliasGamma(9) == "0001001" &&
        EliasGamma(10) == "0001010" &&
        EliasGamma(11) == "0001011" &&
        EliasGamma(12) == "0001100" &&
        EliasGamma(13) == "0001101" &&
        EliasGamma(14) == "0001110" &&
        EliasGamma(15) == "0001111" &&
        EliasGamma(16) == "000010000" &&
        EliasGamma(17) == "000010001" &&
        EliasGamma(18) == "000010010" &&
        EliasGamma(100) == "0000001100100"
        )
    {
        cout << "Test completed " << endl;
        return true;
    }
    else cout << "Test failed" << endl;
    return false;
}