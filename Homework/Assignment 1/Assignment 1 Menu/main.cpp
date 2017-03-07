//Laurie Guimont
//March 6th, 2017
//Menu for Assignment 1

#include <iostream>
#include <iomanip>   
#include <fstream>    
#include <string>    
#include <cstdlib>    
#include <ctime>     
using namespace std;

const int COL=30;    //Used for 2D Array in Problem 8

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
           cout<<"Type 1 for problem 1"<<endl;
           cout<<"Type 2 for problem 2"<<endl;
           cout<<"Type 3 for problem 3"<<endl;
           cout<<"Type 4 for problem 4"<<endl;
           cout<<"Type 5 for problem 5"<<endl;
           cout<<"Type 6 for problem 6"<<endl;
           cout<<"Type 7 for problem 7"<<endl;
           cout<<"Type 8 for problem 8"<<endl;
           cout<<"Type 9 for problem 9"<<endl;
           cout<<"Type 10 for problem 10"<<endl;
           cout<<"Type 11 to exit \n"<<endl;
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
        float temp, F;
        //Input Data
        cout<<"Let's convert from Celsius to Fahrenheit!"<<endl;
        cout<<"Please enter a temperature and I will convert it for you."<<endl;
        cin>>temp;
        //Process Data
        F=(9/5.0*temp)+32;
        //Output Data
        cout<<fixed<<setprecision(1)<<showpoint;
        cout<<"Celsius: "<<temp<<" -> Fahrenheit: "<<F<<endl;
        cout<<"-------------------------------"<<endl;
    }
    void problem2()
    {
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
    }
    void problem3()
    {
        //Declare Variables
        float actual,assess1,assess2,taxrate,quarter,proptax;
        float exempt=5000.00;
        //Input Data
        cout<<"This program assess the amount of property tax a senior ";
        cout<<"citizen will be charged for a property"<<endl;
        cout<<"Please enter the actual value of the property: ";
        cin>>actual;
        cout<<"Now please enter the current tax rate for each $100 of ";
        cout<<"assessed value: ";
        cin>>taxrate;
        //Process Data
        assess1=actual*.60;
        assess2=assess1-exempt;
        proptax=assess2/100*taxrate;
        quarter=proptax/4;    
        //Output Data
        cout<<fixed<<setprecision(2)<<showpoint<<endl;
        cout<<"Actual Value:                       $"<<setw(10)<<actual<<endl;
        cout<<"Assessed Value (before exemptions): $"<<setw(10)<<assess1<<endl;
        cout<<"Exemption Amount:                   $"<<setw(10)<<exempt<<endl;
        cout<<"Assessed Value (after exemptions):  $"<<setw(10)<<assess2<<endl;
        cout<<"Property Tax:                       $"<<setw(10)<<proptax<<endl;
        cout<<"Quarterly Tax Bill:                 $"<<setw(10)<<quarter<<endl;
        cout<<"-------------------------------"<<endl;
    }
    void problem4()
    {
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
    }
    void problem5()
    {
        //Declare Variables
        char package;
        float minutes,extra;
        float A=39.99, B=59.99, C=69.99;

        //Input Data
        cout<<"This program calculates a monthly mobile phone bill."<<endl;
        cout<<"There are three different packages: "<<endl;
        cout<<"Package A: $39.99 per month for 450 minutes. Additional ";
        cout<<"minutes are $0.45 per minute.\n";
        cout<<"Package B: $59.99 per month for 900 minutes. Additional ";
        cout<<"minutes are $0.40 per minute.\n";
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
    }
    void problem6()
    {
        //Declare Variables
        int months=12,years;
        float rain,average,sum=0;
        //Input Data
        cout<<"This program is designed to calculate the average rainfall ";
        cout<<"over a given period of time."<<endl;
        cout<<"Please enter the number of years you would like to calculate. ";
        cin>>years;
        //Input Validation
        while(years<1){
            cout<<"Sorry. No numbers less than 1. Please try again."<<endl;
            cin>>years;
        }
        //Process Data
        for(int i=0;i<years;i++){
            cout<<"For Year "<<i+1<<": "<<endl;
            cout<<"----------"<<endl;
            for(int i=0;i<months;i++){
                cout<<"How many inches of rainfall in month #"<<i+1<<"? ";
                cin>>rain;
                //Input Validation
                while(rain<0){
                    cout<<"Sorry. You can't have a negative number represent ";
                    cout<<"the amount of rainfall in any month. Please try ";
                    cout<<"again.\n";
                    cin>>rain;
                }
                sum+=rain;
            }
        }
        average=sum/(years*12);
        //Output Data
        cout<<fixed<<setprecision(1)<<showpoint;
        cout<<endl;
        cout<<"Average Rainfall over "<<years<<" year(s) is "<<average;
        cout<<" inches\n";
    }
    void problem7()
    {
	//Function Prototypes
        void celsius(float);
        //Declare Variables
        float F;
        int times=21;
        //Call Function to Display Table 
        cout<<"I will call a function that will display temperatures 0 ";
        cout<<"through 20 in Fahrenheit and then convert all temperatures ";
        cout<<"to Celsius."<<endl<<endl;
        cout<<"\tFahrenheit\t   Celsius"<<endl;
        cout<<"\t--------------------------"<<endl;
        for(int i=0;i<times;i++)
            celsius(i);
    }
        void celsius(float temp){
            //Declare Variables
            float C;
            //Process Data
            C=5/9.0*(temp-32);
            //Output Data
            cout<<fixed<<setprecision(2)<<showpoint;
            cout<<"\t  "<<setw(6)<<temp<<"\t   "<<setw(6)<<C<<endl;
            //Return to Problem 7
            return;
        }
    void problem8()
    {
	//Function Prototypes
        void process(char [][COL], int);
        //Declare Variables
        const int ROW=3;
        char rcs[ROW][COL];
        //Process & Output the Data
        process(rcs,ROW);
    }
        void process(char rcs [][COL],int r){
            //Function Prototype
            void readin(string [],char [][COL], int);
            //Declare Variables
            int rain=0,cloud=0,sun=0;      //Total rainy, cloudy, or sunny days
            int juner=0,julyr=0,augustr=0; //total rain per month
            int junec=0,julyc=0,augustc=0; //total cloud per month
            int junes=0,julys=0,augusts=0; //total sun per month
            string months[r]={"June  ", "July  ", "August"};
            //Call Function to Display Array
            readin(months,rcs,r);
            //Process the Data
            for(int i=0;i<r;i++){
                for(int j=0;j<COL;j++){
                    if(rcs[i][j]=='R'){
                        rain++;
                        if(i==0) juner++;
                        else if(i==1) julyr++;
                        else augustr++;
                    }
                    if(rcs[i][j]=='C'){
                        cloud++;
                        if(i==0) junec++;
                        else if(i==1) julyc++;
                        else augustc++;
                    }
                    if(rcs[i][j]=='S'){
                        sun++;
                        if(i==0) junes++;
                        else if(i==1) julys++;
                        else augusts++;
                    }
                }
            }
            //Display Stats
            cout<<endl<<"\tRain\t Cloud\t  Sun"<<endl;
            cout<<"        ---------------------"<<endl;
            cout<<"June:    "<<juner<<"\t  "<<junec<<"\t  "<<junes<<endl;
            cout<<"July:    "<<julyr<<"\t  "<<julyc<<"\t  "<<julys<<endl;
            cout<<"August:  "<<augustr<<"\t  "<<augustc<<"\t  "<<augusts<<endl;
            cout<<endl;
            cout<<"Total number of rainy days over three months:   "<<rain;
            cout<<endl;
            cout<<"Total number of cloudy days over three months:  "<<cloud;
            cout<<endl;
            cout<<"Total number of sunny days over three months:   "<<sun;
            cout<<endl;
            //Return to Problem 8
            return;
        }
        void readin(string months[],char rcs[][COL],int r){
            //Declare the File
            ifstream in;
            //Open the Input File
            in.open("RainorShine.txt");
            //Read In the File
            for(int i=0;i<r;i++){
                cout<<months[i]<<":  ";
                for(int j=0;j<COL;j++){
                    in>>rcs[i][j];
                    cout<<rcs[i][j]<<" ";
                }
                cout<<endl;
            }
            //Close the Input File
            in.close();
            //Return to Process Function
            return;
        }
    void problem9()
    {
	//Function Protoypes
        void random(int [],int);
        void guess(int [],int);
        //Declare Variables
        const int SIZE=5;
        int winning[SIZE];
        int user[SIZE];
        bool match=true;
        //Input Data
        cout<<"Do you like to play the lottery? Think you can win?"<<endl;
        cout<<"Enter five numbers separated by spaces."<<endl;
        guess(user,SIZE);
        //Display Winning Numbers
        cout<<endl;
        cout<<"The winning numbers are:"<<endl;
        cout<<"------------------------"<<endl;
        random(winning,SIZE);
        cout<<endl<<endl;
        //Determine Win or Loss
        for(int j=0;j<SIZE;j++){
            if(user[j]==winning[j])
                match;
            else match=false;
        }
        if(match)
            cout<<"YOU WON!!!!! Congratulations!"<<endl;
        else
            cout<<"Sorry. You lost. Maybe you'll win next time!"<<endl;
    }
        void guess(int user[],int size){
           //Accept User Input
            for(int i=0;i<size;i++){
                cin>>user[i];
            }
            //Return to Problem 9
            return;
        }
        void random(int winning[],int size){
            //Set Random Number Seed
            srand(static_cast<unsigned int>(time(0)));
            //Declare Variables
            int MIN=0, MAX=9;
            //Generate & Display Array
            for(int i=0;i<size;i++){
                winning[i]=(rand()%(MAX-MIN+1))+MIN;
                cout<<winning[i]<<" ";
            }
            //Return to Problem 9
            return;
        }
    void problem10()
    {
	//Function Prototypes
        void sort(string[],int);
        int binsrch(string[],int,string);

        //Declare Variables
        const int SIZE=20;
        int results;
        string value;
        string names[SIZE]={"Collins, Bill","Smith, Bart","Allen, Jim",
                            "Griffin, Jim","Stamey, Marty","Rose, Geri",
                            "Taylor, Terri","Johnson, Jill","Allison, Jeff",
                            "Looney, Joe","Wolfe, Bill","James, Jean",
                            "Weaver, Jim","Pore, Bob","Rutherford, Greg",
                            "Javens, Renee","Harrison, Rose","Setzer, Cathy",
                            "Pike, Gordon","Holland, Beth"};
        //Sort Array
        sort(names,SIZE);
        //Perform a Search
        cout<<"Enter a name you would like to search for and I will tell ";
        cout<<"you if it is in the list."<<endl;
        getline(cin,value);
        results=binsrch(names,SIZE,value);
        //Output Results
        if(results==-1)
            cout<<"Sorry. That name is not in the list."<<endl;
        else
            cout<<"That name is found at element "<<results<<" in the array\n";
    }
        int binsrch(string names[],int size, string value){   
            //Declare Variables
            int first=0,
               last=size-1,
               middle,
               position=-1;
           bool found=false;
           //Search Array
           while (!found && first<=last){
               middle=(first+last)/2;
               if(names[middle]==value){
                   found=true;
                   position=middle;
               }
               else if(names[middle]>value)
                   last=middle-1;
               else
                   first=middle+1;
           }
           //Return Position to Problem 10
           return position;
        }
        void sort(string names[],int size){
            //Declare Variables
            int start,mindx;
            string minval;
            //Sort Array
            for(start=0;start<(size-1);start++){
                mindx=start;
                minval=names[start];
                for(int i=start+1;i<size;i++){
                    if(names[i]<minval){
                        minval=names[i];
                        mindx=i;
                    }
                }
                names[mindx]=names[start];
                names[start]=minval;
            }
            //Display Array
            cout<<"Here is a list of names alphabetized by last name:"<<endl;
            cout<<"--------------------------------------------------"<<endl;
            for(int j=0;j<size;j++)
                cout<<names[j]<<endl;
            cout<<endl;
            //Return to Problem 10
            return;
        }
    void def(int inN)
    {
           cout<<"You typed "<<inN<<" to exit the program. Bye."<<endl;
    }