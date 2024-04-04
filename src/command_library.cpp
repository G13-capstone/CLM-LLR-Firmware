#include <XPD.h>

#include command_library.h

void search_command(const char* command, char *args[]) {
    switch(command) {

        case "echo":
            echo_command(args);
            break;
        
        case "save":
            save_command(args);
            break;
        
        default:
            invalid_command();
            break;
    }
}

void echo_command(char *args[]) {
    puts("Echo command\n");
}

void save_command() {
    puts("Save command\n");
}

void invalid_command() {
    puts("Invalid command\n");
}


int main() {
    return 0;
}