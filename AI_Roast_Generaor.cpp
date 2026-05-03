#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    string name;

    cout << "Enter your name: ";
    getline(cin, name);

    // Handle empty input
    if (name.empty()) {
        cout << "Invalid input. Please enter a valid name." << endl;
        return 0;
    }

    // Roast templates
    vector<string> roasts = {
        "{name} writes code so slow that even a turtle switched to Python.",
        "If procrastination were an Olympic sport, {name} would have gold.",
        "{name}'s debugging style is staring until the bug feels guilty.",
        "{name} doesn’t write bugs, they create unexpected features.",
        "{name}'s code has more issues than a reality TV show.",
        "Even AI gets confused trying to understand {name}'s logic.",
        "{name} compiles code like it's a lottery system.",
        "{name}'s code works... sometimes... on special occasions.",
        "{name} doesn’t fix bugs, they just rename them.",
        "If laziness had a face, it would be {name}."
    };

    // Seed random generator
    srand(time(0));

    // Pick random roast
    int index = rand() % roasts.size();
    string roast = roasts[index];

    // Replace {name} with actual name
    size_t pos = roast.find("{name}");
    while (pos != string::npos) {
        roast.replace(pos, 6, name);
        pos = roast.find("{name}");
    }

    // Output
    cout << "\n🔥 Roast:\n" << roast << endl;

    return 0;
}