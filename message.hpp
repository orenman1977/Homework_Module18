// класс Message

#pragma once
#include <fstream>
#include <iostream>
#include <filesystem>

class Message{
	std::string _text;
	std::string _sender;
	std::string _receiver;

public:
    Message() = default;
	Message(std::string text, std::string sender, std::string receiver):
		_text(text), _sender(sender), _receiver(receiver) {}
	~Message() = default;

	void enter();
	void messageTofile();
	void messageFromfile();

	friend std::fstream& operator >>(std::fstream& is, Message& obj);
	friend std::fstream& operator <<(std::fstream& os, const Message& obj);
};
