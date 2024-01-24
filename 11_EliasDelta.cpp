#include <iostream>
#include <vector>
#include <conio.h>
#include <assert.h>
using namespace std;

string EliasDelta(unsigned num);
vector<int> ToBinary(unsigned num);
unsigned fromDelta(string a); 
bool Test();

int main()
{
    unsigned num;
    cout << "Введите число больше 0: ";
    cin >> num;
    cout << "Результат: " << EliasDelta(num) << " " << fromDelta(EliasDelta(num)) << endl;
    Test();
    getch();
    return 0;
}


string EliasDelta(unsigned num)
{
    if (!num) return "The number should be greater than 0";
    vector<int> n = ToBinary(num), bin = ToBinary(n.size()), result;
    for (int i = 0; i < bin.size() - 1; i++)
        result.push_back(0);
    for (int i = bin.size() - 1; i >= 0; i--)
        result.push_back(bin[i]);

    for (int i = n.size() - 2; i >= 0; i--)
        result.push_back(n[i]);

    string s = "";
    for (int i = 0; i < result.size(); i++)
        s += (int) result[i] + '0';
    return s;
}

unsigned fromDelta(string a)  
{
	int i, c=1, x=0;
    for (i=0; i<a.length(); i++)
      if(a[i] == '1')
        break;
    i=i*2;
    for (int j = a.length()-1; j>i; j--)
	{
	  	x=x+(a[j] == '1')*c;	
	  	c=c*2;
	}
	x=x+c;
	return x;
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
void Test()
{
    assert(EliasDelta(1) == "1"); 
    assert(EliasDelta(2) == "0100"); 
    assert(EliasDelta(3) == "0101");
    assert(EliasDelta(4) == "01100");
    assert(EliasDelta(5) == "01101");
    assert(EliasDelta(6) == "01110");
    assert(EliasDelta(7) == "01111");
	assert(EliasDelta(8) == "00100000"); 
    assert(EliasDelta(9) == "00100001");
    assert(EliasDelta(10) == "00100010");
    assert(EliasDelta(11) == "00100011");
    assert(EliasDelta(12) == "00100100");
    assert(EliasDelta(13) == "00100101");
    assert(EliasDelta(14) == "00100110");
    assert(EliasDelta(15) == "00100111");
    assert(EliasDelta(16) == "001010000");
    assert(EliasDelta(17) == "001010001");
}
