#include <iostream>
#include <string>
#include <vector>
#include <utility> 
#include <cmath> 
using namespace std;
bool ShennonFano();

vector<pair<char, string> > words;

int main()
{
    if (ShennonFano())
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
    return 1;
}

bool ShennonFano()
{
    string value;
    cout << "Enter the string: ";
    cin >> value;
    vector<pair<char, double> > dictionary;
    for (int i = 0; i < value.length(); i++)
    {
        for (int j = 0; j < dictionary.size(); j++)
        {
            if (dictionary[j].first == value[i])
            {
                dictionary[j].second += 1.0 / value.length();
                goto outer;
            }
        }
        dictionary.push_back(pair<char, double>(value[i], 1.0 / value.length()));
    outer:;
    }
    pair<char, double> tmp;
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
    vector<double> q;
    q.push_back(0);
    for (int i = 0; i < dictionary.size() - 1; i++)
        q.push_back(q[i] + dictionary[i].second);
    for (int i = 0; i < dictionary.size(); i++)
    {
        vector<bool> word;
        int digit = ceil(-log2(dictionary[i].second));
        q[i] *= 2;
        for (int j = 1; j < digit; j++)
        {
            word.push_back(floor(q[i]));
            if (q[i] >= 1) q[i]--;
            q[i] *= 2;
        }
        word.push_back(floor(q[i]));
        string result = "";
        for (int k = 0; k < word.size(); k++)
            result += (int) word[k] + '0';
        words.push_back(pair<char, string>(dictionary[i].first, result));
    }
    for (int i = 0; i < words.size(); i++)
        cout << "\nThe letter \"" << words[i].first << "\" is " << words[i].second;
    cout << endl << endl;
    string s1 = "", s2 = "", s3 = "";
    for (int i = 0; i < value.length(); i++)
    {
        for (int j = 0; j < words.size(); j++)
        {
            if (words[j].first == value[i])
            {
                string s = string(words[j].second.length(), ' ');
                string ss = string(words[j].second.length(), ' ');
                s[0] = '|';
                s[s.length() - 1] = '|';
                ss[(ss.length() - 1) / 2] = words[j].first;
                s3 += ss;
                s2 += s;
                s1 += words[j].second;
                break;
            }
        }

    }
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    return true;
}
