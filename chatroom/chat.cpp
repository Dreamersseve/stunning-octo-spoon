#include<bits/stdc++.h>
using namespace std;
#include "GUI.h"
#include "guide.h"
#include "data.h"
#include "chient.h"

int getchatnum(){
	string Rawstring = sendRequest(sock,"GETSTR",token,4);
	int len = Rawstring.length();
	int ans = 0;
	for(int i = 0;i < len;i++){
		if(Rawstring[i] == '|'){
			ans++;
		}
	}
	return ans;
}
const int maxlen = 7;
void PrintChatlist(){
	string Rawstring = sendRequest(sock,"GETSTR",token,4);
	size_t cur = 0;
	for(int i = 4;i <= 4+maxlen;i++){
		gui.io.SetPrintcur(0,i);
		string name;
		while((int)cur < (int)Rawstring.size() &&Rawstring[cur] != ':' && Rawstring[cur] != '|'){
			name += Rawstring[i];
			cur++;
		}
		cur++;
		string inside;
		while((int)cur < (int)Rawstring.size() &&Rawstring[cur] != '%' && Rawstring[cur] != '|'){
			inside += Rawstring[cur];
			cur++;
		}
		cur++;
		string Time;
		while((int)cur < (int)Rawstring.size() && Rawstring[cur] != '|'  ){
			Time += Rawstring[cur];
			cur++;
		}
		if(Time.empty()) continue;
		gui.io.Printf("||   " + Time + '|' + name + ":" + inside + '\n');
	}
}

void addChatList(string chatstring){
	string Rawstring;
	Rawstring += userID;
	Rawstring += ':';
	Rawstring += chatstring;
	Rawstring += '%';
	Rawstring += getCurrentTimeString();
	Rawstring += '|';
	string goalstring = sendRequest(sock,"GETSTR",token,4);
		
	if(getchatnum() > maxlen){
		while(goalstring[0] != '|'){
			goalstring.erase(0,1);
		}
		goalstring.erase(0,1);
	}
		
	
	
	goalstring += Rawstring;
	sendRequest(sock,"SETSTR",token,4,goalstring);
}
extern string whystring;
int chat(){
	 
	
	printStartMenu();
	string GetinString = "键入以编辑消息";
	
	gui.io.ClearOutputGUI();
	gui.io.ReOutputGUI();
	gui.button.init();
	
	
	while(1){
		
		PrintMainMenu();
		PrintChatlist();
		gui.button.init();
		int CheckBottomNum = gui.button.addButton(0,23,16,25,1);
		gui.io.SetPrintcur(0,15);
		gui.io.Printf("----------------\n|点击以编辑消息|\n----------------");
		
		
		gui.io.ReOutputGUI();
		gui.button.startChecking();
		bool editflag = false;
		for(int i = 1;i <= 1000;i++){
			if(gui.button.checkButton(CheckBottomNum)){
				
				editflag = true;
				gui.button.stopChecking();
				gui.button.init();
				break;
			}
			Sleep(5);
		}
		if(editflag){
			gui.io.SetPrintcur(0,15);
			gui.io.Printf("----------------\n|请输入文本    |\n↓↓------------");
			gui.io.ReOutputGUI();
			string sendstring;
			cout<<">>>";
			cin>>sendstring;
			if(CaBeMessage(sendstring)) addChatList(sendstring);
			else {
				PrintErr(whystring);
			}
			
		}
		gui.io.ClearOutputGUI();
		gui.io.ReOutputGUI();
	}
}

