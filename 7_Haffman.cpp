#include <iostream>
#include <string>
#include <vector>
#include <utility> 
#include <map>
#include <cmath> 
#include <conio.h>
using namespace std;
bool Haffman();
vector < pair <char, string > > words;

int main()
{
    if (Haffman())
    {
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                bool test = false;
                for (int k = 0; k < words[i].second.length(); k++)
                {
                    if (words[i].second[k] != words[j].second[k])
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
    _getch();
    return 0;
}
void SortByDesc(vector<pair<string, double> >& dictionary)

    pair<string, double> tmp;
    for (int i = 0; i < dictionary.size(); i++)
    {
        for (int j = dictionary.size() - 1; j >= i + 1; j--)
        {
            if (dictionary[j].second > dictionary[j - 1].second)
            {
                tmp = dictionary[j];
                dictionary[j] = dictionary[j - 1];
                dictionary[j - 1] = tmp;
            }
        }
    }
}

bool Haffman()
{
    map<char, vector<bool> > alpha;
    string value;
    cout << "Enter the string: ";
    cin >> value;
    vector<pair<string, double> > dictionary;
    for (int i = 0; i < value.length(); i++)
    {
        for (int j = 0; j < dictionary.size(); j++)
        {
            if (dictionary[j].first[0] == value[i])
            {
                dictionary[j].second += 1.0 / value.length();
                goto outer;
            }
        }
        dictionary.push_back(pair<string, double>(string(1, value[i]), 1.0 / value.length()));
    outer:;
    }
    SortByDesc(dictionary);
    for (int i = 0; i < dictionary.size(); i++)
    {
        alpha[dictionary[i].first[0]] = vector<bool>();
        words.push_back(pair<char, string>(dictionary[i].first[0], string(0, '0')));
    }
    while (dictionary.size() > 1)
    {
        for (int k = dictionary.size() - 1; k > 0; k--)
        {
            for (int i = 0; i < dictionary[k].first.length(); i++)
                alpha[dictionary[k].first[i]].insert(alpha[dictionary[k].first[i]].begin(), 1);
            for (int i = 0; i < dictionary[k - 1].first.length(); i++)
                alpha[dictionary[k - 1].first[i]].insert(alpha[dictionary[k - 1].first[i]].begin(), 0);
            dictionary[k - 1].first += dictionary[k].first;
            dictionary[k - 1].second += dictionary[k].second;
            dictionary.erase(dictionary.begin() + k);
            SortByDesc(dictionary);
        }
    }
    for (int i = 0; i < words.size(); i++)
    {
        string result = "";
        for (int k = 0; k < alpha[words[i].first].size(); k++)
            result += (int) alpha[words[i].first][k] + '0';
        words[i].second = result;
        cout << "\nThe letter \"" << words[i].first << "\" is " << words[i].second;
    }
    cout << endl << endl;
    return true;
}
