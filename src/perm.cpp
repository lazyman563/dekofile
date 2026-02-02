#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void execute_with_power(string command, bool use_fa) {
    if (command.empty()) return;
    if (use_fa) { system(("sh -c \"" + command + "\"").c_str()); return; }

    if (use_fa) {
        // Lógica de Localhost ativada via IMPORT F_A
        // O sistema recebe o comando como se fosse via bridge de depuração
        string fa_command = "sh -c \"" + command + "\""; 
        system(fa_command.c_str());
    } else {
        // Execução padrão sem privilégios de ponte
        system(command.c_str());
    }
}
