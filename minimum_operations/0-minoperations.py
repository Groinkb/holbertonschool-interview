#!/usr/bin/python3
"""
Calcule le nombre minimal d'opérations nécessaires pour obtenir
exactement n caractères 'H' dans un fichier texte.
BM
"""


def minOperations(n):
    """
    Calcule le nombre minimal d'opérations nécessaires pour obtenir
    exactement n caractères 'H' dans un fichier texte.

    Args:
        n (int): Le nombre cible de caractères 'H'.

    Returns:
        int: Le nombre minimum d'opérations nécessaires. Si n'est pas possible
        à atteindre, retourne 0.
    """
    # Si n est inférieur ou égal à 1, le nombre d'opérations est 0.
    if n <= 1:
        return 0

    # Initialisation du nombre d'opérations.
    operations = 0
    # Diviseur initial pour la factorisation.
    divisor = 2

    # Tant que n est supérieur à 1.
    while n > 1:
        # Tant que n est divisible par le diviseur.
        while n % divisor == 0:
            # Ajoute le diviseur aux opérations.
            operations += divisor
            # Met à jour n.
            n //= divisor
        # Passe au diviseur suivant.
        divisor += 1

    # Retourne le nombre total d'opérations.
    return operations
