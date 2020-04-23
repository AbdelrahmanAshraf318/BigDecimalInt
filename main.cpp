#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#include <vector>
#include <sstream>
#include <fstream>
#include<bits/stdc++.h>
using namespace std;

class BigDecimalInt
{
private:
    int Size;
    vector <int> Number;
    void SetNumber(int Data)//to use it in addition and subtraction
    {
        Number.push_back(Data);
    }
public:
    BigDecimalInt()
    {
        Size = 0;
    }
    BigDecimalInt(int decInt)
    {
        int counter=0;

	while(decInt!=0)//to divide number into digits
	{
		int division=decInt/10;
		Number.push_back(decInt%10);
		decInt=division;
		counter++;
	}
        reverse(Number.begin() , Number.end());
    }
    /////////////////////////////////////////////
    BigDecimalInt(string decStr)
    {
        int Num;
            if(decStr[0]=='-')
            {
                decStr.erase(decStr.begin()+0);
          for(int i=0 ; i<decStr.size() ; i++)
            {
                    Num = decStr[i] - 48;
                  Number.push_back(Num);
            }
            Number[0] = Number[0] * (-1);
            }
            else{
            for(int i=0 ; i<decStr.size() ; i++)
            {
                    Num = decStr[i] - 48;
                  Number.push_back(Num);
            }
            }
            /*the previous operations to turn string into integer*/
    }
    ////////////////////////////////////////////////

    //////////////////////////////////////////////
    int GetSize()
    {
        return Number.size();
    }
    /////////////////////////////////////////////
    BigDecimalInt operator+(BigDecimalInt &obj)
    {
        reverse(Number.begin() , Number.end());
        reverse(obj.Number.begin() , obj.Number.end());
        BigDecimalInt NewObj;
        int sum = 0;
        int sum2 = 0;
        int Carry = 0;
      if(this->Size > obj.GetSize())
      {
        for(int i=0 ; i<GetSize() ; i++)
        {
            if(i<=obj.GetSize()-1)
            {
                sum = (this->Number[i] + obj.Number[i] + Carry);
                sum2 = sum % 10;
                NewObj.SetNumber(sum2);
            }
            else if(i>obj.GetSize()-1)
            {
                sum = this->Number[i] + Carry;
                NewObj.SetNumber(sum);
            }
                  Carry = sum / 10;
        }
      if(Carry)
        {
            NewObj.SetNumber(Carry);
        }
    }
     else if(this->Size < obj.GetSize())
     {
         for(int i=0 ; i<obj.GetSize() ; i++)
        {
            if(i<=this->Size-1)
            {
                sum = (this->Number[i] + obj.Number[i] + Carry);
                sum2 = sum % 10;
                NewObj.SetNumber(sum2);
            }
            else if(i>this->Size-1)
            {
                sum = obj.Number[i] + Carry;
                NewObj.SetNumber(sum);
            }
                  Carry = sum / 10;
        }
      if(Carry)
        {
            NewObj.SetNumber(Carry);
        }
     }
     else
     {
         for(int i=0 ; i<this->Size ; i++)
        {
            sum = this->Number[i] + obj.Number[i] + Carry;
            sum2 = sum % 10;
            NewObj.SetNumber(sum2);
            Carry = sum / 10;
        }
      if(Carry)
        {
            NewObj.SetNumber(Carry);
        }
     }
        reverse(NewObj.Number.begin() , NewObj.Number.end());
        return NewObj;
    }

