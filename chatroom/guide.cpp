

#include"IO.h"
#include"GUI.h"
#include"data.h"
#include<bits/stdc++.h>


using namespace std;
int logout();
void printStartMenu(){
	PrintInfo("======================================");
	PrintInfo("SEVE Chat ROOM           ");
	PrintInfo("                                 ");
	//printPHB();
	PrintInfo(" \n======================================");
		//PrintInfo("若要登录，请输入0|若要注册，请输入1");
		gui.io.SetPrintcur(2,8);
		gui.io.Printf("--------    --------\n| 登录 |    | 注册 |\n--------    --------");
		gui.io.ReOutputGUI();
		int button1cur = gui.button.addButton(2,8,9,10,1);
		int button2cur = gui.button.addButton(14,8,20,10,1);
		
		gui.button.startChecking();
		//int op;
		//cin>>op;
		//int i = 0;
		
		while(1){
			//i++;
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
			//gui.io.Printf("%d",i);
			
			if(gui.button.checkedflag[button2cur]){
				Register();
				if(login() == -1) throw "密码尝试次数过多";
				gui.button.stopChecking();
				break;
			}
			if(gui.button.checkedflag[button1cur]){
				if(login() == -1) throw "密码尝试次数过多";
				gui.button.stopChecking();
				break;
			}
			
		}
	
	
}

void PrintMainMenu(){
	gui.io.SetPrintcur(0,0);
	gui.io.Printf("====================================");
	gui.io.SetPrintcur(0,1);
	gui.io.Printf(Nowplayer.name + "，您好\n====================================");
}
