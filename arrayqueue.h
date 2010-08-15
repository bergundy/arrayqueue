/**
 * =====================================================================================
 * @file   arrayqueue.h
 * @brief  header file for arrayqueue macros
 * @date   07/12/2010 03:34:11 PM
 * @author Roey Berman, (roey.berman@gmail.com)
 * =====================================================================================
 */
#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H 

#define AQ_DEFINE_STRUCT(struct_name, node_type) \
struct struct_name {                             \
    node_type *nodes;                            \
    size_t     size;                             \
    size_t     used;                             \
    off_t      front;                            \
    off_t      rear;                             \
}

#define AQ_NODES_FREE(q) ( (q)->size - (q)->used )
#define AQ_FULL(q)       ( (q)->used == (q)->size )
#define AQ_EMPTY(q)      ( (q)->used == 0 )

#define AQ_REAR_NV(q)    ( (q)->nodes + (q)->rear )
#define AQ_REAR(q)       ( AQUEUE_EMPTY(q) ? NULL : AQUEUE_REAR_NV(q) )

#define AQ_FRONT_NV(q)   ( (q)->nodes + (q)->front )
#define AQ_FRONT(q)      ( AQUEUE_FULL(q) ? NULL : AQUEUE_FRONT_NV(q) )

#define AQ_FIN_GET(q)    ( (q)->rear  = ( (q)->rear  + 1 ) % (q)->size, (q)->used-- )
#define AQ_FIN_PUT(q)    ( (q)->front = ( (q)->front + 1 ) % (q)->size, (q)->used++ )

#endif /* ARRAYQUEUE_H */
