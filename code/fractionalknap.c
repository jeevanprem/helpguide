/*
2. Fractional Knapsack
🧠 Core concept

Unlike 0/1 Knapsack, here you can take a fraction of an item.

So calculate:

ratio = value / weight

Then:

Sort items by decreasing value/weight ratio.

Take the highest ratio first.

Algorithm
1. Calculate value/weight ratio
2. Sort items by decreasing ratio
3. Start capacity = W
4. For every item:
      If whole item fits:
          take whole item
      Else:
          take fraction that fits
          stop
⭐ Important code
if (weight[i] <= capacity) {
    total += value[i];
    capacity -= weight[i];
}
else {
    total += ratio[i] * capacity;
    break;
}
*/
#include <stdio.h>

struct Item {
    int weight;
    int value;
    float ratio;
};

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item item[n];

    for (int i = 0; i < n; i++) {
        printf("Enter weight and value: ");
        scanf("%d %d", &item[i].weight, &item[i].value);

        item[i].ratio =
            (float)item[i].value / item[i].weight;
    }

    printf("Enter capacity: ");
    scanf("%d", &capacity);

    // Sort by decreasing ratio
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {

            if (item[i].ratio < item[j].ratio) {
                struct Item temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }

    float total = 0;

    for (int i = 0; i < n; i++) {

        if (item[i].weight <= capacity) {
            total += item[i].value;
            capacity -= item[i].weight;
        }
        else {
            total += item[i].ratio * capacity;
            break;
        }
    }

    printf("Maximum value = %.2f\n", total);

    return 0;
}

/*
Enter number of items: 3
Enter weight and value: 10 60
Enter weight and value: 20 100
Enter weight and value: 30 120
Enter capacity: 50

Maximum value = 240.00
*/