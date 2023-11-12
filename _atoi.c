#include "shell.h"

/**
 * check_interactive - returns true if the shell is in interactive mode
 * @info: struct holding shell information
 *
 * Return: 1 if in interactive mode, 0 otherwise
 */
int check_interactive(info_t *info)
{
    return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_separator - checks if character is a separator
 * @c: the char to check
 * @separators: the separator string
 * Return: 1 if true, 0 if false
 */
int is_separator(char c, char *separators)
{
    while (*separators)
        if (*separators++ == c)
            return (1);
    return (0);
}

/**
 * is_alpha - checks for alphabetic character
 * @character: The character to input
 * Return: 1 if character is alphabetic, 0 otherwise
 */
int is_alpha(int character)
{
    return ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z'));
}

/**
 * _atoi - converts a string to an integer
 * @str: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */
int _atoi(char *str)
{
    int i, sign = 1, output = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '-')
            sign *= -1;

        if (str[i] >= '0' && str[i] <= '9')
        {
            output *= 10;
            output += (str[i] - '0');
        }
    }

    return (sign * output);
}

