//Laurie Guimont
//April 5th, 2017
//Menu for Assignment 4

#include <iostream>
#include <iomanip>   
#include <cstring> 
#include <cctype>
#include <fstream>
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
           cout<<"Type 1 for Problem 1: String Length"<<endl;
           cout<<"Type 2 for Problem 2: Backwards String"<<endl;
           cout<<"Type 3 for Problem 3: Word Counter"<<endl;
           cout<<"Type 4 for Problem 4: Average Number of Letters"<<endl;
           cout<<"Type 5 for Problem 5: Sentence Capitalizer"<<endl;
           cout<<"Type 6 for Problem 6: Case Manipulator"<<endl;
           cout<<"Type 7 for Problem 7: Password Verifier"<<endl;
           cout<<"Type 8 for Problem 8: File Head Program"<<endl;
           cout<<"Type 9 for Problem 9: File Display Program"<<endl;
           cout<<"Type 10 for Problem 10: Line Numbers"<<endl;
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
        //Function Prototypes
        int length(char *);
        //Declare variables, no doubles
        int size=100;
        char input[size];
    
        //Get the String from User
        cout<<"Enter a string and I will tell you how long it is"<<endl;
        cin.getline(input,size);

        //Output the String Length
        cout<<endl;
        cout<<"This string is "<<length(input)<<" characters long."<<endl;
        cout<<endl;
    }
        int length(char *str){
            int length=strlen(str);
            return length;
        }
    void problem2()
    {
        //Function Prototypes
        void revrse(char *,int);
        //Declare variables, no doubles
        int size=100;
        char input[size];
        int length;

        //Input data
        cout<<"Enter a string and I will output it in reverse!"<<endl;
        cin.getline(input,size);

        //Determine Length and Output Results
        length=strlen(input);
        revrse(input,length);
        cout<<endl;
    }
        void revrse(char *c,int n){
            cout<<"The reversed string is: "<<endl;
            for(int i=n-1;i>=0;i--){
                cout<<*(c+i);
            }
            cout<<endl;
        }
    void problem3()
    {
        //Function Prototypes
        int counter(char *,int);
        //Declare variables, no doubles
        int size=100;
        char input[size];
        int length;

        //Get the String from User
        cout<<"Enter a string and I will count the words"<<endl;
        cin.getline(input,size);
        length=strlen(input);

        //Output the String Length
        cout<<endl;
        cout<<"This string has "<<counter(input,length)<<" words."<<endl;
        cout<<endl;
    }
        int counter(char *str,int l){
            int count=0;
            for(int i=0;i<l;i++){
                if(*(str+i)==' ')
                    count++;
            }
            return count+1;
        }
    void problem4()
    {
        //Function Prototypes
        float average(char *,int);
        //Declare variables, no doubles
        int size=100;
        char input[size];
        int length;

        //Get the String from User
        cout<<"Enter a string and I'll tell you the average number of letters ";
        cout<<"in each word."<<endl;
        cin.getline(input,size);
        length=strlen(input);

        //Output the String Length
        cout<<endl;
        cout<<"This string has an average of "<<average(input,length);
        cout<<" words.\n";
        cout<<endl;
    }
        float average(char *str,int l){
            //Declare Accumulators & Allocate Dynamic Memory
            int count=0, index=0, size=0;
            float sum=0.0;
            int *a=new int[l];

            //Count Letters in Each Word
            for(int i=0;i<l;i++){
                if(*(str+i)!=' ')
                    count++;
                else if(*(str+i)==' '){
                    *(a+index)=count;
                    index++;
                    size++;
                    count=0;
                }
            }
            *(a+index)=count;

            //Total and Average
            for(int i=0;i<size+1;i++)
                sum+=*(a+i);
            float average=sum/(size+1);

            //Prevent Memory Leak
            delete []a;

            cout<<fixed<<setprecision(2)<<showpoint;
            return average;
        }
    void problem5()
    {
        //Function Prototypes
        void capital(char *,int);
        //Declare variables, no doubles
        int size=200;
        char input[size];
        int length;

        //Input data
        cout<<"Enter a couple sentences with proper punctuation. Do NOT ";
        cout<<" capitalize the first word of each sentence though."<<endl;
        cout<<"I will do that for you."<<endl;
        cin.getline(input,size);

        //Get the Length of the string and output
        length=strlen(input);
        cout<<endl;
        cout<<"Results: ";
        capital(input,length);
        cout<<endl;
    }
        void capital(char *c,int n){
            *(c+0)=toupper(*(c+0));
            for(int i=1;i<n;i++){
                if(*(c+i)==' '&&*(c+i-1)=='.'){
                    *(c+i+1)=toupper(*(c+i+1));
                    i++;
                }
            }
            for(int i=0;i<n;i++)
                cout<<*(c+i);
            cout<<endl;
        }
    void problem6()
    {
        //Function Prototypes
        void upper(char *);
        void lower(char *);
        void reverse(char *);
        //Declare variables, no doubles
        int size=100;
        char input[size];

        //Get the String from User
        cout<<"Enter a string and I will manipulate all the cases."<<endl;
        cin.getline(input,size);

        //Output the String Manipulated
        upper(input);
        lower(input);
        reverse(input);
        cout<<endl;
    }
        void reverse(char *c){
            cout<<endl;
            cout<<"All Original Cases Switched: ";
            for(int i=0;i<strlen(c);i++){
                if(islower(*(c+i)))
                    cout<<static_cast<char>(toupper(*(c+i)));
                else if(isupper(*(c+i)))
                    cout<<static_cast<char>(tolower(*(c+i)));
                else
                    cout<<*(c+i);
            }
            cout<<endl;
        }
        void lower(char *c){
            cout<<endl;
            cout<<"All Lowercase:               ";
            for(int i=0;i<strlen(c);i++){
                cout<<static_cast<char>(tolower(*(c+i)));
            } 
        }
        void upper(char *c){
            cout<<endl;
            cout<<"All Uppercase:               ";
            for(int i=0;i<strlen(c);i++){
                cout<<static_cast<char>(toupper(*(c+i)));
            }
        }
    void problem7()
    {
	//Function Prototypes
        void verify(char *,int);
        //Declare variables, no doubles
        int size=50;
        char passwrd[size];
        int length;

        //Input data
        cout<<"Enter any password of your choice. The password should contain ";
        cout<<"at least: "<<endl;
        cout<<"Six characters"<<endl;
        cout<<"One uppercase"<<endl;
        cout<<"One lowercase"<<endl;
        cout<<"One digit"<<endl;
        cin.getline(passwrd,size);

        //Process data
        length=strlen(passwrd);
        verify(passwrd,length);
        cout<<endl;
    }
        void verify(char *c,int l){
            //Declare Variables
            int upper=0,lower=0,digit=0;
            //Test and Output Results
            cout<<endl;
            cout<<"Results: "<<endl;
            //Check Length
            if(l<6){
                cout<<"I'm sorry. Your password must be at least six ";
                cout<<"characters. Your password only contains "<<l;
                cout<<" characters."<<endl;
            }
            else if(l>=6){
                //Search for Uppercase, Lowercase, and Digit
                for(int i=0;i<l;i++){
                    if(isupper(*(c+i)))
                        upper++;
                    if(islower(*(c+i)))
                        lower++;
                    if(isdigit(*(c+i)))
                        digit++;
                }
                if(upper>0&&lower>0&&digit>0)
                    cout<<"The password is valid"<<endl;
                else{
                    if(upper==0)
                        cout<<"No uppercase."<<endl;
                    if(lower==0)
                        cout<<"No lowercase."<<endl;
                    if(digit==0)
                        cout<<"No digit."<<endl;
                    cout<<"The password is invalid"<<endl;
                }
            }
        }
    void problem8()
    {
        //Declare Array & Randomized Size
        fstream file;
        string name,line;

        //Input data
        cout<<"Enter data.txt to see the first 10 lines of the file."<<endl;
        getline(cin,name);

        //Process data
        file.open(name, ios::in);

        if(file){
            getline(file, line);
            for(int i=0;i<10;i++){
                cout<<line<<endl;
                getline(file, line);
            }
            file.close();
        }
        else
            cout<<"Error. Cannot open file"<<endl;
        cout<<endl;
    }
    void problem9()
    {
        //Declare variables, no doubles
        fstream file;
        string name,line;
        int count=0;
        char pause;

        //Input data
        cout<<"Select data.txt, data2.txt, or data3.txt to see the file ";
        cout<<"contents"<<endl;
        getline(cin,name);

        //Process data
        file.open(name, ios::in);

        if(file){
            getline(file, line);
            while(file){
                count++;
                cout<<line<<endl;
                if(count%24!=0)
                    getline(file, line);
                else{
                    cout<<"Enter any character to see more lines"<<endl;
                    cin>>pause;
                    getline(file, line);
                }
            }
            file.close();
        }
        else
            cout<<"Error. Cannot open file"<<endl;
        cout<<endl;
    }
    void problem10()
    {
        //Declare variables, no doubles
        fstream file;
        string name,line;
        int count=0;
        char pause;

        //Input data
        cout<<"Select data.txt, data2.txt, or data3.txt to see the file ";
        cout<<"contents"<<endl;
        getline(cin,name);

        //Process data
        file.open(name, ios::in);

        if(file){
            getline(file, line);
            while(file){
                count++;
                cout<<count<<":"<<line<<endl;
                if(count%24!=0)
                    getline(file, line);
                else{
                    cout<<"Enter any character to see more lines"<<endl;
                    cin>>pause;
                    getline(file, line);
                }
            }
            file.close();
        }
        else
            cout<<"Error. Cannot open file"<<endl;
        cout<<endl;
    }
    void def(int inN)
    {
           cout<<"You typed "<<inN<<" to exit the program. Bye."<<endl;
    }