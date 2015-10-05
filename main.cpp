#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include "helperfunctions.h"

using namespace std;

void load();
void menu();
void action();
void save();

void addEmail();
void displayEmailList();
void printListToFile();
void removeEmail();

static string ldr = "";
static vector<string> emailList;
static int choice = 0;
static string loadname = "";

int main()
{
    load();
    while (choice != 6) {
        menu();
        action();
    }
    save();
    return 0;
}

void load() {
    ifstream inp;
    cout << "Enter the name of your file: ";
    cin >> ldr;
    inp.open((ldr + ".dat").c_str());
    if (inp.is_open()) {
        while (inp >> ldr) {
            emailList.push_back(ldr);
        }
        cout << "\nLoad successful!\n";
        loadname = ldr;
        inp.close();
    } else cout << "\nLoad Failed. Starting a New File... \n";
    pressEnterToContinue();
}

void menu() {
    cout << "--Main Menu--\n\n"
         << " 1. Add Email\n"
         << " 2. View List\n"
         << " 3. Export List to File\n"
         << " 4. Remove Email\n"
         << " 5. dont use yet - Sort List\n"
         << " 6. Save and Quit\n\n";
}

void action() {
    choice = getNumber(" Choice(1-6): ", 1, 6);
    switch (choice) {
    case 1:
        addEmail();
        break;
    case 2:
        displayEmailList();
        break;
    case 3:
        printListToFile();
        break;
    case 4:
        removeEmail();
        break;
    case 5:
       // emailList.sort(1, emailList.size());
        break;
    case 6: save();
    default: exit(1);
    }
}

void addEmail() {
    bool done = false;
    do {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Email Address: ";
        getline(cin, ldr);
        if (ldr != "") {
            emailList.push_back(ldr);
            simpleClearScreen();
            cout << ldr << " added!\n\n";
            done = true;
        } else {
            cout << "Not a valid address.\n\n";
        }
    } while (done == false);
}

void displayEmailList() {
    simpleClearScreen();
    for (auto it = begin(emailList); it != end(emailList); it++) {
        cout << " " << (distance(emailList.begin(), it) + 1) << ". " << *it << endl;
    }
    cout << "\n";
}

void printListToFile() {
    simpleClearScreen();
    ofstream outs;
    outs.open("Latest_Email_List.txt");
    if (outs.is_open()) {
        for (auto it = begin(emailList); it != end(emailList); it++) {
            outs << *it << "; ";
        }
        outs.close();
    }
    cout << "\n Print to File complete! Look for Latest_Email_List.txt \n\n";
}

void removeEmail() {
    do {
        cout << "Email to Remove(leave blank to exit): ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(cin, ldr);
        for (auto it = begin(emailList); it != end(emailList); it++) {
            if (*it == ldr) {
                emailList.erase(it);
                simpleClearScreen();
                cout << ldr << " removed.\n";
            }
        }
    } while (ldr != "");
}

void save() {
    ofstream outs;
    if (loadname == "") cout << "enter name to save as: ";
    cin >> ldr;
    outs.open((ldr + ".dat").c_str());
    if (outs.is_open()) {
        for (auto it = begin(emailList); it != end(emailList); it++) {
            outs << *it << "\n";
        }
        cout << "Save complete. Unit 5 out. \n";
    } else cout << "save failed";
}
