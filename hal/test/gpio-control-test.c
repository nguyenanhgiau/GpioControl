

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "../gpio-control-hal.h"


static void print_usage() {
    printf("Usage: setgpio [-l value] [-r value]\n");
 	printf("\t where:\n"); 	printf("\t\t -l = Left Led:\n");
 	printf("\t\t -r = Right Led:\n");
 	printf("\t\t value = 0|1\n");
 } 
int main(int argc, char *argv[]) {
 	int option = -1;
 	int enable = 0;
 	if (argc < 2) {
 		print_usage();
 		exit(EXIT_FAILURE);
 	} 	

	while ((option = getopt(argc, argv,"l:r:h:")) != -1) {
 		switch (option) {
 			case 'l' :
 			enable = atoi(optarg);
 			printf("Set LED_LEFT=%d\n", enable);
 			set_gpio(LED_LEFT, enable);
 				break;
 			case 'r' :
 			enable = atoi(optarg);
 			printf("Set LED_RIGHT=%d\n", enable);
 			set_gpio(LED_RIGHT, enable);
 				break;
  			default: 				
				print_usage();
 				exit(EXIT_FAILURE);
 		}
 	}
 	return 0;
 }


