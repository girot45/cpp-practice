#define DEC_MAX_VALUE 349525
#define DEC_MIN_VALUE -699050
#define NEG_MAX_VALUE 1111111111111111111
#define NEG_MIN_VALUE 0
#include <iostream>
#include <cmath>
using namespace std;

bool CorrectArgument(unsigned long long arg)
{
    while (arg)
    {
        if (arg % 10 != 0 && arg % 10 != 1)
            return false;
        arg /= 10;
    }
    return true;
}


long long NegToDec(unsigned long long negNum)
{
    if (!CorrectArgument(negNum))
        return -1;

    long i = 0; long long result = 0;
    do result += (negNum % 10) * pow(-2, i++);
    while ((negNum /= 10) > 0);
    return result;
}


unsigned long long DecToNeg(long long decNum)
{
    short reminder; unsigned long long result = 0, i = 1;
    while (decNum != 0)
    {
        result += i * abs(reminder = decNum % -2);
        i *= 10;
        decNum /= -2;
        if (reminder < 0)
            decNum += 1;
    }
    return result;
}

int main()
{
    cout.setf(ios_base::boolalpha);
    for (long long i = NEG_MIN_VALUE; i <= DEC_MAX_VALUE; i++)
    {
        if (NegToDec(DecToNeg(i)) != i)
        {
            cout << "Something went wrong at value: " << i << endl;
            return -1;
        }
    }
    cout << true << endl;
    return 1;
}