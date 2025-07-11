#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>      

#define FIXED_BUFF_LEN 32

struct fixed_buff {
    uint8_t data[FIXED_BUFF_LEN];
    unsigned int data_len;
    struct fixed_buff *next;
};


struct stream {
    FILE *fp;
};

struct fixed_buff* fixed_buff_alloc(void);
uint8_t* stream_get(struct stream *s, unsigned int *data_len);
void* my_memcpy(void* dest, const void* src, size_t n);

struct fixed_buff* build_fixed_buff_list(struct stream *s) {
    uint8_t* curr_data;
    unsigned int curr_data_len;
    struct fixed_buff *head = NULL;
    struct fixed_buff *tail = NULL;

    while ((curr_data = stream_get(s, &curr_data_len))) {
        unsigned int offset = 0;
        while (curr_data_len > 0) {
            struct fixed_buff *node = fixed_buff_alloc();
            if (node == NULL) {
                return head; // Allocation failure
            }
            unsigned int copy_len = curr_data_len > FIXED_BUFF_LEN ? FIXED_BUFF_LEN : curr_data_len;
            my_memcpy(node->data, curr_data + offset, copy_len);
            node->data_len = copy_len;
            node->next = NULL;

            if (head == NULL) {
                head = node;
                tail = node;
            } else {
                tail->next = node;
                tail = node;
            }

            offset += copy_len;
            curr_data_len -= copy_len;
        }
    }

    return head;
}
