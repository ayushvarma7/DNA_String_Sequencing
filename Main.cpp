#include <bits/stdc++.h>
using namespace std;

#define STR_LEN 600
#define STR_NUM 20
string Strings[STR_NUM]; // making array for storing the strings
int l, d, indel, sub;

// Used to generate a random string consisting of the given Strings
string generateRandomString()
{

    string corpus = "ACGT";
    string str = "";

    for (int i = 0; i < STR_LEN; i++)
    {
        str += corpus[rand() % 4];
    }

    return str;
}

// calculate min of 3 numbers
int min(int x, int y, int z) { return min(min(x, y), z); }

int editDistanceStrings(string str1, string str2)
{
    int indel = 1;
    int sub = 1;
    int m = str1.length();
    int n = str2.length();
    // int m=str1.length(), n=str2.length();
    // Create a table to store results of subproblems
    int E[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {

            if (i == 0)
                E[i][j] = j;

            else if (j == 0)
                E[i][j] = i;

            else if (str1[i - 1] == str2[j - 1])
                E[i][j] = min(E[i][j - 1] + indel, E[i - 1][j] + indel, E[i - 1][j - 1]);

            else
                E[i][j] = min(E[i][j - 1] + indel, E[i - 1][j] + indel, E[i - 1][j - 1] + sub);
        }
    }

    return E[m][n];
}

int main()
{

    // putting seed as time to make sure it forces rand() to produce different values
    srand(time(NULL));

    freopen("Data.txt", "r", stdin);
    freopen("Out.txt", "w", stdout);

    cin >> l >> d >> indel >> sub;

    // string x;
    // reads the input.txt file and stores in string x
    // getline(cin, x);

    for (int i = 0; i < STR_NUM; i++)
    {
        Strings[i] = generateRandomString();
    }

    // printing the strings
    for (string s : Strings)
        cout << s << "\n";


    // cout << editDistanceStrings(s1, s2, s1.length(), s2.length());

    // int l=15, d=5, indel=1, sub=1;
    int countFinal=1;

    for (int i = 0; i < STR_NUM; i++) //string selector loop
    {

        for (int j = 0; j < (STR_LEN - l + 1); j++) //substring selector loop
        {
            string mainString = Strings[i].substr(j, l);
            int countSimilar = 0;

            for (int y = 0; y < (STR_NUM); y++) //comparision string selector loop
            {

                if (y == i)
                    continue;
                bool flag = false;

                for (int z = 0; z < (STR_LEN - l + 1); z++) //comparision substring starting index selector loop
                {

                    for (int t = l - d; t <= l + d; t++) //ending range selector for comparision substring loop
                    {
                        string comparisionString = Strings[y].substr(z, t);
                        int distance = editDistanceStrings(mainString, comparisionString);
                        if (distance <= d) //only if distance is less than d
                        { 
                            flag = true; //since we want a min of 1 matching combination from a substring so we break once we find one
                            break;
                        }
                    } // end of for loop 
                     if (flag) // find in the string, move to next string
                        break;
                }
                if(!flag) break;
                else countSimilar++;
            }

            if(countSimilar==19) {
                cout<<countFinal<<": "<< mainString<<endl;
                countFinal++;
            }
        }
    }

    return 0;
}