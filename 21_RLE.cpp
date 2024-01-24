#include <iostream>
#include <assert.h>
using namespace std;
string RLE(string s);
void Test();

int main()
{
	string s;
	cout << "Введите строку: ";
    cin >> s;
    cout << "Результат: " << RLE(s) << endl;
    Test();
    return 0;
}

string RLE(string s)
{
    string result;
    s += '\0';
    char cur = s[0], next;
    int i = 0, rep = 1;
    while (i < s.length() - 1)
    {
    	next = s[i];
        while (cur == (next = s[++i]))
        {
            cur = next;
            rep++;
        }
        if (rep > 1)
        {
            result += "(";
            string number = "";
            while (rep)
            {
                number += (rep % 10) + '0';
                rep /= 10;
            }
            for (int l = number.length() - 1; l >= 0; l--)
                result += number[l];
            result += ", ";
            result += cur;
            result += ")";
        }
        else
            result += cur;
        cur = next;
        rep = 1;
    }
    return result;
}

void Test ()
{
	assert(RLE("rrr4rrr4")=="(3, r)4(3, r)4");
	assert(RLE("helloworld")=="he(2, l)oworld");
	assert(RLE("r")=="r");
	assert(RLE("rr")=="(2, r)");
	assert(RLE("Kirill")=="Kiri(2, l)");
	assert(RLE("rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr")=="(48, r)");
	
	assert(RLE("pyatoe")=="pyatoe");
	assert(RLE("pasmurnaypogoda")=="pasmurnaypogoda");
	assert(RLE("trrrrractor")=="t(5, r)actor");
	assert(RLE("massa")=="ma(2, s)a");
	assert(RLE("rggu")=="r(2, g)u");
}
