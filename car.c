#include "car.h"

void car_init(struct car* c, char* brand, char* model, char* color, unsigned int year_of_launch, enum car_transmission transmission)
{
	c->brand = brand;
	c->model = model;
	c->color = color;
	c->year_of_launch = year_of_launch;
	c->transmission = transmission;

	c->change_color = car_change_color;
	c->change_transmission = car_change_transmission;
	c->print = car_print;
}

void car_clear(struct car* c)
{
	c->brand = 0;
	c->model = 0;
	c->color = 0;
	c->year_of_launch = 0;
	c->transmission = AUTOMATIC;
}

struct car* car_new(char* brand, char* model, char* color, unsigned int year_of_launch, enum car_transmission transmission)
{
	// Allocate memory for the new car object on the heap.
	struct car* c = malloc(sizeof(struct car));

	if (!c) return 0;

	// Initialize the car object using the car_init function.
	car_init(c, brand, model, color, year_of_launch, transmission);

	// Return a pointer to the newly created and initialized car object.
	return c;
}

void car_delete(struct car** c)
{
	// Check if the car object's pointer is null.
	if (*c == NULL)
	{
		return;
	}

	// Free the memory occupied by the car object.
	free(*c);

	// Set the car object's pointer to null.
	*c = NULL;
	return;
}

void car_print(struct car* c, FILE* ostream)
{
	if (!ostream) ostream = stdout;

	fprintf(ostream, "--------------------------------------------------------------------------------\n");
	fprintf(ostream, "Brand: %s\n", c->brand);
	fprintf(ostream, "Model: %s\n", c->model);
	fprintf(ostream, "Color: %s\n", c->color);
	fprintf(ostream, "Year of Launch: %u\n", c->year_of_launch);
	if (c->transmission == 1) {

		fprintf(ostream, "Transmission: MANUAL\n");
	}

	else if (c->transmission == 0) {

		fprintf(ostream, "Transmission: AUTOMATIC\n");
	}
	fprintf(ostream, "--------------------------------------------------------------------------------\n\n");
}

static void car_change_color(struct car* c, char* new_color)
{
	// Set the car object's color to the new color.
	c->color = new_color;
}

static void car_change_transmission(struct car* c)
{
	// Check the car object's current transmission and set it to the opposite value.
	if (c->transmission == AUTOMATIC) {
		c->transmission = MANUAL;
	}
	else {
		c->transmission = AUTOMATIC;
	}
}

void file_read(const char* filepath)
{
	FILE* f = fopen(filepath, "r");
	if (!f) return;
	char s[100] = { '\0' };

	while (fgets(s, sizeof(s), f))
	{
		printf("%s", s);
	}

	fclose(f);
	return;
}