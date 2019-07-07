//------------------------
// Github: SKR-X
//------------------------
// Just Die Already! v?
//------------------------

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
		cout << " - Ok, " + this->playername + " this game is about how well do you\nknow the web programming languages!"<<endl;
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
			if (this->checked_intro==0) {
				cout << " - Hi stranger! Can you give me some money?" << endl;
				this->introducing("Shop");
			}
			else {
			}
	}
	bool checked_intro=0;
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
	void del_cash(int money) {
		this->cash = this->cash - money;
		cout << endl;
		cout << this->name + "'s cash is ";
		cout << this->cash<<endl;
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
		cout << "Stock Question"<<endl;
	}
	Base_Quest(int number) {
		cout << "Quest number ";
		this->questnumber = number;
		cout << this->questnumber;
		cout << " has been constructed!" << endl;
	//блеать, как наследовать-то этот деструктор...
	~Base_Quest()
	{
		cout << "Quest number ";
		cout << this->questnumber;
		cout << " has been destroyed!" << endl;
	}
};

class Quest1 : public Base_Quest {
public:
	Quest1(int number) : Base_Quest(number) {}
	void question() override{
		cout << "Not a stock question num1" << endl;
	}
};

class Quest2 : public Base_Quest {
public:
	Quest2(int number) : Base_Quest(number) {}
	void question() override {
		cout << "Not a stock question num2" << endl;
	}
};
int main()
{
	Player Player;
	string choise = Player.choise;
	Game Game;
	Game.intro();
	Game.start();
	Player.name = Game.playername;
	Player.info();
	cout << endl;
	cout << "Testing." << endl;
	Base_Quest Main_Quest(0);
	Main_Quest.question();
	Quest1 Quest1(1);
	Quest1.question();
	Quest2 Quest2(2);
	cout << endl;
	Quest2.question();
	Game.select();
	if (Game.firststage == "Shop") {
		Game.firststage = "";
		cout << endl;
		cout << endl;
		cout << "  ---TIP TIME!--- " << endl;
		cout << endl;
		Sleep(1500);
		cout << " In this game you need to make choices so choose properly!" << endl;
		cout << " Good luck!";
		Sleep(6000);
		system("cls");
		cout << " - Hi stranger! Can you give me some money?" << endl;
		cout << " A - \"Okay ( - 5 from cash  )\" " << endl;
		cout << " B - *Just go away from him*" << endl;
		cout << " C - \"Hey, go away\" " << endl;
		cout << endl;
		cout << " ";
		cin >> choise;
		if (choise=="A") {
			Player.del_cash(5);
		}
	}
}
