#include "car.h"
/********************************************************************************
main: Ett program som skapar en strukt för en bil som innehåller följande attribut:  
	  -Brand
	  -Model
	  -Colour
	  -Year_of_launch
	  -Transmission
********************************************************************************/
int main(void)
{	
	/*Initierar strukten och arrayen*/
	struct car car1, car2, car3;
	struct car* cars[] = {&car1, &car2, &car3};

	/*Initierar innehållet i varje bil*/
	car_init(&car1, "Volvo", "V70", "Black", 1995, MANUAL);
	car_init(&car2, "BMW", "Z3", "Blue", 2001, AUTOMATIC );
	car_init(&car3, "Skoda", "Octavia RS", "White", 2003, MANUAL);

	/*Öppnar en textfil*/
	FILE* ostream = fopen("cars.txt", "a");

	/*Skriver över innehållet i arrayen till textfilen */
	for (int i = 0; i < sizeof(cars) / sizeof(cars[0]); i++) 
	{
		car_print(cars[i], ostream);
		
	}
	
	/*Byter färg och växellåda på bil 3 och lägger till i textfilen*/
	car3.change_color(&car3, "Green");
	car3.change_transmission(&car3);
	car3.print(&car3, ostream);
	fclose(ostream);

	/*Läser av textfilen och skriver ut i terminalen*/
	file_read("cars.txt");

	return 0;
}