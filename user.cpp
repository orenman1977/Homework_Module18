// Класс юзер

#include "user.hpp"
using namespace std;
namespace fs = std::filesystem;

void User::enter()
{
    string choose;
	while(true){
		cout << "1 Сохранить User в файл\n2 Прочитать User из файла\n3 Выход\n";
		getline(cin, choose);
		if(choose.size() > 1) continue;
		if(choose[0] == '1' || choose[0] =='2' || choose[0] == '3') {
			switch(choose[0]){
				case '1':
                userTofile();
				break;
				case '2':
                userFromfile();
				break;
				case '3':
				return;
			}
		}
	}
}

void User::userTofile()
{
    fstream user_file = fstream("user", ios::out | ios::trunc);
    if(!user_file.is_open()){
        cout << "Error open/create file user\n";
        return;
    }
    //permissions
    fs::permissions("user", fs::perms::owner_all);
    // write
    user_file << *this;
    user_file.close();
}

void User::userFromfile()
{
    fstream user_file = fstream("user", ios::in);
    if(!user_file.is_open()) {
        cout << "\nNo user file\n\n";
        return;
    }
    // read file
    user_file.seekg(0, ios_base::beg);
    user_file >> *this;
    user_file.close();
}

fstream& operator >>(fstream& is, User& obj)
{
	is >> obj._name;
	is >> obj._login;
	is >> obj._pass;
	return is;
}

fstream& operator <<(fstream& os, const User& obj)
{
	os << obj._name;
	os << ' ';
	os << obj._login;
	os << ' ';
	os << obj._pass << '\n';
	return os;
}
