/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on February 26, 2017, 1:45 AM
 * Purpose: Assignment 1 Menu
 */

//System Libraries
#include <iostream>   //Input/Output Stream Library
#include <iomanip>    //Formatting Library
using namespace std;  //Iostream uses the standard namespace

//User Libraries

//Global Constants - PI, Gravity, Conversions

//Function Prototypes
void prob1();
void prob2();
void prob3();
void prob4();
void prob5();
void menu();

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare variables, no doubles
    char choice, cont;
    
    //Input data
    do{
        menu();
        cin>>choice;
    
        //Process the Data and Display Results
        switch(choice){
            case '1':prob1();break;
            case '2':prob2();break;
            case '3':prob3();break;
            case '4':prob4();break;
            case '5':prob5();break;
            default:cout<<"Not option in menu"<<endl;
        }
        cout<<"Would you like to select another program (Y/N)?"<<endl;
        cin>>cont;
    }while(cont=='y'||cont=='Y');
        
    //Exit Stage Right!
    return 0;
}

//000000111111122222223333333344444444455555555556666666667777777788888899999990
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                                  Problem 1
//000000111111122222223333333344444444455555555556666666667777777788888899999990
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//
//Inputs - temp, F
//Outputs - Temperature Conversion
void prob1(){
     //Declare Variables
    float temp, F;
    
    //Input Data
    cout<<"Let's convert from Celsius to Fahrenheit!"<<endl;
    cout<<"Please enter a temperature and I will convert it for you."<<endl;
    cin>>temp;
    
    //Process Data
    F=(9/5.0*temp)+32;
    
    //Output Data
    cout<<"Celsius: "<<temp<<" -> Fahrenheit: "<<F<<endl;
    cout<<"-------------------------------"<<endl;
    
    //Return from Problem 1
    return;
}

//000000111111122222223333333344444444455555555556666666667777777788888899999990
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                                  Problem 2
//000000111111122222223333333344444444455555555556666666667777777788888899999990
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//
//Inputs - dollar, yconv, econv
//Outputs - Currency Conversions
void prob2(){
    //Declare Variables
    float dollar, yconv, econv;
    float yen=98.93;
    float euro=.74;
    
    //Input Data
    cout<<"Let's do some currency conversions."<<endl;
    cout<<"Enter the USD amount and I will convert it to both Yen and ";
    cout<<"Euros."<<endl;
    cin>>dollar;
    
    //Process Data
    yconv=dollar*yen;
    econv=dollar*euro;
    
    //Output Data
    cout<<fixed<<setprecision(2)<<showpoint<<endl;
    cout<<dollar<<" Dollar(s) = "<<setw(2)<<yconv<<" Yen"<<endl;
    cout<<dollar<<" Dollar(s) = "<<setw(2)<<econv<<" Euros"<<endl;
    cout<<"-------------------------------"<<endl;
    
    //Return from Problem 2
    return;
}

//000000111111122222223333333344444444455555555556666666667777777788888899999990
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                                  Problem 3
//000000111111122222223333333344444444455555555556666666667777777788888899999990
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//
//Inputs - actual, assess1, assess2, taxrate, quarter, proptax
//Outputs - Senior Citizen Property Tax
void prob3(){
    //Declare variables, no doubles
    float actual,assess1,assess2,taxrate,quarter,proptax;
    float exempt=5000.00;
    
    //Input data
    cout<<"This program assess the amount of property tax a senior citizen ";
    cout<<"will be charged for a property"<<endl;
    cout<<"Please enter the actual value of the property: ";
    cin>>actual;
    cout<<"Now please enter the current tax rate for each $100 of assessed ";
    cout<<"value: ";
    cin>>taxrate;
    
    //Process data
    assess1=actual*.60;
    assess2=assess1-exempt;
    proptax=assess2/100*taxrate;
    quarter=proptax/4;    
        
    //Output data
    cout<<fixed<<setprecision(2)<<showpoint<<endl;
    cout<<"Actual Value:                       $"<<setw(10)<<actual<<endl;
    cout<<"Assessed Value (before exemptions): $"<<setw(10)<<assess1<<endl;
    cout<<"Exemption Amount:                   $"<<setw(10)<<exempt<<endl;
    cout<<"Assessed Value (after exemptions):  $"<<setw(10)<<assess2<<endl;
    cout<<"Property Tax:                       $"<<setw(10)<<proptax<<endl;
    cout<<"Quarterly Tax Bill:                 $"<<setw(10)<<quarter<<endl;
    cout<<"-------------------------------"<<endl;
    
    //Return from Problem 3
    return;
}

