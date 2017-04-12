/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on April 12, 2017, 12:00 PM
 * Purpose: War Card Game
 */

//System Libraries
#include <iostream> //Input/Output Stream Library
#include <iomanip>  //Formatting Library
#include <ctime>    //Unique Seed Value Library
#include <cstdlib>  //Random Value Library
#include <string>   //String Library
#include <fstream>  //File I/O
#include <cmath>    //Math Library
#include <cctype>
#include <cstring>  
using namespace std;

//User Libraries
#include "Player.h"

//Global Constants--ONLY for 2D Array

//Function Prototypes
string intro();
unsigned short facdDwn(unsigned short &);
const int getSize();
unsigned int menu(unsigned int &);
char pckCard(unsigned int);
int cardVal(unsigned int);
int getRand();
void eval(player,player,int &,int &,int &,int);
int score(const int);
int win(int &);
int loss(int &);
int war(int &,int,player,player,int &,int &);
int warArry(int *,int);
int sumArry(int *,int);
int warCard();
void destroy(int *,int *);

//Execution Begins Here!
int main(int argc, char** argv){
    //Set the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    unsigned short warcnt;
    unsigned int choice;    //The menu option that user chooses
    player comp={0,0};
    player user={0,0};
    int wins=0,losses=0,wars=0;
        
    //DON'T FORGET TO ENTER USER NAME AND DISPLAY MESSAGE IN INTRO
    //Get Name of Opponent & Establish Number of "Faced Down" Cards
    comp.name=intro();
//    const int SIZE=getSize();
//    int score[SIZE];
    facdDwn(warcnt);
    
    do{
        menu(choice);
        if(choice!=3){
            user.card=cardVal(choice);
            comp.card=getRand();
            eval(user,comp,wins,losses,wars,warcnt);
        }    
    }while(choice!=3);
    
    //Exit Stage Right
    return 0;
}

//int score(const int size,player u){
//    int *array=new int[size];
//    int count=0;
//    array[count]=u.score;
//    count++;
//}

int warCard(){
    int number;
    cout<<"Now enter your war card"<<endl;
    cin>>number;
    
    //Input Validation    
    while(!(number)||number<2||number>14){ 
        cin.clear();
        cin.ignore();          
        cout<<"Invalid input. Please type in an integer";
        cout<<" between 2 and 14."<<endl;
        cin>>number;
    }
    return number;    
}

int sumArry(int *a,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=*(a+i);
    }
    return sum;
}

int cwrArry(int *b,int n){
    for(int i=0;i<n;i++){
        *(b+i)=getRand();
    }
    int cnumber=sumArry(b,n);
    return cnumber;
}

int warArry(int *a,int n){
    cout<<"War!!!"<<endl;
    cout<<"Please enter the integer value of the card you ";
    cout<<"would like to draw."<<endl;
    cout<<"Number cards are simply their own value, while T = 10,"
            " J = 11, Q = 12, K = 13, A = 14"<<endl;
    
    for(int i=0;i<n;i++){
        cout<<"Enter card "<<i+1<<": ";
        cin>>*(a+i);
        
        //Validate
        while(!(*(a+i))||*(a+i)<2||*(a+i)>14){
            cin.clear();
            cin.ignore();
            cout<<"Invalid input. Please type in an integer between 2 and 14.";
            cin>>*(a+i);
        }
    }
    int total=sumArry(a,n);
    return total;
}

int war(int &wars,int count,player u,player c,int &won,int &lost){
    wars++;
    int warnum,cwarnum;
    //Declare War Array
    const int SIZE=count;
    int urray[SIZE];
    int crray[SIZE];
    
    u.wscore=warArry(urray,SIZE);
    warnum=warCard();
    c.wscore=cwrArry(crray,SIZE);
    cwarnum=getRand();
    
    if(warnum>cwarnum){
        win(won);
        u.score=u.card+c.card+u.wscore+c.wscore+warnum+cwarnum;
        c.score=c.score-c.card-c.wscore-cwarnum;
    }
    else if(warnum<cwarnum){
        loss(lost);
        u.score=u.score-u.card-u.wscore-warnum;
        c.score=c.card+u.card+c.wscore+u.wscore+cwarnum+warnum;
    }
    else{
        while(warnum==cwarnum){
            wars++;
            int warnum,cwarnum;
            //Declare War Array
            const int SIZE=count;
            int urray[SIZE];
            int crray[SIZE];

            u.wscore=warArry(urray,SIZE);
            warnum=warCard();
            c.wscore=cwrArry(crray,SIZE);
            cwarnum=getRand();

            if(warnum>cwarnum){
                win(won);
                u.score=u.card+c.card+u.wscore+c.wscore+warnum+cwarnum;
                c.score=c.score-c.card-c.wscore-cwarnum;
            }
            else if(warnum<cwarnum){
                loss(lost);
                u.score=u.score-u.card-u.wscore-warnum;
                c.score=c.card+u.card+c.wscore+u.wscore+cwarnum+warnum;
            }
        }
    }
}

