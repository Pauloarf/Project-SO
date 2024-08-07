/******************************************************************************
 *                             IO FIFO UTILITY                                *
 *                                                                            *
 *   The IO FIFO Utility module contains unified names for FIFOs used         *
 * throughout the application.                                                *
 ******************************************************************************/

#ifndef COMMON_IO_FIFO_H
#define COMMON_IO_FIFO_H

/**
 * @brief The name for the server fifo.
 */
#define SERVER_FIFO "sv_fifo"

/**
 * @brief The name for the client fifo.
 */
#define CLIENT_FIFO "cl_fifo"

/**
 * @brief The name of tasks files.
*/
#define TASK "task_"

/**
 * @brief Creates a fifo, checking for errors.
*/
#define SAFE_FIFO_SETUP(name, mode) ({\
    unlink(name);\
    int status = mkfifo(name, mode);\
    if (status == -1) {\
        perror("Unable to create fifo");\
    }\
    (status);\
})

#endif