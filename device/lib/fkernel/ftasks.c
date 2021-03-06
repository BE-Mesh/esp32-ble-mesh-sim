/*
 * ftasks.c
 * Contains all the definition for the FreeRTOS task library on ESP.
 * Can remap these to thread_create.
 */

#include "ftasks.h"

void vTaskDelete(void* task_to_delete) { // Delete a task object
  return;
}

int xTaskCreate(TaskFunction_t t_fn,
		const char* const t_name,
		const unsigned int t_stack_dept,
		void* const t_params,
		unsigned int t_priority,
		void* t_task_handle) {
  return 0;
}

