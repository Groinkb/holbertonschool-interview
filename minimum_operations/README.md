# Minimum Operations

## Description
Ce projet consiste à résoudre un problème d'optimisation où nous devons calculer le nombre minimum d'opérations nécessaires pour obtenir exactement n caractères 'H' dans un fichier, en utilisant uniquement deux opérations : "Copy All" et "Paste".

## Spécifications

### Environnement
- Ubuntu 14.04 LTS
- Python 3.4.3
- Éditeurs autorisés : vi, vim, emacs

### Exigences
- Tous les fichiers doivent commencer par `#!/usr/bin/python3`
- Code documenté et conforme au style PEP 8 (version 1.7.x)
- Tous les fichiers doivent être exécutables
- Tous les fichiers doivent se terminer par une nouvelle ligne

## Tâche : Minimum Operations

### Prototype
```python
def minOperations(n)
```

### Paramètres
- `n` : nombre de caractères 'H' à obtenir

### Valeur de retour
- Un entier représentant le nombre minimum d'opérations nécessaires
- 0 si n est impossible à atteindre

### Exemple
```python
n = 9

# Séquence d'opérations :
# H => Copy All => Paste => HH => Paste => HHH => Copy All => Paste => HHHHHH => Paste => HHHHHHHHH
# Nombre total d'opérations : 6

n = 4
# Résultat : 4 opérations

n = 12
# Résultat : 7 opérations
```

### Fonctionnement
1. On commence avec un seul caractère 'H'
2. On ne peut utiliser que deux opérations :
   - Copy All : copie tout le contenu actuel
   - Paste : colle le contenu copié
3. Le but est de trouver le nombre minimum d'opérations pour atteindre exactement n caractères

### Utilisation
```python
#!/usr/bin/python3
minOperations = __import__('0-minoperations').minOperations

n = 4
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

n = 12
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))
```

## Structure du projet
minimum_operations/
│
├── 0-minoperations.py - Implémentation de la fonction
├── 0-main.py         - Fichier de test
└── README.md         - Documentation du projet

## Auteur
[Groinkb]

## Licence
[THEPROJECT]
