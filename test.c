/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#include <stdio.h>
#include <sys/wait.h>
 
int test_printf(char *format, float value)
{
    char buf[1024];
    char expected[1024];
    int total = 0;
    int bytes;
    int fd[2];
    pid_t pid;
 
    if (pipe(fd) == -1)
        return -1;
    if ((pid = fork()) < 0)
        return -1;
    if (pid > 0) {
        close(fd[1]);
        while ((bytes = read(fd[0], buf + total, sizeof(buf) - total - 1)) > 0)
            total += bytes;
        close(fd[0]);
        wait(0);
        sprintf(expected, format, value);
        if (total > 0)
            buf[total] = '\0';
        if (my_strcmp(buf, expected) == 0) {
//            printf("\e[32;1mSUCCESS\e[0;1m:\e[0m for ");
//            printf("\e[0;1m%s\e[0m, got \e[0;1m%s\e[0m\n", expected, buf);
            return 0;
        }
        printf("\e[31;1mFAIL\e[0;1m:\e[0m for ");
        printf("\e[0;1m%s\e[0m, got \e[0;1m%s\e[0m\n", expected, buf);
        return 1;
    } else {
        close(fd[0]);
        dup2(fd[1], 1);
        my_printf(format, value);
        close(fd[1]);
        _exit(0);
    }
    return -1;
}
 
int main()
{
    int failures = 0;
    int total = 0;
 
    printf("\n\e[1m[\e[34m====\e[0;1m] Starting tests...\e[34m\n\n");
    for (double f = -1.0; f < 1; f += 0.001, total++)
        failures += test_printf("%G", (float)f);
    printf("\n\e[1m[\e[34m====\e[0;1m] Synthesis: Tested: \e[34m");
    printf("%d\e[0;1m | Passing: \e[32m%d", total, total - failures);
    printf("\e[0;1m | Failing: \e[31m%d\e[0;1m\n\n", failures);
    return 0;
}
