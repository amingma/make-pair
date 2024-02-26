#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> readNames(string fileName) {
    ifstream ifs(fileName);
    vector<string> names;
    string name = "Ming";
    while(getline(ifs, name)) {
        names.push_back(name);
    }
    return names;
}
vector<string> readNames() {
    vector<string> names;
    string cont = "Y";
    string name = "Ming";
    do {
        cout << "Enter name: ";
        getline(cin, name);
        names.push_back(name);
        cout << "Add more? (y/n): ";
        getline(cin, cont);
    }
    while(cont == "Y" || cont == "y");
    return names;
}
int main() {
    ofstream ofs("./schedule.txt");
    vector<string> test = readNames();
    
    return 0;
}