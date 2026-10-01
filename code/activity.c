/*
4. Activity Selection
🧠 Core concept

Given activities:

Start time
Finish time

Select the maximum number of non-overlapping activities.

Greedy rule ⭐

Always select the activity that finishes earliest.

First:

Sort by finish time

Then:

Select first activity

For every next activity:
    if start >= last_finish:
        select it
⭐ Most important line
if (activities[i].start >= lastFinish)
*/

#include <stdio.h>

struct Activity {
    int start;
    int finish;
};

int main() {
    int n;

    printf("Enter number of activities: ");
    scanf("%d", &n);

    struct Activity a[n];

    for (int i = 0; i < n; i++) {
        printf("Enter start and finish: ");
        scanf("%d %d", &a[i].start, &a[i].finish);
    }

    // Sort according to finish time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {

            if (a[i].finish > a[j].finish) {
                struct Activity temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("Selected activities:\n");

    int lastFinish = -1;

    for (int i = 0; i < n; i++) {

        if (a[i].start >= lastFinish) {
            printf("(%d, %d)\n",
                   a[i].start,
                   a[i].finish);

            lastFinish = a[i].finish;
        }
    }

    return 0;
}
/*
Enter number of activities: 6

1 2
3 4
0 6
5 7
8 9
5 9

Selected activities:
(1, 2)
(3, 4)
(5, 7)
(8, 9)
*/