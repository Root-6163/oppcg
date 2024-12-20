#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // Define the map type and create the population map
    typedef map<string, int> maptype;
    maptype populationmap;

    // Insert values into the population map
    populationmap.insert(pair<string, int>("Maharashtra", 709387));
    populationmap.insert(pair<string, int>("Rajasthan", 298374));
    populationmap.insert(pair<string, int>("Kashmir", 234546));
    populationmap.insert(pair<string, int>("Punjab", 938472));

    // Display the size of the population map
    cout << "Size of population map: " << populationmap.size() << endl;

    // Prompt the user to search for a state
    string state_name;
    cout << "Enter the state name to search: ";
    cin >> state_name;

    // Find the state in the map
    maptype::iterator iter = populationmap.find(state_name);

    if (iter != populationmap.end()) {
        // If found, display the population
        cout << state_name << " population is " << iter->second << endl;
    } else {
        // If not found, display a message
        cout << "Key is not in the population map." << endl;
    }

    // Clear the map
    populationmap.clear();
    return 0;
}
