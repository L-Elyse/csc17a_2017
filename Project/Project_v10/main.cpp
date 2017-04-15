/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on April 14, 2017, 10:30 PM
 * Purpose: War Card Game
 */

//System Libraries
#include <iostream> //Input/Output Stream Library
#include <iomanip>  //Formatting Library
#include <ctime>    //Unique Seed Value Library
#include <cstdlib>  //Random Value Library
#include <string>   //String Library
#include <fstream>  //File I/O Library
#include <cmath>    //Math Library
#include <cctype>   //Character Test Library
#include <cstring>  //Character String Library
using namespace std; 

//User Libraries
#include "Player.h"

//Global Constants
enum Day {MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY};

//Function Prototypes
string intro();
string oppname();
unsigned short facdDwn(unsigned short &);
const int getSize();
unsigned int menu(unsigned int &);
char pckCard(unsigned int);
int cardVal(unsigned int);
int getRand();
void eval(player,player,int &,int &,int &,int,const int,int &);
int win(int &);
int loss(int &);
void war(int &,int,player,player,int &,int &,int &);
int warArry(int *,int);
int sumArry(int *,int);
int warCard();
void stats(player,player,const int);
void prntAry(player,const int);
void prntBry(player,const int);
void destroy(player,player);
void readldr();
void finstat(player,player,int,int,int,const int);
void DayName(Day);

//Execution Begins Here!
int main(int argc, char** argv){
    //Set the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    unsigned short warcnt;
    unsigned int choice;    //The menu option that user chooses
    player comp;
    player user;
    bool again;
        
    //Get Name of Opponent & Establish Number of "Faced Down" Cards
    user.name=intro();
    comp.name=oppname();
    facdDwn(warcnt);
    
    do{
        int wins=0,losses=0,wars=0;
        int count=0,i=0;
        const int SIZE=getSize();
        user.score=new int[SIZE];
        comp.score=new int [SIZE];
        
        do{
            menu(choice);
            user.card=cardVal(choice);
            comp.card=getRand();
            eval(user,comp,wins,losses,wars,warcnt,SIZE,i);
            count++;
        }while(count<SIZE);
        
        //Finishing Stats
        finstat(user,comp,wins,losses,wars,SIZE);  //Output to File
        stats(user,comp,SIZE);                //Output to Screen
        
        cout<<"Would you like to play more hands?"<<endl;
        cout<<"Press 1 for yes or 0 for no."<<endl;
        cin>>again;
    }while(again==true);
    
    //End Game
    cout<<"Thank you for playing!"<<endl<<endl;
    
    //Show Leaderboard
    readldr();
        
    //Exit Stage Right
    return 0;
}

void finstat(player u,player c,int win,int lose,int war,const int SIZE){
    //Declare Variables
    int ngames;
    float pwins,plosses;
    int utotal=0,ctotal=0;
    string winner;
    fstream finish;
    
    //Open & Write to file
    finish.open("stats.dat",ios::app);
    finish<<"Here are your Game Stats:"<<endl<<endl;
    finish<<"Name: "<<u.name<<endl;
    finish<<"Opponent: "<<c.name<<endl;
    finish<<"Wins:     "<<setw(4)<<win<<endl;
    finish<<"Losses:   "<<setw(4)<<lose<<endl;
    finish<<"Wars:     "<<setw(4)<<war<<endl;
    finish<<endl;
    
    //Calculate Total Scores
    for(int i=0;i<SIZE;i++)
        utotal+=u.score[i];
    finish<<"Your final score: "<<setw(4)<<utotal<<endl;
    for(int i=0;i<SIZE;i++)
        ctotal+=c.score[i];
    finish<<c.name<<"'s final score: "<<setw(4)<<ctotal<<endl;
    finish<<"Point difference:  "<<setw(4)<<abs(utotal-ctotal)<<endl;
    
    //Determine Winner of Game
    if(utotal>ctotal)
        winner=u.name;
    else
        winner=c.name;
    finish<<"Winner:  "<<winner<<endl;
    
    //Calculate Number of Games
    ngames=win+lose;
    finish<<"Total games played: "<<ngames<<endl;
    
    pwins=static_cast<float>(win)/ngames;
    plosses=static_cast<float>(lose)/ngames;
    
    //Output Percentage
    finish<<fixed<<setprecision(1)<<showpoint;
    finish<<"You won "<<pwins*100<<"% of the hands you played"<<endl;
    finish<<"You lost "<<plosses*100<<"% of the hands you played"<<endl;
    finish<<endl<<endl;
    
    //Close file
    finish.close();
}

void DayName(Day d){
    switch(d){
        case MONDAY:   cout<<"Monday    "; break;
        case TUESDAY:  cout<<"Tuesday   "; break;
        case WEDNESDAY:cout<<"Wednesday "; break;
        case THURSDAY: cout<<"Thursday  "; break;
        case FRIDAY:   cout<<"Friday    "; break;
        case SATURDAY: cout<<"Saturday  "; break;
        case SUNDAY:   cout<<"Sunday    "; break;
    }
}

