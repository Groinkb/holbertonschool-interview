/**
 * wildcmp - compares two strings and returns 1 if the strings
 *           can be considered identical, otherwise return 0
 * @s1: first string to compare
 * @s2: second string to compare - can contain the special character *
 *
 * Return: 1 if the strings can be considered identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
    /* If both strings are empty, they are identical */
    if (*s1 == '\0' && *s2 == '\0')
        return (1);

    /* If s2 has a '*' */
    if (*s2 == '*')
    {
        /* If the next character in s2 is also '*', skip it */
        if (*(s2 + 1) == '*')
            return (wildcmp(s1, s2 + 1));

        /* Skip characters in s1 until a match is found for the rest of s2 */
        if (*s1 == '\0')
            return (wildcmp(s1, s2 + 1));

        /* Two possibilities: either we use the * or we don't */
        return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
    }

    /* If current characters match, continue with next characters */
    if (*s1 == *s2)
        return (wildcmp(s1 + 1, s2 + 1));

    /* If we reach here, the strings are not identical */
    return (0);
}