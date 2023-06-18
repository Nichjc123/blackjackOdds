#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>

void displayStartup();
void setCard(int &total, bool isDealer);
double oddsofBusting(int total);
double oddsofDealerBusting(int total);
void printResults(double playerOdds, double dealerOdds);

using namespace std;

map<string,int> Card_Values = {{"2",2},{"3",3},{"4",4},{"5",5},{"6",6},{"7",7},{"8",8},{"9",9},{"10",10},{"A",11},{"J",10},{"Q",10},{"K",10}};
bool playerHasAce{false};

void printResults(double playerOdds, double dealerOdds)
{
        //Output odds of losing(busting) on hit
        if (!playerHasAce)
        {
            cout << "Odds of losing on hit: [" << playerOdds  << "%] ";
        }

        //Output odds of losing(dealer busting) on stand
        cout << "Odds of losing on stand: [" << dealerOdds << "%]" << endl;
}

int main() {
    while(1)
    {
        string userSelection;
        displayStartup();

        playerHasAce = false;
        //Set Dealer Total
        int dealersTotal{0};
        setCard(dealersTotal, true);

        //Set player total
        int playerTotal{0};
        setCard(playerTotal, false);
        setCard(playerTotal, false);

        cout << endl;

        printResults(round((oddsofBusting(playerTotal) * 100) * 100.0) / 100.0, round(((1 - oddsofDealerBusting(dealersTotal)) * 100) * 100.0) / 100.0);

        while(1) {
            //Prompt to Hit, start a new hand or quit
            cout << "Press H: hit, Press N: new hand, Press Q: quit" << endl;
            cin>>userSelection;
            if (userSelection == "H")
            { 
                setCard(playerTotal, false);
                if (playerTotal < 22)
                {
                    printResults(round((oddsofBusting(playerTotal) * 100) * 100.0) / 100.0, round(((1 - oddsofDealerBusting(dealersTotal)) * 100) * 100.0) / 100.0);
                }
            }
            else if (userSelection == "N")
            {
                break;
            }
            else if (userSelection == "Q")
            {
                break;
            }
            else {
                cout << "You have entered invalid input please try again." << endl;
                cin.clear(); 
            }
        }
        if (userSelection == "N") {
            continue;
        } else {
            break;
        }
    }
    return 0;
}

double oddsofDealerBusting(int total)
{
    //data from wizardofodds.com
    map<int, double> dealerOdds = {{2,0.35473},{3,0.372750},{4,0.39594},{5,0.41562},{6,0.42197},{7,0.261690},{8,0.24462},{9,0.22958},{10,0.210600},{11,0.132580}};
    return dealerOdds.find(total)->second;
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
        return (total - 8.0) / 13.0;
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
    if (!isDealer && Card_Values.find(in)->second == 11)
    {
        playerHasAce = true;
    }
    if (total > 21){
        cout << "You have lost please press Q or N" << endl;
    }
}