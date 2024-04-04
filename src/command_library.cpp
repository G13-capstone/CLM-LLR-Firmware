#include <XPD.h>

#include command_library.h

bool compare_string(char *str1, char *str2) {
    int i = 0;
    while (true) {
        if (str1[i] == '\0' && str2[i] == '\0') {
            return true;
        } else if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
}

void search_command(const char* command, char *args[]) {

    if (compare_string(command, "echo")) {
        echo_command(args);
    }

    else if (compare_string(command, "save")) {
        save_command();
    }

    else if (compare_string(command, "load")) {
        load_command();
    }

    else if (compare_string(command, "copy")) {
        copy_command();
    }

    else if (compare_string(command, "scratch")) {
        scratch_command();
    }

    // Invalid Command
    else {
        invalid_command();
    }
}

void echo_command(char *args[]) {
    puts("Echo command\n");
}

void save_command() {
    puts("Save command\n");
}

void load_command() {
    puts("Load command\n");
}

void copy_command() {
    puts("Copy command\n");
}

void scratch_command() {
    puts("Scratch command\n");
}

void invalid_command() {
    puts("Invalid command\n");
}


int main() {
    return 0;
}