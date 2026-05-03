#include <iostream>
#include <vector>
#include <string>
#include <random>   // modern random library

using namespace std;

int main() {
    string name;

    // Ask user for input
    cout << "Enter your name: ";
    getline(cin, name);

    // Handle empty input
    if (name.empty()) {
        cout << "Invalid input" << endl;
        return 0;
    }

    // Store excuse templates
    vector<string> excuses = {
        "{name} couldn’t finish the assignment because the laptop updated for 6 hours.",
        "{name} was about to complete the homework when the Wi-Fi suddenly disappeared.",
        "{name}'s dog accidentally submitted the wrong file.",
        "{name} forgot the assignment at home while rushing to college.",
        "{name} was helping a friend and lost track of time.",
        "{name}'s system crashed right before saving the work.",
        "{name} got stuck in traffic and couldn’t reach on time.",
        "{name} had a power cut during the final submission.",
        "{name} misunderstood the deadline date.",
        "{name} was feeling unwell and couldn’t complete the task."
    };

    // Random number setup (better than rand())
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, excuses.size() - 1);

    // Select random excuse
    int randomIndex = dist(gen);
    string selectedExcuse = excuses[randomIndex];

    // Replace {name} with actual name
    size_t pos = selectedExcuse.find("{name}");
    if (pos != string::npos) {
        selectedExcuse.replace(pos, 6, name);
    }

    // Print result
    cout << "\n📌 Excuse Generator:\n";
    cout << selectedExcuse << endl;

    return 0;
}