    /////////////////////////////////////////////////
    BigDecimalInt operator-(BigDecimalInt obj)
    {
        reverse(this->Number.begin() , this->Number.end());
        reverse(obj.Number.begin() , obj.Number.end());
        BigDecimalInt NewObj;
        int sub = 0;
        int Carry = 0;
        if(this->Size > obj.GetSize()){
            for(int i=0 ; i<GetSize() ; i++)
            {
                if(i<=obj.GetSize()-1)
                {
                    sub = (this->Number[i] - obj.Number[i] - Carry);
                    if(sub<0)
                    {
                        sub+=10;
                        Carry = 1;
                    }
                    else
                        Carry = 0;
                    NewObj.SetNumber(sub);
                }
                else if(i>obj.GetSize()-1)
                {
                    NewObj.SetNumber(this->Number[i]);
                }
            }
        }
        else if(this->Size < obj.GetSize())
        {
            for(int i=0 ; i<obj.GetSize() ; i++)
            {
                if(i<=this->Size-1)
                {
                    sub = (this->Number[i] - obj.Number[i] - Carry);
                    if(sub<0)
                    {
                        sub+=10;
                        Carry = 1;
                    }
                    else
                        Carry = 0;
                    NewObj.SetNumber(sub);
                }
                else if(i>this->Size-1)
                {
                    NewObj.SetNumber(this->Number[i]);
                }
            }
        }
        else
        {
            for(int i=0 ; i<this->Size ; i++)
            {
                    sub = (this->Number[i] - obj.Number[i] - Carry);
                    if(sub<0)
                    {
                        sub+=10;
                        Carry = 1;
                    }
                    else{
                        Carry = 0;
                        }
                    NewObj.SetNumber(sub);
            }
        }
        reverse(NewObj.Number.begin() , NewObj.Number.end());
        return NewObj;
    }
    ////////////////////////////////////////////////////
    BigDecimalInt operator= (BigDecimalInt anotherDec)
    {
        BigDecimalInt NewObj;
        for(int i=0 ; i<anotherDec.GetSize() ; i++)
        {
            NewObj.SetNumber(anotherDec.Number[i]);
        }
    }
    ///////////////////////////////////////////////////////
    friend ostream& operator << (ostream& out , const BigDecimalInt &obj)
    {
        for(int i = 0 ; i<obj.Number.size() ; i++)
        {
            out<<obj.Number[i];
        }
        out<<endl;
    }
};

int main()
{
    /*BigDecimalInt num1("123456789012345678901234567890");
    BigDecimalInt num2("113456789011345678901134567890");
    cout<<"Num1 = "<<num1<<endl;
    cout<<"Num2 = "<<num2<<endl;
    BigDecimalInt num3 = num1 + num2;
    cout<<"Num1 + Num2 = "<<num3<<endl;
    cout<<"******************************************\n";
    BigDecimalInt num4("123456789012345678901234567890");
    BigDecimalInt num5("113456789011345678901134567890");
    cout<<"Num4 = "<<num4<<endl;
    cout<<"Num5 = "<<num5<<endl;
    BigDecimalInt num6 = num4 - num5;
    cout<<"Num4 - Num5 = "<<num6<<endl;
    cout<<"***************************************\n";
    BigDecimalInt obj(123);
    BigDecimalInt obj2(123);
    BigDecimalInt obj3 = obj + obj2;
    cout<<"Result = "<<obj3<<endl;*/
    int choose;
    string num1 , num2;
    do
    {
        cout<<"Welcome to FCI Calculator\n";
        cout<<"-----------------------------\n";
        cout<<"1- Perform Addition \n";
        cout<<"2- Perform Subtraction \n";
        cout<<"3- Exit\n";
        cout<<"Choose one of the previous: ";
        cin>>choose;
        if(choose==1)
        {
            cout<<"Enter number1: ";
            cin>>num1;
            cout<<"Enter number2: ";
            cin>>num2;
            BigDecimalInt obj1(num1);
             BigDecimalInt obj2(num2);
            cout<<"Number1 = "<<obj1<<endl;
            cout<<"Number2 = "<<obj2<<endl;
            BigDecimalInt Result = obj1 + obj2;
            cout<<"Num1 + Num2 = "<<Result<<endl;
        }
        else if(choose==2)
        {
             cout<<"Enter number1: ";
            cin>>num1;
            cout<<"Enter number2: ";
            cin>>num2;
            BigDecimalInt obj1(num1);
            BigDecimalInt obj2(num2);
            cout<<"Number1 = "<<obj1<<endl;
            cout<<"Number2 = "<<obj2<<endl;
            BigDecimalInt num6 = obj1 - obj2;
            cout<<"Num1 - Num2 = "<<num6<<endl;
        }
        else if(choose==3)
        {
            cout<<"Thanks for using my calculator\n";
        }
    }while(choose!=3);
    return 0;
}
