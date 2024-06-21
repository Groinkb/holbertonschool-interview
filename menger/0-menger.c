#include "menger.h"
#include <stdio.h>
#include <math.h>

/**
 * draw_char - Dessine un caractère pour un niveau donné du Menger Sponge.
 *
 * @level: Niveau du Menger Sponge.
 * @x: Coordonnée x du caractère dans le niveau actuel.
 * @y: Coordonnée y du caractère dans le niveau actuel.
 *
 * Description :
 *  Cette fonction est utilisée pour dessiner un caractère dans un niveau
 *  donné du Menger Sponge. Elle prend en compte le niveau actuel ainsi que
 *  les coordonnées du caractère dans ce niveau pour décider s'il doit être
 *  dessiné comme un espace ou comme un caractère '#'.
 */
void draw_char(int level, int x, int y)
{
	int size = (int)pow(3, level - 1);

	if (level == 0)
	{
		printf("#");
		return;
	}

	if (x >= size && x < size * 2 && y >= size && y < size * 2)
	{
		printf(" ");
	} else
	{
		draw_char(level - 1, x % size, y % size);
	}
}

/**
 * draw_level - Dessine un niveau complet du Menger Sponge.
 *
 * @level: Niveau du Menger Sponge à dessiner.
 *
 * Description :
 *  Cette fonction dessine un niveau complet du Menger Sponge. Elle utilise la
 *  fonction draw_char pour dessiner chaque caractère du niveau.
 */
void draw_level(int level)
{
	int size = (int)pow(3, level);
	int y, x;

	for (y = 0; y < size; y++)
	{
		for (x = 0; x < size; x++)
		{
			draw_char(level, x, y);
		}
		printf("\n");
	}
}

/**
 * menger - Dessine un Menger Sponge de niveau donné.
 *
 * @level: Niveau du Menger Sponge à dessiner.
 *
 * Description :
 *  Cette fonction dessine un Menger Sponge de niveau donné. Si le niveau est
 *  inférieur à zéro, la fonction ne fait rien. Sinon, elle appelle
 *  draw_level pour dessiner le Menger Sponge.
 */
void menger(int level)
{
	if (level < 0)
	{
		return;
	}

	draw_level(level);
}
