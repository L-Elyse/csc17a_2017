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

//Global Constants

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
        display(movie1);
        cout<<endl;
        display(movie2);
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
        disply1(movie1);
        cout<<endl;
        disply1(movie2);
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
        cout<<"This program stores data about a company's divisions"<<endl;
        first(dvsion1);
        second(dvsion2);
        third(dvsion3);
        fourth(dvsion4);
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
        cout<<"This program computes weather statistics for the year. \n";
        for(int i=0;i<SIZE;i++){
            cout<<"Please enter the following for Month: "<<i+1<<endl;
            cout<<"Total Rainfall: ";
            cin>>array[i].rain;
            cout<<"High Temperature: ";
            cin>>array[i].high;
            while((array[i].high)<-100||(array[i].high)>140){
                cout<<"Sorry. Only values between -100 and 140 degrees Fahrenheit ";
                cout<<"are allowed."<<endl;
                cin>>array[i].high;
            }
            cout<<"Low Temperature: ";
            cin>>array[i].low;
            while((array[i].low)<-100||(array[i].low)>140){
                cout<<"Sorry. Only values between -100 and 140 degrees Fahrenheit ";
                cout<<"are allowed."<<endl;
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
        cout<<"Here are the results: "<<endl;
        highest(array,SIZE);
        lowest(array,SIZE);
        cout<<fixed<<setprecision(1)<<showpoint;
        cout<<"Average Temperature: "<<avgtemp<<endl;
        cout<<"Total Rainfall: "<<totalr<<endl;
        cout<<"Average Rainfall: "<<avrgr<<endl;
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
        void arrSrtD(int *, int);
        //Declare variables, no doubles
        int donate;
        int *array,*ptr;

        //Ask for Size & Fill the Array
        cout<<"This program takes in as many donations as the user wants, ";
        cout<<"sorts them, and displays them in descending order."<<endl;
        cout<<"How many donations would you like to input?"<<endl;
        cin>>donate; 
        array=fllAry4(donate);

        //Pointer array
        ptr=loopPtr(donate);

        //Process data
        for(int count=0;count<donate;count++)
            ptr[count]=array[count];

        //Sort the Data
        arrSrtD(ptr,donate);

        //Output the Data
        cout<<"The donations,sorted in descending order are: \n";
        showPtr(ptr,donate);

        cout<<"The donations, sorted in their original order are: \n";
        showAry(array,donate);

        //Delete Array
        delete []array;
        delete []ptr;
    }
        void arrSrtD(int *a,int n){
            int start, minIndx;
            int minElem;

            for(start=0;start<n-1;start++){
                minIndx=start;
                minElem=a[start];
                for(int i=start+1;i<n;i++){
                    if(a[i]>minElem){
                        minElem=a[i];
                        minIndx=i;
                    }
                }
                a[minIndx]=a[start];
                a[start]=minElem;
            }
        }
    void problem6()
    {
        //Function Prototypes
        int *fllAry1(int);
        int *copyAry(int *,int);
        //Declare variables, no doubles
        const int SIZE=50;
        int *array=fllAry1(SIZE);
        int *newAry;

        //Copy and Reverse Array
        cout<<"This program displays an array, then displays the same array ";
        cout<<"in reversed order"<<endl;
        prntAry(array,SIZE,10);
        newAry=copyAry(array,SIZE);

        //Process data
        prntAry(newAry,SIZE,10);

        //Delete Array
        delete []newAry;
    }
        int *copyAry(int *a,int n){
            int *b=new int[n];
            for(int j=0;j<n;j++)
                b[j]=a[(n-1)-j];
            delete []a;
            return b;
        }
        int *fllAry1(int n){
            int *a=new int[n];
            for(int i=0;i<n;i++)
                a[i]=i;

            return a;
        }
    void problem7()
    {
	//Function Prototypes
        int *fllAry2(int);
        int *cpyAry1(int *,int);
        void *prtAry1(int *,int,int);
        //Declare variables, no doubles
        const int SIZE=100;
        int *array=fllAry2(SIZE);
        int *newAry;
        //Copy & Expand Array
        cout<<"Array Expanded: \n";
        newAry=cpyAry1(array,SIZE);

        //Delete Array
        delete []newAry;
    }
        int *cpyAry1(int *a,int n){
            //Function Prototype
            void *prtAry1(int*,int,int);
            //Variables
            int size=n*2;
            int *b=new int[size];
            for(int i=0;i<size;i++)
                i>(n-1)?(b[i]=0):(b[i]=a[i]);

            //Print the Array
            prtAry1(b,size,10);

            delete []a;
            return b;
        }
        void *prtAry1(int *a,int n,int perLine){
            for(int i=0;i<n;i++){
                cout<<setw(4)<<a[i];
                if((i%perLine)==(perLine-1))
                    cout<<endl;
            }
            cout<<endl;
        }
        int *fllAry2(int n){
            int *a=new int[n];
            for(int i=0;i<n;i++){
                a[i]=i*5;
            }
            //Print the Array
            cout<<"This program displays an array, then expands it by ";
            cout<<"increase the size by a factor of 2.\n";
            cout<<"However, it initializes all the unused elements to 0"<<endl;
            prtAry1(a,n,10);

            return a;
        }
    void problem8()
    {
        //Function Prototypes
        int randDgt();
        int *fllAry3(int);
        void *sortAry(int *,int);
        void mean(int *,int);
        void median(int *,int);
        void mode(int *,int);
        //Set the Random Number Seed
        srand(static_cast<unsigned int>(time(0)));

        //Declare Array & Randomized Size
        const int SIZE=randDgt();
        cout<<"Here is an array of size "<<SIZE<<":"<<endl;
        int *array=fllAry3(SIZE);

        //Display Randomized Array
        prtAry1(array,SIZE,10);
        sortAry(array,SIZE);

        //Sort & Display Array
        cout<<"Sorted Array: \n";
        prtAry1(array,SIZE,10);

        //Calculate Mean, Median, Mode
        mean(array,SIZE);
        median(array,SIZE);
        mode(array,SIZE);

        //Delete Pointer
        delete []array;
    }
        void mode(int *a,int n){
            int count=1,nmodes=0;
            int *b=new int [n];

            for(int i=0;i<n;i++) 
                *(b+i)=1;

            for(int i=0;i<n-1;i++){
                for(int j=i+1;j<n;j++){
                    if (*(a+i)==*(a+j)){
                        b[i]++;
                    }
                if(b[i]>count)
                    count=*(b+i);
                }
            }

            //Modes
            if(count>1){
                cout<<"The mode set is { ";
                for(int j=0;j<n;j++)
                    if(*(b+j)==count){
                        cout<<*(a+j)<<" ";
                        nmodes++;
                    }
                cout<<"}"<<endl;
                cout<<"The frequency of each is: "<<count<<endl;
                cout<<"The number of modes is: "<<nmodes<<endl;
            }
            else
                cout<<"No Mode!!"<<endl;
            cout<<endl;
            //Delete Array
            delete []b;
        }
        void median(int *a,int n){
            float median;
            if(n%2==1)
                median=(a[n/2])/1.0;
            else if(n%2==0)
                median=(a[n/2]+a[n/2-1])/2.0;
            cout<<fixed<<setprecision(1)<<showpoint;
            cout<<"The median is: "<<median<<endl;
        }
        void mean(int *a,int n){
            int total=0;
            float average;
            for(int i=0;i<n;i++){
                total+=a[i];
            }
            average=total/(n*1.0);
            cout<<fixed<<setprecision(1)<<showpoint;
            cout<<"The average is: "<<average<<endl;
        }
        void *sortAry(int *a,int n){
            //Declare More Variables
            int start, minindx, minval;

            //Sort Values in Array
            for(start=0;start<n-1;start++){
                minindx=start;
                minval=a[start];
                for(int i=start+1;i<n;i++){
                    if(a[i]<minval){
                        minval=a[i];
                        minindx=i;
                    }
                }
                a[minindx]=a[start];
                a[start]=minval;
            }
        }
        int *fllAry3(int n){
            //Function Prototypes
            int randDgt();
            int *a=new int[n];
            for(int i;i<n;i++)
                a[i]=randDgt();
            return a;
        }
        int randDgt(){
            const int MIN=1, MAX=100;
            return (rand()%(MAX-MIN+1)+MIN);
        }
    void def(int inN)
    {
           cout<<"You typed "<<inN<<" to exit the program. Bye."<<endl;
    }