#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5
#define NUM_CHOPSTICKS 5

pthread_t philosopher[NUM_PHILOSOPHERS];
pthread_mutex_t chopstick[NUM_CHOPSTICKS];
pthread_mutex_t room; // to allow only limited philosophers
int philosopher_ids[NUM_PHILOSOPHERS];

void *dine(void *arg);

int main()
{
    int i;

    pthread_mutex_init(&room, NULL);

    for (i = 0; i < NUM_CHOPSTICKS; i++)
    {
        pthread_mutex_init(&chopstick[i], NULL);
    }

    for (i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        philosopher_ids[i] = i;
        pthread_create(&philosopher[i], NULL, dine, &philosopher_ids[i]);
    }

    for (i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        pthread_join(philosopher[i], NULL);
    }

    for (i = 0; i < NUM_CHOPSTICKS; i++)
    {
        pthread_mutex_destroy(&chopstick[i]);
    }

    pthread_mutex_destroy(&room);

    return 0;
}

void *dine(void *arg)
{
    int n = *((int *)arg);

    printf("\nPhilosopher %d is thinking\n", n);
    sleep(1);

    // Limit entry to max 2 philosophers
    pthread_mutex_lock(&room);

    pthread_mutex_lock(&chopstick[n]);
    pthread_mutex_lock(&chopstick[(n + 1) % NUM_CHOPSTICKS]);

    printf("Philosopher %d is eating\n", n);
    sleep(2);

    pthread_mutex_unlock(&chopstick[n]);
    pthread_mutex_unlock(&chopstick[(n + 1) % NUM_CHOPSTICKS]);

    printf("Philosopher %d finished eating\n", n);

    pthread_mutex_unlock(&room);

    return NULL;
}
