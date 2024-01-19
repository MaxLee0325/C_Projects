#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "linkedlist.h"
/**
 * findNode function takes in a linked list and an item, returns the node if the item is found, returns null otherwise
 * @param list a linked list where item is supposed to be found
 * @param roomName an item name
 * @return the node that contains the item, null if no such node is found
 */
ll_node_t* findNode(linked_list_t list, char *roomName){
    linked_list *lis = list;
    for(ll_node_t *node = lis->head; node; node = node->next)
        if(!strcmp(node->item, roomName)) return node;
    return NULL;
}

int main() {
    //input the room list, for the fist round of input just fill the items in the nodes
    char room[20];
    linked_list_t *roomList = ll_new();
    while(scanf("%s", room)){
        if(!strcmp(room, "END")) break;
        else ll_add_back(roomList, strdup(room));
    }
    //cast the room list called baseList
    linked_list *baseList = (linked_list*)roomList;

    //input the list which indicates the room and it's connection
    char target[20], connectTo[20];
    scanf("%s", target);
    while(strcmp(target, "END")){
        scanf("%s", connectTo);
        //validate the two rooms before proceed
        bool valid = true;
        if(!findNode(roomList, target)){
            printf("Oops: Cannot find room %s.\n", target);
            valid = false;
        }
        if(!findNode(roomList, connectTo)){
            printf("Oops: Cannot find room %s.\n", connectTo);
            valid = false;
        }
        if(valid) {
            //find the target node and add the room in the connection list in that node
            ll_node_t *node = findNode(baseList, target);
            ll_add_back(node->connectTo, strdup(connectTo));
        }
        scanf("%s", target);
    }

    //input the entering of the rooms
    char enter[20], *end;
    scanf("%s", enter);
    //a holder node to be worked on in the loop, starts with the head of base list
    ll_node_t *node = baseList->head;
    bool firstInput = true;
    while(strcmp(enter, "END")){
        //validate if the room is in the base list
        if(!findNode((linked_list *)baseList, enter)){
            printf("Oops: Cannot find room %s.\n", enter);
            return 0;
        }
        linked_list *lis = node->connectTo;
        //validate if the room is in the sub list
        if(!findNode(lis, enter) && !firstInput) {
            printf("Oops: Room %s does not connect to room %s.\n", node->item, enter);
            scanf("%s", enter);
            firstInput = false;
            return 0;
        }
        firstInput = false;
        printf("Entering room %s.\n", enter);
        //update the temporary node
        node = findNode(baseList, enter);
        end = strdup(enter);
        scanf("%s", enter);
    }
    printf("Ended in room %s.\n", end);
}