//000000111111122222223333333344444444455555555556666666667777777788888899999990
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                                  Problem 4
//000000111111122222223333333344444444455555555556666666667777777788888899999990
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//
//Inputs - month, year
//Outputs - Number of Days in Month in Particular Year
void prob4(){
    //Declare Variables
    unsigned int month, year;
    
    //Input Data
    cout<<"Enter a month (1-12): ";
    cin>>month;
    cout<<"Enter a year: ";
    cin>>year;
    cout<<endl;
    
    //Process & Output Data
    switch(month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: 
            cout<<"31 days"<<endl;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            cout<<"30 days"<<endl;
            break;
        case 2:
            if(year%100==0){
                if(year%400==0)
                    cout<<"29 days"<<endl;
            }else if(year%4==0)
                cout<<"29 days"<<endl;
            else
                cout<<"28 days"<<endl;
            break;
        default:
            cout<<"Not a valid entry. Sorry"<<endl;        
    }
    cout<<"-------------------------------"<<endl;
    
    //Return from Problem 4
    return;
}

//000000111111122222223333333344444444455555555556666666667777777788888899999990
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                                  Problem 5
//000000111111122222223333333344444444455555555556666666667777777788888899999990
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//
//Inputs - package, minutes, extra;
//Outputs - Total Monthly Bill
void prob5(){
    //Declare Variables, no doubles
    char package;
    float minutes,extra;
    float A=39.99, B=59.99, C=69.99;
    
    //Input Data
    cout<<"This program calculates a monthly mobile phone bill."<<endl;
    cout<<"There are three different packages: "<<endl;
    cout<<"Package A: $39.99 per month for 450 minutes. Additional minutes ";
    cout<<"are $0.45 per minute.\n";
    cout<<"Package B: $59.99 per month for 900 minutes. Additional minutes ";
    cout<<"are $0.40 per minute.\n";
    cout<<"Package C: $69.99 per month unlimited\n";
    cout<<"Please enter your package (A, B, or C): ";
    cin>>package;
    cout<<"Now enter the total minutes used this month: ";
    cin>>minutes;
    cout<<endl;
    
    //Process and Output Data
    switch(package){
        case 'a':
        case 'A':
            if(minutes>450){
                extra=minutes-450;
                minutes=A+extra*.45;
                cout<<"Package Price: $"<<A<<endl;
                cout<<"Extra Minutes Used: "<<extra<<endl;
                cout<<"Total Monthly Bill: $"<<minutes<<endl;
            }else
                cout<<"Total Monthly Bill: $"<<A<<endl;
            break;
        case 'b':
        case 'B':
            if(minutes>900){
                extra=minutes-900;
                minutes=B+extra*.40;
                cout<<"Package Price: $"<<B<<endl;
                cout<<"Extra Minutes Used: "<<extra<<endl;
                cout<<"Total Monthly Bill: $"<<minutes<<endl;
            }else
                cout<<"Total Monthly Bill: $"<<B<<endl;
            break;
        case 'c':
        case 'C':
            cout<<"Total Monthly Bill: $"<<C<<endl;
            break;
        default:
            cout<<"Sorry. That is not a valid entry.";
    }
    cout<<"-------------------------------"<<endl;
    
    //Return from Problem 5
    return;
}

//000000111111122222223333333344444444455555555556666666667777777788888899999990
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                                  MENU
//000000111111122222223333333344444444455555555556666666667777777788888899999990
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//
//Displays Menu
//Inputs - None
//Outputs - The Menu
void menu(){
    cout<<"Menu Program for Assignment 1"<<endl;
    cout<<"Simply choose the number for the problem to display"<<endl;
    cout<<"1. Celsius to Fahrenheit"<<endl;
    cout<<"2. Currency"<<endl;
    cout<<"3. Senior Citizen Property Tax"<<endl;
    cout<<"4. Days in a Month"<<endl;
    cout<<"5. Mobile Service"<<endl;
    
    //Exit Menu Choice
    return;
}