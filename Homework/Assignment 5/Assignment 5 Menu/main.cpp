//Laurie Guimont
//May 10th, 2017
//Menu for Assignment 4

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

#include "Date.h"
#include "Employee.h"
#include "Car.h"
#include "Personal.h"
#include "RetailItem.h"
#include "TestScores.h"
#include "Circle.h"
#include "NumDays.h"
#include "FeetInches.h"
#include "FeetInch.h"

void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();
void problem10();

    int main(int argv,char *argc[])
    {
	int inN;
        do{
         Menu();
         inN=getN();
         switch(inN){
          case 1:    problem1();break;
          case 2:    problem2();break;
          case 3:    problem3();break;
          case 4:    problem4();break;
          case 5:    problem5();break;
          case 6:    problem6();break;
          case 7:    problem7();break;
          case 8:    problem8();break; 
          case 9:    problem9();break;
          case 10:   problem10();break;
          default:   def(inN);}
        }while(inN<11);
        return 0;
    }
    void Menu()
    {
           cout<<"Type 1 for Problem 1: Date Format Program"<<endl;
           cout<<"Type 2 for Problem 2: Employee Display Program"<<endl;
           cout<<"Type 3 for Problem 3: Car Accelerate/Decelerate Program\n";
           cout<<"Type 4 for Problem 4: Personal Information Program"<<endl;
           cout<<"Type 5 for Problem 5: Retail Item Display Program"<<endl;
           cout<<"Type 6 for Problem 6: Test Average Program"<<endl;
           cout<<"Type 7 for Problem 7: Circle Information Program"<<endl;
           cout<<"Type 8 for Problem 8: Number of Work Days Program"<<endl;
           cout<<"Type 9 for Problem 9: FeetInches Modify Program"<<endl;
           cout<<"Type 10 for Problem 10: FeetInches 2nd Modify Program"<<endl;
           cout<<"Type 11 to Exit \n"<<endl;
    }
    int getN()
    {
           int inN;
           cin>>inN;
           cin.ignore();
           return inN;
    }
    void problem1()
    {
        //Declare Variables
        Date date;
        int m,d,y;

        //Input Data
        cout<<"Please enter a month, day, and a 4-digit year."<<endl;
        cin>>m>>d>>y;

        //Process Data
        date.setmnth(m);
        date.setday(d);
        date.setyear(y);

        //Output Date in 3 Formats
        cout<<"Here is what you entered: "<<endl;
        cout<<date.getmnth()<<"/"<<date.getday()<<"/"<<date.getyear()<<endl;
        cout<<date.mname()<<" "<<date.getday()<<", "<<date.getyear()<<endl;
        cout<<date.getday()<<" "<<date.mname()<<" "<<date.getyear()<<endl;
        cout<<endl;
    }
    void problem2()
    {
        //Declare Variables
        Employee emp1,emp2,emp3;

        //Store Data in each object
        //Employee 1
        emp1.setname("Susan Meyers");
        emp1.setid(47899);
        emp1.setdept("Accounting");
        emp1.setpos("Vice President");

        //Employee 2
        emp2.setname("Mark Jones");
        emp2.setid(39119);
        emp2.setdept("IT");
        emp2.setpos("Programmer");

        //Employee 3
        emp3.setname("Joy Rogers");
        emp3.setid(81774);
        emp3.setdept("Manufacturing");
        emp3.setpos("Engineer");

        //Output the Data
        cout<<"Name\t\tID Number\tDepartment\tPosition"<<endl;
        cout<<"-------------------------------------------------------------\n";
        cout<<emp1.getname()<<"\t"<<emp1.getid()<<"\t\t"<<emp1.getdept()<<"\t"
                <<emp1.getpos()<<endl;
        cout<<emp2.getname()<<"\t"<<emp2.getid()<<"\t\t"<<emp2.getdept()<<"\t\t"
                <<emp2.getpos()<<endl;
        cout<<emp3.getname()<<"\t"<<emp3.getid()<<"\t\t"<<emp3.getdept()<<"\t"
                <<emp3.getpos()<<endl;
        cout<<endl;
    }
    void problem3()
    {
        //Declare Variables
        int y;
        string m;

        //Get Car's Model Year & Make
        cout<<"Please enter the car's year model: ";
        cin>>y;
        cin.ignore();
        cout<<"Enter the car's make: ";
        getline(cin,m);

        //Declare Class Object
        Car object(y,m);

        //Adjust and Output the Speed
        cout<<endl;
        cout<<object.getmake()<<" "<<object.getyear()<<endl;
        cout<<"Accelerating Now!"<<endl;
        for(int i=0;i<5;i++){
            object.accelerate();
            cout<<object.getspd()<<endl;
        }
        cout<<endl;
        cout<<"Decelerating Now!"<<endl;
        for(int i=0;i<5;i++){
            cout<<object.brake()<<endl;
        }
        cout<<endl;
    }
    void problem4()
    {
        //Declare Variables
        Personal people[3];
        string n,a,p;
        int g;

        //Fill Array
        cout<<"Enter the following information for yourself and then two ";
        cout<<"others\n";
        for(int i=0;i<3;i++){
            cout<<"Person "<<i+1<<": "<<endl;
            cout<<"Name: ";
            getline(cin,n);
            cout<<"Address: ";
            getline(cin,a);
            cout<<"Age: ";
            cin>>g;
            cin.ignore();
            cout<<"Phone: ";
            getline(cin,p);

            cout<<endl;
            cout<<"Here are what you input: \n";
            //Set the Information
            people[i].setname(n);
            people[i].setaddy(a);
            people[i].setage(g);
            people[i].setphne(p);

            //Get the Information
            cout<<"Name: "<<people[i].getname()<<endl;
            cout<<"Address: "<<people[i].getaddy()<<endl;
            cout<<"Age: "<<people[i].getage()<<endl;
            cout<<"Phone: "<<people[i].getphne()<<endl<<endl;
        }
    }
    void problem5()
    {
        //Function Prototypes
        void prntPtr(RetailItem);
        //Declare & Initialize Class Variables
        string d;
        int u;
        float p;
        RetailItem item1(d,u,p),item2(d,u,p),item3(d,u,p);

        //Set Item 1 Info
        item1.setdesc("Jacket\t");
        item1.setunit(12);
        item1.setprce(59.95);

        //Set Item 2 Info
        item2.setdesc("Designer Jeans");
        item2.setunit(40);
        item2.setprce(34.95);

        //Set Item 3 Info
        item3.setdesc("Shirt\t");
        item3.setunit(20);
        item3.setprce(24.95);

        //Display All Information
        cout<<"\tDecription\t\tUnits on Hand\t\tPrice"<<endl;
        cout<<"\t-----------------------------------------------------\n";
        cout<<"Item #1\t";
        prntPtr(item1);
        cout<<"Item #2\t";
        prntPtr(item2);
        cout<<"Item #3\t";
        prntPtr(item3);
    }
        void prntPtr(RetailItem i){
            cout<<i.getdesc()<<"\t\t      "<<i.getunit()<<"\t\t"<<i.getprce();
            cout<<endl<<endl;
        }
    void problem6()
    {
        //Declare Variables
        TestScores object;
        float s1,s2,s3;

        cout<<"Please enter three test scores: ";
        cin>>s1>>s2>>s3;

        //Set & Get Test Scores
        object.setTest(s1,s2,s3);

        cout<<"The test scores you entered were: "<<endl;
        cout<<fixed<<setprecision(1)<<showpoint;
        cout<<"Test #1: "<<object.getTst1()<<endl;
        cout<<"Test #2: "<<object.getTst2()<<endl;
        cout<<"Test #3: "<<object.getTst3()<<endl;
        cout<<"The average of these is: ";
        cout<<object.average()<<endl<<endl;
    }
    void problem7()
    {
	//Instantiate Class Object
        float r;
        Circle circle;

        //Get Radius from User
        cout<<"Enter the radius of a circle: "<<endl;
        cin>>r;

        //Set Radius and Begin Getting Information
        circle.setRad(r);

        cout<<"Thank you. Here is some information that you can obtain:"<<endl;
        cout<<"Radius:        "<<circle.getRad()<<endl;
        cout<<"Diameter:      "<<circle.getDiam()<<endl;
        cout<<"Area:          "<<circle.getArea()<<endl;
        cout<<"Circumference: "<<circle.getCrcm()<<endl<<endl;
    }
    void problem8()
    {
        //Instantiate Class Objects
        NumDays first(40);
        NumDays second(28);

        //First's Hours & Number of Days
        cout<<"First Number:"<<endl;
        cout<<"Number of Hours: "<<first.getHrs()<<endl;
        cout<<"Number of Work Days:  "<<first.getDays()<<endl<<endl;

        //Second's Hours & Number of Days
        cout<<"Second Number:"<<endl;
        cout<<"Number of Hours: "<<second.getHrs()<<endl;
        cout<<"Number of Work Days:  "<<second.getDays()<<endl<<endl;

        //Instantiate Class Object
        NumDays third(0);

        //Demonstrating Operator Overload
        third=first+second;
        cout<<"Testing Operator Overloading Now:"<<endl;
        cout<<"First + Second = "<<third.getDays()<<endl;
        third=first-second;
        cout<<"First - Second = "<<third.getDays()<<endl<<endl; 
        cout<<"Testing first++:    "<<first++<<endl;
        cout<<"First's hours now:  "<<first.getHrs()<<endl;
        cout<<"Testing ++second:   "<<++second<<endl;
        cout<<"Second's hours now: "<<second.getHrs()<<endl;
        cout<<"Testing first--:    "<<first--<<endl;
        cout<<"First's hours now:  "<<first.getHrs()<<endl;
        cout<<"Testing --second:   "<<--second<<endl;
        cout<<"Second's hours now: "<<second.getHrs()<<endl;
        cout<<endl;
    }
    void problem9()
    {
        //Declare Variables
        int feet, inches;

        FeetInches first,second;

        cout<<"Enter a distance in feet and inches: ";
        cin>>feet>>inches;

        //Store the distance in first
        first.setFeet(feet);
        first.setInch(inches);

        cout<<"Enter another distance in feet and inches: ";
        cin>>feet>>inches;

        //Store the distance in second
        second.setFeet(feet);
        second.setInch(inches);

        //Compare the two objects
        cout<<endl<<"Facts:"<<endl;
        if(first<=second)
            cout<<"first is less than or equal to second"<<endl;
        if(first>=second)
            cout<<"first is greater than or equal to second"<<endl;
        if(first!=second)
            cout<<"first does not equal second"<<endl;
        cout<<endl;
    }
    void problem10()
    {
        //Declare Variables
        int feet, inches;
        FeetInch first,second;

        cout<<"Enter a distance in feet and inches: ";
        cin>>feet>>inches;

        //Store the distance in first
        first.setFeet(feet);
        first.setInch(inches);

        //Copy the first object to the second
        second=first;

        //Multiply the two objects together
        first.multiply(second);
        cout<<endl;
        cout<<"After multiplying the distance by itself: "<<endl;
        cout<<first.getFeet()<<"ft. "<<first.getInch()<<"in."<<endl<<endl;
    }
    void def(int inN)
    {
           cout<<"You typed "<<inN<<" to exit the program. Bye."<<endl;
    }