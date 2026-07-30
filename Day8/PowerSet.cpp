#include<iostream>
#include<vector>
#include<string.h>
#include<string>
using namespace std;


void allPossibleStrings(string s, string output, vector<string> &result)
{
    if(s.length()==0)
    {
        result.push_back(output);
        return;
    }
    string output1=output;
    string output2=output;
    output2.push_back(s[0]);
    s.erase(s.begin()+0);
    allPossibleStrings(s,output1,result);
    allPossibleStrings(s,output2,result);
    return;
}
int main()
{
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);

    vector<string> result;
    string output;
    allPossibleStrings(str,output,result);
    for(auto str:result)
    {
        cout<<str<<endl;
    }
    return 0;

}