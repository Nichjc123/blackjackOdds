#include <iostream>
#include <iomanip>
#include <map>

void displayStartup();
void setCard(int &total, bool isDealer);
double oddsofBusting(int total);

using namespace std;

map<string,int> Card_Values = {{"2",2},{"3",3},{"4",4},{"5",5},{"6",6},{"7",7},{"8",8},{"9",9},{"10",10},{"A",11},{"J",10},{"Q",10},{"K",10}};
bool playerHasAce{false};
bool dealerHasAce{false};

//TODO: Handle A input (for now its decrementing total by 1 which is wrong :( )

int main() {
    displayStartup();

    //Set Dealer Total
    int dealersTotal{0};
    setCard(dealersTotal, true);

    //Set player total
    int playerTotal{0};
    setCard(playerTotal, false);
    setCard(playerTotal, false);

    //Output odds of losing(busting) on hit
    if (!playerHasAce)
    {
        cout << "Odds of losing on hit: [" << oddsofBusting(playerTotal) << "%]";
    }

    //Output odds of losing(dealer busting) on stand
    if (!dealerHasAce)
    {
        cout << "Odds of losing on stand: [" << 1 - oddsofBusting(dealersTotal) << "%]";
    }

    // prompt to hit / new hand
    // hit (prompt to enter new card and recalculate odds of winning and busting on next hit) 

    // ALWAYS prompt for new hand

    return 0;
}

double oddsofBusting(int total)
{
    //**This assumes no knowledge of previous cards
    //Calculate the odds of busting having a given total
    //21 -> 100% (all cards)
    //20 -> 12/13% (ace only)
    //19 -> 11/13% (ace/2)
    //18 -> 10/13%
    // . . .
    //13 -> 5/13% (9,10,J,Q,K)
    //12 -> 4/13% (10,J,Q,K)
    //11 -> 0%
    // ..
    //1 -> 0%
    if (total <= 11) {
        return 0;
    } else {
        return (total - 8) / 13;
    }
}

void displayStartup()
{
    //Display disclaimer and author info
    cout << "============================" << endl;
    cout << "=== ** BlackJack Odds ** ===" << endl;
    cout << "============================" << endl;
    cout << endl;
    cout << "DISCLAIMER: don't gamble. you won't win. \nhere is mathematical proof that you won't win. \nAlso this program does not count cards." << endl;
    cout << setw(60);
    cout << "written by: nich" << endl;
}


void setCard(int &total, bool isDealer) 
{
    //Take in user input and convert to int value for calculation
    string in;
    cout << endl;
    cout << endl;

    string player = (isDealer) ? "dealer" : "player";
    cout << "Please Enter the " << player << "'s card" << endl;
    cout << "Valid entries: 2-10,A,J,Q,K" << endl;
    while(1)
    {
        cin>>in;
        if (Card_Values.find(in) == Card_Values.end()) 
        {
            //user input is not valid 
            cin.clear();
            cout << "You have entered invalid input please try again." << endl;
        }
        else 
        {
            break;
        }
    }
    total += Card_Values.find(in)->second;

}