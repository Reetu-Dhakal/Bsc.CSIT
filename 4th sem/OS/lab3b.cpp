#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_READERS 5

// Semaphores
sem_t rw_mutex;   // controls access to the shared resource (writer-exclusive)
sem_t mutex;      // protects reader_count and read_batch

// Shared state
int reader_count = 0;
int read_batch   = 0;

void* reader(void* arg) {
    int id = *((int*)arg);
    free(arg);

    // Entry section for readers
    sem_wait(&mutex);
    reader_count++;
    if (reader_count == 1) {
        // first reader locks out writers
        sem_wait(&rw_mutex);
    }
    sem_post(&mutex);

    // Critical section (reading)
    printf("Reader %d is reading...\n", id);
    sleep(1);

    // Exit section for readers
    sem_wait(&mutex);
    reader_count--;
    read_batch++;

    if (reader_count == 0) {
        // last reader lets writers in
        sem_post(&rw_mutex);
    }

    if (read_batch == MAX_READERS) {
        printf("5 readers have read. Writer can write now.\n");
        read_batch = 0; // reset batch counter
    }
    sem_post(&mutex);

    pthread_exit(NULL);
}

void* writer(void* arg) {
    int id = *((int*)arg);
    free(arg);

    // Writers need exclusive access
    sem_wait(&rw_mutex);
    printf("Writer %d is writing...\n", id);
    sleep(2);
    sem_post(&rw_mutex);

    pthread_exit(NULL);
}

int main(void) {
    pthread_t r[10], w[2];

    // Init semaphores
    sem_init(&rw_mutex, 0, 1);
    sem_init(&mutex,   0, 1);

    // Start readers
    for (int i = 0; i < 10; i++) {
        int* id = (int*)malloc(sizeof(int));
        *id = i + 1;
        if (pthread_create(&r[i], NULL, reader, id) != 0) {
            perror("pthread_create(reader)");
            return 1;
        }
        sleep(1); // stagger starts so output is clearer
    }

    // Start writers
    for (int i = 0; i < 2; i++) {
        int* id = (int*)malloc(sizeof(int));
        *id = i + 1;
        if (pthread_create(&w[i], NULL, writer, id) != 0) {
            perror("pthread_create(writer)");
            return 1;
        }
        sleep(5); // stagger to let some readers go first
    }

    // Join readers
    for (int i = 0; i < 10; i++) {
        pthread_join(r[i], NULL);
    }
    // Join writers
    for (int i = 0; i < 2; i++) {
        pthread_join(w[i], NULL);
    }

    // Cleanup
    sem_destroy(&rw_mutex);
    sem_destroy(&mutex);

    printf("@Ritudhakal\n");
    return 0;
}
