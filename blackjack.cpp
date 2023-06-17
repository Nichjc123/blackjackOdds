#include <iostream>
#include <iomanip>
#include <map>

void displayStartup();
void setCard(int &total, bool isDealer);

using namespace std;

map<string,int> Card_Values = {{"2",2},{"3",3},{"4",4},{"5",5},{"6",6},{"7",7},{"8",8},{"9",9},{"10",10},{"A",-1},{"J",10},{"Q",10},{"K",10}};

int main() {
    displayStartup();

    //Set Dealer Total
    int dealersTotal{0};
    setCard(dealersTotal, true);

    //Set player total
    int playerTotal{0};
    setCard(playerTotal, false);
    setCard(playerTotal, false);

    

    //2.1 here are your odds of winning (calculate what percentage of cards the dealer can have that are greater than )
    //2.2 here are your odds of busting on hit
    

    // hit (prompt to enter new card and recalculate odds of winning and busting on next hit) 

    // ALWAYS prompt for new hand

    return 0;
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