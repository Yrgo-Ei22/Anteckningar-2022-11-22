/********************************************************************************
* main.c: Implementering av dynamisk vektor för lagring av rumsdimensioner.
********************************************************************************/
#include "room.h"
#include "room_vector.h"

/********************************************************************************
* main: Lagrar dimensioner för tre rum i en vektor och skriver ut uppgifterna
*       i terminalen.
********************************************************************************/
int main(void)
{
   struct room r1, r2, r3;
   struct room_vector v1;

   room_init(&r1, 10, 5, 2.5);
   room_init(&r2, 20, 10, 3);
   room_init(&r3, 5, 5, 5);

   room_vector_init(&v1);

   room_vector_push(&v1, &r1);
   room_vector_push(&v1, &r2);
   room_vector_push(&v1, &r3);

   room_vector_print(&v1, 0);
   room_vector_clear(&v1);
   return 0;
}