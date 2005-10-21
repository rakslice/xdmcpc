/*
** xdmcp.h - XDMCP protocol definitions and structures
**
** Copyright (c) 2005 Peter Eriksson <pen@lysator.liu.se>
*/

#ifndef XDMCP_H
#define XDMCP_H 1

typedef unsigned char BYTE;

typedef enum {
    XDMCP_OP_BROADCASTQUERY = 1,
    XDMCP_OP_QUERY = 2,
    XDMCP_OP_INDIRECTQUERY = 3,
    XDMCP_OP_FORWARDQUERY = 4,
    XDMCP_OP_WILLING = 5,
    XDMCP_OP_UNWILLING = 6,
    XDMCP_OP_REQUEST = 7,
    XDMCP_OP_ACCEPT = 8,
    XDMCP_OP_DECLINE = 9,
    XDMCP_OP_MANAGE = 10,
    XDMCP_OP_REFUSE = 11,
    XDMCP_OP_FAILED = 12,
    XDMCP_OP_KEEPALIVE = 13,
    XDMCP_OP_ALIVE = 14,
    XDMCP_OP_LAST
} XDMCP_OPCODE;

typedef enum {
    XDMCP_STATE_START = 1,
    XDMCP_STATE_QUERY = 2,
    XDMCP_STATE_COLLECT_QUERY = 3,
    XDMCP_STATE_BROADCAST = 4,
    XDMCP_STATE_COLLECT_BROADCAST_QUERY = 5,
    XDMCP_STATE_UPDATE_BROADCAST_WILLING = 6,
    XDMCP_STATE_INDIRECT = 7,
    XDMCP_STATE_COLLECT_INDIRECT_QUERY = 8,
    XDMCP_STATE_UPDATE_INDIRECT_WILLING = 9,
    XDMCP_STATE_START_CONNECTION = 10,
    XDMCP_STATE_AWAIT_REQUEST_RESPONSE = 11,
    XDMCP_STATE_MANAGE = 12,
    XDMCP_STATE_AWAIT_MANAGE_RESPONSE = 13,
    XDMCP_STATE_STOP_CONNECTION = 14,
    XDMCP_STATE_RUN_SESSION = 15,
    XDMCP_STATE_KEEP_ALIVE = 16,
    XDMCP_STATE_AWAIT_ALIVE = 17,
    XDMCP_STATE_RESET_DISPLAY = 18,
} XDMCP_STATE;


extern int
xdmcp_send(int fd, int op, void *buf, size_t len);

extern int
xdmcp_recv(int fd, int *op, void *buf, size_t len, int timeout);
    
#endif
