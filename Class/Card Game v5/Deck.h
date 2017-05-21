/* 
 * File:   Deck.h
 * Author: Laurie Guimont
 * Created on May 20, 2017, 6:26 PM
 * Purpose: Deck Class Specifications
 */

#ifndef DECK_H
#define DECK_H

template <class T>
class Deck{
    private:
        int *index;
        T **card;
        int dealt;
        int nCrds;
        float pctShuf;
        int nShufle;
        public:
            Deck();
            ~Deck();
            T **deal(int);
            void shuffle();
            void cleanup(T **,int);
};

template <class T>
Deck<T>::Deck(){
    nCrds=52;
    pctShuf=0.8;
    nShufle=7;
    index=new int[nCrds];
    card=new T*[nCrds];
    for(int i=0;i<nCrds;i++){
        index[i]=i;
        card[i]=new T(i);
    }
    dealt=0;
}

template <class T>
Deck<T>::~Deck(){
    delete []index;
    for(int i=0;i<nCrds;i++){
        delete card[i];
    }
    delete []card;
}

template <class T>
T **Deck<T>::deal(int toDeal){
    if(dealt>pctShuf*nCrds) shuffle();
    T **hand=new T*[toDeal];
    for(int i=1;i<=toDeal;i++){
        hand[i-1]=new T(index[dealt++]);
    }
    return hand;
}

template <class T>
void Deck<T>::shuffle(){
    //Shuffle
    for(int shuffle=1;shuffle<=nShufle;shuffle++){
        for(int eachCrd=0;eachCrd<nCrds;eachCrd++){
            int rnd=rand()%nCrds;
            int temp=index[eachCrd];
            index[eachCrd]=index[rnd];
            index[rnd]=temp;
        }
    }
}

template <class T>
void Deck<T>::cleanup(T **hand,int nCrds){
    for(int i=0;i<nCrds;i++){
        delete hand[i];
    }
    delete []hand;
}

#endif /* DECK_H */