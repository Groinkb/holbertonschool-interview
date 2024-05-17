#!/usr/bin/python3
def canUnlockAll(boxes):
    """
    Détermine si toutes les boîtes peuvent être ouvertes à partir de la première boîte (boîte 0).

    :param boxes: Liste de listes, où chaque sous-liste contient les clés disponibles dans cette boîte.
                  Par exemple, boxes[i] contient les clés pour ouvrir d'autres boîtes.
    :return: True si toutes les boîtes peuvent être ouvertes, sinon False.
    """
    
    # Nombre total de boîtes
    n = len(boxes)
    
    # Une liste pour suivre les boîtes déverrouillées
    unlocked = [False] * n
    unlocked[0] = True  # La première boîte est déverrouillée par défaut
    
    # Une pile pour gérer les boîtes à explorer (DFS)
    stack = [0]
    
    while stack:
        # Prendre une boîte de la pile
        current_box = stack.pop()
        
        # Explorer les clés dans la boîte actuelle
        for key in boxes[current_box]:
            if key < n and not unlocked[key]:
                # Si la clé correspond à une boîte valide et non déverrouillée
                unlocked[key] = True
                stack.append(key)
    
    # Vérifier si toutes les boîtes ont été déverrouillées
    return all(unlocked)

# Exemples d'utilisation :
print(canUnlockAll([[1], [2], [3], []]))  # Doit afficher : True
print(canUnlockAll([[1, 2], [3], [3], []]))  # Doit afficher : True
print(canUnlockAll([[1, 2, 3], [], [], []]))  # Doit afficher : True
print(canUnlockAll([[1, 4], [2], [3], [], [0]]))  # Doit afficher : False
