#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#include "sources/source/player.c"
#include "sources/source/item_list.c"


int main() {
    itemList *item = initItemList();
    Player *hero = initPlayer();

    //printItemList(item);
    printCategoryItem(item,"Arme");
    printArmor(hero);
    modifyArmor(hero, 11, item);
    printArmor(hero);


    printf("le level de ce type est : %d \n ", hero->level);

}