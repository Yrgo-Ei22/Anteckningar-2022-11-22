#ifndef ROOM_H_
#define ROOM_H_

/* Inkluderingsdirektiv: */
#include <stdio.h>

/********************************************************************************
* room: Strukt för lagring av dimensioner för ett rum.
********************************************************************************/
struct room
{
   double length; /* Rummets längd i meter. */
   double width;  /* Rummets bredd i meter. */
   double height; /* Rummets höjd i meter. */
};

/********************************************************************************
* room_init: Lagrar dimensionerar för angivet rum.
*
*            - self  : Pekare till objektet som ska lagrar parametrarna.
*            - length: Rummets längd i meter.
*            - width : Rummets bredd i meter.
*            - heigth: Rummets höjd i meter.
********************************************************************************/
void room_init(struct room* self,
               const double length,
               const double width,
               const double height);

/********************************************************************************
* room_clear: Nollställer angivet rums parametrar.
*
*             - self: Pekare till objektet som lagrar parametrarna.
********************************************************************************/
void room_clear(struct room* self);

/********************************************************************************
* room_get_area: Returnerar angivet rums area mätt i kvadratmeter.
*
*                - self: Pekare till objektet som lagrar rummets parametrar.
********************************************************************************/
static inline double room_get_area(const struct room* self)
{
   return self->length * self->width;
}

/********************************************************************************
* room_get_volume: Returnerar angivet rums volym mätt i kubikmeter.
*
*                  - self: Pekare till objektet som lagrar rummets parametrar.
********************************************************************************/
static inline double room_get_volume(const struct room* self)
{
   return self->length * self->width * self->height;
}

/********************************************************************************
* room_print: Skriver ut dimensionerna på angivet rum via angiven utström,
*             där standardutenheten stdout används för utskrift i terminalen.
*
*             - self   : Pekare till objektet som lagrar rummets parametrar.
*             - ostream: Pekare till angiven utström (default = stdout).
********************************************************************************/
void room_print(const struct room* self,
                FILE* ostream);

#endif /* ROOM_H_ */