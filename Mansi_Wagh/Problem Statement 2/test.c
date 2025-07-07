#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define FIXED_BUFF_LEN 32

struct fixed_buff {
    uint8_t data[FIXED_BUFF_LEN];
    unsigned int data_len;
    struct fixed_buff *next;
};

struct stream {
    int dummy; // not used
};

// Test data for the stream
uint8_t test_data1[50];
uint8_t test_data2[20];
int call_count = 0;

// Mock fixed_buff_alloc
struct fixed_buff* fixed_buff_alloc(void) {
    struct fixed_buff *b = (struct fixed_buff*)malloc(sizeof(struct fixed_buff));
    if (b) {
        b->data_len = 0;
        b->next = NULL;
    }
    return b;
}

// Mock stream_get
uint8_t* stream_get(struct stream *s, unsigned int *data_len) {
    if (call_count == 0) {
        *data_len = 50;
        call_count++;
        return test_data1;
    } else if (call_count == 1) {
        *data_len = 20;
        call_count++;
        return test_data2;
    } else {
        return NULL;
    }
}

// Declaration of function to test
struct fixed_buff* build_fixed_buff_list(struct stream *s);

int main() {
    FILE *fout = fopen("output.txt", "w");
    if (!fout) {
        printf("Failed to open output.txt\n");
        return 1;
    }

    // Fill test data with simple pattern
    for (int i = 0; i < 50; i++) test_data1[i] = (uint8_t)(i+1);
    for (int i = 0; i < 20; i++) test_data2[i] = (uint8_t)(i+101);

    struct stream s;
    struct fixed_buff *list = build_fixed_buff_list(&s);

    // Print the linked list
    int node_num = 1;
    struct fixed_buff *curr = list;
    int total_bytes = 0;
    while (curr) {
        fprintf(fout, "Node %d: data_len = %u, data = ", node_num, curr->data_len);
        for (unsigned int j = 0; j < curr->data_len; j++) {
            fprintf(fout, "%d ", curr->data[j]);
        }
        fprintf(fout, "\n");
        total_bytes += curr->data_len;
        curr = curr->next;
        node_num++;
    }
    if (total_bytes == 70) {
        fprintf(fout, "SUCCESS: Total bytes = %d as expected.\n", total_bytes);
    } else {
        fprintf(fout, "ERROR: Total bytes = %d, expected 70.\n", total_bytes);
    }

    // Free the list
    curr = list;
    while (curr) {
        struct fixed_buff *tmp = curr;
        curr = curr->next;
        free(tmp);
    }

    fclose(fout);
    return 0;
} 