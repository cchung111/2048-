#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include "movescore.h"
#include "board.h"
#include "logo.h"
#include "checkend.h"

using namespace std;

struct user     //struct to store player's name and highscore
{
    int highscore;
    char name[10];
};

void normalmode(int & s, int gamedata[4][4])
{
    s = 0;
    int first = 1, leave;
    initialboard(gamedata);
    randomtile(gamedata);
    randomtile(gamedata);

    while (gameover(gamedata) == false)
    {
        cout<<endl;
        cout<<"current score: "<<s<<endl;
        printboard(gamedata);
        cout<<endl;
        move(gamedata,s);
        if (have2048(gamedata) == true && first == 1)
        {
            first = 0;
            cout<<endl;
            cout<<"Yay! You have achieved 2048, continue the game?";    //player can choose to continue after getting 2048
            cout<<"1. Continue"<<endl;
            cout<<"2. Quit"<<endl;
            cout<<"Please enter a number: ";
            cin>>leave;
            if (leave == 2)
                break;
            else
                cout<<endl;
        }
        if (fullboard(gamedata) == false)
            randomtile(gamedata);       // generate a random tile each turn;
    }
    cout<<"Gameover !"<<endl;
}

void hardmode (int & s, int gamedata[4][4])
{
    s = 0;
    int first = 1, leave;
    initialboard(gamedata);
    randomtile(gamedata);
    randomtile(gamedata);

    while (gameover(gamedata) == false)
    {
        cout<<endl;
        cout<<"current score: "<<s<<endl;
        printboard(gamedata);
        move(gamedata,s);
        if (have2048(gamedata) == true && first == 1)
        {
            first = 0;
            cout<<endl;
            cout<<"Yay! You have achieved 2048, continue the game?";
            cout<<"1. Continue"<<endl;
            cout<<"2. Quit"<<endl;
            cout<<"Please enter a number: ";
            cin>>leave;
            if (leave == 2)
                break;
            else
                cout<<endl;
        }
        if (fullboard(gamedata) == false)       // generate 2 random tiles each turn in hard mode;
            randomtile(gamedata);
        if (fullboard(gamedata) == false)
            randomtile(gamedata);
    }
    cout<<"Gameover !"<<endl;
}

void printrecord(vector<user> records)      // print top 10 records
{
    cout<<endl;
    cout<<"TOP 10 Records"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"      "<<"player name"<<"  "<<"highscore"<<endl;
    cout<<endl;
    for (int i = 9; i >= 0; i--)
    {
        cout<<setfill(' ')<<setw(2)<<10-i;
        cout<<". "<<setw(12)<<records[i].name<<"      ";
        cout<<setfill('0')<<setw(6)<<records[i].highscore<<endl;
        cout<<endl;
    }
}

bool operator <(const user & a, const user & b)     // to help sorting of the vectors of user
{
    return (a.highscore < b.highscore);
}

void updaterecord(vector<user> & records,int & score)   //let player input their name after breaking record and update the records;
{
        user a;
        a.highscore = score;
        cout<<"Please enter your name: ";
        cin>>a.name;
        records.pop_back();
        records.push_back(a);
        sort(records.begin(), records.end());
}

int main() {
    int gamedata[4][4] = {
        {0 , 0 , 0 , 0},
        {0 , 0 , 0 , 0},
        {0 , 0 , 0 , 0},
        {0 , 0 , 0 , 0}
    };
    user a;
    vector<user> normalrecords;
    vector<user> hardrecords;
    int choice, score, mode, r;
    ifstream finnorm, finhard;
    ofstream foutnorm, fouthard;
    printlogo();
    cout<<endl;
    while (choice != 3)
    {
        normalrecords.clear();
        hardrecords.clear();

        finnorm.open("top10records_normal.txt");           // read records from txt files to vectors
        if ( finnorm.fail() )
        {
    		cout << "Error in file opening!" << endl;
     		exit(1);
        }
        while(finnorm>>a.name>>a.highscore)
        {
            normalrecords.push_back(a);
        }
        finnorm.close();

        finhard.open("top10records_hard.txt");
        if ( finhard.fail() )
        {
    		cout << "Error in file opening!" << endl;
     		exit(1);
        }
        while(finhard>>a.name>>a.highscore)
        {
            hardrecords.push_back(a);
        }
        finhard.close();


        cout<<endl;         //main menu
        cout<<"1. Play"<<endl;
        cout<<"2. Check Scores"<<endl;
        cout<<"3. Quit"<<endl;
        cout<<"Please enter a number: ";
        cin>>choice;
        while (choice != 1 && choice !=2 && choice !=3)
        {
            cout<<"invalid input, enter again: "<<endl;
            cin>>choice;
        }
        if (choice == 1)
        {
            cout<<endl;
            cout<<"1. Normal"<<endl;
            cout<<"2. Hard"<<endl;
            cout<<"Please enter a number to choose the difficulty: ";       // to choose the difficulty of the game
            cin>>mode;
            while (mode != 1 && mode !=2 )
            {
                cout<<"invalid input, enter again: "<<endl;
                cin>>mode;
            }
            cout<<endl;
            cout<<"Enter w/a/s/d to move the tiles upwards/leftwards/downwards/righwards."<<endl;
            if (mode == 1)
            {
                normalmode(score, gamedata);    // run the game in normal mode
                printrecord(normalrecords);
                foutnorm.open("top10records_normal.txt", std::ofstream::out | std::ofstream::trunc);     // output records to txt file
                if ( foutnorm.fail() )
                {
            		cout << "Error in file opening!" << endl;
             		exit(1);
                }
                if (score > normalrecords[9].highscore)
                {
                    if (score > normalrecords[0].highscore)
                        cout<<"NEW BEST RECORD !!!"<<endl;
                    else
                        cout<<"Record update"<<endl;
                    updaterecord(normalrecords, score);
                    for (int i = 0; i < 10; i++)
                    {
                        foutnorm<<normalrecords[i].name<<' '<<normalrecords[i].highscore<<endl;
                    }
                }
                foutnorm.close();
            }
            else
            {
                hardmode(score, gamedata);  // run the game in hard mode
                printrecord(hardrecords);
                fouthard.open("top10records_hard.txt", std::ofstream::out | std::ofstream::trunc);       // output records to txt file
                if ( fouthard.fail() )
                {
            		cout << "Error in file opening!" << endl;
             		exit(1);
                }
                if (score > hardrecords[9].highscore)
                {

                    updaterecord(hardrecords, score);
                    for (int i = 0; i < 10; i++)
                    {
                        fouthard<<hardrecords[i].name<<' '<<hardrecords[i].highscore<<endl;
                    }
                }
                fouthard.close();
            }
        }
        else if (choice == 2)
        {
            cout<<"1. Normal"<<endl;
            cout<<"2. Hard"<<endl;
            cout<<"Please enter a number to check the highscores of the selected difficulty: ";     // choose to see records of normal mode or hard mode
            cin>>r;
            while ( r != 1 && r !=2 )
            {
                cout<<"invalid input, enter again: "<<endl;
                r>>mode;
            }
            if (r == 1)
            {
                printrecord(normalrecords);
            }
            else
            {
                printrecord(hardrecords);
            }
        }
        else
        {
            cout<<"Bye"<<endl;
        }
    }
    return 0;
}
