#include <stdio.h>
#include <stdlib.h>

#define MAX_N 200000

typedef struct {
    int start, end;
} Lecture;

int cmp(const void* a, const void* b) {
    Lecture* l1 = (Lecture*)a;
    Lecture* l2 = (Lecture*)b;
    if (l1->start == l2->start) {
        return l1->end - l2->end;
    }
    return l1->start - l2->start;
}

int main() {
    int n;
    scanf("%d", &n);

    Lecture lectures[MAX_N];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &lectures[i].start, &lectures[i].end);
    }

    qsort(lectures, n, sizeof(Lecture), cmp);

    int lecture_queue[MAX_N];
    int queue_size = 0;
    lecture_queue[queue_size++] = lectures[0].end;

    for (int i = 1; i < n; i++) {
        if (lectures[i].start < lecture_queue[0]) {
            lecture_queue[queue_size++] = lectures[i].end;
            // insert into min heap
            int j = queue_size - 1;
            while (j > 0 && lecture_queue[j] < lecture_queue[(j - 1) / 2]) {
                int temp = lecture_queue[j];
                lecture_queue[j] = lecture_queue[(j - 1) / 2];
                lecture_queue[(j - 1) / 2] = temp;
                j = (j - 1) / 2;
            }
        } else {
            lecture_queue[0] = lectures[i].end;
            // restore heap property
            int j = 0;
            while (2 * j + 1 < queue_size) {
                int child = 2 * j + 1;
                if (child + 1 < queue_size && lecture_queue[child + 1] < lecture_queue[child]) {
                    child++;
                }
                if (lecture_queue[j] <= lecture_queue[child]) {
                    break;
                }
                int temp = lecture_queue[j];
                lecture_queue[j] = lecture_queue[child];
                lecture_queue[child] = temp;
                j = child;
            }
        }
    }

    printf("%d\n", queue_size);

    return 0;
}
