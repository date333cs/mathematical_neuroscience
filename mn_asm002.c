/*
  mn_asm002.c
*/

#include <stdio.h>
#include <stdlib.h> /* for srand48(), drand48() */
#include <math.h>   /* for sqrt(), log(), M_PI */


void generate_memories(){

} 

void set_weights(){

}
 
void set_initial_state(){

}


void update_sates(){

}


int main ( int argc , char * argv []){

/* 
   Experimental Procedure:
   
   1. generate memory patterns 
   2. set connection weights 
   3. set an initial state 
      3.1 put flip noise
   4. update states 
*/

    generate_memories();
    set_weights();
    set_initial_state();

    for (i=0; i<20; i++){
        update_sates();
    }

    return 0;
}
