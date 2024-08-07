/******************************************************************************
 *                                 TEST SUITE                                 *
 *                                                                            *
 *   The Test Suite runs automatic tests to ensure various parts of the       *
 * application behave as they are supposed to.                                *
 *                                                                            *
 * Currently tested modules:                                                  *
 *   - common/datagram/datagram.c                                             *
 *   - common/datagram/execute.c                                              *
 *   - common/datagram/status.c                                               *
 ******************************************************************************/

#include <stdio.h>
#include "common/util/string.h"
#include "common/io/io.h"
#include "test/common/datagram/datagram.h"
#include "test/server/worker_datagrams.h"

#define TEST_DATA_DIR "test_data"

int IS_DEBUG = 0;

int main(int argc, char const *argv[]) {
    // Setup
    char* cwd = get_cwd();
    char* test_data_dir = join_paths(2, cwd, TEST_DATA_DIR);

    if (argc > 1 && STRING_EQUAL(argv[1], "-d")) IS_DEBUG = 1;

    // Test runners
    test_datagram(test_data_dir);
    test_worker_datagram(test_data_dir);

    // Cleanup
    free(test_data_dir);

    printf("All tests passed!\n");
    
    return 0;
}
