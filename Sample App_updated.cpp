#include <iostream>
#include <string>
#include <unordered_map>
#include <cstdlib>

using namespace std;
/// @brief 
unordered_map<string, string> users = {
    {"admin", "admin_pass"},
    {"user", "user_pass"}
};

void getUserInput(string& input) {
    cout << "Enter input: ";
    getline(cin, input);
}

int main() {
    string username;
    string password;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    if (users.find(username) != users.end() && users[username] == password) {
        cout << "Authentication successful! Welcome " << username << "!\n";

        string command;

        cout << "Enter a command to execute: ";
        cin.ignore(); // Clear the newline character
        getline(cin, command);

        if (command.length() > 0) {
            system(command.c_str());
        } else {
            cout << "Invalid command, nothing was executed.\n";
        }

        cout << "Enter the username whose password you want to view: ";
        string viewUsername;
        cin >> viewUsername;

        if (users.find(viewUsername) != users.end()) {
            cout << "Password for " << viewUsername << " is: " << users[viewUsername] << "\n";
        } else {
            cout << "User " << viewUsername << " does not exist!\n";
        }
    } else {
        cout << "Invalid username or password!\n";
    }

    return 0;
}
