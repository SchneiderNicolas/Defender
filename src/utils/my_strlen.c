/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** my_strlen
*/

unsigned int my_strlen(char const *str)
{
    unsigned int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        count += 1;
    return (count);
}