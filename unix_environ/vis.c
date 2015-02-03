/*******************************************************************************
 *
 * vis: make funny characters visible
 *
 ******************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int         strip = 0;

int main( int argc, char * argv[] ) {
    int     c;
    FILE    *fp;

    //if( argc > 1 && strcmp( argv[1], "-s" ) == 0 ) {
    if( argc > 1 && strcmp( argv[1], "-s" ) == 0 ) {
        strip = 1;
    }

    
    return 0;
}

void vis( FILE * fp ) {
    int c; 

    while( ( c = getc( fp ) ) != EOF ) {

        if( isascii( c ) && 
                ( isprint( c ) || c == '\n' || c == '\t' || c == ' ' ) ) {
            putchar( c );
        } else if( !strip ) {
            printf( "\\%03o", c );
        }

    }

}

