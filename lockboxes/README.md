
# Boîtes Verrouillées

## Description du problème

Vous avez devant vous `n` boîtes verrouillées numérotées séquentiellement de `0` à `n - 1`. Chaque boîte peut contenir des clés permettant d'ouvrir d'autres boîtes.

## Objectif

Écrire une méthode qui détermine si toutes les boîtes peuvent être ouvertes.

## Prototype de la fonction

```python
def canUnlockAll(boxes)
```

## Paramètres

- `boxes` : Une liste de listes
  - Chaque liste interne contient les clés disponibles dans cette boîte
  - Les clés sont représentées par des entiers positifs

## Contraintes et règles

1. Une clé avec le même numéro qu'une boîte peut ouvrir cette boîte
2. Toutes les clés sont des entiers positifs
3. Il peut y avoir des clés qui n'ont pas de boîtes correspondantes
4. La première boîte `boxes[0]` est déjà déverrouillée
5. Une boîte peut être vide (ne contenir aucune clé)

## Valeur de retour

- `True` : si toutes les boîtes peuvent être ouvertes
- `False` : si certaines boîtes restent verrouillées

## Exemple d'utilisation

```python
boxes = [[1], [2], [3], [4], []]
print(canUnlockAll(boxes))  # True

boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
print(canUnlockAll(boxes))  # True

boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
print(canUnlockAll(boxes))  # False
```

## Complexité

- Temporelle : O(N + K) où N est le nombre de boîtes et K est le nombre total de clés
- Spatiale : O(N) pour stocker l'ensemble des boîtes déverrouillées

## Approche utilisée

1. On commence avec la boîte 0 qui est déjà déverrouillée
2. On utilise un ensemble pour garder trace des boîtes qu'on peut ouvrir
3. Pour chaque boîte déverrouillée, on essaie d'utiliser ses clés
4. On continue ce processus jusqu'à ce qu'on ne puisse plus ouvrir de nouvelles boîtes
5. On vérifie si toutes les boîtes ont été ouvertes