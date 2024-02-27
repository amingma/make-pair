#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
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
void shuffle(vector<string>& names) {
    int n = names.size();
    for (int i=0; i<n; i++) {
        int t = rand()%n;
        string tmp = names[t];
        names[t] = names[i];
        names[i] = tmp;
    }
}
void generateOrder() {
    vector<string> names = readNames();
    shuffle(names);
    if (names.size()%2==1) {
        names.push_back("Bye");
    }
    map<string, int> index;
    int n = names.size();
    for (int i=0; i<n; i++) {
        index[names.at(i)] = i;
    }
    vector<vector<string>> pairs(n);
    for (int i=0; i<n-1; i++) {
        string tmp = names[n-1];
        for (int j=n-1; j>=1; j--) {
            if (j!=1) {
                names[j] = names[j-1];
            }
            else {
                names[j] = tmp;
            }
        }
        for (int j=0; j<n; j++) {
            pairs[index[names.at(j)]].push_back(names.at(n-1-j));
        }
    }
    for (int i=0; i<n; i++) {
        if (names.at(i)=="Bye") {
            continue;
        }
        cout << names.at(i) << ": ";
        for (string s: pairs[index[names.at(i)]]) {
            cout << s << " ";
        }
        cout << "\n";
    }
}
int main() {
    generateOrder();
    return 0;
}