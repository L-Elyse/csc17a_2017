/* 
 * File:   Chance.h
 * Author: Laurie Guimont
 * Created on May 27, 2017, 5:04 PM
 * Purpose: ChncCom Class Implementation
 */

#include "ChncCom.h"
#include "Player.h"
#include "Property.h"
#include "Rules.h"
#include "Railroad.h"
#include "Die.h"

#include <iostream>
#include <string>
using namespace std; 

ChncCom::ChncCom(){
    message="";
}

void ChncCom::setMess(unsigned short pick,short index,Player &player,
        Player &opp,Rules &rule){
    Railroad RR;
    Property spot;
    Die die1,die2;
    if(pick==1){
        switch(index){
            case 1:{
                message="Advance token to the nearest Railroad and pay owner "
                        "TWICE the rental to which he/she is otherwise "
                        "entitled. \nIf Railroad is UNOWNED, you may buy it "
                        "from the Bank.";
                if(player.getSpot()==CHANCE1)
                    player.setNew(PENNRR);
                else if(player.getSpot()==CHANCE2)
                    player.setNew(BNORR);
                else if(player.getSpot()==CHANCE3){
                    player.setNew(READRR);
                    player.money+=200;
                    cout<<player.getName()<<" just passed GO, and collected ";
                    cout<<"$200."<<endl;
                }
                if(opp.findPrp(player.getSpot())==true){
                    player.money-=(RR.setrent(opp,player.spot)*2);
                    cout<<"Charged: "<<RR.setrent(opp,player.spot);
                    opp.money+=(RR.setrent(opp,player.spot)*2);
                }
                else if(opp.findPrp(player.getSpot())!=true&&
                        player.findPrp(player.getSpot())!=true){
                    player.setPrps();
                    player.money-=200;
                }
                break;            
            }
            case 2:{
                message="Go directly TO JAIL. Do not pass Go, do not collect "
                        "$200.";
                player.setNew(GO2JAIL);
                break;
            }
            case 3:{
                message="Take a ride on the Reading. If you pass Go, collect "
                        "$200.";
                player.setNew(READRR);
                player.money+=200;
                cout<<player.getName()<<" just passed GO, and collected ";
                cout<<"$200."<<endl;
                if(opp.findPrp(player.getSpot())==true){
                    player.payRent(RR.setrent(opp,player.spot));
                    cout<<endl;
                    cout<<"Your opponent already owns this railroad. You owe ";
                    cout<<"them $"<<RR.setrent(opp,player.spot)<<" of rent.\n";
                    opp.setMony(opp.getMony()+RR.setrent(opp,player.spot));
                }
                else if(player.findPrp(player.getSpot())==true)
                    cout<<"You already own "<<spot.getname()<<endl;
                else{
                    player.money-=200;
                    player.setPrps();
                }
                break;
            }
            case 4:{
                message="Advance to Illinois Ave.";
                if(player.getSpot()==CHANCE3){
                    player.money+=200;
                    cout<<player.getName()<<" just passed GO, and collected ";
                    cout<<"$200."<<endl;
                }
                player.setNew(ILLNOIS);
                if(opp.findPrp(player.getSpot())==true){
                    spot.inform(player.getSpot(),opp.nHouses);
                    player.payRent(spot.getrent());
                    cout<<endl;
                    cout<<"Your opponent already owns "<<spot.getname()<<". You owe ";
                    cout<<"them $"<<spot.getrent()<<" of rent."<<endl;
                    player.setMony(player.getMony()+spot.getrent());
                }
                else if(player.findPrp(player.getSpot())==true)
                    cout<<"You already own "<<spot.getname()<<endl;
                else{
                    player.money-=240;
                    player.setPrps();
                }
                break;
            }
            case 5:{
                message="Bank pays you dividend of $50.";
                player.money+=50;
                break;
            }
            case 6:{
                message="Advance token to the nearest Railroad and pay owner "
                        "TWICE the rental to which he/she is otherwise "
                        "entitled. \nIf Railroad is UNOWNED, you may buy it "
                        "from the Bank.";
                if(player.getSpot()==CHANCE1)
                    player.setNew(PENNRR);
                else if(player.getSpot()==CHANCE2)
                    player.setNew(BNORR);
                else if(player.getSpot()==CHANCE3){
                    player.setNew(READRR);
                    player.money+=200;
                    cout<<player.getName()<<" just passed GO, and collected ";
                    cout<<"$200."<<endl;
                }
                if(opp.findPrp(player.getSpot())==true){
                    player.money-=(RR.setrent(opp,player.spot)*2);
                    cout<<"Charged: "<<RR.setrent(opp,player.spot);
                    opp.money+=(RR.setrent(opp,player.spot)*2);
                }
                else if(opp.findPrp(player.getSpot())!=true&&
                        player.findPrp(player.getSpot())!=true){
                    player.setPrps();
                    player.money-=200;
                }
                break;
            }
            case 7:{
                message="Take a walk on the Boardwalk. Advance token to "
                        "Boardwalk.";
                player.setNew(BRDWALK);
                if(opp.findPrp(player.getSpot())==true){
                    spot.inform(player.getSpot(),opp.nHouses);
                    player.payRent(spot.getrent());
                    cout<<endl;
                    cout<<"Your opponent already owns "<<spot.getname()<<". You owe ";
                    cout<<"them $"<<spot.getrent()<<" of rent."<<endl;
                    player.setMony(player.getMony()+spot.getrent());
                }
                else if(player.findPrp(player.getSpot())==true)
                    cout<<"You already own "<<spot.getname()<<endl;
                else{
                    player.money-=400;
                    player.setPrps();
                }
                break;
            }
            case 8:{
                message="Get out of Jail Free!! This card may be kept until "
                        "needed, or sold.";
                player.outJail++;
                break;
            }
            case 9:{
                message="You have been elected Chairman of the Board. Pay each "
                        "player $50.";
                player.money-=50;
                opp.money+=50;
                break;
            }
            case 10:{
                message="Advance to St. Charles Place. If you pass Go, collect "
                        "$200.";
                if(player.getSpot()==CHANCE2||player.getSpot()==CHANCE3){
                    player.money+=200;
                    cout<<player.getName()<<" just passed GO, and collected ";
                    cout<<"$200."<<endl;
                }
                player.setNew(STCHRLS);
                if(opp.findPrp(player.getSpot())==true){
                    spot.inform(player.getSpot(),opp.nHouses);
                    player.payRent(spot.getrent());
                    cout<<endl;
                    cout<<"Your opponent already owns "<<spot.getname()<<". You owe ";
                    cout<<"them $"<<spot.getrent()<<" of rent."<<endl;
                    player.setMony(player.getMony()+spot.getrent());
                }
                else if(player.findPrp(player.getSpot())==true)
                    cout<<"You already own "<<spot.getname()<<endl;
                else{
                    player.money-=140;
                    player.setPrps();
                }
                break;
            }
            case 11:{
                message="Make general repairs on all your property. For each "
                        "House, pay $25. For each Hotel, pay $100.";
                if(player.nHouses>=1){
                    player.money-=(player.nHouses*25);
                }
                if(player.nHotels>=1&&player.nHouses>=1){
                    player.money-=(player.nHotels*100);
                }
                else if(player.nHotels>=1){
                    player.money-=(player.nHotels*100);
                }
                break;
            }
            case 12:{
                message="Your building and loan matures. Collect $150.";
                player.money+=150;
                break;
            }
            case 13:{
                message="Pay Poor Tax of $15.";
                player.money-=15;
                break;
            }
            case 14:{
                message="Advance to Go. Collect $200.";
                player.setNew(GO);
                player.money+=200;
                cout<<player.getName()<<" just passed GO, and collected ";
                cout<<"$200."<<endl;
                break;
            }
            case 15:{
                message="Go back 3 spaces.";
                player.setNew(player.getSpot()-3);
                if(opp.findPrp(player.getSpot())==true){
                    spot.inform(player.getSpot(),opp.nHouses);
                    player.payRent(spot.getrent());
                    cout<<endl;
                    cout<<"Your opponent already owns "<<spot.getname();
                    cout<<". You owe them $"<<spot.getrent()<<" of rent."<<endl;
                    player.setMony(player.getMony()+spot.getrent());
                }
                else if(player.findPrp(player.getSpot())==true)
                    cout<<"You already own "<<spot.getname()<<endl;
                else{
                    player.money-=spot.getprce();
                    player.setPrps();
                }
                break;
            }
            case 16:{
                message="Advance token to nearest Utility. If UNOWNED you may "
                        "buy it from the Bank. If OWNED, throw dice and pay "
                        "owner a total ten times the amount thrown.";
                //Roll the dice
                die1.roll();
                die2.roll();
                int total=die1.getVal()+die2.getVal();
                
                //Advance Procedure
                if(player.getSpot()==CHANCE1||player.getSpot()==CHANCE3){
                    player.setNew(ELECTRC);
                    if(player.getSpot()==CHANCE3){
                        player.money+=200;
                        cout<<player.getName()<<" just passed GO, and ";
                        cout<<"collected $200."<<endl;
                    }
                }
                else
                    player.setNew(WATERWK);
                
                //Owned or Not
                if(opp.findPrp(player.getSpot())==true){
                    int number=2;
                    spot.utilRnt(number,total);
                    player.payRent(spot.getrent());
                    cout<<"Rolled: "<<total<<endl;
                    cout<<"Charged: $"<<spot.getrent();
                    opp.money+=spot.getrent();
                }
                else if(opp.findPrp(player.getSpot())!=true&&
                    player.findPrp(player.getSpot())!=true){
                    player.setPrps();
                    player.money-=150;
                }
                else
                   cout<<"You already own "<<spot.getname()<<endl; 
                break;
            }
        }
    }
    else if(pick==2){
        switch(index){
            case 1:{
                message="Pay Hospital $100.";
                player.money-=100;
                break;            
            }
            case 2:{
                message="Christmas Fund matures. Collect $100.";
                player.money+=100;
                break;
            }
            case 3:{
                message="Advance to Go. Collect $200.";
                player.setNew(GO);
                player.money+=200;
                cout<<player.getName()<<" just passed GO, and collected ";
                cout<<"$200."<<endl;
                break;
            }
            case 4:{
                message="Get out of Jail free!!! This card may be kept until "
                        "needed, or sold.";
                player.outJail++;
                break;
            }
            case 5:{
                message="Go TO JAIL. Go directly to Jail. Do not pass Go, do "
                        "not collect $200.";
                player.setNew(GO2JAIL);
                break;
            }
            case 6:{
                message="Bank error in your favor. Collect $200.";
                player.money+=200;
                break;
            }
            case 7:{
                message="You are assessed for street repairs. $40 per House, "
                        "$115 per Hotel.";
                if(player.nHouses>=1){
                    player.money-=(player.nHouses*40);
                }
                if(player.nHotels>=1&&player.nHouses>=1){
                    player.money-=(player.nHotels*115);
                }
                else if(player.nHotels>=1){
                    player.money-=(player.nHotels*115);
                }
                break;
            }
            case 8:{
                message="You have won second prize in a beauty contest. "
                        "Collect $10.";
                player.money+=10;
                break;
            }
            case 9:{
                message="Income Tax refund. Collect $20.";
                player.money+=20;
                break;
            }
            case 10:{
                message="Grand Opera Opening. Collect $50 from every player "
                        "for opening night seats.";
                player.money+=50;
                opp.money-=50;
                break;
            }
            case 11:{
                message="From sale of stock you get $45.";
                player.money+=45;
                break;
            }
            case 12:{
                message="Pay school tax of $150.";
                player.money-=150;
                break;
            }
            case 13:{
                message="You inherit $100.";
                player.money+=100;
                break;
            }
            case 14:{
                message="Receive for services $25.";
                player.money+=25;
                break;
            }
            case 15:{
                message="Life insurance matures. Collect $100.";
                player.money+=100;
                break;
            }
            case 16:{
                message="Doctor's fee. Pay $50.";
                player.money-=50;
                break;
            }
        }
    }
}

string ChncCom::getMess() const{
    return message;
}