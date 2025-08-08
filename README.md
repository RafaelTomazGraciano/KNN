# KNN Classifier for Iris Dataset

[![C](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))


This project implements a simple K-Nearest Neighbors (KNN) classifier (k=1) in C for the Iris dataset.

## Features
- Reads training and test data from CSV files (`IrisTrain.txt` and `IrisTest.txt`)
- Classifies each test sample using the nearest neighbor from the training set
- Reports the number of correct predictions and overall accuracy

## Files
- `KNN.c`: Main C source code for the classifier
- `IrisTrain.txt`: Training data (CSV format)
- `IrisTest.txt`: Test data (CSV format)

## Usage

1. **Compile the code:**
   ```sh
   gcc KNN.c -o knn -lm
   ```

2. **Run the program:**
   ```sh
   ./knn
   ```

3. **Output:**
   The program will print the number of correct predictions and the accuracy percentage.

## Data Format
Each line in the data files should be in the format:
```
feature1,feature2,feature3,feature4,class
```
Where `class` is an integer label (e.g., 0, 1, 2).

## Example Output
```
Number of Correct Predictions: 45
Accuracy: 100.00%
```
