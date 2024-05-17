def canUnlockAll(boxes):
    # Nombre total de boîtes
    n = len(boxes)
    
    # Une liste pour suivre les boîtes déverrouillées
    unlocked = [False] * n
    unlocked[0] = True
    
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


