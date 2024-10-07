#include "stdio.h"
// Convert from celsius to fahrenheit
float celsius_to_fahrenheit(float tempature){
    float a = 9;
    float b = 5;
    return ((a/b)*tempature)+32;
}
// Convert from fahrenheit to celsius
float fahrenheit_to_celsius(float tempature){
    float a = 5;
    float b = 9;
    return (a/b)*(tempature-32);
}
// Convert from celsius to kelvin
float celsius_to_kelvin(float tempature){
    return tempature+273.15;
}
// Convert from kelvin to celsius
float kelvin_to_celsius(float tempature){
return tempature-273.15;
}
int main(int argc, char *argv[])
{
    // init to imposible and itentical values
	int convertFrom = 5;
	int convertTo = 5;
	float temp;
	printf("Enter the tempature: ");
	scanf("%f", &temp);
	// Only let them move on if the selections are less then 3 and are diffrent
	while((convertFrom == convertTo) || convertFrom > 3 || convertTo > 3){
	printf("What do you want to convert from:\n(1). Celsius\n(2). Fahrenheit\n(3). Kelvin\n:");
	scanf("%d", &convertFrom);
	printf("What do you want to convert to:\n(1). Celsius\n(2). Fahrenheit\n(3). Kelvin\n:");
	scanf("%d", &convertTo);
	// Tell them what they did wrong
	if(convertFrom == convertTo){
		// My program can actually handle this but its required to do this.
		printf("Please don't convert to the thing your converting from the same thing!\n");
	}
	if(convertTo>3){
		printf("Please only input 1,2, or 3 for what your converting to.\n");
	}
	if(convertFrom>3){
		printf("Please only input 1,2, or 3 for what your converting from.\n");
	}
	}
	// Convert whatever they give to celsius
	if(convertFrom==2){
	    temp=fahrenheit_to_celsius(temp);
	}

	else if(convertFrom==3){
	    temp=kelvin_to_celsius(temp);
	}
	float conveted = temp;
	char tempsymbol = 'C';
	// Depending on what they selected we pick the symol at the end of the tempature message and convert the tepature
	if(convertTo == 2){
	    tempsymbol = 'F';
	    conveted = celsius_to_fahrenheit(temp);
	}
	else if(convertTo == 3){
	    tempsymbol = 'K';
	    conveted = celsius_to_kelvin(temp);
	}
	else{
	    conveted = temp;
	}
	printf("Converted temperature: %f%c\n",conveted,tempsymbol);
	// im doing this in Fahrenheit because thats what i know
	float farhren = celsius_to_fahrenheit(temp);
	printf("Temperature category: ");
	char advisery[50];
	//give output
	if(convertTo == 3 && conveted<0){
	    printf("Impossably cold!\n");
	    printf("Weather advisory: Don't leave the house.");
	}
	else if(farhren<32){
	    printf("Freazing\n");
		printf("Weather advisory: Bundle up!");
	}
	else if(farhren<60){
	    printf("Chilly\n");
		printf("Weather advisory: Wear a jacket.");
	}
	else if(farhren<75){
	    printf("Mild\n");
		printf("Weather advisory: Up to you!");
	}
	else if(farhren<90){
	    printf("Hot\n");
		printf("Weather advisory: Wear cool clothing.");
	}
	else if(farhren<110){
	    printf("Really hot\n");
		printf("Weather advisory: May not want to leave the house.");
	}
	else if(farhren>110){
	    printf("Burning\n");
		printf("Weather advisory: Don't leave the house and stay cool.");
	}
	return 1;
}
