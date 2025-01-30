#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ChatApp {
private:
    string username;
    vector<string> messages;

public:
    ChatApp(string user) : username(user) {}

    void sendMessage(string message) {
        messages.push_back(username + ": " + message);
    }

    void displayChat() {
        cout << "\nChat History:\n";
        for (auto& msg : messages) {
            cout << msg << endl;
        }
    }

    void startChat() {
        string message;
        while (true) {
            cout << username << ": ";
            getline(cin, message);
            if (message == "exit") {
                break;
            }
            sendMessage(message);
            displayChat();
        }
    }
};

int main() {
    string user;
    cout << "Enter your username: ";
    getline(cin, user);
    ChatApp chat(user);

    cout << "Type 'exit' to quit the chat.\n";
    chat.startChat();

    return 0;
}
