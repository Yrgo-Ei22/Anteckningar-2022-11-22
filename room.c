#include "room.h"

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
   const double height)
{
   self->length = length;
   self->height = height;
   self->width = width;
   return;
}

/********************************************************************************
* room_clear: Nollst�ller angivet rums parametrar.
*
*             - self: Pekare till objektet som lagrar parametrarna.
********************************************************************************/
void room_clear(struct room* self)
{
   self->length = 0;
   self->height = 0;
   self->width = 0;
   return;
}

/********************************************************************************
* room_print: Skriver ut dimensionerna p� angivet rum via angiven utstr�m,
*             d�r standardutenheten stdout anv�nds f�r utskrift i terminalen.
*
*             - self   : Pekare till objektet som lagrar rummets parametrar.
*             - ostream: Pekare till angiven utstr�m (default = stdout).
********************************************************************************/
void room_print(const struct room* self,
                FILE* ostream)
{
   if (!ostream) ostream = stdout;
   fprintf(ostream, "--------------------------------------------------------------------------------\n");

   fprintf(ostream, "Length: %lg m\n", self->length);
   fprintf(ostream, "Width: %lg m\n", self->width);
   fprintf(ostream, "Height: %lg m\n", self->height);

   fprintf(ostream, "Area: %lg m^2\n", room_get_area(self));
   fprintf(ostream, "Volume: %lg m^3\n", room_get_volume(self));

   fprintf(ostream, "--------------------------------------------------------------------------------\n\n");
   return;
}