void readldr(){
    //Declare the file
    fstream leader;
    string board;
   
    //Open the file
    leader.open("leaderboard.dat",ios::in);
  
    //Send the array to the file
    cout<<"Leaderboard:"<<endl;
    if(leader){
        getline(leader, board);
        for(Day highest=MONDAY;highest<=SUNDAY;
                highest=static_cast<Day>(highest+1)){
            DayName(highest);
            cout<<":";
            cout<<setw(6)<<board<<endl;
            getline(leader, board);
        }        
 
        //Close the file
        leader.close();
    }
    else
        cout<<"Error. Cannot open file"<<endl;
}

void destroy(player u,player c){
    delete []u.score;
    delete []c.score;
}

void prntBry(player b,const int n){
    for(int i=0;i<n;i++)
        cout<<*(b.score+i)<<" ";
}

void prntAry(player a,const int n){
    for(int i=0;i<n;i++)
        cout<<*(a.score+i)<<" ";
}

void stats(player u,player c,int size){
    cout<<u.name<<"'s score: [ ";
    prntAry(u,size);
    cout<<"]"<<endl;
    cout<<c.name<<"'s score: [ ";
    prntBry(c,size);
    cout<<"]"<<endl;
    
    //Prevent Memory Leak!
    destroy(u,c);
}

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
    int ctotal=sumArry(b,n);
    return ctotal;
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

void war(int &wars,int count,player u,player c,int &won,int &lost,int &i){
    wars++;
    int warnum,cwarnum;
    //Declare War Array
    const int SIZE=count;
    int urray[SIZE],crray[SIZE];
    
    u.wscore=warArry(urray,SIZE);
    warnum=warCard();
    c.wscore=cwrArry(crray,SIZE);
    cwarnum=getRand();    
    if(warnum>cwarnum){
        win(won);
        u.score[i]=u.card+c.card+u.wscore+c.wscore+warnum+cwarnum;
        c.score[i]=0-c.card-c.wscore-cwarnum;
        return;
    }
    else if(warnum<cwarnum){
        loss(lost);
        u.score[i]=0-u.card-u.wscore-warnum;
        c.score[i]=c.card+u.card+c.wscore+u.wscore+cwarnum+warnum;
        return;
    }
    else{
        while(warnum==cwarnum){  //Must War Again!
            wars++;
            int warnum,cwarnum;
            //Declare War Array
            const int SIZE=count;
            int urray[SIZE],crray[SIZE];

            u.wscore=warArry(urray,SIZE);
            warnum=warCard();
            c.wscore=cwrArry(crray,SIZE);
            cwarnum=getRand();
            if(warnum>cwarnum){
                win(won);
                u.score[i]=u.card+c.card+u.wscore+c.wscore+warnum+cwarnum;
                c.score[i]=0-c.card-c.wscore-cwarnum;
                return;
            }
            else if(warnum<cwarnum){
                loss(lost);
                u.score[i]=0-u.card-u.wscore-warnum;
                c.score[i]=c.card+u.card+c.wscore+u.wscore+cwarnum+warnum;
                return;
            }
        }
    }
}

int loss(int &loss){
    loss++;
    cout<<"Sorry. You lost."<<endl;
    return loss;
}

int win(int &win){
    win++;
    cout<<"You won!!"<<endl;
    return win;
}

void eval(player u,player c,int &won,int &lost,int &wars,int wcount,
        const int n,int &i){
    if(u.card>c.card){
        win(won);
        u.score[i]=u.card+c.card;
        c.score[i]=0-c.card;
        cout<<c.name<<"'s card: "<<c.card<<endl;
    }
    else if(u.card<c.card){
        loss(lost);
        u.score[i]=0-u.card;
        c.score[i]=c.card+u.card;
        cout<<c.name<<"'s card: "<<c.card<<endl;
    }
    else{
       war(wars,wcount,u,c,won,lost,i); 
    }
    i++;
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
    cin>>option;
    
    return option;
}

const int getSize(){
    //Get size of score array
    int size;
    cout<<endl;
    cout<<"How many hands would you like to play?"<<endl;
    cin>>size;
    
    return size;
}

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

string oppname(){
    //Declare Variables
    string c;
    cout<<"Now give your opponent a name. You didn't think you were playing ";
    cout<<"against the computer did you?"<<endl; 
    getline(cin,c);
    return c;
}

string intro(){
    //Declare Variables
    string c;
    cout<<"The name of the game? WAR!"<<endl;
    cout<<"The object of the game is to throw down a card that is higher ";
    cout<<"than your opponent's card."<<endl;
    cout<<"Please enter your name."<<endl;
    getline(cin,c);
    return c;
}