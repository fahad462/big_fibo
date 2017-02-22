#include <bits/stdc++.h>
#define SIZE 100000

using namespace std;

string BigIntFibo (string a,string b)
{
    if (a.size()<b.size())
    {
        string temp=a;
        a=b;
        b=temp;
    }
    int carry=0;
    char sum[SIZE];
    int l=0;
    int temp;
    for (int i=a.size()-1,j=b.size()-1; i>=0; i--,j--)
    {
        if (j>=0)
        {
            if (carry==0)
            {
                temp=(a[i]-'0')+(b[j]-'0');
                if (temp<10)
                {
                    sum[l++]=temp+'0';
                }
                else
                {
                    carry=temp/10;
                    sum[l++]=temp%10+'0';
                }
            }
            else
            {
                temp=(a[i]-'0')+(b[j]-'0')+(carry);
                if (temp<10)
                {
                    sum[l++]=temp+'0';
                    carry=0;
                }
                else
                {
                    carry=temp/10;
                    sum[l++]=temp%10+'0';
                }
            }
        }
        else
        {
            if (carry==0)
            {
                sum[l++]=a[i];
            }
            else
            {
                temp=(a[i]-'0')+(carry);
                if (temp<10)
                {
                    sum[l++]=(temp+'0');
                    carry=0;
                }
                else
                {
                    sum[l++]=(temp%10+'0');
                    carry=temp/10;
                }
            }
        }
    }
    if (carry!=0)
    {
        sum[l]=carry+'0';
        l=l+1;
    }
    string result;
    for (int i=l-1; i>=0; i--)
    {
        result.push_back (sum[i]);
    }
    return result;
}

int main()
{
    string first="0",second="1",next;
    cout << "Fibo No. 0: 0" << endl << "Fibo No. 1: 1" << endl;
    for (int i=1; i<=30000; i++)
    {
        next= BigIntFibo(first,second);
        cout << "Fibo No. " << i+1 << ":" << ends;
        cout << next << endl;
        first=second;
        second=next;
    }
    return 0;
}
