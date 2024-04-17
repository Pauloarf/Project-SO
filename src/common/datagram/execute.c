#include "common/datagram/datagram.h"
#include "common/datagram/execute.h"
#include "common/util/string.h"
#include "common/io/io.h"

ExecuteDatagram create_execute_datagram() {
    EXECUTE_DATAGRAM dg = {
        .header = create_datagram_header(),
        .data = { 0 }
    };

    // "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Morbi lobortis, enim eu fringilla elementum, leo erat bibendum nulla, at efficitur lorem diam eget nisi. Proin euismod, urna a cursus semper, felis elit sollicitudin purus, in lobortis dolor leo a est. Praesent aliquam lacus nec massa laoreet"
}

ExecuteDatagram read_execute_datagram(int fd) {
    #define ERR NULL

    ExecuteDatagram execute = calloc(1, sizeof(EXECUTE_DATAGRAM));
    SAFE_READ(fd, execute, sizeof(EXECUTE_DATAGRAM));

    return execute;
}

ExecuteDatagram read_partial_execute_datagram(int fd, DATAGRAM_HEADER header) {
    #define ERR NULL
    
    ExecuteDatagram execute = calloc(1, sizeof(EXECUTE_DATAGRAM));
    execute->header = header;

    SAFE_READ(fd, (((void*)execute) + sizeof(DATAGRAM_HEADER)), sizeof(EXECUTE_DATAGRAM) - sizeof(DATAGRAM_HEADER));

    return execute;
}

char* execute_datagram_to_string(ExecuteDatagram dg, int expandEnums, int stringPayload) {
    char* dh = datagram_header_to_string(&dg->header, expandEnums);
    char* bytes = stringPayload ? dg->data : bytes_to_hex_string(dg->data, EXECUTE_DATAGRAM_PAYLOAD_LEN, ':');

    char* str = isnprintf(
        "ExecuteDatagram{ header: %s, data: '%s' }",
        dh,
        bytes
    );

    if (!stringPayload) free(bytes);
    free(dh);

    return str;
}
