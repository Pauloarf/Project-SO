#include "common/datagram/datagram.h"
#include "common/datagram/execute.h"
#include "common/util/string.h"
#include "common/util/alloc.h"
#include "common/io/io.h"

#pragma region ======= REQUEST =======
ExecuteRequestDatagram create_execute_request_datagram() {
    #define ERR NULL
    
    ExecuteRequestDatagram dg = SAFE_ALLOC(ExecuteRequestDatagram, sizeof(EXECUTE_REQUEST_DATAGRAM));
    dg->header = create_datagram_header();
    dg->header.mode = DATAGRAM_MODE_EXECUTE_REQUEST;

    memset(dg->data, 0, 300);

    return dg;
}

ExecuteRequestDatagram read_execute_request_datagram(int fd) {
    #define ERR NULL

    ExecuteRequestDatagram execute = calloc(1, sizeof(EXECUTE_REQUEST_DATAGRAM));
    SAFE_READ(fd, execute, sizeof(EXECUTE_REQUEST_DATAGRAM));

    return execute;
}

ExecuteRequestDatagram read_partial_execute_request_datagram(int fd, DATAGRAM_HEADER header) {
    #define ERR NULL
    
    ExecuteRequestDatagram execute = calloc(1, sizeof(EXECUTE_REQUEST_DATAGRAM));
    execute->header = header;

    SAFE_READ(fd, (((void*)execute) + sizeof(DATAGRAM_HEADER)), sizeof(EXECUTE_REQUEST_DATAGRAM) - sizeof(DATAGRAM_HEADER));

    return execute;
}

char* execute_request_datagram_to_string(ExecuteRequestDatagram dg, int expandEnums, int stringPayload) {
    char* dh = datagram_header_to_string(&dg->header, expandEnums);
    char* bytes = stringPayload ? dg->data : bytes_to_hex_string(dg->data, EXECUTE_REQUEST_DATAGRAM_PAYLOAD_LEN, ':');

    char* str = isnprintf(
        "ExecuteRequestDatagram{ header: %s, data: '%s' }",
        dh,
        bytes
    );

    if (!stringPayload) free(bytes);
    free(dh);

    return str;
}
#pragma endregion

#pragma region ======= RESPONSE =======
ExecuteResponseDatagram create_execute_response_datagram() {
    #define ERR NULL
    
    ExecuteResponseDatagram dg = SAFE_ALLOC(ExecuteResponseDatagram, sizeof(EXECUTE_RESPONSE_DATAGRAM));
    dg->header = create_datagram_header();
    dg->header.mode = DATAGRAM_MODE_EXECUTE_RESPONSE;

    dg->taskid = 0;

    return dg;
}

ExecuteResponseDatagram read_execute_response_datagram(int fd) {
    #define ERR NULL

    ExecuteResponseDatagram execute = calloc(1, sizeof(EXECUTE_RESPONSE_DATAGRAM));
    SAFE_READ(fd, execute, sizeof(EXECUTE_RESPONSE_DATAGRAM));

    return execute;
}

ExecuteResponseDatagram read_partial_execute_response_datagram(int fd, DATAGRAM_HEADER header) {
    #define ERR NULL
    
    ExecuteResponseDatagram execute = calloc(1, sizeof(EXECUTE_RESPONSE_DATAGRAM));
    execute->header = header;

    SAFE_READ(fd, (((void*)execute) + sizeof(DATAGRAM_HEADER)), sizeof(EXECUTE_RESPONSE_DATAGRAM) - sizeof(DATAGRAM_HEADER));

    return execute;
}

char* execute_response_datagram_to_string(ExecuteResponseDatagram dg, int expandEnums) {
    char* dh = datagram_header_to_string(&dg->header, expandEnums);
    
    char* str = isnprintf(
        "ExecuteResponseDatagram{ header: %s, taskid: %d }",
        dh,
        dg->taskid
    );

    free(dh);

    return str;
}
#pragma endregion
