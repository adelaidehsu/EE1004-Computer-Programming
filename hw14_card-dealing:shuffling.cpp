//
//  HW14.cpp
//  HW14
//
//  Created by Aliyah on 12/31/16.
//  Copyright © 2016 Aliyah. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


class card
{
public:
    card();
    card(string, string);
    void print();
    string getface ();
    string getsuit();
private:
    string face;
    string suit;
};

card::card()
{
    
}

card::card(string f, string s)
{
    face = f;
    suit = s;
}

string card::getface()
{
    return face;
}

string card::getsuit()
{
    return suit;
}

void card::print()
{
    cout<<face<<" of "<<suit<<",";
}

void checkpairs(card c1, card c2, card c3, card c4, card c5, int &);
void threekindcheck(card c1, card c2, card c3, card c4, card c5, int &);
void fourkindcheck(card c1, card c2, card c3, card c4, card c5, int &);
void flushcheck(card c1, card c2, card c3, card c4, card c5, int &);
void straightcheck(card c1, card c2, card c3, card c4, card c5, int &);


int main()
{
    srand(time(0));
    card p[10] ={};
    card deck[52]={};
    string faces[13]={"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
    string suits[4]={"Spade","Heart","Club","Diamond"};
    for(int i=0; i<52; i++)
    {
        deck[i] = card (faces[rand()%13], suits[i/13]);
    }
    
    for(int i=0; i<10; i++)
    {
        p[i] = deck[rand()%52];
        
    }
    
    card p1[5] = {p[0], p[1], p[2], p[3], p[4]};
    card p2[5] = {p[5], p[6], p[7], p[8], p[9]};
    int handcount1=0;
    int handcount2=0;
    cout<<"Player1 holds:";
    for(int i=0; i<5; i++)
    {
        p1[i].print();
    }
    cout<<endl;
    cout<<"Player2 holds:";
    for(int i=0; i<5; i++)
    {
        p2[i].print();
    }
    cout<<endl;
    
    cout<<"Player1:"<<endl;
    checkpairs(p1[0], p1[1], p1[2], p1[3], p1[4], handcount1);
    threekindcheck(p1[0], p1[1], p1[2], p1[3], p1[4], handcount1);
    fourkindcheck(p1[0], p1[1], p1[2], p1[3], p1[4], handcount1);
    flushcheck(p1[0], p1[1], p1[2], p1[3], p1[4], handcount1);
    straightcheck(p1[0], p1[1], p1[2], p1[3], p1[4], handcount1);
    cout<<endl;
    
    cout<<"Player2:"<<endl;
    checkpairs(p2[0], p2[1], p2[2], p2[3], p2[4], handcount2);
    threekindcheck(p2[0], p2[1], p2[2], p2[3], p2[4], handcount2);
    fourkindcheck(p2[0], p2[1], p2[2], p2[3], p2[4], handcount2);
    flushcheck(p2[0], p2[1], p2[2], p2[3], p2[4], handcount2);
    straightcheck(p2[0], p2[1], p2[2], p2[3], p2[4], handcount2);
    cout<<endl;
    
    cout<<handcount1<<":"<<handcount2<<endl;
    if(handcount1 > handcount2)
        cout<<"Player1 has a better hand."<<endl;
    if(handcount1 < handcount2)
        cout<<"Player 2 has a better hand."<<endl;
    if(handcount1 == handcount2)
        cout<<"two players have equal hands. No one is better."<<endl;
    return 0;
    
}


void checkpairs(card c1, card c2, card c3, card c4, card c5, int &n)
{
    string f1 = c1.getface();
    string f2 = c2.getface();
    string f3 = c3.getface();
    string f4 = c4.getface();
    string f5 = c5.getface();
    string totalf[5] = {f1, f2, f3, f4, f5};
    int paircount =0;
    for(int i=1; i<5; i++)
    {
        if(totalf[i] == f1)
        {
            paircount++;
        }
    }
    for(int i=2; i<5; i++)
    {
        if(totalf[i] == f2)
        {
            paircount++;
        }
        
    }
    for(int i=3; i<5; i++)
    {
        if(totalf[i] == f3)
        {
            paircount++;
        }
        
    }
    for(int i=4; i<5; i++)
    {
        if(totalf[i] == f4)
        {
            paircount++;
        }
        
    }
    
    if(paircount == 1)
    {
        cout<<"the hand contains a pair."<<endl;
        n++;
    }
    
    if(paircount == 2)
    {
        cout<<"the hand contains two pairs."<<endl;
        n++;
    }
    
}

void threekindcheck(card c1, card c2, card c3, card c4, card c5, int &n)
{
    string s1 = c1.getsuit();
    string s2 = c2.getsuit();
    string s3 = c3.getsuit();
    string s4 = c4.getsuit();
    string s5 = c5.getsuit();
    string totals[5] = {s1, s2, s3, s4, s5};
    int s1count=0;
    int s2count=0;
    int s3count=0;
    for(int i=1; i<5;i++)
    {
        if(totals[i] == s1)
        {
            s1count++;
        }
    }
    for(int i=2;i<5;i++)
    {
        if(totals[i]==s2)
        {
            s2count++;
        }
    }
    for(int i=3; i<5; i++)
    {
        if(totals[i] == s3)
        {
            s3count++;
        }
    }
    if(s1count ==2 || s2count ==2 || s3count ==2)
    {
        cout<<"the hand contains three of a kind."<<endl;
        n++;
    }
}
void fourkindcheck(card c1, card c2, card c3, card c4, card c5, int &n)
{
    string s1 = c1.getsuit();
    string s2 = c2.getsuit();
    string s3 = c3.getsuit();
    string s4 = c4.getsuit();
    string s5 = c5.getsuit();
    string totals[5] = {s1, s2, s3, s4, s5};
    int s1count=0;
    int s2count=0;
    for(int i=1; i<5;i++)
    {
        if(totals[i] == s1)
        {
            s1count++;
        }
    }
    for(int i=2;i<5;i++)
    {
        if(totals[i]==s2)
        {
            s2count++;
        }
    }
    if(s1count ==3 || s2count ==3)
    {
        cout<<"the hand contains four of a kind."<<endl;
        n++;
    }
}

void flushcheck(card c1, card c2, card c3, card c4, card c5, int &n)
{
    string s1 = c1.getsuit();
    string s2 = c2.getsuit();
    string s3 = c3.getsuit();
    string s4 = c4.getsuit();
    string s5 = c5.getsuit();
    if(s1==s2 && s2==s3 && s3==s4 && s4==s5)
    {
        cout<<"the hand contains a flush."<<endl;
        n++;
    }
    
}

void swap(string *ptr1, string *ptr2)
{
    string hold = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = hold;
}

void straightcheck(card c1, card c2, card c3, card c4, card c5, int &n)
{
    string f1 = c1.getface();
    string f2 = c2.getface();
    string f3 = c3.getface();
    string f4 = c4.getface();
    string f5 = c5.getface();
    string totalf[5] = {f1, f2, f3, f4, f5};
    int a[13]={};
    for(int i=0; i<5; i++)
    {
        if(totalf[i] == "Ace")
            a[0]++;
        if(totalf[i] == "2")
            a[1]++;
        if(totalf[i] == "3")
            a[2]++;
        if(totalf[i] == "4")
            a[3]++;
        if(totalf[i] == "5")
            a[4]++;
        if(totalf[i] == "6")
            a[5]++;
        if(totalf[i] == "7")
            a[6]++;
        if(totalf[i] == "8")
            a[7]++;
        if(totalf[i] == "9")
            a[8]++;
        if(totalf[i] == "10")
            a[9]++;
        if(totalf[i] == "Jack")
            a[10]++;
        if(totalf[i] == "Queen")
            a[11]++;
        if(totalf[i] == "King")
            a[12]++;
    }
    for(int i=0; i<9; i++)
    {
        if(a[i]==1 && a[i+1]==1 && a[i+2]==1 &&a[i+3]==1 &&a[i+4]==1)
        {
            cout<<"the hand contains a straight."<<endl;
            n++;
        }
    }
    
    if(a[9]==1 && a[10]==1 && a[11]==1 &&a[12]==1 &&a[0]==1)
    {
        cout<<"the hand contains a straight."<<endl;
        n++;
    }
    if(a[10]==1 && a[11]==1 && a[12]==1 &&a[0]==1 &&a[1]==1)
    {
        cout<<"the hand contains a straight."<<endl;
        n++;
    }
    if(a[11]==1 && a[12]==1 && a[0]==1 &&a[1]==1 &&a[2]==1)
    {
        cout<<"the hand contains a straight."<<endl;
        n++;
    }
    if(a[12]==1 && a[0]==1 && a[1]==1 &&a[2]==1 &&a[3]==1)
    {
        cout<<"the hand contains a straight."<<endl;
        n++;
    }
}

