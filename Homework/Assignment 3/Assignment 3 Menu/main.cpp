//Laurie Guimont
//March 29th, 2017
//Menu for Assignment 3

#include <iostream>
#include <iomanip>   
#include <string>     
using namespace std;

//User Libraries
#include "Movie Data.h"
#include "Movie Data Mod.h"
#include "Sales.h"
#include "Weather.h"
#include "Soccer.h"
#include "Account.h"
#include "Speaker.h"

//Global Constants
enum Months {JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST,
                 SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};

//Function Prototypes
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
          default:   def(inN);}
        }while(inN<9);
        return 0;
    }
    void Menu()
    {
           cout<<"Type 1 for Problem 1: Movie Data"<<endl;
           cout<<"Type 2 for Problem 2: Movie Data Modification"<<endl;
           cout<<"Type 3 for Problem 3: Corporate Sales Data"<<endl;
           cout<<"Type 4 for Problem 4: Weather Statistics"<<endl;
           cout<<"Type 5 for Problem 5: Weather Statistics Modification"<<endl;
           cout<<"Type 6 for Problem 6: Soccer Scores"<<endl;
           cout<<"Type 7 for Problem 7: Customer Accounts"<<endl;
           cout<<"Type 8 for Problem 8: Speakers' Bureau"<<endl;
           cout<<"Type 9 to Exit \n"<<endl;
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
        //Function Prototypes
        void display(movie);
        
        //Declare variables, no doubles
        movie movie1={"Whiplash","Damien Chazelle",2014,107};
        movie movie2={"The Help","Tate Taylor",2011,146};

        //Display Information on Movies
        cout<<"This program displays information about two different ";
        cout<<"movies."<<endl;
        display(movie1);
        cout<<endl;
        display(movie2);
        cout<<endl;
    }
        void display(movie m){
            //Print  Movie Information to the Screen
            cout<<"Movie:         "<<m.title<<endl;
            cout<<"Director:      "<<m.direct<<endl;
            cout<<"Year Released: "<<m.year<<endl;
            cout<<"Running Time:  "<<m.runtime<<" minutes"<<endl;
        }
    void problem2()
    {
        //Function Prototypes
        void disply1(modify);
        
        //Declare variables, no doubles
        modify movie1={"Whiplash","Damien Chazelle",2014,107,3300000,33000000};
        modify movie2={"The Help","Tate Taylor",2011,146,25000000,213000000};

        //Display Information on Movies
        cout<<"This program is similar to Problem 1, except that this ";
        cout<<"program displays Production Costs and Revenue of both ";
        cout<<"movies"<<endl;
        disply1(movie1);
        cout<<endl;
        disply1(movie2);
        cout<<endl;
    }
        void disply1(modify m){
            //Print  Movie Information to the Screen
            cout<<"Movie:            "<<m.title<<endl;
            cout<<"Director:         "<<m.direct<<endl;
            cout<<"Year Released:    "<<m.year<<endl;
            cout<<"Running Time:     "<<m.runtime<<" minutes"<<endl;
            cout<<fixed<<setprecision(2)<<showpoint;
            cout<<"Production Cost:  $"<<setw(12)<<m.product<<endl;
            cout<<"Revenue:          $"<<setw(12)<<m.revenue<<endl;
        }
    void problem3()
    {
        //Function Prototypes
        void first(Sales);
        void second(Sales);
        void third(Sales);
        void fourth(Sales);
        
        //Declare variables, no doubles
        Sales dvsion1={"East"}, dvsion2={"West"}, dvsion3={"North"}, 
            dvsion4={"South"};
    
        //Get the Information for each division
        cout<<"This program stores and displays sales information about a ";
        cout<<"company's North, South, East, and West divisions."<<endl;
        first(dvsion1);
        second(dvsion2);
        third(dvsion3);
        fourth(dvsion4);
        cout<<endl;
    }
        void first(Sales d1){
            //Get the Amount of Sales
            cout<<"Please enter the following information for "<<d1.name<<":\n";
            cout<<"First-Quarter Sales: ";
            cin>>d1.Q1;
            cout<<"Second-Quarter Sales: ";
            cin>>d1.Q2;
            cout<<"Third-Quarter Sales: ";
            cin>>d1.Q3;
            cout<<"Fourth-Quarter Sales: ";
            cin>>d1.Q4;
            cout<<endl;

            //Calculate the total & average sales
            d1.total=d1.Q1+d1.Q2+d1.Q3+d1.Q4;
            d1.average=d1.total/4;

            //Output results
            cout<<fixed<<setprecision(2)<<showpoint;
            cout<<"Here are the results for the "<<d1.name<<" sales:"<<endl;
            cout<<"Total Sales:   $"<<setw(5)<<d1.total<<endl;
            cout<<"Average Sales: $"<<setw(5)<<d1.average<<endl;
        }
        void second(Sales d2){
            cout<<endl;
            //Get the Amount of Sales
            cout<<"Please enter the following information for "<<d2.name<<":\n";
            cout<<"First-Quarter Sales: ";
            cin>>d2.Q1;
            cout<<"Second-Quarter Sales: ";
            cin>>d2.Q2;
            cout<<"Third-Quarter Sales: ";
            cin>>d2.Q3;
            cout<<"Fourth-Quarter Sales: ";
            cin>>d2.Q4;
            cout<<endl;

            //Calculate the total & average sales
            d2.total=d2.Q1+d2.Q2+d2.Q3+d2.Q4;
            d2.average=d2.total/4;

            //Output results
            cout<<fixed<<setprecision(2)<<showpoint;
            cout<<"Here are the results for the "<<d2.name<<" sales:"<<endl;
            cout<<"Total Sales:   $"<<setw(5)<<d2.total<<endl;
            cout<<"Average Sales: $"<<setw(5)<<d2.average<<endl;
        }
        void third(Sales d3){
            cout<<endl;
            //Get the Amount of Sales
            cout<<"Please enter the following information for "<<d3.name<<":\n";
            cout<<"First-Quarter Sales: ";
            cin>>d3.Q1;
            cout<<"Second-Quarter Sales: ";
            cin>>d3.Q2;
            cout<<"Third-Quarter Sales: ";
            cin>>d3.Q3;
            cout<<"Fourth-Quarter Sales: ";
            cin>>d3.Q4;
            cout<<endl;

            //Calculate the total & average sales
            d3.total=d3.Q1+d3.Q2+d3.Q3+d3.Q4;
            d3.average=d3.total/4;

            //Output results
            cout<<fixed<<setprecision(2)<<showpoint;
            cout<<"Here are the results for the "<<d3.name<<" sales:"<<endl;
            cout<<"Total Sales:   $"<<setw(5)<<d3.total<<endl;
            cout<<"Average Sales: $"<<setw(5)<<d3.average<<endl;
        }
        void fourth(Sales d4){
            cout<<endl;
            //Get the Amount of Sales
            cout<<"Please enter the following information for "<<d4.name<<":\n";
            cout<<"First-Quarter Sales: ";
            cin>>d4.Q1;
            cout<<"Second-Quarter Sales: ";
            cin>>d4.Q2;
            cout<<"Third-Quarter Sales: ";
            cin>>d4.Q3;
            cout<<"Fourth-Quarter Sales: ";
            cin>>d4.Q4;
            cout<<endl;

            //Calculate the total & average sales
            d4.total=d4.Q1+d4.Q2+d4.Q3+d4.Q4;
            d4.average=d4.total/4;

            //Output results
            cout<<fixed<<setprecision(2)<<showpoint;
            cout<<"Here are the results for the "<<d4.name<<" sales:"<<endl;
            cout<<"Total Sales:   $"<<setw(5)<<d4.total<<endl;
            cout<<"Average Sales: $"<<d4.average<<endl;
        }
    void problem4()
    {
        //Function Prototypes
        void highest(weather [],int);
        void lowest(weather [],int);
        
        //Declare variables, no doubles
        const int SIZE=12;
        weather array[SIZE];
        float totalr=0,avrgr,avgtemp=0;

        //Input data
        cout<<"This program computes weather statistics for each month of ";
        cout<<"the year. \n";
        for(int i=0;i<SIZE;i++){
            cout<<"Please enter the following for Month: "<<i+1<<endl;
            cout<<"Total Rainfall: ";
            cin>>array[i].rain;
            cout<<"High Temperature: ";
            cin>>array[i].high;
            while((array[i].high)<-100||(array[i].high)>140){
                cout<<"Sorry. Only values between -100 and 140 degrees ";
                cout<<"Fahrenheit are allowed."<<endl;
                cin>>array[i].high;
            }
            cout<<"Low Temperature: ";
            cin>>array[i].low;
            while((array[i].low)<-100||(array[i].low)>140){
                cout<<"Sorry. Only values between -100 and 140 degrees ";
                cout<<"Fahrenheit are allowed."<<endl;
                cin>>array[i].low;
            }
            //Calculate Averages
            totalr+=array[i].rain;
            array[i].average=(array[i].high+array[i].low)/2;
            avgtemp+=array[i].average;
        }

        //Process data
        avrgr=totalr/12;
        avgtemp/=12;

        //Output data
        cout<<endl;
        cout<<"Here are the results: "<<endl;
        highest(array,SIZE);
        lowest(array,SIZE);
        cout<<fixed<<setprecision(1)<<showpoint;
        cout<<"Average Temperature: "<<avgtemp<<endl;
        cout<<"Total Rainfall: "<<totalr<<endl;
        cout<<"Average Rainfall: "<<avrgr<<endl;
        cout<<endl;
    }
        void lowest(weather a[],int n){
            int index;
            float lowest;
            for(int i=0;i<n-1;i++){
                for(int j=i+1;j<n;j++){
                    if(a[i].low<a[j].low){
                        if(a[i].low<lowest){
                            index=i;
                            lowest=a[i].low;
                        }
                    }
                }
            }
            cout<<"The lowest temperature for the year is "<<lowest;
            cout<<" degrees which occurred in Month "<<index+1<<endl;
        }
            void highest(weather a[],int n){
            int index;
            float highest;
            for(int i=0;i<n-1;i++){
                for(int j=i+1;j<n;j++){
                    if(a[i].high>a[j].high){
                        if(a[i].high>highest){
                            highest=a[i].high;
                            index=i;
                        }
                    }
                }
            }
            cout<<"The highest temperature for the year was "<<highest;
            cout<<" degrees which occurred in Month "<<index+1<<endl;
        }
    void problem5()
    {
        //Function Prototypes
        void disply2(Months);
        
        //Declare variables, no doubles
        const int SIZE=12;
        weather array[SIZE];
        float totalr=0,avrgr,avgtemp=0;

        //Input data
        cout<<"This program is similar to Problem 4 however, this one ";
        cout<<"computes weather statistics each month of the year \n";
        cout<<"by using enumerated data types to display the actual months \n";
        for(Months i=JANUARY;i<SIZE;i=static_cast<Months>(i+1)){
            cout<<"Please enter the following for ";
            disply2(i);
            cout<<": "<<endl;
            cout<<"Total Rainfall: ";
            cin>>array[i].rain;
            cout<<"High Temperature: ";
            cin>>array[i].high;
            while((array[i].high)<-100||(array[i].high)>140){
                cout<<"Sorry. Only values between -100 and 140 degrees ";
                cout<<"Fahrenheit are allowed."<<endl;
                cin>>array[i].high;
            }
            cout<<"Low Temperature: ";
            cin>>array[i].low;
            while((array[i].low)<-100||(array[i].low)>140){
                cout<<"Sorry. Only values between -100 and 140 degrees ";
                cout<<"Fahrenheit are allowed."<<endl;
                cin>>array[i].low;
            }
            //Calculate Averages
            totalr+=array[i].rain;
            array[i].average=(array[i].high+array[i].low)/2;
            avgtemp+=array[i].average;
        }

        //Process data
        avrgr=totalr/12;
        avgtemp/=12;

        //Output data
        cout<<endl;
        cout<<"Here are the results: "<<endl;
        cout<<fixed<<setprecision(1)<<showpoint;
        cout<<"Average Temperature: "<<avgtemp<<endl;
        cout<<"Total Rainfall: "<<totalr<<endl;
        cout<<"Average Rainfall: "<<avrgr<<endl;
        cout<<endl;
    }
        void disply2(Months m){
            switch(m){
                case JANUARY: cout<<"January"; break;
                case FEBRUARY: cout<<"February";break;
                case MARCH: cout<<"March";break;
                case APRIL: cout<<"April";break;
                case MAY: cout<<"May";break;
                case JUNE: cout<<"June";break;
                case JULY: cout<<"July";break;
                case AUGUST: cout<<"August";break;
                case SEPTEMBER: cout<<"September";break;
                case OCTOBER: cout<<"October";break;
                case NOVEMBER: cout<<"November";break;
                case DECEMBER: cout<<"December";break;
            }
        }
    void problem6()
    {
        //Function Prototypes
        scores *fillAry(scores [],int);
        void disply3(scores [],int);
        void teampts(scores [],int);
        void highscr(scores [],int);
        
        //Declare variables, no doubles
        int SIZE=12;
        scores points[SIZE];
        int total;

        //Input & Display the Data
        cout<<"This program receives data on soccer scores and determines the ";
        cout<<"overall team score and highest scorer on the team. "<<endl;
        fillAry(points,SIZE);
        disply3(points,SIZE);
        
        //Calculate Total Team Points and Highest Scorer
        teampts(points,SIZE);
        highscr(points,SIZE);
        cout<<endl;
    }
        void highscr(scores p[],int n){
            int highest=1,index;
            for(int i=0;i<n-1;i++){
                for(int j=i+1;j<n;j++){
                    if(p[i].points>p[j].points){
                        if(p[i].points>highest){
                            highest=p[i].points;
                            index=i;
                        }
                    }
                }
            }
            cout<<endl;
            cout<<"The player who scored the most points is: "<<endl;
            cout<<p[index].name<<endl;
            cout<<p[index].number<<endl;
            cout<<"They scored "<<highest<<" points. Congratulate them!"<<endl;
        }
        void teampts(scores p[],int n){
            int total=0;
            for(int i=0;i<n;i++){
                total+=p[i].points;
            }
            cout<<"Total Team Points: "<<total<<endl;
        }
        void disply3(scores p[],int n){
            cout<<endl;
            cout<<"Here is the Team Roster"<<endl;
            cout<<"-----------------------"<<endl;
            for(int i=0;i<n;i++){
                cout<<"Name:   "<<p[i].name<<endl;
                cout<<"Number: "<<p[i].number<<endl;
                cout<<"Points: "<<p[i].points<<endl;
                cout<<endl;
            }
            cout<<endl;
        }
        scores *fillAry(scores p[],int n){
            for(int i=0;i<n;i++){
                cout<<"Player "<<i+1<<":"<<endl;
                cout<<"Name: ";
                getline(cin,p[i].name);
                cout<<"Number: ";
                cin>>p[i].number;
                while(p[i].number<0){
                    cout<<"No negatives! Enter a positive number.";
                    cin>>p[i].number;
                }
                cout<<"Points Scores: ";
                cin>>p[i].points;
                while(p[i].points<0){
                    cout<<"No negatives! Enter a positive number.";
                    cin>>p[i].points;
                }
                cin.ignore();
            }
            return p;
        }
    void problem7()
    {
	//Function Prototypes
        int Menu1();
        void process(int,account [],int);
        account *adjust(account [],int);
        account *fill(account [],int,int);
        void disply4(account [],int);
        
        //Declare variables, no doubles
        int SIZE=10;
        account custmer[SIZE];
        int choice,index=0;

        //Input the Data
        cout<<"This program accepts information on customer accounts, then ";
        cout<<"allows the user to choose to display the information, \n";
        cout<<"or change the information of any account."<<endl;
        fill(custmer,SIZE,index);
        
        //Display the Menu Options
        do{
        choice=Menu1();
        process(choice,custmer,SIZE);
        }while(choice!=3);
        cout<<endl;
    }
        void disply4(account c[],int n){
            for(int i=0;i<n;i++){
                cout<<endl;
                cout<<c[i].name<<endl;
                cout<<c[i].address<<endl;
                cout<<c[i].city<<", "<<c[i].state<<", "<<c[i].zip<<endl;
                cout<<c[i].telphne<<endl;
                cout<<"$"<<c[i].balance<<endl;
                cout<<c[i].lpyment;
                cout<<endl;
            }
        }
        account *fill(account c[],int n,int index){
            cout<<"Please enter: "<<endl;
            for(int i=index;i<n;i++){
                cout<<"Name "<<i+1<<": ";
                getline(cin,c[i].name);
                cout<<"Address: ";
                getline(cin,c[i].address);
                cout<<"City: ";
                getline(cin,c[i].city);
                cout<<"State: ";
                getline(cin,c[i].state);
                cout<<"Zip Code: ";
                cin>>c[i].zip;
                cin.ignore();
                cout<<"Telephone Number: ";
                getline(cin,c[i].telphne);
                cout<<"Account Balance: ";
                cin>>c[i].balance;
                cin.ignore();
                cout<<"Date of Last Payment (Month & Year): ";
                getline(cin,c[i].lpyment);
            }
            return c;
        }
        account *adjust(account c[],int n){
            int choose;
            cout<<"Which element (0-9) would you like to change?"<<endl;
            cin>>choose;
            cin.ignore();

            fill(c,choose+1,choose);

            return c;
        }
        void process(int choice,account c[],int n){
            switch(choice){
                case 1: adjust(c,n); break;
                case 2: disply4(c,n); break;
                default: return;
            }
        }
        int Menu1(){
            int choice;
            //Display Menu
            cout<<"Now choose what you would like to do with the information ";
            cout<<"you have input"<<endl;
            cout<<"1. Change the Data"<<endl;
            cout<<"2. Display the Data"<<endl;
            cout<<"3. Absolutely Nothing"<<endl;

            cin>>choice;
            while(choice<1||choice>3){
                cout<<"Only select options 1 through 3: ";
                cin>>choice;
            }

            return choice;
        }
    void problem8()
    {
        //Function Prototypes
        void prcess(int,speaker [],int);
        speaker *adjust1(speaker [],int);
        speaker *fill1(speaker [],int,int);
        void disply5(speaker [],int);
        
        //Declare variables, no doubles
        int SIZE=10;
        speaker person[SIZE];
        int choice,index=0;

        //Input the Data
        cout<<"This program keeps track of a speakers' bureau. The user can ";
        cout<<"enter the information, then choose to display or change \n";
        cout<<"any of the information of the speakers' information."<<endl;
        fill1(person,SIZE,index);
        
        //Menu
        do{
        choice=Menu1();
        prcess(choice,person,SIZE);
        }while(choice!=3);
        cout<<endl;
    }
        void disply5(speaker s[],int n){
            for(int i=0;i<n;i++){
                cout<<endl;
                cout<<s[i].name<<endl;
                cout<<s[i].telphne<<endl;
                cout<<s[i].topic<<endl;
                cout<<"$"<<s[i].fee<<endl;
                cout<<endl;
            }
        }
        speaker *fill1(speaker s[],int n,int index){
            cout<<"Please enter: "<<endl;
            for(int i=index;i<n;i++){
                cout<<"Speaker Name "<<i+1<<": ";
                getline(cin,s[i].name);
                cout<<"Telephone Number: ";
                getline(cin,s[i].telphne);
                cout<<"Topic: ";
                getline(cin,s[i].topic);
                cout<<"Speaker Fee: ";
                cin>>s[i].fee;
                cin.ignore();
            }
            return s;
        }
        speaker *adjust1(speaker s[],int n){
            int choose;
            cout<<"Which element (0-9) would you like to change?"<<endl;
            cin>>choose;
            cin.ignore();

            fill1(s,choose+1,choose);

            return s;
        }
        void prcess(int choice,speaker s[],int n){
            switch(choice){
                case 1: adjust1(s,n); break;
                case 2: disply5(s,n); break;
                default: return;
            }
        }
    void def(int inN)
    {
           cout<<"You typed "<<inN<<" to exit the program. Bye."<<endl;
    }