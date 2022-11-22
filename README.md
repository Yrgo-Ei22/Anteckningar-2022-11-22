# Anteckningar 2022-11-22
Demonstration av dynamisk minnesallokering i C via funktioner malloc, realloc och free.

Filen "heap.c" utgör ett enkelt exempel på dynamisk minnesallokering, omallokering samt frigörande av ett dynamiskt
fält innehållande flyttal. Här beskrivs också ovanstående funktioner i detalj.

Resterande filer demonstrerar hur vektorer (dynamiska arrayer) för lagring av rumsdimensioner kan implementeras i C 
via en strukt döpt room_vector, dvs. objekt av strukten room, som skapades under en tidigare lektion.

Just denna vektorstrukt är alltså anpassad för lagring av rumsdimensioner, men motsvarande vektor kan implementeras
med nästan samma kod, enbart modifierad så att motsvarande datatyp allokeras och används i stället för int. Exempelvis
ska då struktens fältpekare rooms sättas till önskad datatyp (och ett mer lämpligt namn bör nämnas, såsom data). 
Vid omallokering med realloc (och malloc, men används inte här) bör också minne allokeras för önskad datatyp 
multiplicerat med antalet element i fältet.

Filen "room_vector C++.zip" innehåller motsvarande C++-kod.