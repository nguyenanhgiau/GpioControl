#ifndef GPIO_CONTROL_H
#define GPIO_CONTROL_H

#define LED_LEFT   1
#define LED_RIGHT  2

#ifdef __cplusplus
extern "C" {
#endif

void set_gpio(unsigned int id, unsigned int enable);

#ifdef __cplusplus
}
#endif

#endif // GPIO_CONTROL_H
