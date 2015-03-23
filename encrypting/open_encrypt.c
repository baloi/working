#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <openssl/des.h>

char * Encrypt( char *Key, char *Msg, int size ) {
    static char*        Res;
    int                 n;
    DES_cblock          Key2;
    DES_key_schedule    schedule;
    
    n = 0;
    Res = ( char * ) malloc ( size );

    /* Prepare the key for use with DES_cfb64_encrypt */
    memcpy( Key2, Key, 8 );
    DES_set_odd_parity( &Key2 );

    DES_set_key_checked( &Key2, &schedule );

    /* Encryption occurs here */
    DES_cfb64_encrypt( ( unsigned char * ) Msg, ( unsigned char * ) Res,
                        size, &schedule, &Key2, &n, DES_ENCRYPT );

    return ( Res );


}

int main( int argc, char **argv ) {
    printf( "Encryption and Decription sample \n" );
    
    char    key[]      = "password";
    char    clear[]    = "This is a secret message";
    char *  decrypted;
    char *  encrypted;

    encrypted   = malloc( sizeof( clear ));
    decrypted   = malloc( sizeof( clear ));

    printf( "Clear text\t : %s \n", clear );
    memcpy( encrypted, Encrypt( key, clear, sizeof( clear )), sizeof( clear ) );

    printf( "Encrypted text\t : %s \n", encrypted );

    return 0;

}