int loss(int &loss){
    loss++;
    cout<<"Sorry. You lost."<<endl;
    return loss;
}

//Input User Name?
int win(int &win){
    win++;
    cout<<"You won!!"<<endl;
    return win;
}

void eval(player u,player c,int &won,int &lost,int &wars,int wcount){
    if(u.card>c.card){
        win(won);
        u.score=u.card+c.card;
        c.score-=c.card;
        cout<<c.name<<"'s card: "<<c.card<<endl;
    }
    else if(u.card<c.card){
        loss(lost);
        u.score-=u.card;
        c.score=c.card+u.card;
        cout<<c.name<<"'s card: "<<c.card<<endl;
    }
    else{
       war(wars,wcount,u,c,won,lost); 
    }
}

int getRand(){
    //Declare Variables
    const int MIN=2;
    const int MAX=14;
    int oppCard;
    
    return oppCard=rand()%(MAX-MIN+1)+MIN;
}

int cardVal(unsigned int option){
    //Get Card Choice
    char cchoice=pckCard(option);
    int number;
    
    //Evaluate Card Choice
    switch(cchoice){
        case 'a':
        case 'A':number=14;break;
        case 'k':
        case 'K':number=13;break;
        case 'q':
        case 'Q':number=12;break;
        case 'j':
        case 'J':number=11;break;
        case 't':
        case 'T':number=10;break;
        case '9':
        case '8':
        case '7':
        case '6':
        case '5':
        case '4':
        case '3':
        case '2':number=(cchoice-48);break;
    }
    return number;
}

char pckCard(unsigned int option){
    //Declare Variable
    char card;
    
    if(option==1){
        cout<<"Please enter the number of your choice(2-9)"<<endl;
        cin>>card;
        //Validate
        while(card<'2'||card>'9'){
            cout<<"Invalid entry! Please enter (2-9)"<<endl;
            cin>>card;
        }
    }    
    else if(option==2){
        cout<<"Please enter T, J, Q, K, or A"<<endl;
        cin>>card;
        //Validate
        while(toupper(card)!='A'&&toupper(card)!='K'&&toupper(card)!='Q'&&
                toupper(card)!='J'&&toupper(card)!='T'){
            cout<<"Invalid entry! Please enter one of the choices above"<<endl;
            cin>>card;
        }
    }
    return card;
}

unsigned int menu(unsigned int &option){    
    cout<<endl;
    cout<<"What type of card would you like to play?"<<endl;
    cout<<"1. Number Card"<<endl;
    cout<<"2. Face Card"<<endl;
    cout<<"3. End Game"<<endl<<endl;
    cin>>option;
    
    return option;
}

//const int getSize(){
//    //Get size of score array
//    const int SIZE;
//    cout<<endl;
//    cout<<"How many hands would you like to play?"<<endl;
//    cin>>SIZE;
//    
//    return SIZE;
//}

unsigned short facdDwn(unsigned short &number){
    cout<<endl;
    cout<<"When war is waged, How many cards do you want to put down before ";
    cout<<"the war card is flipped?"<<endl;
    cout<<"(Please pick a number from 2-4)"<<endl;
    cin>>number;
    
    //Validation
    while(number<2||number>4){
        cout<<"Error. Please enter 2, 3 or 4"<<endl;
        cin>>number;
    }
    return number;
}

string intro(){
    //Declare Variables
    string c;
    cout<<"The name of the game? WAR!"<<endl;
    cout<<"First give your opponent a name. You didn't think you were playing ";
    cout<<"against the computer did you?"<<endl; 
    getline(cin,c);
    return c;
}