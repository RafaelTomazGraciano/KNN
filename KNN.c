#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float test_f1, test_f2, test_f3, test_f4;
    int test_class, predicted_class;
    int correct = 0, total = 0;


    FILE *testFile = fopen("IrisTest.txt", "r");
    if (!testFile) {
        printf("Error opening IrisTest.txt\n");
        return 1;
    }

    // For each test sample
    while (fscanf(testFile, "%f,%f,%f,%f,%d", &test_f1, &test_f2, &test_f3, &test_f4, &test_class) == 5) {
        float min_dist = 1e9;
        int min_class = -1;

        FILE *trainFile = fopen("IrisTrain.txt", "r");
        if (!trainFile) {
            printf("Error opening IrisTrain.txt\n");
            fclose(testFile);
            return 1;
        }

        float train_f1, train_f2, train_f3, train_f4;
        int train_class;

        // For each train sample, find the nearest neighbor
        while (fscanf(trainFile, "%f,%f,%f,%f,%d", &train_f1, &train_f2, &train_f3, &train_f4, &train_class) == 5) {
            float dist = sqrt(pow(train_f1 - test_f1, 2) + pow(train_f2 - test_f2, 2) +
                             pow(train_f3 - test_f3, 2) + pow(train_f4 - test_f4, 2));
            if (dist < min_dist) {
                min_dist = dist;
                min_class = train_class;
            }
        }
        fclose(trainFile);

        if (min_class == test_class) {
            correct++;
        }
        total++;
    }
    fclose(testFile);

    printf("\nNumber of Correct Predictions: %d", correct);
    printf("\nAccuracy: %.2f%%\n", (total > 0) ? (100.0 * correct / total) : 0.0);
    return 0;
}