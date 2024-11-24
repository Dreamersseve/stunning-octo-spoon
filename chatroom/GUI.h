#ifndef GUI_H
#define GUI_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdarg>
#include <cstdio>
#include <sstream>
#include <windows.h>
#include <bits/stdc++.h>
#include <thread>
#include <chrono>

//using namespace Microsoft::WRL;  // Windows Runtime Library for COM support

// 要使用的 UWP 和 Windows API，需要包含这些库
//#include <windows.ui.notifications.h>
//#include <windows.data.xml.dom.h>
//#include <shobjidl.h>  // 包含与 ToastNotification 的 COM 接口

//#pragma comment(lib, "windowsapp.lib")  // 需要链接 windowsapp.lib 来使用 Windows API

class GUI {
public:
	struct Point {
		int x, y;
		void init();
	};
	
	struct ButtonPoint {
		int index, type;
		Point start, end;
		ButtonPoint();
		void init();
	};
	
	class IO {
	public:
		IO();
		void ReOutputGUI();
		void SetPrintcur(int x, int y);
		void Printf(const std::string& format, ...);
		void PrintBlock(int x,int y,const std::string& text, const std::string& prefix = "", const std::string& suffix = "");
		void DisableEchoInput();
		void EnableEchoInput();
		void ClearOutputGUI();
		std::string GetString(int x,int y,std::string prefix = "", std::string suffix = "");
		
	private:
		std::vector<std::string> outMap;
		Point PrintCur;
		HANDLE hOutput, hOutBuf;
		COORD coord = {0, 0};
		DWORD bytes = 0;
		int showflag = 0;
		int sd = 1;
		void InitConsoleBuffers();
		std::vector<std::string> processString(const std::string& str);
		bool IsShiftKeyPressed();
		char GetKeyPressed();
	};
	
	struct ClickPosition {
		bool isClicked;
		int x, y;
		int checkType;
	};
	
	class mouse_checker {
	public:
		ClickPosition GetMouseClickPosition();
	private:
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
	};
	
	class BUTTON {
		static const int maxnbutton = 100;
	public:
		int addButton(int startx, int starty, int endx, int endy, int type);
		void delButton(int cur);
		bool checkButton(int cur);
		void stopChecking();
		void startChecking();
		bool checkedflag[maxnbutton];
		BUTTON();
		void init();
	private:
		
		ButtonPoint Button[maxnbutton];
		bool reCheckingFlag;
		
		void reCheckingLoop();
		std::thread* checkingThread;
	};
	
	//static mouse_checker checker;
	IO io;
	BUTTON button;
	//void ShowToastNotification(const std::wstring& message);
};
extern GUI gui;


#endif // GUI_H

