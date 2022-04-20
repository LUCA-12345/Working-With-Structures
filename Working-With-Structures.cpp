// Lab 11A.cpp
// Programmer: Luke Tascone

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};
struct Player {
    string name;
    string team;
    string jerseyNum;
    Date dateOfBirth; //Structure Date is nested in structure Player.
};

int found = 0;

int showMenu();
void addPlayer(Player[], int);
void displayPlayers(Player[], int);
void modifyPlayer(Player[], int, string);
string dateToString(Date);
void addData(Player[]);


int main()
{

    int option, numPlayers = 5;
    string jNum;
    int const SIZE = 50;


    Player players[SIZE];

    addData(players); // Call the function that reads the data from the file
    option = showMenu();

    Player foundPlayer;

    while (option != 4)
    {
        switch (option)
        {
            case 1:
                addPlayer(players, numPlayers);
                numPlayers++;
                cout << "You have entered information for player number " << numPlayers << endl;
                break;
            case 2:
                cout << "Enter the player's jersey number: ";
                cin >> jNum;
                modifyPlayer(players, numPlayers, jNum);
                break;
            case 3:
                displayPlayers(players, numPlayers);
                break;
            case 4:
                cout << "Goodbye!";
                break;
            default:
                cout << option << " is not a valid choice." << endl;
        }
        option = showMenu();
    }

    cout << "Goodbye!" << endl;

}

// This function presents the menu to the user and inputs the
// option.  The option is then return to the calling function (main).
int showMenu()
{
    int option;

    cout << endl;
    cout << "Please choose an option:" << endl;
    cout << "1. Enter new player information" << endl;
    cout << "2. Change player information" << endl;
    cout << "3. Display all players information" << endl;
    cout << "4. Exit the program" << endl;
    cout << "Option: ";
    cin >> option;

    return option;
}

// This function is in charge of adding a new player to the array.
// Option 1
void addPlayer(Player p[], int num)
{
    string value;
    cin.ignore();
    cout << "Enter name:";
    getline(cin, p[num].name);

    cout << "Enter team name: ";
    getline(cin, p[num].team);

    cout << "Enter jersey number: ";
    getline(cin, p[num].jerseyNum);

    cout << "Enter birth month: ";
    cin >> p[num].dateOfBirth.month;

    cout << "Enter birth day: ";
    cin >> p[num].dateOfBirth.day;

    cout << "Enter birth year: ";
    cin >> p[num].dateOfBirth.year;

    cin.ignore();

}


// This function receives the array of players and the number of elements
// in it. It them prints out all information for each player.
// Option 3
void displayPlayers(Player p[], int n)
{
    cout << "There are " << n << " players." << endl;
    cout << "Players' information: " << endl << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Name: " << p[i].name << endl;
        cout << "Team: " << p[i].team << endl;
        cout << "Jersey number: " << p[i].jerseyNum << endl;
        cout << "Date of birth: " << dateToString(p[i].dateOfBirth) << endl;
        cout << endl;
    }
}

// This function receives a variable of type Date and returns the month, day
// and year values in a string with the format mm/dd/yyyy.
string dateToString(Date d)
{
    return to_string(d.month) + "/" + to_string(d.day) + "/" + to_string(d.year);
}


// This function fills the players array with the data in a
// playerData.txt file.  It receives the empty player array.
// This function assumes there are only 5 players in the file.
// If more players are added to the file, minor changes will be needed.

void addData(Player p[])
{
    const int NUM = 5;
    string value;
    ifstream data;
    data.open("playerData.txt");

    for (int i = 0; i < NUM; i++)
    {
        getline(data, p[i].name);
        getline(data, p[i].team);
        getline(data, p[i].jerseyNum);
        data >> p[i].dateOfBirth.month;
        data >> p[i].dateOfBirth.day;
        data >> p[i].dateOfBirth.year;
        data.ignore();
    }
    data.close();
}

// This function modifies a player's data in the array.
// It receives the player array, the current number of players
// in the array, and the jersey number of the player to be modified.
// The function finds the player to be modified in the array and
// outputs the current information.The function then asks the user
// what information needs to be modified (name, team name,
// jersey number, or date of birth).  The program will ask the
// user to enter the new information and update this value in
// the array.

void modifyPlayer(Player p[], int numOfPlayers, string Jnum)
{
    Player tempPlayer;

    for (int count = 0; count < numOfPlayers; count++)
    {
        if ( p[count].jerseyNum == Jnum )
        {
            found = 1;
            tempPlayer = p[count];
        }
    }
    if(found == 0)
    {
        cout << "There is no player with that number." << endl;
        return;
    }

    cout << "1. " << tempPlayer.name << endl;
    cout << "2. " << tempPlayer.team << endl;
    cout << "3. " << tempPlayer.jerseyNum << endl;
    cout << "4. " << tempPlayer.dateOfBirth.day << "/" << tempPlayer.dateOfBirth.month << "/"
         << tempPlayer.dateOfBirth.year << endl;

    int tempMenu;
    cin.ignore();
    cout << "Enter the number of the item you want to change: ";
    cin >> tempMenu;
    cout << endl;

    int tempNum;
    tempNum = stoi(Jnum);

    switch (tempMenu)
    {
                    case 1:
                        cin.ignore();
                        cout << "Enter name: ";
                        getline(cin, p[tempNum].name);
                        break;
                    case 2:
                        cin.ignore();
                        cout << "Enter team: ";
                        getline(cin, p[tempNum].team);
                        break;
                    case 3:
                        cin.ignore();
                        cout << "Enter jersey number: ";
                        getline(cin, p[tempNum].jerseyNum);
                        break;
                    case 4:                         //cin
                        cout << "Enter birth month: ";
                        cin >> p[tempMenu].dateOfBirth.month;
                        cout << endl;
                        cout << "Enter birth day: ";
                        cin >> p[tempMenu].dateOfBirth.day;
                        cout << endl;
                        cout << "Enter birth year: ";
                        cin >> p[tempMenu].dateOfBirth.year;
                        cout << endl;
                        break;
                    default:
                        cout << "There is no number " << tempMenu << " option." << endl;
    }




}



