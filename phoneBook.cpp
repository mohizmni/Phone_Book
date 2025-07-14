#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

class Contact{
public:
    string name;
    map <string, string> phones;

    Contact(string _name):name(_name){}
    
    void addPhonenumber(const string& type , string& phoneNumber){
        phones[type] = phoneNumber;
    }
    void removePhonenumber(string& type){
        phones.erase(type);
    }
    void editphoneNumber(const string& type ,const string& newnumber){
        auto it = phones.find(type);
        if (it != phones.end()) {
            it->second = newnumber;
        }
    }
    void display()const{
        cout << "Name: " <<name <<endl;
        for(auto& phone: phones){
            cout << " " << phone.first << " " << phone.second << endl;
        }
    }
};

class phoneBook{
private:
    vector<Contact> contacts;
    vector<Contact> favorite;

public:
    void addContact(const string& name){
        contacts.emplace_back(name);
    }
    void deleteContact(string& name){
        auto it = remove_if(contacts.begin(), contacts.end(),
            [&name](const Contact& c) { return c.name == name; });
        if (it != contacts.end()) {
            contacts.erase(it, contacts.end());
            cout << name << " deleted from phoneBook!\n";
        }
        else {
            cout << name << " doesn't exist in phoneBook\n";
        }
        deleteFromFavorite(name);
    }
    void editContact(const string& oldname,const string& newname){
        for(auto& contact: contacts){
            if(contact.name == oldname){
                contact.name = newname;
                cout << "Edited successfully" << endl;
                for (auto& favcontact : favorite) {
                    if (favcontact.name == oldname) {
                        favcontact.name = newname;
                    }
                }
                return;
            }
        }
        cout << "Contact not found\n";
    }

    void addphonetoContact(const string& name ,const string& type, string& phone){
        for(auto& contact: contacts){
            if(contact.name == name){
                contact.addPhonenumber(type , phone);
                cout << "added to phoneBook" <<endl;
                return;
            }
        }
        cout << "Contact not found\n";
    }
    
    void RemovephonenumberContact(const string& name,string& type){
        for(auto& contact: contacts){
            if(contact.name == name){
                contact.removePhonenumber(type);
                cout << "remooved\n";
                return;
            }
        }
        cout << "Contact not found\n";
    }
   
    void elditphonenumber(const string& name, const string& type, const string& newphone){
        for(auto& contact: contacts){
            if(contact.name == name){
                contact.editphoneNumber(type, newphone);
                cout << "edited\n";
                return;
            }
        }
        cout << "Contact not found\n";
    }
    
    void addToFavorite(const string& name){
        for(auto& contact: contacts){
            if(contact.name == name){     
               if (find(favorite.begin(), favorite.end(), name) == favorite.end()) {
                    favorite.push_back(name);
                    cout << "Added to favorite\n";
                }
                else {
                    cout << "Already in favorite\n";
                }
                return;
            }
        }
        cout << "Contact not found\n";
    }
     
    void deleteFromFavorite(const string& name){
        auto it = remove(favorite.begin(), favorite.end(), name);
        if (it != favorite.end()) {
            favorite.erase(it, favorite.end());
            cout << "Removed from favorite\n";
        }
        else {
            cout << "Name not found in favorite\n";
        }
    }
    
    void showFavorite() const{
        cout << "Favorite Contacts:\n";
        for (const auto& contact : favorite) {
            cout << " " << contact.name << endl;
        }
    }
    
    void searchContacts(const string& name) const{
        cout << "Search results:\n";
        for(auto& contact: contacts){
            if(contact.name.find(name) == 0) { //searching from 0 index of the name
                cout << contact.name << endl;
            }
        }
    }
    
    void displayPhoneNumbers(const string& contactname) const {
        for(auto& contact: contacts){
            if(contact.name == contactname){
                contact.display();
                return;
            }
        }
        cout << "Contact not found\n";
    }
    
