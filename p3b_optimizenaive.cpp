#include<bits/stdc++.h>
using namespace std ;

int main()
{
    string text ,pattern;
    cout<<"Enter the text : ";
    getline(cin,text);
    fflush(stdin);
    cout<<"Enter the pattern to be searched :  ";
    getline(cin,pattern);
    bool found= false;
    cout<<"Text : "<<text<<"\n";
    cout<<"patter : "<<pattern<<"\n";
    int n= text.size(), k= pattern.size();
    for (int i = 0; i<n-k+1; i++)
    {
        if (text[i]==pattern[0])
        {
            int j=0;
            for ( j =1; j <k ; j++)
            {
                if (text[i+j]!=pattern[j])
                {
                    break;
                }
            }
            if (j==k)
            {
                cout<<"\nPattern found in text at index: "<<i<<"\n";
                found= true;
            }
            else
            {
                i+=k-1;
            }
        }
    }
    if (!found)
    {
        cout<<"\nPattern not found !!";
    }
}