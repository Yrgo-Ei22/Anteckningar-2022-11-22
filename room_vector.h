/********************************************************************************
* room_vector.h: Innehåller funktionalitet för lagring av dimensioner för rum
*                i dynamiska arrayer (vektorer) via strukten room_vector samt
*                associerade funktioner.
********************************************************************************/
#ifndef ROOM_VECTOR_H_
#define ROOM_VECTOR_H_

/* Inkluderingsdirektiv: */
#include "room.h"
#include <stdlib.h>

/********************************************************************************
* room_vector: Strukt för lagring av rum-dimensioner i en dynamisk array.
*              Elementen som lagras utgörs av objekt av strukten room.
********************************************************************************/
struct room_vector
{
   struct room* rooms; /* Pekare till fält innehållande rum. */
   size_t size;        /* Vektorns storlek, dvs. antalet room-objekt i fältet. */
};

/********************************************************************************
* room_vector_init: Initierar ny tom vektor för lagring av rumdimensioner.
*
*                   - self: Pekare till vektorn som ska initieras.
********************************************************************************/
static inline void room_vector_init(struct room_vector* self)
{
   self->rooms = 0;
   self->size = 0;
   return;
}

/********************************************************************************
* room_vector_clear: Tömmer angiven vektor.
*
*                    - self: Pekare till vektorn som ska tömmas.
********************************************************************************/
static inline void room_vector_clear(struct room_vector* self)
{
   free(self->rooms);
   room_vector_init(self);
   return;
}

/********************************************************************************
* room_vector_begin: Returnerar adressen till det första rummet i angiven vektor.
*                    Om vektorn är tom returneras null.
*
*                    - self: Pekare till vektorn.
********************************************************************************/
static inline struct room* room_vector_begin(const struct room_vector* self)
{
   return self->rooms;
}

/********************************************************************************
* room_vector_end: Returnerar adressen efter det sista rummet i angiven vektor.
*                  Om vektorn är tom returneras null.
*
*                  - self: Pekare till vektorn.
********************************************************************************/
static inline struct room* room_vector_end(const struct room_vector* self)
{
   return self->rooms + self->size;
}

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
                     const struct room* new_room);

/********************************************************************************
* room_vector_pop: Raderar sista elementet (dimensioner för ett rum) längst bak
*                  i angiven vektor. Om detta mot förmodan misslyckas returneras
*                  felkod 1, annars returneras 0.
*
*                  - self: Pekare till vektorn vars sista element ska raderas.
********************************************************************************/
int room_vector_pop(struct room_vector* self);

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
                       FILE* ostream);

#endif /* ROOM_VECTOR_H_ */