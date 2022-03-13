#include<iostream>
using namespace std;
int main()
{
    string s;
    cout << "Enter string : "; cin >> s;
    for (int i = 0; s[i] != '\0'; i++)
    {
        int k = i;
        while (s[i] == s[i + 1]) i++;
        if ((abs(k - i) % 2 == 1))
        {
            for (int t = k; t <= i; t++)
                cout << s[t];
            cout << endl;
        }
    }
    system("pause");
    return 0;
}