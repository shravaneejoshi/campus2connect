// test.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fixed_buff_list.h"


struct stream {
    int call_count;
};

static const char *test_data[] = {
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890abcdefghijklmnopqrstuvwxyz",
    "12345678901234567890",
    NULL
};

uint8_t* stream_get(struct stream *s, unsigned int *data_len) {
    if (test_data[s->call_count] == NULL)
        return NULL;

    const char* str = test_data[s->call_count++];
    *data_len = strlen(str);
    uint8_t* data = malloc(*data_len);
    memcpy(data, str, *data_len);
    return data;
}

struct fixed_buff* fixed_buff_alloc(void) {
    return malloc(sizeof(struct fixed_buff));
}

void print_and_log(struct fixed_buff *head, FILE *log_fp) {
    int node_index = 0;
    while (head) {
        fprintf(log_fp, "Node %d: Length = %u | Data = ", node_index, head->data_len);
        for (unsigned int i = 0; i < head->data_len; i++) {
            fprintf(log_fp, "%c", head->data[i]);
        }
        fprintf(log_fp, "\n");
        head = head->next;
        node_index++;
    }
}

int main() {
    FILE *log_fp = fopen("output.log", "w");
    if (!log_fp) {
        perror("Error opening log file");
        return 1;
    }

    struct stream s = {0};
    struct fixed_buff* head = build_fixed_buff_list(&s);

    if (!head) {
        fprintf(log_fp, "ERROR: Failed to build buffer list.\n");
    } else {
        fprintf(log_fp, "SUCCESS: Buffer list created.\n");
        print_and_log(head, log_fp);
    }

    fclose(log_fp);
    return 0;
}
