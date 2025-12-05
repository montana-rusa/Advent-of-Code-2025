#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


vector<string> get_data() {
    fstream file("input.txt");
    vector<string> lines;

    string line;
    while (getline(file, line)) {
        lines.push_back(line); }

    return lines; }


int main() {
    int dial = 50;
    int answer = 0;
    int num;
    vector<string> lines = get_data();
    char direction;

    for (auto line: lines) {
        direction = line[0];
        num = stoi(line.substr(1));

        if (direction == 'L') {
            dial -= num;
        } else { dial += num; }

        while (dial < 0) { dial += 100; }
        while (dial > 99) { dial -= 100; }
        if (dial == 0) { answer += 1; } }

    cout << to_string(answer);
    return 0; }