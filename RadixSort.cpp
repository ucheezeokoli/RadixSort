#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

    // for (i = 0; i < 10; i++)
    // {
    //     cout << Minval.at(i);
    // }

int RadixSort(vector<vector<int> >& FreeSpace, vector<vector<int> >& sorted, int size)
{
    while (size > 0)
    {
        vector<int> Minval;
        int MinRowIndex = 0;
        int i = 0;
        int k = 0;
        int j = 0;
        int l = 0;
        for (i = 0; i < FreeSpace.at(j).size(); i++)
        {
            Minval.push_back(FreeSpace.at(j).at(i));
        }

        for (i = 1; i < size; i++)
        {
            for (j = 0; j < 10; j++)
            {
                if (FreeSpace.at(i).at(j) < Minval.at(j))
                {
                    for (k = 0; k < 10; k++)
                    {
                        Minval.at(k) = FreeSpace.at(i).at(k);
                        MinRowIndex = i;
                    }
                }
                if (FreeSpace.at(i).at(j) > Minval.at(j))
                {
                    break;
                }
            } 
        }

        sorted.push_back(Minval);
        FreeSpace.erase(FreeSpace.begin() + MinRowIndex);
        size--;
    }
}


int main()
{
    int size;
    cin >> size;

    vector<vector<int> > sorted;
    vector<vector<int> > FreeSpace; // DECLARE VECTOR WITH SIZE FROM INPUT
    
    // FILL VECTOR W/ FreeSpace VALUES
    int i,j;
    int input;

    for (i = 0; i < size; i++)
    {
        vector<int> col;

        for (j = 0; j < 10; j++)
        {   
            cin >> input;
            col.push_back(input);
        }

        FreeSpace.push_back(col);
    }

    RadixSort(FreeSpace, sorted, size);

    for (i = 0; i < sorted.size(); i++)
    {
        for (j = 0; j < sorted.at(i).size(); j++)
        {
            cout << sorted.at(i).at(j) <<";";
        }
        cout << endl;
    }

    // string str;
    // for (i = 1; i <= (size * 10); i++)
    // {
    //     cin >> input;
    //     str += to_string(input);

    //     if (i != 0 && i % 10 == 0)
    //     {
    //         // cout << str<< endl;
    //         // cout << "index: " <<i << endl;
    //         FreeSpace.at(j) = str;
    //         j++;
    //         str="";
    //     }
    // }


    //HOW TO PRINT AT THE END!!!
   
    // for (i = 1; i <= (size * 10); i++)
    // {
    //     strcpy(Furisupesu, FreeSpace.at(i).c_str());
    //     for (j = 0; j < 10; j++)
    //     {
    //         cout << Furisupesu[j] << ";";
    //     }
    //     cout << endl;
    // }
}
