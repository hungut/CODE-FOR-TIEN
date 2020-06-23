#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
using namespace std;
class Champion
{
    int id;
    int health;
    int damage;
    static int numberOfAliveChampions; // Think: Why static? What is a static member?
                                       /* What are the differences between a static member and the others? */
public:
    Champion(int _id, int _health, int _damage);
    ~Champion();
    bool attack(Champion &_victim);
    int getHeath();
    static int getNumberOfAliveChampions(); // Why static? What is a static method?
                                            /* What are the differences between a static method and the others? */
};
Champion::Champion(int _id, int _health, int _damage)
{
    // Hint: set the corresponding passed values to id, health, and damage
    // Hint: We have a static variable for alive champion counting!
    this->id = _id;
    this->health = _health;
    this->damage = _damage;
    numberOfAliveChampions++;
}
Champion::~Champion()
{
    numberOfAliveChampions--;
    //somthing wrong
    // Think: What must be done when the the object is destroyed?
    // Hint: We have a static variable for alive champion counting!
}
/* This champion attack another champion, the victim will lose an amount of health
equal to the attacker damage, return true if the victim dies after being attacked */
bool Champion::attack(Champion &_victim)
{
    _victim.health = _victim.health - damage;
    if (_victim.health > 0)
        return false;
    else
        return true;
}
/* The getter for instance member: this->health */
int Champion::getHeath()
{
    return this->health;
}
/* The getter for the class member: Champion::numberOfAliveChampions */
int Champion::getNumberOfAliveChampions()
{ // Why static? What is a static method?
    return numberOfAliveChampions;
}
int Champion::numberOfAliveChampions = 0;
/* For each event, if event is true then the champion A attack the champion B and vise versa.
Return 1 if the champion A killed the champion B, return -1 if the champion B killed the champion A,
or return 0 if no one dies after the fight. Please note that, to mark that a champion is killed,
you have to delete that champion object and set the corresponding pionter to NULL*/
int fight(Champion *&a, Champion *&b, bool *eventList, int numberOfEvent)
{
    //cout << Champion::getNumberOfAliveChampions() << endl;

    bool A = false;
    bool B = false;
    if (a != NULL && b != NULL)
    {
        for (int i = 0; i < numberOfEvent; i++)
        {

            if (eventList[i] == 1)
            {
                A = a->attack(*(b));
                if (A == true)
                {
                    delete b;
                    b = NULL;
                    return 1;
                }
            }
            if (eventList[i] == 0)
            {
                B = b->attack(*(a));
                if (B == true)
                {
                    delete a;
                    a = NULL;
                    return -1;
                }
            }
        }
    }
    /*if (A == false && B == false)
    {
        return 0;
    }*/
    return 0;
}
struct Match
{
    int indexOfA;
    int indexOfB;
    int numberOfEvents;
    bool *eventList;
};
/* There are many matches, in each match, the two champion will fight with each other */
void combat(Champion **championList, int numberOfChampions, Match *matchList, int numberOfMatches)
{
    for (int i = 0; i < numberOfMatches; i++)
    {
        if (championList[matchList[i].indexOfA] != NULL && championList[matchList[i].indexOfB] != NULL)
            fight(championList[matchList[i].indexOfA], championList[matchList[i].indexOfB], matchList[i].eventList, matchList[i].numberOfEvents);
    }
}
int main(int argc, char *argv[])
{
    // Section: read testcase
    ///Student may comment out this section for local testing
    if (argc < 2)
        return 0;
    ifstream fileIn;
    try
    {
        fileIn.open(argv[1]);
        if (fileIn.fail())
            throw "Failed to open file.";
        int numberOfChampions;
        fileIn >> numberOfChampions;
        Champion **champList = new Champion *[numberOfChampions];
        int id, health, damage;
        for (int i = 0; i < numberOfChampions; i++)
        {
            fileIn >> id >> health >> damage;
            champList[i] = new Champion(id, health, damage);
        }
        int numberOfMatches;
        fileIn >> numberOfMatches;
        Match *matchList = new Match[numberOfMatches];
        for (int i = 0; i < numberOfMatches; i++)
        {
            fileIn >> matchList[i].indexOfA >> matchList[i].indexOfB;
            fileIn >> matchList[i].numberOfEvents;
            matchList[i].eventList = new bool[matchList[i].numberOfEvents];
            for (int j = 0; j < matchList[i].numberOfEvents; j++)
                fileIn >> matchList[i].eventList[j];
        }
        combat(champList, numberOfChampions, matchList, numberOfMatches);
        cout << Champion::getNumberOfAliveChampions();
        fileIn.close();
        for (int i = 0; i < numberOfChampions; i++)
            delete champList[i];
        delete[] champList;
        for (int i = 0; i < numberOfMatches; i++)
            delete[] matchList[i].eventList;
        delete[] matchList;
    }
    catch (const char *errMsg)
    {
        cerr << errMsg;
    }
    // Endsection: read testcase
    //------------------------------------
    return 0;
}
