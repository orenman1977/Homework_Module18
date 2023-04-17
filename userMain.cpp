// используем класс юзер

#include <memory>
#include "user.hpp"
#include "message.hpp"
using namespace std;

int main() {
	unique_ptr<User>  user = make_unique<User>("user1","login1","pass1");
	unique_ptr<Message> message = make_unique<Message>("text1","sender1","receiver1");
	std::string choose;
	while(true){
		cout << "1 Пользователи\n2 Сообщения\n3 Выход\n";
		getline(cin, choose);
		if(choose.size() > 1) continue;
		if(choose[0] == '1' || choose[0] =='2' || choose[0] == '3') {
			switch(choose[0]){
				case '1':
                user->enter();
				break;
				case '2':
                message->enter();
				break;
				case '3':
				cout << "End program\n";
				return 0;
			}
		}
	}
}
