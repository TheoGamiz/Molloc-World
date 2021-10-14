#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
/////////////////////////////////////////////////
//Structure of the Player's inventory//
/////////////////////////////////////////////////

struct inventory{
    int id;                         //The id of the item
    char name [20];                 //The name of the item
    char type [20];                 //The type of the item(weapon,tools,armor,crafting ressource,heal)
    int damage;                     //the damage of the item(only for type  weapon)
    int resistance;                 //the percentage of damage reduction (only for type armor)
    int restoring;                  //the number of HP that the item restore (only for type heal)
    int durabilityMax;              //the number of use of an item ( only for type weapon and tools)
    int currentDurability;          //the current durability of the item ( only for type weapon and tools)
    int quantity;                   //the quantity of a crafting ressource (only for crafting ressoruce)
};
typedef struct inventory  inventory;

/////////////////////////////////////////////////
//Structure of the Player//
/////////////////////////////////////////////////

struct Player{
    int level;                      //the level of the player
    float xp;                       //the quantity of xp
    int xpNextLevel;                //the quantity of xp needed for a level up
    int hpMax;                      //the maximum quantity of life that the player can reach
    float currHp;                   //the current quantity of life of the player
    int currentArmor;               //the id of the currentArmor
    char armorName[20];             //the name of the currentArmor
    inventory CurrentInventory;     //the inventory of the player

};
typedef struct Player Player;

/////////////////////////////////////////////////
//Structure of the itemList //
/////////////////////////////////////////////////

struct itemList{
    int id;
    char name [20];
    char type [20];
    int damage;
    int resistance;
    int restoring;
    int durability;
    struct itemList* next;
};
typedef struct itemList itemList;

/////////////////////////////////////////////////
//Function of the ItemList//
/////////////////////////////////////////////////

//add an element in the itemList
itemList* newItem(int id,char name[],char type[],int damage,int resistance,int restoring,int durability){
    itemList* temp = malloc(sizeof(itemList));
    temp->id=id;
    int i ;
    for ( i = 0; name[i]!='\0' ; ++i) {
        temp->name[i]=name[i];

    }
    temp->name[i]=name[i];
    for ( i = 0; type[i]!='\0' ; ++i) {
        temp->type[i]=type[i];
    }
    temp->type[i]=type[i];
    temp->damage=damage;
    temp->resistance=resistance;
    temp->restoring=restoring;
    temp->durability=durability;
    temp->next=NULL;
    return temp;

}

//init the itemList
itemList* initItemList(){
    itemList* tmp;
    itemList* head = newItem(1,"Epee en bois","Arme",1,-1,-1,10);
    tmp= head;
    head->next = newItem(2,"Pioche en bois","Outil",-1,-1,-1,10);
    tmp=tmp->next;
    tmp->next = newItem(3,"Serpe en bois","Outil",-1,-1,-1,10);
    tmp=tmp->next;
    tmp->next= newItem(4,"Hache en bois","Outil",-1,-1,-1,10);
    tmp=tmp->next;
    tmp->next= newItem(5,"Sapin","Ressource de craft",-1,-1,-1,-1);
    tmp=tmp->next;
    tmp->next= newItem(6,"Pierre","Ressource de craft",-1,-1,-1,-1);
    tmp=tmp->next;
    tmp->next= newItem(7,"Herbe","Ressource de craft",-1,-1,-1,-1);
    tmp=tmp->next;
    tmp->next= newItem(8,"Epee en pierre","Arme",2,-1,-1,10);
    tmp=tmp->next;
    tmp->next= newItem(9,"Lance en pierre","Arme",3,-1,-1,8);
    tmp=tmp->next;
    tmp->next= newItem(10,"Marteau en pierre","Arme",4,-1,-1,5);
    tmp=tmp->next;
    tmp->next= newItem(11,"Plastron en pierre","Armure",-1,10,-1,-1);
    tmp=tmp->next;
    tmp->next = newItem(12,"Pioche en pierre","Outil",-1,-1,-1,10);
    tmp=tmp->next;
    tmp->next = newItem(13,"Serpe en pierre","Outil",-1,-1,-1,10);
    tmp=tmp->next;
    tmp->next = newItem(14,"Hache en pierre","Outil",-1,-1,-1,10);
    tmp=tmp->next;
    tmp->next = newItem(15,"Potion de vie I","Soin",-1,-1,30,-1);
    tmp=tmp->next;
    tmp->next= newItem(16,"Hetre","Ressource de craft",-1,-1,-1,-1);
    tmp=tmp->next;
    tmp->next= newItem(17,"Fer","Ressource de craft",-1,-1,-1,-1);
    tmp=tmp->next;
    tmp->next= newItem(18,"Lavande","Ressource de craft",-1,-1,-1,-1);
    tmp=tmp->next;
    tmp->next= newItem(19,"Epee en fer","Arme",5,-1,-1,10);
    tmp=tmp->next;
    tmp->next= newItem(20,"Lance en fer","Arme",7,-1,-1,8);
    tmp=tmp->next;
    tmp->next= newItem(21,"Marteau en fer","Arme",10,-1,-1,5);
    tmp=tmp->next;
    tmp->next= newItem(22,"Plastron en fer","Armure",-1,20,-1,-1);
    tmp=tmp->next;
    tmp->next = newItem(23,"Pioche en fer","Outil",-1,-1,-1,10);
    tmp=tmp->next;
    tmp->next = newItem(24,"Serpe en fer","Outil",-1,-1,-1,10);
    tmp=tmp->next;
    tmp->next = newItem(25,"Hache en fer","Outil",-1,-1,-1,10);
    tmp=tmp->next;
    tmp->next = newItem(26,"Potion de vie II","Soin",-1,-1,80,-1);
    tmp=tmp->next;
    tmp->next= newItem(27,"Chene","Ressource de craft",-1,-1,-1,-1);
    tmp=tmp->next;
    tmp->next= newItem(28,"Diamant","Ressource de craft",-1,-1,-1,-1);
    tmp=tmp->next;
    tmp->next= newItem(29,"Chanvre","Ressource de craft",-1,-1,-1,-1);
    tmp=tmp->next;
    tmp->next= newItem(30,"Epee en diamant","Arme",10,-1,-1,10);
    tmp=tmp->next;
    tmp->next= newItem(31,"Lance en diamant","Arme",15,-1,-1,8);
    tmp=tmp->next;
    tmp->next= newItem(32,"Marteau en diamant","Arme",20,-1,-1,5);
    tmp=tmp->next;
    tmp->next= newItem(33,"Plastron en diamant","Armure",-1,40,-1,-1);
    tmp=tmp->next;
    tmp->next = newItem(34,"Potion de vie III","Soin",-1,-1,200,-1);


    return head;
};

