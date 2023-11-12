#include "shell.h"

/**
 * _myexit - exits the shell
 * @info: Structure containing potential arguments.
 *
 * Return: Exits with a given exit status:
 *         (0) if info->argv[0] != "exit"
 *         (-2) if exit command with a specific status
 */
int _myexit(info_t *info)
{
    int exit_status;

    if (info->argv[1])  /* If there is an exit argument */
    {
        exit_status = _erratoi(info->argv[1]);

        if (exit_status == -1)
        {
            info->status = 2;
            print_error(info, "Illegal number: ");
            _eputs(info->argv[1]);
            _eputchar('\n');
            return (1);
        }

        info->err_num = exit_status;
        return (-2);  /* Signal for exit with a specific status */
    }

    info->err_num = -1;
    return (-2);  /* Signal for normal exit */
}

/**
 * _mycd - changes the current directory of the process
 * @info: Structure containing potential arguments.
 *
 * Return: Always 0
 */
int _mycd(info_t *info)
{
    char *dir, buffer[1024];
    int chdir_ret;

    if (!info->argv[1])
    {
        dir = _getenv(info, "HOME=");
        if (!dir)
            chdir_ret = chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
        else
            chdir_ret = chdir(dir);
    }
    else if (_strcmp(info->argv[1], "-") == 0)
    {
        if (!_getenv(info, "OLDPWD="))
        {
            _puts(getcwd(buffer, 1024));
            _putchar('\n');
            return (1);
        }
        _puts(_getenv(info, "OLDPWD=")), _putchar('\n');
        chdir_ret = chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
    }
    else
        chdir_ret = chdir(info->argv[1]);

    if (chdir_ret == -1)
    {
        print_error(info, "can't cd to ");
        _eputs(info->argv[1]), _eputchar('\n');
    }
    else
    {
        _setenv(info, "OLDPWD", _getenv(info, "PWD="));
        _setenv(info, "PWD", getcwd(buffer, 1024));
    }

    return (0);
}

/**
 * _myhelp - prints help message
 * @info: Structure containing potential arguments.
 *
 * Return: Always 0
 */
int _myhelp(info_t *info)
{
    (void)info; /* Suppress unused parameter warning */
    
    _puts("Help message: Function not yet implemented\n");
    return (0);
}

