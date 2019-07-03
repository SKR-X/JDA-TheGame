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
	string answer;
	string playername;
	string accept;
	void intro() {
		cout << "Version: " + cur_version << endl;
		cout << "Game: " + GameName << endl;
	}
	void start() {
		cout << endl;
		cout << "- Hi stranger! What is your name?" << endl;
		cout << endl;
		cout << " ";
		cin >> playername;
		cout << endl;
		cout << "- Ok, " + playername + " this game is about how well do you\nknow the web programming languages!"<<endl;
		Sleep(2000);
		cout << endl;
		cout << endl;
		cout << "- Are you ready to play this game? Y/N" << endl;
		cout << endl;
		cout << " ";
		cin >> accept;
		if (accept == "Y" || accept == "Yes" || accept == "yes") {
			cout << endl;
			cout << "- Okay. Lets begin.";
			Sleep(2000);
			system("cls");
		}
		else {
			cout << endl;
			cout << "- You are pathetic.";
			Sleep(2000);
			exit(0);
		}
	}
	void select_check() {
		if (answer == "C") {
			exit(0);
		}
		else if (answer == "A" || answer == "B") {
			cout << "- this part of the game is in progress...";
		}
		else {
			cout << endl;
			cout << "- What? Repeat please..." << endl;
			cout << endl;
			cout << " ";
			cin >> answer;
			select_check();
		}
	}
	void select() {
		cout << endl;
		cout << "- Hey, what you gonna do now?" << endl;
		cout << endl;
		cout << "------SELECT------" << endl;
		cout << endl;
		cout << "Im gonna go to the shop = A" << endl;
		cout << "Im gonna to do some quests = B" << endl;
		cout << "Quit = C" << endl;
		cout << endl;
		cout << " ";
		cin >> answer;
		select_check();
	}
};
class Player {
private:
	int health = 100;
	int cash = 50;
	int attempts = 5;
	float level = 0;
public:
	string name;
	void info() {
		cout << "-------------------" << endl;
		cout << "| Your level is ";
		cout << level;
		cout << " |" << endl;
		cout << "-------------------" << endl;
		cout << "| Your health is ";
		cout << health << endl;
		cout << "| Your cash is ";
		cout << cash << endl;
		cout << "| Your attemps is ";
		cout << attempts << endl;
	}
};

class Base_Quest {
private:
	int questnumber;
public:
	Base_Quest(int number) {
		cout << "Quest number ";
		questnumber = number;
		cout << questnumber;
		cout << " has been constructed!" << endl;
	}
	~Base_Quest()
	{
		cout << "Quest number ";
		cout << questnumber;
		cout << " has been destroyed!" << endl;
	}
};

class Quest1 : public Base_Quest {
public:
	Quest1(int number) : Base_Quest(number) {}
};

class Quest2 : public Base_Quest {
public:
	Quest2(int number) : Base_Quest(number) {}

};

int main()
{
	Player Player;
	Game Game;
	Game.intro();
	Game.start();
	Player.name = Game.playername;
	Player.info();
	Game.select();
}
