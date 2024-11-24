#include<bits/stdc++.h>
using namespace std;
string whystring;
bool lengthcheck(string s){
	if(s.length() > 40){
		whystring += "长度非法";
		return false;
	} 
	for(int i = 0;i < (int)s.length();i++){
		whystring += "含有非法特殊字符";
		if(s[i] == '|' || s[i] == '%' || s[i] == ':') return false;
	}
	return true;
}
bool keywordcheck(string s){
	if(s.find("傻") != string::npos){
		whystring += "含有非法字符";
		return false;
	}
	if(s.find("操") != string::npos){
		whystring += "含有非法字符";
		return false;
	}
	if(s.find("国") != string::npos){
		whystring += "含有非法字符";
		return false;
	}
	if(s.find("狗") != string::npos){
		whystring += "含有非法字符";
		return false;
	}
	if(s.find("炮") != string::npos){
		whystring += "含有非法字符";
		return false;
	}
	return true;
}
bool CaBeMessage(string Rawstring){
	whystring.clear();
	if(lengthcheck(Rawstring) == 0) return false;
	if(keywordcheck(Rawstring) == 0) return false;
	return true;
}
