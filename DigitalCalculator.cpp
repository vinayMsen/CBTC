#include<bits/stdc++.h>
using namespace std;
// function for divide operation:
long long dividation(long long a, long long b)
{
    return a/b;
}
// function for Multiplication:
long long multiply(long long a, long long b)
{
     return a*b;
}
// function for subtraction:

long long subtraction(long long a,long long b)
{
    return a-b;
}
// function for  addition:
long long addition(long long  a,long long b)
{
    return a+b;
}
// main function:
int main()
{
    cout<<"     \nWELCOME TO THE DIGITAL CALCULATOR   \n";
    cout<<endl<<endl;
    cout<<"  -INSTRUCTIONS"<<endl;
    cout<<" 1-input the first integer value"<<endl;
    cout<<" 2-then choose the operation accordingly"<<endl;
    cout<<" 3-Make sure the values are in numerical form "<<endl;
    cout<<" 4-Avoid zero in the denominator during divide operation"<<endl;
    cout<<" 5-After your operation done click on the = for the final answer"<<endl;
    
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"Enter the first numeric value"<<endl;
    long long  a,b;
    cin>>a;
    cout<<"Enter the operation"<<endl;
    char c; cin>>c;
    if(c=='+')
    {
        cin>>b;
        long long answer=addition(a,b);
        char an;
        while(cin>>an)
        {
            if(an=='=')
            break;
            if(an=='+')
            {
                cin>>b;
                answer=addition(answer,b);
            }
            else if(an=='-')
            {
                cin>>b;
                answer=subtraction(answer,b);
            }
            else if(an=='*')
            {
                cin>>b;
                answer=multiply(answer,b);
            }
            else if(an=='/'){
                cin>>b;
                if(b==0)continue;
                answer=dividation(answer,b);
            }
        }
         cout<<answer<<endl;
    }
    else if(c=='-')
    {
       cin>>b;
       long long answer=subtraction(a,b);
        char an;
        while(cin>>an)
        {
            if(an=='=')
            break;
            if(an=='+')
            {
                cin>>b;
                answer=addition(answer,b);
            }
            else if(an=='-')
            {
                cin>>b;
                answer=subtraction(answer,b);
            }
            else if(an=='*')
            {
                cin>>b;
                answer=multiply(answer,b);
            }
            else if(an=='/'){
                cin>>b;
                if(b==0)continue;
                answer=dividation(answer,b);
            }
        }
         cout<<answer<<endl;
       
    }
    else if(c=='/')
    {
       cin>>b;
       if(b==0)
       {
        cout<<"Undefined Error"<<endl;
        return 0;
       }
       long long answer=subtraction(a,b);
        char an;
        while(cin>>an)
        {
            if(an=='=')
            break;
            if(an=='+')
            {
                cin>>b;
                answer=addition(answer,b);
            }
            else if(an=='-')
            {
                cin>>b;
                answer=subtraction(answer,b);
            }
            else if(an=='*')
            {
                cin>>b;
                answer=multiply(answer,b);
            }
            else if(an=='/'){
                cin>>b;
                if(b==0)continue;
                answer=dividation(answer,b);
            }
        }
         cout<<answer<<endl;
       
    }
    else if(c=='*')
    {
       cin>>b;
       long long answer=subtraction(a,b);
        char an;
        while(cin>>an)
        {
            if(an=='=')
            break;
            if(an=='+')
            {
                cin>>b;
                answer=addition(answer,b);
            }
            else if(an=='-')
            {
                cin>>b;
                answer=subtraction(answer,b);
            }
            else if(an=='*')
            {
                cin>>b;
                answer=multiply(answer,b);
            }
            else if(an=='/'){
                cin>>b;
                if(b==0)continue;
                answer=dividation(answer,b);
            }
        }
         cout<<answer<<endl;
       
    }

    return 0;
}