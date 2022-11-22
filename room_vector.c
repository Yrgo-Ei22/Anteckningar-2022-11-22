/********************************************************************************
* room_vector.c: Innehåller funktionsdefinitioner för associerade funktioner
*                till strukten room_vector.
********************************************************************************/
#include "room_vector.h"

/********************************************************************************
* room_vector_push: Lägger till dimensioner för ett nytt rum längst bak i
*                   angiven vektor. Om tillägget lyckas returneras 0, annars
*                   returneras felkod 1.
*
*                   - self: Pekare till vektorn som ska tilldelas.
*                   - new_room: Pekare till objekt innehållande det nya
*                               rummets dimensioner.
********************************************************************************/
int room_vector_push(struct room_vector* self,
                     const struct room* new_room)
{
   struct room* copy = (struct room*)realloc(self->rooms, sizeof(struct room) * (self->size + 1));
   if (!copy) return 1;
   copy[self->size++] = *new_room;
   self->rooms = copy;
   return 0;
}

/********************************************************************************
* room_vector_pop: Raderar sista elementet (dimensioner för ett rum) längst bak
*                  i angiven vektor. Om detta mot förmodan misslyckas returneras
*                  felkod 1, annars returneras 0.
*
*                  - self: Pekare till vektorn vars sista element ska raderas.
********************************************************************************/
int room_vector_pop(struct room_vector* self)
{
   if (self->size <= 1)
   {
      room_vector_clear(self);
      return 0;
   }
   else
   {
      struct room* copy = (struct room*)realloc(self->rooms, sizeof(struct room) * (self->size - 1));
      if (!copy) return 1;
      self->rooms = copy;
      self->size--;
      return 0;
   }
}

/********************************************************************************
* room_vector_print: Skriver ut information om samtliga rum lagrade i angiven
*                    vektor. Utskriften sker via godtycklig utström, där
*                    standardutenheten stdout används som default för utskrift
*                    i terminalen.
*
*                   - self   : Pekare till vektorn vars innehåll ska skrivas ut.
*                   - ostream: Pekare till godtycklig utström (default = stdout).
********************************************************************************/
void room_vector_print(const struct room_vector* self,
                       FILE* ostream)
{
   if (!ostream) ostream = stdout;

   for (const struct room* i = room_vector_begin(self); i < room_vector_end(self); ++i)
   {
      room_print(i, ostream);
   }

   return;
}