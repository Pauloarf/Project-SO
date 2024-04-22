/******************************************************************************
 *                               WORKER PROCESS                               *
 *                                                                            *
 *   The worker process is responsible for executing the different tasks that *
 * are assigned to it by the operator process. On creation, it shall connect  *
 * to the event system of the operator process and transmit a ready signal,   *
 * upon which the operator process shall distribute tasks as they arrive.     *
 *   The amount of worker processes to be created depends on the server input *
 * parallel_tasks.                                                            *
 ******************************************************************************/