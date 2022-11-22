#ifndef ROOM_H_
#define ROOM_H_

/* Inkluderingsdirektiv: */
#include <stdio.h>

/********************************************************************************
* room: Strukt f�r lagring av dimensioner f�r ett rum.
********************************************************************************/
struct room
{
   double length; /* Rummets l�ngd i meter. */
   double width;  /* Rummets bredd i meter. */
   double height; /* Rummets h�jd i meter. */
};

/********************************************************************************
* room_init: Lagrar dimensionerar f�r angivet rum.
*
*            - self  : Pekare till objektet som ska lagrar parametrarna.
*            - length: Rummets l�ngd i meter.
*            - width : Rummets bredd i meter.
*            - heigth: Rummets h�jd i meter.
********************************************************************************/
void room_init(struct room* self,
               const double length,
               const double width,
               const double height);

/********************************************************************************
* room_clear: Nollst�ller angivet rums parametrar.
*
*             - self: Pekare till objektet som lagrar parametrarna.
********************************************************************************/
void room_clear(struct room* self);

/********************************************************************************
* room_get_area: Returnerar angivet rums area m�tt i kvadratmeter.
*
*                - self: Pekare till objektet som lagrar rummets parametrar.
********************************************************************************/
static inline double room_get_area(const struct room* self)
{
   return self->length * self->width;
}

/********************************************************************************
* room_get_volume: Returnerar angivet rums volym m�tt i kubikmeter.
*
*                  - self: Pekare till objektet som lagrar rummets parametrar.
********************************************************************************/
static inline double room_get_volume(const struct room* self)
{
   return self->length * self->width * self->height;
}

/********************************************************************************
* room_print: Skriver ut dimensionerna p� angivet rum via angiven utstr�m,
*             d�r standardutenheten stdout anv�nds f�r utskrift i terminalen.
*
*             - self   : Pekare till objektet som lagrar rummets parametrar.
*             - ostream: Pekare till angiven utstr�m (default = stdout).
********************************************************************************/
void room_print(const struct room* self,
                FILE* ostream);

#endif /* ROOM_H_ */