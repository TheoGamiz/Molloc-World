#include <stdio.h>
#include "Map.h"
#include "MapGraphic.h"

#include "sources/source/player.c"
#include "sources/source/item_list.c"

static void ConstruireZone(Zone_Map zone, int largeur, int hauteur)
{
    Map * map = Creer_Map(zone, largeur, hauteur);

    Remplir_Map(map);

    Afficher_Map(map);
    Afficher_MapGraphic(map);

    Detruire_Map(map);
}

int main()
{
    ConstruireZone(ZONE1, 10, 10);
    ConstruireZone(ZONE2, 10, 20);
    ConstruireZone(ZONE3, 30, 30);

    printf("\n< Appuyer sur une touche >");
    getchar();
}
