#include <stdio.h>
#include <bsp.h>

#include <bsp/io.h> //Everything we need is in io.h


stm32f4_gpio_config led3config =
{
	.fields={
		.pin_first = STM32F4_GPIO_PIN(3, 12),
	.pin_last = STM32F4_GPIO_PIN(3, 12),
	.mode = STM32F4_GPIO_MODE_OUTPUT,
	.otype = STM32F4_GPIO_OTYPE_PUSH_PULL,
	.ospeed = STM32F4_GPIO_OSPEED_2_MHZ,
	.pupd = STM32F4_GPIO_NO_PULL,
	.output = 1,
	.af = 0
   }
};  



rtems_task Init(
  rtems_task_argument argument
)
{
  rtems_interval    one_second;

  puts( "\n\n*** LED BLINKER -- task wake after ***" );

  one_second = 1 * rtems_clock_get_ticks_per_second();

    stm32f4_gpio_set_config(&led3config); 

  while (1) {

    (void) rtems_task_wake_after( one_second );
      stm32f4_gpio_set_output(STM32F4_GPIO_PIN(3,12), 0); 

    (void) rtems_task_wake_after( one_second );
        stm32f4_gpio_set_output(STM32F4_GPIO_PIN(3,12), 1); 

  }

  (void) rtems_task_delete( RTEMS_SELF );
}
