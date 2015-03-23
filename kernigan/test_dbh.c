#include "dbg.h"
#include <stdlib.h>
#include <stdio.h>

void test_debug() {
    // notice you don't need the \n
    debug( "I have Brown Hair" );

    // passing arguments like printf
    debug( "I am %d years old. ", 37 );
}

int main( int argc, char ** argv ) {
    
    check( argc == 2, "Need an argument" );

    test_debug();

    return 0;
}
