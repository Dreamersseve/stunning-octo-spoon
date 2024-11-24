#ifndef CHIENT_H
#define CHIENT_H

 // Winsock2 header should be included before windows.h
#include <windows.h>
 // For network-related functions and structures
#include <iostream>
#include <string>
#include <thread> 
#include<bits/stdc++.h>

std::string sendRequest(SOCKET sock, const std::string& action, const std::string& token, int index = -1, const std::string& value = "", int intValue = -1);

int run_chient();
extern std::string token;
extern SOCKET sock;
extern std::string serverIP;
#endif
