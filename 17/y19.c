#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void new_cmd(void);
void open_cmd(void);
void close_cmd(void);
void close_all_cmd(void);
void save_cmd(void);
void save_as_cmd(void);
void save_all_cmd(void);
void print_cmd(void);
void exit_cmd(void);

int main(int argc, char *argv[])
{
    struct cmd {
        char *cmd_name;
        void (*cmd_pointer) (void);
    } file_cmd[] = {
        {"new",         new_cmd},
        {"open",        open_cmd},
        {"close",       close_cmd},
        {"close all",   close_all_cmd},
        {"save",        save_cmd},
        {"save as",     save_as_cmd},
        {"save all",    save_all_cmd},
        {"print",       print_cmd},
        {"exit",        exit_cmd},
    };

    if (argc == 1) {
        printf("Usage: %s [command]\n", argv[0]);
        return 0;
    }

    char *command = malloc(sizeof(argv[0]) + sizeof(argv[1]) + 1);

    strcpy(command, argv[1]);
    if (argc > 2) {
        strcat(command, " ");
        strcat(command, argv[2]);
    }

    int n = (int) sizeof(file_cmd) / sizeof(struct cmd);

    for (int i = 0; i < n; i++)
        if (strcmp(command, file_cmd[i].cmd_name) == 0) {
            (*file_cmd[i].cmd_pointer)();
            return 0;
        }

    printf("Command not found\n");

}

void new_cmd(void)
{
    printf("new_cmd\n");
}

void open_cmd(void)
{
    printf("open_cmd\n");
}

void close_cmd(void)
{
    printf("close_cmd\n");
}

void close_all_cmd(void)
{
    printf("close_all_cmd\n");
}

void save_cmd(void)
{
    printf("save_cmd\n");
}

void save_as_cmd(void)
{
    printf("save_as_cmd\n");
}

void save_all_cmd(void)
{
    printf("save_all_cmd\n");
}

void print_cmd(void)
{
    printf("print_cmd\n");
}

void exit_cmd(void)
{
    printf("exit_cmd\n");
}
