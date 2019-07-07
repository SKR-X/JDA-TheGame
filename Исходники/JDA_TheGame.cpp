//------------------------
// Github: SKR-X
//------------------------
// Just Die Already! v?
//------------------------

#include "JDA_obj.h";


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
	Game.select();
	if (Game.firststage == "Shop") {
		Game.firststage = "";
		cout << endl;
		cout << "  ---TIP TIME!--- " << endl;
		cout << endl;
		Sleep(1500);
		cout << " In this game you need to make choices so choose properly!" << endl;
		cout << " Good luck!";
		Sleep(6000);
		system("cls");
		cout << endl;
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
	cout << endl;
	cout << endl;
	cout << "Testing." << endl;
	Quest1 Quest1(1);
	Quest1.question();
	return 0;
}
