#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define FIXED_BUFF_LEN 32
#define CHUNK_SIZE 50

struct fixed_buff {
    uint8_t data[FIXED_BUFF_LEN];
    unsigned int data_len;
    struct fixed_buff *next;
};

struct stream {
    FILE *fp;
};

// Function prototypes
struct fixed_buff* build_fixed_buff_list(struct stream *s);
struct fixed_buff* fixed_buff_alloc(void);
uint8_t* stream_get(struct stream *s, unsigned int *data_len);

// Custom memcpy
void* my_memcpy(void* dest, const void* src, size_t n) {
    unsigned char* d = (unsigned char*)dest;
    const unsigned char* s = (const unsigned char*)src;
    for (size_t i = 0; i < n; i++) {
        d[i] = s[i];
    }
    return dest;
}

// Allocates a fixed_buff node
struct fixed_buff* fixed_buff_alloc(void) {
    struct fixed_buff *b = (struct fixed_buff*)malloc(sizeof(struct fixed_buff));
    if (b) {
        b->data_len = 0;
        b->next = NULL;
    }
    return b;
}

// Stream get reads fixed chunks from file
uint8_t* stream_get(struct stream *s, unsigned int *data_len) {
    static uint8_t buffer[CHUNK_SIZE];
    size_t read_bytes = fread(buffer, 1, CHUNK_SIZE, s->fp);

    if (read_bytes == 0) {
        return NULL;
    }

    *data_len = (unsigned int)read_bytes;
    return buffer;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *fin = fopen(argv[1], "rb");
    if (!fin) {
        printf("Failed to open input file: %s\n", argv[1]);
        return 1;
    }

    FILE *fout = fopen("output.txt", "w");
    if (!fout) {
        printf("Failed to open output.txt\n");
        fclose(fin);
        return 1;
    }

    struct stream s = { .fp = fin };
    struct fixed_buff *list = build_fixed_buff_list(&s);

    // Print the linked list
    int node_num = 1;
    int total_bytes = 0;
    struct fixed_buff *curr = list;
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

    fprintf(fout, "Total bytes processed = %d\n", total_bytes);

    // Free the list
    curr = list;
    while (curr) {
        struct fixed_buff *tmp = curr;
        curr = curr->next;
        free(tmp);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
