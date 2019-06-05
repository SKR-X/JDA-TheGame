//------------------------
// Github: Skrillexazem
//------------------------
// Just Die Already! v?
//------------------------

#include <iostream>
#include <string>
#include "windows.h"


using namespace std;

class Game {
private:
	string cur_version = "1.0";
	string GameName = "Just Die Already!";
public:
	string playername;
	string accept;
	void intro() {
		cout << "Version: " + cur_version << endl;
		cout << "Game: " + GameName << endl;
	}
	void start() {
		cout << endl;
		cout << "Hi stranger! What is your name?" << endl;
		cin >> this->playername;
		cout << endl;
		cout << "Ok, " + this->playername + " this game is about how well do you\nknow the web programming languages!"<<endl;
		cout << endl;
		cout << "are you ready to play this game? Y/N" << endl;
		cin >> this->accept;
		if (this->accept == "Y" || this->accept == "Yes") {
			cout << "Okay. Lets begin.";
			Sleep(2000);
			system("cls");
		}
		else {
			cout << endl;
			cout << "Pathetic.";
			Sleep(2000);
			exit(0);
		}
	}
};
class Player {
private:
	int health = 100;
	int cash = 50;
	int attempts = 5;
public:
	string name;
	void info() {
		cout << "Your health is ";
		cout << this->health << endl;
		cout << "Your cash is ";
		cout << this->cash << endl;
		cout << "Your attemps is ";
		cout << this->attempts << endl;
	}
};

int main()
{
	Player Player;
	Game Game;
	Game.intro();
	Game.start();
	Player.name = Game.playername;
	Player.info();
}
