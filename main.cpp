#include <iostream>
#include "string"
#include <vector>
#include "math.h"
#include "random"
using namespace std;
vector<char>dirt{'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int find_index(char ch)
{
    for(int i = 0;i<dirt.size();i++)
    {
        if(ch == dirt[i])
            return i;
    }
    return -1;
}
void Ten_TransFrom(string &s)
{
    int num =0;
    reverse(s.begin(),s.end());
    int i = 0;
    while (i<s.length())
    {
        int pos = find_index(s[i]);
        num += pow(16,i)*pos;
        i++;
    }
    cout<<num<<endl;
}
void Add_TransFrom(string &s,string &t)
{
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
    int i = 0,j = 0,cnt =0;
    string res;
    while(i < s.length() || j < t.length() || cnt)
    {
       if(i<s.length())
       {
           cnt+= find_index(s[i]);
           i++;
       }
       if(j<t.length())
       {
           cnt+= find_index(t[j]);
           j++;
       }
       res+= dirt[cnt%16];
       cnt /=16;
    }
    reverse(res.begin(),res.end());
    cout<<res<<endl;
}
int main() {
    string s,t;
    //cin>>s;
    //cin>>t;
    s = "AB";
    t = "C";
    Add_TransFrom(s,t);
    string m = "AB";
    Ten_TransFrom(m);
    //随机生成1-10的数，闭区间[1,10]
    //若是生成左闭右开的区间 rand()%9+1 [1,10) a+rand()%n n是整数的范围
    //左开右闭 rand()%10+1+1;(1,10)
    //生成0~1的浮点数值 rand()/double(RAND_MAX)

    for(int i = 0;i<10;i++)
    {
        cout<<(rand()%(10)+1)<<endl;
    }
    return 0;
}
