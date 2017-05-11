/* 
 * File:   TestScores.h
 * Author: Laurie Guimont
 * Created on May 10, 2017, 2:20 PM
 * Purpose: TestScores Class Specifications
 */

#ifndef TESTSCORES_H
#define TESTSCORES_H

class TestScores{
    private:
        float test1;
        float test2;
        float test3;
    public:
        TestScores(){
            test1=0;
            test2=0;
            test3=0;
        }
        void setTest(float t1,float t2,float t3){
            test1=t1;
            test2=t2;
            test3=t3;
        }
        float getTst1()const{
            return test1;
        }
        float getTst2()const{
            return test2;
        }
        float getTst3()const{
            return test3;
        }
        float average(){
            float temp;
            temp=(test1+test2+test3)/3;
            return temp;
        }
};



#endif /* TESTSCORES_H */

