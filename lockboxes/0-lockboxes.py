#!/usr/bin/python3
"""
Ce module contient une solution pour le problème des boîtes verrouillées.

Le problème:
- On a n boîtes numérotées de 0 à n-1
- Chaque boîte peut contenir des clés pour d'autres boîtes
- Une clé avec le même numéro qu'une boîte peut ouvrir cette boîte
- La première boîte (boxes[0]) est déjà déverrouillée
- Les clés sont des entiers positifs
- Il peut y avoir des clés qui n'ont pas de boîtes correspondantes
- Le but est de déterminer si toutes les boîtes peuvent être ouvertes

Approche:
1. On utilise un ensemble pour garder trace des boîtes qu'on peut ouvrir
2. On commence avec la boîte 0 qui est déjà déverrouillée
3. Pour chaque boîte qu'on peut ouvrir, on ajoute ses clés à l'ensemble
4. On continue jusqu'à ce qu'on ne puisse plus ouvrir de nouvelles boîtes
5. On vérifie si on peut ouvrir toutes les boîtes
"""


def canUnlockAll(boxes):
    """
    Détermine si toutes les boîtes peuvent être ouvertes.

    Args:
        boxes (list): Une liste de listes où chaque liste contient les clés
                     disponibles dans cette boîte

    Returns:
        bool: True si toutes les boîtes peuvent être ouvertes, False sinon
    """
    if not boxes or len(boxes) == 0:
        return False

    n = len(boxes)
    unlocked = {0}  
    keys_to_try = set(boxes[0]) 

    while keys_to_try:
        key = keys_to_try.pop()
        if key < n and key not in unlocked:
            unlocked.add(key)
            
            keys_to_try.update(boxes[key])

    
    return len(unlocked) == n
