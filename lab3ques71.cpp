# lab3ques71

up vote
4
down vote
favorite
	

I am a semi-beginner in C++ and I have a project in C++ to convert a hexadecimal integer into decimal equivalent, but I extended it and now this program can also convert a fractional part.

Logic I have used:

    First the whole program is inside a do-while loop so that the user can convert a number as many time as desired.
    Another do-while loop checks if the inputted number is valid or invalid. If invalid, it again asks the user for input.
    A for loop counts the number of characters before the decimal point (if any).
    Another for loop converts the characters before the decimal point into a decimal number.
    Another for loop converts the characters after the decimal point into a decimal fraction and adds it to the original number.
    It prints it and asks if the user wants to again run the loop.

I have knowledge on selection statements (if-else), loops (for, while, do-while), operators and other basic things in C++.

Note: This program is compiled with MinGW and CodeBlocks. My school teacher uses TurboC++.

Please provide advice on things which I can understand; don't get too advanced. I want to score full marks on my school project but also want to understand the code.

// This is a C++ project for Unit Test 2 (2015-16). This program can convert a hexadecimal number into decimal equivalent.

#include <iostream>
#include<string.h>
#include<math.h>

using namespace std;
int main()
{
char choice;
cout<<" *** HEXADECIMAL TO DECIMAL CONVERTER ***";
do{                  //The whole program is inside a do-while loop, so that user can convert a number as many times as they want.
char hexd[120];
                                                         //This string will store the hexadecimal number input by the user.
int validn_count=0,length,lcopy,p=1,num,i,countp=0;
double decimal=0;

do{                                 //This do-while loop checks if the inputed number is valid or not. If not valid it again asks to enter the number.
cout<<"\n Enter a hexadecimal number for conversion (0-F): ";
cin>>hexd;
length=strlen(hexd);
for(int i=0;i<length;++i)
{
    if( (hexd[i]>=48 and hexd[i]<=57) or (hexd[i]>=65 and hexd[i]<=70) or      (hexd[i]>=97 and hexd[i]<=102) or hexd[i]==46)
      ++validn_count;
    else
       {
        validn_count=0;
        cout<<"\n ! WARNING! Invalid HEXADECIMAL NUMBER!!!!";
        break;
       }
}

}while(validn_count==0);




for(i=0;i<length;i++)   //This for loop checks how many characters are there before the decimal point (.)
{
    if(hexd[i]==46)
     break;
   else
     ++countp;


}
lcopy=countp;          // Copying the value of countp for usage in the  conversion.

for(i=0;i<countp;++i)  // This for loop converts all the character before    the decimal point (.) into decimal number and stores it in the variable 'decimal'.
 {
  if(hexd[i]>=48 and hexd[i]<=57)
    num=((int)hexd[i]-48);
  else if(hexd[i]>=65 and hexd[i]<=70)
   num=((int)hexd[i]-55);
  else if (hexd[i]>=97 and hexd[i]<=102)
    num=((int)hexd[i]-87);

 decimal=decimal+(num*pow(16,--lcopy));
 }


for(i=(countp+1);i<length;i++) // This for loop converts all the character after the decimal point (.) into decimal number and further stores it in the variable 'decimal'.
    {

    if(hexd[i]>=48 and hexd[i]<=57)
    num=((int)hexd[i]-48);
   else if(hexd[i]>=65 and hexd[i]<=70)
   num=((int)hexd[i]-55);
   else if (hexd[i]>=97 and hexd[i]<=102)
   num=((int)hexd[i]-87);

   decimal=decimal+(num*pow(16,-p));
    ++p;                                    //p is used for the multiply with 16 with negative powers.
   }


   cout<<" \n The decimal equivalent of hexadecimal number "<<hexd<<" is "    <<decimal;
  cout<<"\n Do you want to convert another hexadecimal number into decimal?   (Y/N): ";  // Asks if the user again wants to do a conversion.
 cin>>choice;
 }while(choice=='Y' or choice=='y');
cout<<"\n\n **** THANK YOU FOR USING THIS SOFTWARE ****";
return 0;
