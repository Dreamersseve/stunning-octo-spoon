
#include <winsock2.h>  
#include<windows.h>
#include <ws2tcpip.h>  
#include <iostream>  
#include <string>  
#include <thread>  
#include<bits/stdc++.h>
#include "IO.h"
#include "guide.h"
#include "chat.h"
//192.168.5.92
string serverIP = "103.123.4.252";
int port = 32446;
std::string sendRequest(SOCKET sock, const std::string& action, const std::string& token, int index = -1, const std::string& value = "", int intValue = -1) {  
	char buffer[2048]; 
	std::string fullRequest;  
	if (action == "SETSTR") {  
		// 构建 "SET TOKEN INDEX VALUE INTVALUE" 请求  
		fullRequest = "SETSTR " + token + " " + std::to_string(index) + " " + value  + "\r";  
	} 
	else if (action == "SETINT") {  
		// 构建 "SET TOKEN INDEX VALUE INTVALUE" 请求  
		fullRequest = "SETINT " + token + " " + std::to_string(index) + " " + std::to_string(intValue) + "\r";  
	} 
	else if (action == "GETINT") {  
		// 构建 "GETINT TOKEN INDEX" 请求（注意：这里假设不需要整数值）  
		fullRequest = "GETINT " + token + " " + std::to_string(index) + "\r";  
	} 
	else if (action == "GETSTR") {  
		// 构建 "GETSTR TOKEN INDEX" 请求（注意：这里假设不需要整数值）  
		fullRequest = "GETSTR " + token + " " + std::to_string(index) + "\r";  
	} 
	else {  
		return "ERROR: Unknown action";  
	}  
	int sentBytes = send(sock, fullRequest.c_str(), fullRequest.size(), 0);  
	if (sentBytes == SOCKET_ERROR) {  
		std::cerr << "Error sending request: " << WSAGetLastError() << std::endl;  
		return "ERROR: Sending request failed";  
	}  
	int bytesReceived = recv(sock, buffer, sizeof(buffer) - 1, 0);
	//cout<<"buffer "<<buffer<<endl;
	if (bytesReceived > 0) {  
		buffer[bytesReceived] = '\0';  
		return std::string(buffer);  
	} else if (bytesReceived == 0) {  
		return "ERROR: Connection closed by server";  
	} else {  
		return "ERROR: Receiving response failed";  
	}  
	//cerr<<111<<endl;
}  
std::string token = "sever_pro::";
SOCKET sock;



int run_chient() {  
	
	//PrintInfo("使用默认ip连接?");
	//int opt;
	//cin>>opt;
	//if(opt != 0){
	//	cin>>serverIP;
	//}
	
	
	WSADATA wsaData;  
	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);  
	if (result != 0) {  
		std::cerr << "WSAStartup failed: " << result << std::endl;  
		return 1;  
	}  
	
	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);  
	if (sock == INVALID_SOCKET) {  
		std::cerr << "Error at socket(): " << WSAGetLastError() << std::endl;  
		WSACleanup();  
		return 1;  
	}  
	
	sockaddr_in serverAddr;  
	serverAddr.sin_family = AF_INET;  
	serverAddr.sin_port = htons(port); // 假设服务器在端口11451上监听  
	inet_pton(AF_INET, serverIP.c_str(), &serverAddr.sin_addr); // 连接到本地服务器  
	
	if (connect(sock, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {  
		std::cerr << "connect failed: " << WSAGetLastError() << std::endl;  
		closesocket(sock);  
		WSACleanup();  
		return 1;  
	}  
	
	 // 使用有效的身份验证字符串（确保与服务器端的authTokens匹配）  
	//std::string response;  
	/*I
		string分配
			1.玩家ID-密码表 格式：ID:密码|
			2.玩家ID-数据 格式:  ID:K|D|
			3.在线玩家列表 ID|ID|
	4.聊天列表(10条数据) A:vava%time|B:adad%time|
			6-100:对局数据 
				玩家A-玩家B-操作分配地址ijk | ij 落子坐标 k 轮数
		int分配
			随服务器决定
	
		// 示例：获取索引为0的字符串和整数  
	string response ;
	
	
	response = sendRequest(sock, "SETSTR", token, 1, "hello",1);  
	std::cout << "Response: " << response << std::endl;  
	
	response = sendRequest(sock, "SETSTR", token, 1, "hello",1);  
	std::cout << "Response: " << response << std::endl;  
	
	response = sendRequest(sock, "SETSTR", token, 1, "hello",1);  
	std::cout << "Response: " << response << std::endl;  
	
	response = sendRequest(sock, "GETSTR", token, 1);  
	std::cout << "Response: " << response << std::endl; 
	
	response = sendRequest(sock, "SETSTR", token, 1, "hello114",1);  
	std::cout << "Response: " << response << std::endl;  
	
	response = sendRequest(sock, "GETSTR", token, 1);  
	std::cout << "Response: " << response << std::endl; 
	
	response = sendRequest(sock, "GETSTR", token, 1);  
	std::cout << "Response: " << response << std::endl; 
	
	response = sendRequest(sock, "GETSTR", token, 1);  
	std::cout << "Response: " << response << std::endl; 
	*/
	//string response = sendRequest(sock, "GETSTR", token, 1);  
	//std::cout << "Response: " << response << std::endl; 
	
	
	
	//do someting
	chat();
	
	closesocket(sock);  
	WSACleanup();  
	return 0;
}
