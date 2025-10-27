#include <stdio.h>

struct Page {
    int value;     // Page value
    int last_used; // Last used time for LRU
};

int main() {
    int capacity, n, page_faults = 0, page_hits = 0, time = 0;

    printf("Enter the number of frames: ");
    scanf("%d", &capacity);  // Number of frames

    printf("Enter the number of page requests: ");
    scanf("%d", &n);  // Number of page requests

    struct Page frames[capacity];  // Array of frames
    int pages[n];                  // Page reference string

    // Initialize frames
    for (int i = 0; i < capacity; i++) {
        frames[i].value = -1;
        frames[i].last_used = 0;
    }

    // Input page reference string
    printf("Enter the page reference string: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    // Process each page request
    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;
        time++;  // Increase time for LRU tracking

        // Check if page already exists (hit)
        for (int j = 0; j < capacity; j++) {
            if (frames[j].value == page) {
                found = 1;
                frames[j].last_used = time;  // Update last used
                break;
            }
        }

        // Display current request
        printf("Page %2d: ", page);

        if (found) {
            page_hits++;
        } else {
            page_faults++;

            // Find replacement index (least recently used page)
            int replace_idx = 0, min_time = frames[0].last_used;
            for (int j = 1; j < capacity; j++) {
                if (frames[j].last_used < min_time) {
                    min_time = frames[j].last_used;
                    replace_idx = j;
                }
            }

            // Replace the page
            frames[replace_idx].value = page;
            frames[replace_idx].last_used = time;
        }

        // Print frame state
        for (int j = 0; j < capacity; j++) {
            if (frames[j].value == -1)
                printf("  -  ");
            else
                printf("%3d  ", frames[j].value);
        }

        if (found)
            printf("[ H ]\n");
        else
            printf("[ F ]\n");
    }

    // Results
    printf("\nTotal Page Faults: %d\n", page_faults);
    printf("Total Page Hits: %d\n", page_hits);

    return 0;
}
