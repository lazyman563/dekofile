#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
bool FAKE_ADB_ENABLED = false;
#include <algorithm>

using namespace std;

// Function to check if a command exists in the environment
bool cmd_exists(string cmd) {
    string check = "command -v " + cmd + " > /dev/null 2>&1";
    return (system(check.c_str()) == 0);
}

// Function to trim whitespace from strings
string trim(const string& s) {
    size_t first = s.find_first_not_of(" \t\r\n");
    if (string::npos == first) return s;
    size_t last = s.find_last_not_of(" \t\r\n");
    return s.substr(first, (last - first + 1));
}

void process_line(string line) {
    line = trim(line);
    if (line.empty() || line == "EnD") return;
    if (line.find("IMPORT F_A") == 0) { FAKE_ADB_ENABLED = true; return; }

    // 1. IMPORT Logic: Check and install dependencies
    if (line.find("IMPORT") == 0) {
        stringstream ss(line);
        string key, pkg, mode;
        ss >> key >> pkg >> mode; // IMPORT [pkg] [mode]
        
        if (!cmd_exists(pkg)) {
            // Try Termux pkg first, then fall back to apt
            string install_cmd = "pkg install " + pkg + " -y || apt-get install " + pkg + " -y";
            system(install_cmd.c_str());
        }
        return;
    }

    // 2. RUN ./DF IN: Logic
    // This part ensures that the engine acknowledges the subfolders/files scope
    if (line.find("RUN ./DF IN:") == 0) {
        // The engine naturally operates in the current directory. 
        // We just signal the mapping is active.
        return;
    }

    // 3. Direct Execution (G++, sudo, or any raw bash command)
    // The engine doesn't babysit the user. If you put it there, it runs.
    system(line.c_str());
}

int main(int argc, char* argv[]) {
    // Silent mode: No usage prints, just execution.
    if (argc < 2) return 1;

    ifstream file(argv[1]);
    if (!file.is_open()) return 1;

    string line;
    while (getline(file, line)) {
        process_line(line);
    }

    file.close();
    return 0;
}
