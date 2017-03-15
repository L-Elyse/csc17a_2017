//Laurie Guimont
//March 14th, 2017
//Menu for Assignment 2

#include <iostream>
#include <iomanip>   
#include <cstdlib>    
#include <ctime>     
using namespace std;

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
           cout<<"Type 1 for Problem 1: Array Allocator"<<endl;
           cout<<"Type 2 for Problem 2: Average Test Scores"<<endl;
           cout<<"Type 3 for Problem 3: Drop Lowest Test Score"<<endl;
           cout<<"Type 4 for Problem 4: Case Study Modification #1"<<endl;
           cout<<"Type 5 for Problem 5: Case Study Modification #2"<<endl;
           cout<<"Type 6 for Problem 6: Array Reversal"<<endl;
           cout<<"Type 7 for Problem 7: Array Expander"<<endl;
           cout<<"Type 8 for Problem 8: Mean, Median, Mode"<<endl;
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
        int *fillAry(int);
        void *prntAry(int *,int,int);
        //Declare variables, no doubles
        const int SIZE=50;
        int *array=fillAry(SIZE);

        //Print Array
        cout<<"This program writes a function that dynamically allocates ";
        cout<<"an array and returns a pointer to the array."<<endl;
        prntAry(array,SIZE,10);

        //Delete Pointer
        delete []array;
    }
        void *prntAry(int *a,int n,int perLine){
            for(int i=0;i<n;i++){
                cout<<(a[i]<10?"  ":" ")<<a[i];
                if(i%perLine==(perLine-1))
                    cout<<endl;
            }
            cout<<endl;
    }
        int *fillAry(int n){
            //Declare New Array
            int *a=new int[n];
            for(int i=0;i<n;i++)
                a[i]=i*2;
            return a;
        }
    void problem2()
    {
        //Function Prototypes
        int *gettest(int);
        int *sort(int *,int);
        void average(int *,int);
        //Declare variables, no doubles
        int scores;
        int *tests;

        //Get Size from User
        cout<<"This program calculates Test Averages"<<endl;
        cout<<"How many test scores would you like to enter? ";
        cin>>scores;
        tests=gettest(scores);

        //Sort & Display Test Scores
        sort(tests,scores);
        cout<<"The "<<scores<<" tests that you would like to average are: { ";
        for(int i=0;i<scores;i++)
            cout<<tests[i]<<" ";
        cout<<"}"<<endl;

        //Calculate & Display Average
        average(tests,scores);
        delete []tests;
    }
        void average(int *a,int n){
            float sum=0, mean;
            for(int i=0;i<n;i++){
                sum+=a[i];
            }
            mean=sum/n;
            cout<<fixed<<setprecision(1)<<showpoint;
            cout<<"The average of your values is: "<<mean<<endl<<endl;
        }
        int *sort(int *a,int n){
            int start,minIndx,minVal;
            for(start=0;start<(n-1);start++){
                minIndx=start;
                minVal=a[start];
                for(int i=start+1;i<n;i++){
                    if(a[i]<minVal){
                        minVal=a[i];
                        minIndx=i;
                    }
                }
                a[minIndx]=a[start];
                a[start]=minVal;
            }
            return a;
        }
        int *gettest(int size){
            //Declare new array with pointer
            int *a=new int[size];
            for(int i=0;i<size;i++){
                cout<<"Test Score #"<<i+1<<" : ";
                cin>>a[i];
                while(a[i]<0){
                    cout<<"Invalid Entry. No negative values please.";
                    cin>>a[i];
                }
            }
            cout<<endl;
            return a;
        }
    void problem3()
    {
        //Function Prototypes
        int *dropLow(int *,int);
        //Declare variables, no doubles
        int scores;
        int *tests;

        //Get Size from User
        cout<<"This program drops the lowest test score, then calculates ";
        cout<<"the average."<<endl;
        cout<<"How many test scores would you like to enter? ";
        cin>>scores;
        tests=gettest(scores);

        //Sort & Display Test Scores
        sort(tests,scores);
        cout<<"The "<<scores<<" tests that you would like to average are: { ";
        for(int i=0;i<scores;i++)
            cout<<tests[i]<<" ";
        cout<<"}"<<endl;            

        //Drop Lowest Test Score
        tests=dropLow(tests,(scores-1));
        cout<<"But wait!! Let's drop the lowest test score!"<<endl;
        cout<<"Now you are only finding the average of : { ";
        for(int i=0;i<(scores-1);i++)
            cout<<tests[i]<<" ";
        cout<<"}"<<endl;

        //Calculate & Display Average
        average(tests,(scores-1));
        delete []tests;
    }
        int *dropLow(int *a,int n){
            int *b=new int[n];
            for(int i=0;i<n;i++){
                b[i]=a[i+1];
            }
            delete []a;
            return b;
        }
    void problem4()
    {
        //Function Prototypes
        int *fllAry4(int);
        int *loopPtr(int);
        void arrSort(int *, int);
        void showAry(int *,int);
        void showPtr(int *,int);
        //Declare variables, no doubles
        int donate;
        int *array,*ptr;

        //Ask for Size & Fill the Array
        cout<<"This program takes in as many donations as the user wants, ";
        cout<<"sorts them, and displays them in ascending order."<<endl;
        cout<<"How many donations would you like to input?"<<endl;
        cin>>donate; 
        array=fllAry4(donate);

        //Pointer array
        ptr=loopPtr(donate);

        //Process data
        for(int count=0;count<donate;count++)
            ptr[count]=array[count];

        //Sort the Data
        arrSort(ptr,donate);

        //Output the Data
        cout<<"The donations,sorted in ascending order are: \n";
        showPtr(ptr,donate);

        cout<<"The donations, sorted in their original order are: \n";
        showAry(array,donate);

        //Delete Arrays
        delete []array;
        delete []ptr;
    }
        void showAry(int *a,int size){
            for(int i=0;i<size;i++)
                cout<<a[i]<<" ";
            cout<<endl;
        }
        void showPtr(int *a,int n){
            for(int i=0;i<n;i++)
                cout<<a[i]<<" ";
            cout<<endl;
        }
        void arrSort(int *a,int n){
            int start, minIndx;
            int minElem;

            for(start=0;start<n-1;start++){
                minIndx=start;
                minElem=a[start];
                for(int i=start+1;i<n;i++){
                    if(a[i]<minElem){
                        minElem=a[i];
                        minIndx=i;
                    }
                }
                a[minIndx]=a[start];
                a[start]=minElem;
            }
        }
        int *loopPtr(int size){
            int *b=new int[size];
            for(int j=0;j<size;j++){
                b[j]=0;
            }
            return b;
        }
        int *fllAry4(int size){
            int *a=new int[size];
            for(int i=0;i<size;i++){
                cout<<"Donation #"<<i+1<<" : ";
                cin>>a[i];
            }
            return a;
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