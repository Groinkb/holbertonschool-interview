#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/**
 * is_digit_str - Vérifie si une chaîne est composée uniquement de chiffres
 * @str: La chaîne à vérifier
 *
 * Return: 1 si tous les caractères sont des chiffres, sinon 0
 */
int is_digit_str(char *str)
{
    while (*str)
    {
        if (!isdigit(*str))
        {
            return (0);
        }
        str++;
    }
    return (1);
}

/**
 * print_number - Imprime une chaîne de caractères représentant un grand nombre
 * @str: La chaîne à imprimer
 */
void print_number(char *str)
{
    while (*str)
    {
        _putchar(*str);
        str++;
    }
    _putchar('\n');
}

/**
 * mul - Multiplie deux grands nombres représentés sous forme de chaînes
*/