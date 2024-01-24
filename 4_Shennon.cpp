#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
bool Shennon();

vector<string> words;

int main()
{
    if (Shennon())
    {
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                bool test = false;
                for (int k = 0; k < words[i].length(); k++)
                {
                    if (words[i][k] != words[j][k])
                        test = true;
                }
                if (!test)
                {
                    cout << "\nTest failed. The code is not prefixed" << endl;
                    return -1;
                }
            }
        }
        cout << "\nTest completed successfully! The code is prefixed" << endl;
    }
    return 1;
}

bool Shennon()
{
    int wordsCount;
    cout << "Enter the count of the words: ";
    cin >> wordsCount;
    if (wordsCount < 1)
    {
        cout << "The word's count should be greater than 0" << endl;
        return false;
    }
    int counter = 1, max = -1, currentLength;
    vector<int> lengthsArr;
    double kraft = 0;

    while (wordsCount--)
    {
        cout << "Enter the length of the word number " << counter++ << ": ";
        cin >> currentLength;
        lengthsArr.push_back(currentLength);
        if (currentLength < 1)
        {
            cout << "The word's length should be greater than 1" << endl;
            return false;
        }
        if (max <= currentLength)
            max = currentLength;
        else
        {
            cout << "Doesn't satisfy the Shennon's condition" << endl;
            return false;
        }
        kraft += pow(2, -currentLength);
    }
    if (kraft > 1)
    {
        cout << "Doesn't satisfy the Kraft's inequality" << endl;
        return false;
    }
    words.push_back(string(lengthsArr[0], '0'));
    vector<bool> prev;
    for (int i = 1; i < lengthsArr.size(); i++)
    {
        int length = lengthsArr[i], reminder = 0;
        prev.resize(length);
        vector<bool> value(length), sum;
        value[lengthsArr[i - 1] - 1] = 1;
        while (length--)
        {
            sum.insert(sum.begin(), (value.back() + prev.back() + reminder) % 2);
            reminder = value.back() + prev.back() + reminder > 1 ? 1 : 0;
            value.pop_back();
            prev.pop_back();
        }
        prev = sum;
        string result = "";
        for (int i = 0; i < sum.size(); i++)
            result += (int) sum[i] + '0';
        words.push_back(result);
    }
    for (int i = 0; i < words.size(); i++)
        cout << "\nWord number " << i + 1 << " is " << words[i];
    cout << endl;
    return true;
}