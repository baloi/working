#include <stdio.h>
#include <stdlib.h>

#include "link_list.h"

agPerson * agPerson_create() {
    agPerson * person;
        
    person = calloc( 1, sizeof( agPerson ) );

    if( person == NULL ) {
        printf( "Error creating person\n" );
    }

    return person;
}

agListNode * agListNode_create() {
    agListNode *    node;

    node = calloc( 1, sizeof( agListNode ) );

    if( node == NULL ) {
        printf( "Error creating node\n" );
    }
    
    node->item = NULL;
    node->prev = NULL;
    node->next = NULL;

    node->person = agPerson_create();

    return node;

}


agList * agList_create() {
    agList *       lp;

    lp = calloc( 1, sizeof( agList ) );
    
    if( lp == NULL ) {
        printf( "Error creating list\n" );
    }
    
    lp->head = NULL;
    lp->tail = NULL;

    lp->count = 0;

    return lp;
}
