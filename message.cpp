
#include "message.hpp"
using namespace std;
namespace fs = std::filesystem;

void Message::enter()
{
    string choose;
	while(true){
		cout << "1 Cохранить Message в файл\n2 Прочитать Message из файла\n3 Выход\n";
		getline(cin, choose);
		if(choose.size() > 1) continue;
		if(choose[0] == '1' || choose[0] =='2' || choose[0] == '3') {
			switch(choose[0]){
				case '1':
                messageTofile();
				break;
				case '2':
                messageFromfile();
				break;
				case '3':
				return;
			}
		}
	}
}

void Message::messageTofile()
{
    fstream message_file = fstream("message", ios::out | ios::trunc);
    if(!message_file.is_open()) {
        cout << "Error open/create file message\n";
        return;
    }
    // permissions
    fs::permissions("message", fs::perms::owner_all);
    // write
    message_file << *this;
    message_file.close();
}

void Message::messageFromfile()
{
    fstream message_file = fstream("message", ios::in);
    if(!message_file.is_open()) {
        cout << "\nNo message file\n\n";
        return;
    }
    // read
	message_file.seekg(0, ios_base::beg);
	message_file >> *this;
	message_file.close();
}


std::fstream& operator >>(std::fstream& is, Message& obj){
	is >> obj._text;
	is >> obj._sender;
	is >> obj._receiver;
	return is;
}

std::fstream& operator <<(std::fstream& os, const Message& obj){
	os << obj._text << ' ';
	os << obj._sender << ' ';
	os << obj._receiver << ' ';
	return os;
}