//print the item list
itemList* printItemList(itemList* item){
    while (item!=NULL){
        printf("\n-------------------------------------------------------------------\n\n");
        printf("cet item est le numero %d de la liste \n",item->id);
        printf("cet item s'appelle: ");
        for (int i = 0; item->name[i]!='\0' ; ++i) {
            printf("%c",item->name[i]);
        }
        printf("\ncet item est du type: ");
        for (int i = 0; item->type[i]!='\0' ; ++i) {
            printf("%c",item->type[i]);
        }
        if (strcmp(item->type,"Arme")==0){
            printf("\ncet item fait %d de degat\n",item->damage);
            printf("cet item a %d de durabilite maximum\n",item->durability);
        }
        else if(strcmp(item->type,"Outil")==0){
            printf("\ncet item a %d de durabilite maximum\n",item->durability);
        }
        else if(strcmp(item->type,"Ressource de craft")==0){
            printf("\n");
        }
        else if(strcmp(item->type,"Armure")==0){
            printf("\ncet item permet de resister a %d %% de degat maximum\n",item->resistance);
        }
        else if(strcmp(item->type,"Soin")==0){
            printf("\ncet item permet de soigner un maximum de %d de HP\n",item->restoring);
        }
        else{
            printf("\nPas de type trouver a cette item\n");
        }
        item=item->next;

    }
    printf("\n-------------------------------------------------------------------\n\n");
}

//print the item list filtered by a category
itemList* printCategoryItem(itemList* item,char category[]){
    int compteur=0;
    while (item!=NULL){
        if(strcmp(item->type,category)==0){
            printf("\n-------------------------------------------------------------------\n\n");
            printf("cet item est le numero %d de la liste \n",item->id);
            printf("cet item s'appelle: ");
            for (int i = 0; item->name[i]!='\0' ; ++i) {
                printf("%c",item->name[i]);
            }
            printf("\ncet item est du type: ");
            for (int i = 0; item->type[i]!='\0' ; ++i) {
                printf("%c",item->type[i]);
            }
            if (strcmp(item->type,"Arme")==0){
                printf("\ncet item fait %d de degat\n",item->damage);
                printf("cet item a %d de durabilite maximum\n",item->durability);
            }
            else if(strcmp(item->type,"Outil")==0){
                printf("\ncet item a %d de durabilite maximum\n",item->durability);
            }
            else if(strcmp(item->type,"Ressource de craft")==0){
                printf("\n");
            }
            else if(strcmp(item->type,"Armure")==0){
                printf("\ncet item permet de resister a %d %% de degat maximum\n",item->resistance);
            }
            else if(strcmp(item->type,"Soin")==0){
                printf("\ncet item permet de soigner un maximum de %d de HP\n",item->restoring);
            }
            else{
                printf("\nPas de type trouver a cette item\n");
            }
        }
        compteur+=1;
        item=item->next;
    }
    printf("il y a donc %d de %s",compteur,category);
    printf("\n-------------------------------------------------------------------\n\n");

}

/////////////////////////////////////////////////
//Function of the Player//
/////////////////////////////////////////////////

//init the player with beggining values
Player* initPlayer(){
    Player* Hero = malloc(sizeof (Player));
    Hero->level =1;
    Hero->xp= 0;
    Hero->hpMax=100;
    Hero->currHp =100;
    Hero->currentArmor=0;

    return Hero;
}

//modify the armor of the Player
Player modifyArmor(Player* Hero,int idArmor,itemList* item){

        if(idArmor==0){
            Hero->currentArmor=idArmor;
            Hero->armorName[0]='\0';
        }
        else{
            int test;
            while (item!=NULL ||  test!=1){

                if(idArmor==item->id){
                    int i;
                    Hero->currentArmor=idArmor;
                    for (i = 0; item->name[i]!='\0' ; ++i) {
                        Hero->armorName[i]=item->name[i];
                    }
                    Hero->armorName[i]=item->name[i];
                    test=1;
                }
                item=item->next;
            }
        }


}


//print the actual armor of the Player
void printArmor(Player* hero){
    if (hero->currentArmor==0){
        printf("Le glandu la il a pas d'armure  bahahaha\n");
    }
    else{
        printf("LE PREUX CHEVALIER A CETTE ARMURE: ");
        for (int i = 0; hero->armorName[i]!='\0'; ++i) {
            printf("%c",hero->armorName[i]);
        }
        printf("\n");
    }
};
int main() {
    itemList* item=initItemList();
    Player* hero = initPlayer();
    //printItemList(item);
    //printCategoryItem(item,"Arme");
    printArmor(hero);
    modifyArmor(hero,11,item);
    printArmor(hero);


    printf("le level de ce type est : %d \n ",hero->level);





}
