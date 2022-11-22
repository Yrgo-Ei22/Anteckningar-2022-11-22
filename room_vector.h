/********************************************************************************
* room_vector.h: Inneh�ller funktionalitet f�r lagring av dimensioner f�r rum
*                i dynamiska arrayer (vektorer) via strukten room_vector samt
*                associerade funktioner.
********************************************************************************/
#ifndef ROOM_VECTOR_H_
#define ROOM_VECTOR_H_

/* Inkluderingsdirektiv: */
#include "room.h"
#include <stdlib.h>

/********************************************************************************
* room_vector: Strukt f�r lagring av rum-dimensioner i en dynamisk array.
*              Elementen som lagras utg�rs av objekt av strukten room.
********************************************************************************/
struct room_vector
{
   struct room* rooms; /* Pekare till f�lt inneh�llande rum. */
   size_t size;        /* Vektorns storlek, dvs. antalet room-objekt i f�ltet. */
};

/********************************************************************************
* room_vector_init: Initierar ny tom vektor f�r lagring av rumdimensioner.
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
* room_vector_clear: T�mmer angiven vektor.
*
*                    - self: Pekare till vektorn som ska t�mmas.
********************************************************************************/
static inline void room_vector_clear(struct room_vector* self)
{
   free(self->rooms);
   room_vector_init(self);
   return;
}

/********************************************************************************
* room_vector_begin: Returnerar adressen till det f�rsta rummet i angiven vektor.
*                    Om vektorn �r tom returneras null.
*
*                    - self: Pekare till vektorn.
********************************************************************************/
static inline struct room* room_vector_begin(const struct room_vector* self)
{
   return self->rooms;
}

/********************************************************************************
* room_vector_end: Returnerar adressen efter det sista rummet i angiven vektor.
*                  Om vektorn �r tom returneras null.
*
*                  - self: Pekare till vektorn.
********************************************************************************/
static inline struct room* room_vector_end(const struct room_vector* self)
{
   return self->rooms + self->size;
}

/********************************************************************************
* room_vector_push: L�gger till dimensioner f�r ett nytt rum l�ngst bak i
*                   angiven vektor. Om till�gget lyckas returneras 0, annars
*                   returneras felkod 1.
*
*                   - self: Pekare till vektorn som ska tilldelas.
*                   - new_room: Pekare till objekt inneh�llande det nya
*                               rummets dimensioner.
********************************************************************************/
int room_vector_push(struct room_vector* self,
                     const struct room* new_room);

/********************************************************************************
* room_vector_pop: Raderar sista elementet (dimensioner f�r ett rum) l�ngst bak
*                  i angiven vektor. Om detta mot f�rmodan misslyckas returneras
*                  felkod 1, annars returneras 0.
*
*                  - self: Pekare till vektorn vars sista element ska raderas.
********************************************************************************/
int room_vector_pop(struct room_vector* self);

/********************************************************************************
* room_vector_print: Skriver ut information om samtliga rum lagrade i angiven
*                    vektor. Utskriften sker via godtycklig utstr�m, d�r
*                    standardutenheten stdout anv�nds som default f�r utskrift
*                    i terminalen.
*
*                   - self   : Pekare till vektorn vars inneh�ll ska skrivas ut.
*                   - ostream: Pekare till godtycklig utstr�m (default = stdout).
********************************************************************************/
void room_vector_print(const struct room_vector* self,
                       FILE* ostream);

#endif /* ROOM_VECTOR_H_ */