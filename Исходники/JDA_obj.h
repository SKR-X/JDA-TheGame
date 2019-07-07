#include <iostream>
#include <string>
#include "windows.h"

using namespace std;

class Game {
private:
	string cur_version = "?";
	string GameName = "Just Die Already!";
public:
	string answer;
	string playername;
	string accept;
	bool do_something = 0;
	void intro() {
		cout << "Version: " + cur_version << endl;
		cout << "Game: " + GameName << endl;
	}
	void start() {
		cout << endl;
		cout << " - Hi stranger! What is your name?" << endl;
		cout << endl;
		cout << " ";
		cin >> this->playername;
		cout << endl;
		cout << " - Ok, " + this->playername + " this game is about how well do you\nknow the web programming languages!" << endl;
		Sleep(2000);
		cout << endl;
		cout << endl;
		cout << "- Are you ready to play this game? Y/N" << endl;
		cout << endl;
		cout << " ";
		cin >> this->accept;
		if (this->accept == "Y" || this->accept == "Yes" || this->accept == "yes" || this->accept == "y") {
			cout << endl;
			cout << " - Okay. Lets begin.";
			Sleep(2000);
			system("cls");
		}
		else {
			cout << endl;
			cout << " - You are pathetic.";
			Sleep(2000);
			exit(0);
		}
	}
	void select_check() {
		if (this->answer == "C") {
			exit(0);
		}
		else if (this->answer == "A") {
			system("cls");
			Sleep(2000);
			cout << endl;
			cout << endl;
			cout << " moving to the shop...";
			Sleep(3000);
			this->shop();
		}
		else {
			cout << endl;
			cout << " - What? Repeat please..." << endl;
			cout << endl;
			cout << " ";
			cin >> this->answer;
			select_check();
		}
	}
	void select() {
		cout << endl;
		cout << " - " + this->playername;
		cout << ", what are you going to do now?" << endl;
		cout << endl;
		cout << " ------SELECT------ " << endl;
		cout << endl;
		cout << " Im gonna go to the shop = A" << endl;
		cout << " Im gonna to do some quests = B" << endl;
		cout << " Quit = C" << endl;
		cout << endl;
		cout << " ";
		cin >> this->answer;
		select_check();
	}
	void shop() {
		system("cls");
		if (this->checked_intro == 0) {
			cout << " - Hi stranger! Can you give me some money?" << endl;
			this->introducing("Shop");
		}
		else {
		}
	}
	bool checked_intro = 0;
	string firststage;
	void introducing(string firststage) {
		this->checked_intro = 1;
		Sleep(3000);
		system("cls");
		this->firststage = firststage;
	}
};
class Player {
private:
	float status = 0;
	int health = 100;
	int cash = 50;
	int attempts = 5;
	float level = 0;
public:
	string choise;
	string name;
	void info() {
		cout << " -------------------" << endl;
		cout << " | Your level is ";
		cout << this->level;
		cout << " |" << endl;
		cout << " -------------------" << endl;
		cout << " | Your health is ";
		cout << this->health << endl;
		cout << " | Your cash is ";
		cout << this->cash << endl;
		cout << " | Your attemps is ";
		cout << this->attempts << endl;
	}
	void del_cash(int d_money) {
		this->cash = this->cash - d_money;
		cout << endl;
		cout << this->name + "'s cash is ";
		cout << this->cash << endl;
		cout << endl;
	}
	void add_cash(int a_money) {
		this->cash = this->cash - a_money;
		cout << endl;
		cout << this->name + "'s cash is ";
		cout << this->cash << endl;
		cout << endl;
	}
};

class Base_Quest {
public:
	int questnumber;
	virtual void question() {
		cout << "Stock Question" << endl;
	}
	Base_Quest(int number) {
		cout << "Quest number ";
		this->questnumber = number;
		cout << this->questnumber;
		cout << " has been constructed!" << endl;
	}
	virtual ~Base_Quest()
	{
		cout << "Quest number ";
		cout << this->questnumber;
		cout << " has been destroyed!" << endl;
	}
};

class Quest1 : public Base_Quest {
public:
	using Base_Quest::Base_Quest;
	void question() override {
		cout << "Not a stock question num1" << endl;
	}
};

class Quest2 : public Base_Quest {
public:
	using Base_Quest::Base_Quest;
	void question() override {
		cout << "Not a stock question num2" << endl;
	}
};
