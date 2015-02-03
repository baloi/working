#include <stdio.h>
#include <stdlib.h>

#include "link_list.h"

agListNode * agListNode_create() {
    agListNode *    node;

    node = calloc( 1, sizeof( agListNode ) );

    if( node == NULL ) {
        printf( "Error creating node\n" );
    }
    
    node->item = NULL;
    node->prev = NULL;
    node->next = NULL;

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
