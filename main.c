#include "car.h"
/********************************************************************************
main: Ett program som skapar en strukt f�r en bil som inneh�ller f�ljande attribut:  
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

	/*Initierar inneh�llet i varje bil*/
	car_init(&car1, "Volvo", "V70", "Black", 1995, MANUAL);
	car_init(&car2, "BMW", "Z3", "Blue", 2001, AUTOMATIC );
	car_init(&car3, "Skoda", "Octavia RS", "White", 2003, MANUAL);

	/*�ppnar en textfil*/
	FILE* ostream = fopen("cars.txt", "a");

	/*Skriver �ver inneh�llet i arrayen till textfilen */
	for (int i = 0; i < sizeof(cars) / sizeof(cars[0]); i++) 
	{
		car_print(cars[i], ostream);
		
	}
	
	/*Byter f�rg och v�xell�da p� bil 3 och l�gger till i textfilen*/
	car3.change_color(&car3, "Green");
	car3.change_transmission(&car3);
	car3.print(&car3, ostream);
	fclose(ostream);

	/*L�ser av textfilen och skriver ut i terminalen*/
	file_read("cars.txt");

	return 0;
}