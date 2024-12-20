#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // Typedef for easier map declaration
    typedef map<string, float> mapType;
    mapType populationMap;

    // Inserting data into the map
    populationMap.insert(make_pair("Maharashtra", 125));          // Population in millions
    populationMap.insert(make_pair("Uttar Pradesh", 225));
    populationMap.insert(make_pair("Bihar", 120));
    populationMap.insert(make_pair("West Bengal", 100));
    populationMap.insert(make_pair("Madhya Pradesh", 90));
    populationMap.insert(make_pair("Tamil Nadu", 80));
    populationMap.insert(make_pair("Rajasthan", 78));
    populationMap.insert(make_pair("Andhra Pradesh", 53));
    populationMap.insert(make_pair("Odisha", 47));
    populationMap.insert(make_pair("Kerala", 38));
    populationMap.insert(make_pair("Telangana", 37));
    populationMap.insert(make_pair("Assam", 35));
    populationMap.insert(make_pair("Jharkhand", 38));
    populationMap.insert(make_pair("Karnataka", 68));
    populationMap.insert(make_pair("Gujarat", 70));
    populationMap.insert(make_pair("Punjab", 31));
    populationMap.insert(make_pair("Chhattisgarh", 30));
    populationMap.insert(make_pair("Haryana", 29));
    populationMap.insert(make_pair("UT Delhi", 19));
    populationMap.insert(make_pair("UT Jammu and Kashmir", 14));
    populationMap.insert(make_pair("Uttarakhand", 12));
    populationMap.insert(make_pair("Himachal Pradesh", 8));
    populationMap.insert(make_pair("Tripura", 4));
    populationMap.insert(make_pair("Meghalaya", 4));
    populationMap.insert(make_pair("Manipur", 3));
    populationMap.insert(make_pair("Nagaland", 2));
    populationMap.insert(make_pair("Goa", 2));
    populationMap.insert(make_pair("Arunachal Pradesh", 2));
    populationMap.insert(make_pair("UT Puducherry", 2));
    populationMap.insert(make_pair("Mizoram", 1));
    populationMap.insert(make_pair("UT Chandigarh", 1));
    populationMap.insert(make_pair("Sikkim", 1));
    populationMap.insert(make_pair("UT Dadra and Nagar Haveli and Daman and Diu", 1));
    populationMap.insert(make_pair("UT Andaman and Nicobar Islands", 1));
    populationMap.insert(make_pair("UT Lakshadweep", 0.0003));   // Population less than 1 million
    populationMap.insert(make_pair("UT Ladakh", 0.00006));

    // Display total number of states and UTs with populations
    cout << "Total number of states and UTs in India: " << populationMap.size() << '\n';
    cout << "======== Population of states and UTs in India =========\n";

    // Iterating and displaying the map content
    for (const auto& entry : populationMap) {
        cout << entry.first << ": " << entry.second << " million\n";
    }

    char choice;
    do {
        string state;
        cout << "\nEnter the name of the state/UT you want to know the population of: ";
        cin >> state;

        // Find the state/UT in the map
        mapType::iterator iter = populationMap.find(state);
        if (iter != populationMap.end()) {
            cout << state << "'s population is " << iter->second << " million\n";
        } else {
            cout << "State/UT not found in populationMap.\n";
        }

        // Ask if the user wants to continue
        cout << "Do you wish to continue? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    // Clearing the map at the end
    populationMap.clear();
    
    return 0;
}
