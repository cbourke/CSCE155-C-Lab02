#include <stdio.h>

int main(){
	double area, base, height;
		
	printf("Please type in the base and height(separated by a space) and press Enter: ");
	scanf("%lf%lf",&base, &height);
	
	area = 1/2*base*height;
	
	printf("The area is %f sq. units.\n", area);
	
	return 0;
}