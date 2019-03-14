#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> getNext(string str)
{
    vector <int > next(str.size());

    next[0]=-1;
    int k=-1,j=0;
    while (j<str.size())
    {
        if(k==-1||str[k]==str[j])
        {
            next[++j]=++k;
        } else{
            k=next[k];
        }
    }
    return next;
}
int index(string str1,string str2)
{
    if (str1.size()<str2.size())
        return -1;
    vector<int> array=getNext(str2);

    int p=0,s=0;
    //cout<<str1.size()<<" "<<str2.size();
    int str1_length=str1.size();
    int str2_length=str2.size();
    cout<<str2_length;
    while (p<str2_length&&s<str1_length)
    {
        if(p==-1||str1[s]==str2[p])
        {
            s++,p++;
        }
        else
           {
                p=array[p];
           }
        //cout<<"str1.size()"<<str1.size()<<"str2.size()" <<str2.size()<<endl;
        cout<<"s="<<s<<"p="<<p<<endl;

    }
  if (p == str2_length) {

        return s - p;

    } else {

       return -1;

     }
}

int main()
{
string str1="acabaabaabcacaabc",str2="abaabcac";
cout<<index(str1,str2);

}
