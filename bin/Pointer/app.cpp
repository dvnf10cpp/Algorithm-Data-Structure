#include <bits/stdc++.h>

using std::string;
using std::vector;
using std::cout;
using std::cin;

class User {
    private:
    string username;
    string password;

    public:
    User(string username, string password) : username(username), password(password) {

    }

    bool isMatch(string password) {
        return password == this->password;
    }

    string getUsername() {
        return username;
    }

    string getPassword() {
        return password;
    }

    void setUsername(string username) {
        this->username = username;
    }

    void setPassword(string password) {
        this->password = password;
    }
};

class Database {
    private:
    vector<User*> users;  

    public:
    void add(User* user) { 
        users.push_back(user);
    }

    void print() {
        if (!users.size()) {
            cout << "DATABASE IS EMPTY\n";
            return;
        }
        for(int i = 0; i < users.size(); i++) {
            cout << "|" << i+1 << "| [" << users[i]->getUsername() << "]\n";
        }
    }

    User* get(int index){
        return users[index];
    }

    int size() {
        return users.size();
    }

    void remove(int index) {
        User* user = users[index];
        users.erase(users.begin() + index);

        delete user;
        user = nullptr;
    }
};

class Route {
    private:
    static Database* db;
    public:

    static void init() {
        db = new Database();
    }

    static void get() {
        cout << "LIST USERS\n";
        cout << "===================================\n";
        db->print();
        cout << "===================================\n";
    }

    static void post() {
        string username,password;
        cin.ignore();
        cout << "Masukkan username : ";
        getline(cin, username, '\n');
        cout << "Masukkan password : ";
        getline(cin, password, '\n');
        db->add(new User(username, password));
    }

    static void patch() {
        string username, password;
        int index;
        db->print();
        cout << "===================================\n";
        do {
            cout << "Masukkan index yang ingin diupdate : ";
            cin >> index;
        } while(index < 0 || index > int(db->size()));
        User* user = db->get(index - 1);
        cout << "PRESS ENTER IF YOU DONT WANT TO UPDATE\n";
        cout << "===================================\n";
        cin.ignore();
        cout << "Masukkan username : ";
        getline(cin, username, '\n');
        cout << "Masukkan password : ";
        getline(cin, password, '\n');
        if (!username.empty())
            user->setUsername(username);
        if (!password.empty())
            user->setPassword(password);
    }

    static void remove() {
        if(!db->size()) {
            cout << "Tidak ada yang bisa dihapus\n";
            return;
        }
        string username, password;
        int index;
        db->print();
        cout << "===================================\n";
        do {
            cout << "Masukkan index yang ingin dihapus : ";
            cin >> index;
        } while(index < 0 || index > int(db->size()));
        db->remove(index - 1);
    }

    static void clear() {
        delete db;
        db = nullptr;
    }
};

Database* Route::db = nullptr;

int main() {
    char c = 'y'; int index;
    Route::init();
    do {
        cout << "===================================\n";
        cout << "1. GET\n";
        cout << "2. POST\n";
        cout << "3. PATCH\n";
        cout << "4. REMOVE\n";
        cout << "===================================\n";
        cout << "Masukkan pilihan : ";
        cin >> index;
        switch (index)
        {
            case 1 : 
                Route::get();
                break;
            case 2 :    
                Route::post();
                break;
            case 3 : 
                Route::patch();
                break;
            case 4 : 
                Route::remove();
                break;
            default:
                break;
        }
        cout << "Apakah masih ingin menggunakan program ? : ";
        cin >> c; c=tolower(c);
    } while(c!='n');

    Route::clear();

    return 0;
}