#include <stdio.h>

/* strcmp: return < 0 of s < t, 0 if s == t, > 0 of s > t */
int strcmp( char *s, char *t ) {
    int i;
    
    for( i = 0; s[i] == t[i]; i ++ ) {
        if ( s[i] == '\0' ) {
            return 0;
        }
    }

    return s[i] - t[i];
}

int main( int argc, char **argv ) {
    if( strcmp( 'a', 'a' ) == 0 ) {
        printf( "a == a\n" );
    } 
    else {
        printf( "a != a\n" );
    }
    
    return 0;
}
