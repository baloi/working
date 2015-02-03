#include "link_list.h"

#include <stdio.h>
#include <assert.h>

agList * agList_create();

////////////////////////////////////////////////////////////////////////////////
//
//  test functions
//
////////////////////////////////////////////////////////////////////////////////

void test_list_node_create() {
    printf( "test_list_node_create -- START\n" );
    agListNode *    node =  agListNode_create();
    node->item           = "An item\n";

     
    //printf( "\nTODO: test_list_node_create \n\n" );
    printf( "node->item = %s", node->item );
    printf( "test_list_node_create -- END\n" );
}

void test_list_create() {
    printf( "test_list_create -- START\n" );
    agList *        list =  agList_create();

    //assert( agList != null ); 
    if( list != NULL ) {
        printf( "Created list\n" );
        // list tail and head should be NULL
        assert( list->head == NULL );
        assert( list->tail == NULL );
        assert( list->count == 0 );
    } else {
        printf( "Could not create list\n" );
    }

    printf( "test_list_create -- END\n" );
}


////////////////////////////////////////////////////////////////////////////////
//
//  main function
//
////////////////////////////////////////////////////////////////////////////////

int main( int argc, char * argv[] ) {
    printf( "List tests\n" );

    test_list_create();
    test_list_node_create();

    // test_adding_nodes();
    // test_searching_node();

    return 0; 
}
