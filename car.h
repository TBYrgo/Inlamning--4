#ifndef CAR_H_
#define CAR_H_

/*Inkluderingsdirektiv*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/********************************************************************************
* enum car_transmission: Enumration av växellådan
********************************************************************************/
enum car_transmission {
	AUTOMATIC,
	MANUAL
};

/********************************************************************************
* struct car: Strukt som innehåller bilens olika attribut.
********************************************************************************/
struct car 
{
	const char* brand;
	const char* model;
	const char* color;
	unsigned int year_of_launch;
	enum car_transmission transmission;

	void (*change_color)(struct car*, char* new_colour);
	void (*change_transmission)(struct car*);
	void (*print)(struct car*, FILE* ostream);
};

/********************************************************************************
* car_init: Funktion som intierar varje bil.
********************************************************************************/
void car_init(struct car* c, char* brand, char* model, char* color, unsigned int year_of_launch, enum car_transmission transmission);

/********************************************************************************
* car_clear: Funktion som nollställer önskad bil
********************************************************************************/
void car_clear(struct car* c);

/********************************************************************************
* car_new: Funktion som lägger till en ny bil på heapen. Retunerar en pekare till
*		   den nya bilen.
********************************************************************************/
struct car* car_new(char* brand, char* model, char* color, unsigned int year_of_launch, enum car_transmission transmission);

/********************************************************************************
* car_delete: Funktion som tar bort önskad bil.
********************************************************************************/
void car_delete(struct car** c);

/********************************************************************************
* car_print: Funktion som skriver ut innehållet för varje bil.
********************************************************************************/
void car_print(struct car* c, FILE* ostream);

/********************************************************************************
* car_change_color: Funktion som byter färgen på bilen.
********************************************************************************/
void car_change_color(struct car* c, char* new_color);

/********************************************************************************
* car_change_transmission: Funktion som byter växellåda på bilen.
********************************************************************************/
void car_change_transmission(struct car* c);

/********************************************************************************
* file_read: Funktion som läser av en textfil och skriver ut i terminalen.
********************************************************************************/
void file_read(const char* filepath);

#endif /* CAR_H_ */