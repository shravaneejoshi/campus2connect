// fixed_buff_list.c
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "fixed_buff_list.h"

#define FIXED_BUFF_LEN 32


struct fixed_buff {
    uint8_t data[FIXED_BUFF_LEN];
    unsigned int data_len;
    struct fixed_buff *next;
};


extern struct fixed_buff* fixed_buff_alloc(void);
extern uint8_t* stream_get(struct stream *s, unsigned int *data_len);

struct fixed_buff* build_fixed_buff_list(struct stream *s) {
    uint8_t* curr_data;
    unsigned int curr_data_len;

    struct fixed_buff *head = NULL, *tail = NULL;

    while ((curr_data = stream_get(s, &curr_data_len)) != NULL) {
        unsigned int offset = 0;

        while (curr_data_len > 0) {
            struct fixed_buff *node = fixed_buff_alloc();
            if (!node) return NULL;

            unsigned int copy_len = curr_data_len > FIXED_BUFF_LEN ? FIXED_BUFF_LEN : curr_data_len;

            memcpy(node->data, curr_data + offset, copy_len);
            node->data_len = copy_len;
            node->next = NULL;

            if (!head) {
                head = node;
                tail = node;
            } else {
                tail->next = node;
                tail = node;
            }

            offset += copy_len;
            curr_data_len -= copy_len;
        }

        free(curr_data);  
    }

    return head;
}
