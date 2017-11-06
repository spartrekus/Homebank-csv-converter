
//////////////////
//////////////////
/// ncatpsconv.c 
//////////////////
//////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



////////////////////////////////////////////////////////////////////
char *strrlf(char *str) 
{     // copyleft, C function made by Spartrekus 
      char ptr[strlen(str)+1];
      int i,j=0;
      for(i=0; str[i]!='\0'; i++)
      {
        if (str[i] != '\n' && str[i] != '\n') 
        ptr[j++]=str[i];
      } 
      ptr[j]='\0';
      size_t siz = sizeof ptr ; 
      char *r = malloc( sizeof ptr );
      return r ? memcpy(r, ptr, siz ) : NULL;
}
////////////////////////////////////////////////////////////////////
char *strcut( char *str , int myposstart, int myposend )
{     // copyleft, C function made by Spartrekus 
      char ptr[strlen(str)+1];
      int i,j=0;
      for(i=0; str[i]!='\0'; i++)
      {
        if ( ( str[i] != '\0' ) && ( str[i] != '\0') )
         if ( ( i >=  myposstart-1 ) && (  i <= myposend-1 ) )
           ptr[j++]=str[i];
      } 
      ptr[j]='\0';
      size_t siz = sizeof ptr ; 
      char *r = malloc( sizeof ptr );
      return r ? memcpy(r, ptr, siz ) : NULL;
}





/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
char *strsplit(char *str , int mychar , int myitemfoo )
{  
      char ptr[strlen(str)+1];
      int myitem = myitemfoo +1;
      int i,j=0;
      int fooitem = 0;
      for(i=0; str[i]!='\0'; i++)
      {
        if ( str[i] == mychar ) 
           fooitem++;
        //else if ( str[i] != mychar &&  fooitem == myitem-1  ) 
        else if ( str[i] != mychar &&  fooitem == myitem-2  ) 
           ptr[j++]=str[i];
      } 
      ptr[j]='\0';
      size_t siz = sizeof ptr ; 
      char *r = malloc( sizeof ptr );
      return r ? memcpy(r, ptr, siz ) : NULL;
}



/// customed one
char *strdelimit(char *str , int mychar1, int mychar2,  int mycol )
{ 
      char ptr[strlen(str)+1];
      char ptq[strlen(str)+1];
      strncpy( ptr, strsplit( str, mychar1 , mycol+1 ), strlen(str)+1 );
      strncpy( ptq, strsplit( ptr, mychar2 , 1 ), strlen(str)+1 );
      size_t siz = sizeof ptq ; 
      char *r = malloc( sizeof ptq );
      return r ? memcpy(r, ptq, siz ) : NULL;
}





////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
int main( int argc, char *argv[])
{
        int begin = 1;
        char linebuffer[BUFSIZ];
        strncpy( linebuffer, "" , BUFSIZ );
        char ptr[BUFSIZ];
        int j=0;

        printf( "date;paymode;info;payee;wording;amount;category;tags\n" );

        int c ; 
        c = getchar();
        while( c != EOF )
        {
           ptr[j++] = c;
           begin = 0;

           if ( c == '\n' )
           {  
             begin = 1;
             ptr[j]='\0';

             // date
             printf( "%s",  strsplit( ptr, ';', 3 ) );
             printf( "%c", ';' );

             // paymode
             printf( "1;" );

             // info
             printf( "info;" );

             // payee
             printf( "%s",  strsplit( ptr, ';', 2 ) );
             printf( "%c", ';' );

             // wording
             printf( ";" );

             // amount
             printf( "%s",  strsplit( ptr, ';', 5 ) );
             printf( "%c", ';' );

             // cat
             printf( "%c", ';' ); 

             // tag
             printf( "%c", ';' ); 

             printf( "\n"); // newline
             strncpy( ptr, "", BUFSIZ );
             j = 0;
           }

           c = getchar();
        }
	return 0;
 }






