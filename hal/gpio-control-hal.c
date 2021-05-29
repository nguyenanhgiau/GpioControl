#define LOG_TAG "gpio-control"

#include <stdlib.h>
#include <stdint.h> 
#include <string.h> 
#include <fcntl.h> 
#include <pthread.h> 
#include <sys/ioctl.h>
#include <sys/types.h> 
#include <errno.h>
#include <unistd.h>
#include "../../external/libgpio-control-hal/gpio-control-hal.h"

/* Replace by the path to your driver */
#define RIGHT_FILE      "/sys/class/gpio/gpio21/value"
#define LEFT_FILE       "/sys/class/gpio/gpio21/value"

static int write_int(char const* path, int value) {
     int fd, bytes;
     char buffer[20];
     fd = open(path, O_RDWR);
     if (fd >= 0) {
         bytes = sprintf(buffer, "%d\n", value);
         int amt = write(fd, buffer, bytes);
         close(fd);
         return amt == -1 ? -errno : 0;
     } else {
         return -errno;
     }
} 

void set_gpio(unsigned int id, unsigned int enable) {
	switch(id) {
		case LED_LEFT: 
		write_int(LEFT_FILE, enable? 1:0); 
		break;
		case LED_RIGHT: 
		write_int(RIGHT_FILE, enable? 1:0); 
		break;
		default: 
		break;
	}
	return;
}
