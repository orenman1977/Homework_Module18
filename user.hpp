// класс юзер

#pragma once
#include <fstream>
#include <iostream>
#include <filesystem>

class User {
	std::string _name;
	std::string _login;
	std::string _pass;

public:
    User() = default;
	User(std::string name, std::string login, std::string pass):
	    _name(name), _login(login), _pass(pass) {}
	~User() = default;

	void enter();
	void userTofile();
	void userFromfile();

	friend std::fstream& operator >>(std::fstream& is, User& obj);
	friend std::fstream& operator <<(std::fstream& os, const User& obj);
};
