#!/usr/bin/python3
"""
Module qui contient la fonction canUnlockAll pour résoudre le problème des boîtes verrouillées.
La fonction prend une liste de listes 'boxes' où chaque liste contient des clés (entiers)
permettant d'ouvrir d'autres boîtes. La première boîte (boxes[0]) est toujours déverrouillée.
Une clé avec le même numéro qu'une boîte permet d'ouvrir cette boîte.
La fonction retourne True si toutes les boîtes peuvent être ouvertes, False sinon.
"""


def canUnlockAll(boxes):
    """
    Détermine si toutes les boîtes peuvent être ouvertes.
    
    Args:
        boxes (list): Liste de listes où chaque liste contient les clés
                     pour d'autres boîtes
    
    Returns:
        bool: True si toutes les boîtes peuvent être ouvertes, False sinon
    """
    if not boxes or len(boxes) == 0:
        return False

    n = len(boxes)
    boites_ouvertes = {0}  
    cles_a_verifier = boxes[0]  

    
    while cles_a_verifier:
        cle = cles_a_verifier.pop()  
        
        
        if isinstance(cle, int) and 0 <= cle < n and cle not in boites_ouvertes:
            boites_ouvertes.add(cle) 
            cles_a_verifier.extend(boxes[cle])  
    
    return len(boites_ouvertes) == n
