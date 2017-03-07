/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on March 5, 2017, 9:00 PM
 * Purpose: Assignment 2 Menu
 */

//System Libraries
#include <iostream>   //Input/Output Stream Library
#include <iomanip>    //Formatting Library
#include <fstream>    //File Input/Output
#include <string>     //String Library
#include <cstdlib>    //Random Value Library
#include <ctime>      //Unique Seed Value Library
using namespace std;

//Global Constants - PI, Gravity, Conversions
const int COL=30;     //Columns for 2-Dimensional Array

//Function Prototypes
void prob1();
void prob2();
void prob3();
void prob4();
void prob5();
void menu();

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    char choice, cont;
    
    //Input Data
    do{
        menu();
        cin>>choice;
        cin.ignore();  //Necessary due to getline in Problem 5
    
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
        cin.ignore();
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
//Purpose - Average Rainfall
void prob1(){
    //Declare Variables
    int months=12,years;
    float rain,average,sum=0;
    
    //Input Data
    cout<<"This program is designed to calculate the average rainfall over ";
    cout<<"a given period of time."<<endl;
    cout<<"Please enter the number of years you would like to calculate. \n";
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
                cout<<"Sorry. You cannot have a negative number represent the ";
                cout<<"amount of rainfall in any month. Please try again.\n";
                cin>>rain;
            }
            sum+=rain;
        }
    }
    average=sum/(years*12);
        
    //Output Data
    cout<<fixed<<setprecision(1)<<showpoint;
    cout<<endl;
    cout<<"Average Rainfall over "<<years<<" year(s) is "<<average<<" inches\n";
    
    //Return from Problem 1
    return;
}

//000000111111122222223333333344444444455555555556666666667777777788888899999990
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                                  Problem 2
//000000111111122222223333333344444444455555555556666666667777777788888899999990
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//
//Purpose - Temperature Conversions by Calling a Function
void prob2(){
    //Function Prototypes
    void celsius(float);

    //Declare Variables
    float F;
    int times=21;
    
    //Call Function to Display Table 
    cout<<"I will call a function that will display temperatures 0 through 20 ";
    cout<<"in both Celsius and Fahrenheit."<<endl<<endl;
    cout<<"\tFahrenheit\t   Celsius"<<endl;
    cout<<"\t--------------------------"<<endl;
    for(int i=0;i<times;i++)
        celsius(i);
    
    //Return from Problem 2
    return;
}

void celsius(float temp){
    //Declare Variables
    float C;
    
    //Process Data
    C=5/9.0*(temp-32);
    
    //Output Data
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"\t  "<<setw(6)<<temp<<"\t   "<<setw(6)<<C<<endl;
    
    //Return to Problem 2
    return;
}

//000000111111122222223333333344444444455555555556666666667777777788888899999990
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                                  Problem 3
//000000111111122222223333333344444444455555555556666666667777777788888899999990
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//
//Purpose - Rain or Shine Statistics using 2D Arrays
void prob3(){
    //Function Prototypes
    void process(char [][COL], int);
    
    //Declare Variables
    const int ROW=3;
    char rcs[ROW][COL];
 
    //Process & Output the Data
    process(rcs,ROW);
    
    //Return from Problem 3
    return;
}

void process(char rcs [][COL],int r){
    //Function Prototype
    void readin(string [],char [][COL], int);
    
    //Declare Variables
    int rain=0,cloud=0,sun=0;      //Overall rain, cloud, or sun over period
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
    cout<<"August:  "<<augustr<<"\t  "<<augustc<<"\t  "<<augusts<<endl<<endl;
    cout<<"Total number of rainy days over three months:   "<<rain<<"\n";
    cout<<"Total number of cloudy days over three months:  "<<cloud<<"\n";
    cout<<"Total number of sunny days over three months:   "<<sun<<"\n";
    
    //Return to Problem 3
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

//000000111111122222223333333344444444455555555556666666667777777788888899999990
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                                  Problem 4
//000000111111122222223333333344444444455555555556666666667777777788888899999990
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//
//Purpose - Lottery Simulation and Parallel Array Implementation
void prob4(){
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
    
    //Return from Problem 4
    return;
}

void guess(int user[],int size){
   //Accept User Input
    for(int i=0;i<size;i++){
        cin>>user[i];
    }
    
    //Return to Problem 4
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
       
    //Return to Problem 4
    return;
}

//000000111111122222223333333344444444455555555556666666667777777788888899999990
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                                  Problem 5
//000000111111122222223333333344444444455555555556666666667777777788888899999990
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//
//Purpose - Conduct a Binary Search and Selection Sort
void prob5(){
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
                        "Looney, Joe","Wolfe, Bill","James, Jean","Weaver, Jim",
                        "Pore, Bob","Rutherford, Greg","Javens, Renee",
                        "Harrison, Rose","Setzer, Cathy","Pike, Gordon",
                        "Holland, Beth"};
    
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
    
    //Return from Problem 5
    return;
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
   
   //Return Position to Problem 5
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
    
    //Return to Problem 5
    return;
}

//000000111111122222223333333344444444455555555556666666667777777788888899999990
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                                  MENU
//000000111111122222223333333344444444455555555556666666667777777788888899999990
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//
//Purpose - Displays Menu
void menu(){
    cout<<"Menu Program for Assignment 1"<<endl;
    cout<<"Simply choose the number for the problem to display"<<endl;
    cout<<"1. Average Rainfall"<<endl;
    cout<<"2. Temperature Conversion"<<endl;
    cout<<"3. Rain or Shine"<<endl;
    cout<<"4. Lottery Simulation"<<endl;
    cout<<"5. Binary String Search"<<endl;
    
    //Exit Menu Choice
    return;
}