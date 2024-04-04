#include <XPD.h>

#include "command_library.h"
#include "io.h"
#include "main.h"


bool compare_string( char *str1,  char *str2) {
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

void echo_command(char *args[], IO &outputStream) {
    puts(outputStream, "\n\r"); 
    int i; 
    for (i=0; args[i] != "\0"; i++) {
        puts(outputStream, args[i]);
        puts(outputStream, " ");

    }
    puts(outputStream, "\n\r"); 
}

void save_command(IO &outputStream) {
    puts(outputStream, "\n\rSave command\n\r");
}

void load_command(IO &outputStream) {
    puts(outputStream, "\n\rLoad command\n\r");
}

void copy_command(IO &outputStream) {
    puts(outputStream, "\n\rCopy command\n\r");
}

void scratch_command(IO &outputStream) {
    puts(outputStream, "\n\rScratch command\n\r");
}

void invalid_command(IO &outputStream) {
    puts(outputStream, "\n\rInvalid command\n\r");
}


void search_command( char* command, char *args[], IO &outputStream) {

    if (compare_string(command, "echo")) {
        echo_command(args, outputStream);
    }

    else if (compare_string(command, "save")) {
        save_command(outputStream);
    }

    else if (compare_string(command, "load")) {
        load_command(outputStream);
    }

    else if (compare_string(command, "copy")) {
        copy_command(outputStream);
    }

    else if (compare_string(command, "scratch")) {
        scratch_command(outputStream);
    }

    else {
        invalid_command(outputStream);
    }
}