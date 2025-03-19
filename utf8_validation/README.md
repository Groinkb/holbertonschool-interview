# UTF-8 Validation

## Description
Ce projet implémente une méthode qui détermine si un ensemble de données représente un encodage UTF-8 valide.

## Contexte
L'UTF-8 (Unicode Transformation Format - 8-bit) est un format d'encodage de caractères qui peut représenter n'importe quel caractère du standard Unicode en utilisant des séquences d'octets de longueur variable (1 à 4 octets).

## Règles de l'encodage UTF-8
- Un caractère ASCII (0-127) est codé sur 1 octet: `0xxxxxxx`
- Un caractère sur 2 octets commence par: `110xxxxx 10xxxxxx`
- Un caractère sur 3 octets commence par: `1110xxxx 10xxxxxx 10xxxxxx`
- Un caractère sur 4 octets commence par: `11110xxx 10xxxxxx 10xxxxxx 10xxxxxx`

## Fonction
```python
def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding

    Args:
        data: A list of integers where each integer represents 1 byte of data

    Returns:
        True if data is a valid UTF-8 encoding, else False
    """
```

## Exemples
```python
data = [65]  # ASCII 'A' - Valid
print(validUTF8(data))  # True

data = [80, 121, 116, 104, 111, 110, 32, 105, 115, 32, 99, 111, 111, 108, 33]  # "Python is cool!" - Valid
print(validUTF8(data))  # True

data = [229, 65, 127, 256]  # Invalid UTF-8 sequence
print(validUTF8(data))  # False
```

## Exigences
- Python 3.4.3
- PEP 8 style (version 1.7.x)