    void showContacts() const {
        vector<Contact> sorted = contacts;
        sort(sorted.begin(), sorted.end(), [](const Contact& a, const Contact& b)
            { return a.name  < b.name;}); 
            cout << "Contacts List:\n";
        for (const auto& contact: sorted){
            cout << contact.name << endl;
        }
    }
   
};

int main()
{
    phoneBook pbook;

    //menu:
    while(true){
        cout <<"chose your option:\n";
        cout <<"1. insert, delete, edit (Contact)\n";
        cout <<"2. insert, delete, edit (Numbers)\n";
        cout <<"3. add/delete to favorite List";
        cout <<"4. show favorites\n";
        cout <<"5. show ordered contacts\n";
        cout <<"6. show all numbers\n";
        cout << "7. search contacts\n";
        cout << "0. Exit\n";

        int option;
        cin >> option;
        string name;

        switch(option){
            case 1:{ 
                int chois;
                cout << "1. inert contact\n2. delete contact\n3. edit contact\n";
                cin >> chois;
                if(chois == 1){
                    cout << "Enter name: \n";
                    cin >> name;
                    pbook.addContact(name);
                } 
                else if(chois == 2){
                        cout << "Enter name: \n";
                        cin >> name;
                        pbook.deleteContact(name);
                }
                else if(chois == 3){
                        cout << "Enter old name: \n";
                        cin >> name;
                        cout << "Enter new name\n";
                        string newname;
                        cin >> newname;
                        pbook.editContact(name , newname);
                } else {
                    cout <<"invalid  input" <<endl;
                }
                break;
            }
            case 2:{
                int chois;
                cout << "1. inert phonenumber\n2. delete phonenumber\n3. edit phonenumber\n";
                cin >> chois;
                if (chois == 1){
                    cout << "Enter name: \n";
                    cin >> name;
                    cout << "Enter phone type(Work ,Home,..)\n";
                    string type;
                    cin >>type;
                    cout <<"Enter Phone number\n";
                    string phone;
                    cin >> phone;
                    pbook.addphonetoContact(name , type ,phone); 
                } 
                else if(chois == 2){
                    cout << "enter contacts name\n";
                    string name;
                    cin >> name;
                    cout <<"Enter Phone type\n";
                    string type;
                    cin >> type;
                    pbook.RemovephonenumberContact(name , type);
                }
                else if(chois == 3){
                    cout << "entetr name\n";
                    string name;
                    cin >> name;
                    cout << "enter phoonne type\n";
                    string type;
                    cin >> type;
                    cout <<"Enter Phone number\n";
                    string newphone;
                    cin >> newphone;
                    pbook.elditphonenumber(name ,type, newphone);
                }
                else {
                cout << "Invalid input\n";
                }
                break;
            }
            case 3:{
                cout << "enter your chois:\n";
                cout << "1. add to favorite\n2. delete from favorite\n";
                int option;
                cin >> option;
                if(option == 1){
                    cout << "enter contact name\n";
                    string name;
                    cin >> name;
                    pbook.addToFavorite(name);
                    break;
                } else if(option == 2){
                    cout << "enter Contact name\n";
                    string name;
                    cin >> name;
                    pbook.deleteFromFavorite(name);
                    break;
                } else {
                    cout <<"invalid input\n";
                }
            }
            case 4:{
                pbook.showFavorite();
                break;
            }
            case 5:{
                pbook.showContacts();
                break;
            }
            case 6:{
                cout << "Enter naem\n";
                string name;
                cin >> name;
                pbook.displayPhoneNumbers(name);
                break;
            }
            case 7:{
                cout << "Enetr name to search\n";
                string name;
                cin >> name;
                pbook.searchContacts(name);
                break;
            }
            case 0:{
                cout << "exiting";
                return 0;
            }
            default:{
                cout << "invalid input\n";
                break;
            }
        }
    }
}

