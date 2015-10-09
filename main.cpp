#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include "helperfunctions.h"

using namespace std;

void load();
void menu();
void save();

void addEmail();
void displayEmailList();
void printListToFile();
void removeEmail();
void sortEmail();

static string ldr = "";
static vector<string> emailList;
static int choice = 0;
static string loadname = "";

int main() {
    load();
    while (choice != 6) {
        menu();
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
            sortEmail();
            break;
        case 6:
            save();
            break;
        default:
            cout << "how did you get here?";
        }
    }
    return 0;
}

void load() {
    ifstream inp;
    cout << "Enter the name of your file: ";
    cin >> ldr;
    inp.open((ldr + ".dat").c_str());
    if (inp.is_open()) {
        loadname = ldr;
        while (inp >> ldr) {
            emailList.push_back(ldr);
        }
        cout << "\nLoad successful!\n";
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
         << " 5. Sort List\n"
         << " 6. Save and Quit\n\n";
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
            cout << "No text entered try again.\n\n";
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
        for (auto it = begin(emailList); it != end(emailList); ++it) {
            outs << *it << "; ";
        }
        outs.close();
    }
    cout << "\n Print to File complete! Look for Latest_Email_List.txt \n\n";
}

void removeEmail() {
    bool r_complete = false;
    while (!r_complete) {
        cout << "Email to Remove(leave blank to exit): ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(cin, ldr);
	if (ldr == "") r_complete = true;
        else { 
		for (auto it = begin(emailList); it != end(emailList); it++) {
            		if (*it == ldr) {
                  		emailList.erase(it);
                		simpleClearScreen();
 	               		cout << ldr << " removed.\n";
        	    		r_complete = true;
	    		}
        	}
	}	
    }
}

void sortEmail() {
    sort(emailList.begin(), emailList.end());
    simpleClearScreen();
    cout << "Sort Complete!\n\n";
}

void save() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    ofstream outs;
    if (loadname == "") {
	cout << "Enter name to save as: ";
        getline(cin, ldr, '\n');
        outs.open((ldr + ".dat").c_str());
    } else outs.open((loadname + ".dat").c_str());
    if (outs.is_open()) {
        for (auto it = begin(emailList); it != end(emailList); it++) {
            outs << *it << endl;
            cout << *it << " written" << "\n";
        }
        cout << "Save complete.\n";
        outs.close();
    } else cout << "save failed";

}
