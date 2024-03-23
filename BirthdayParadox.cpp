#include <iostream>
#include <random>
#include <ctime>
#include <cstring>

using namespace std;

double calculateCollisionProbability(int trial_students, int test_iterations) {
    int favourable_count = 0;

    for (int iter = 1; iter <= test_iterations; iter++) {
        int test[365];
        memset(test, 0, sizeof(test));

        for (int student = 1; student <= trial_students; student++) {
            int index = rand() % 365;
            if (test[index] == 1) {
                favourable_count++;
                break;
            } else {
                test[index]++;
            }
        }
    }

    return (double)favourable_count / (double)test_iterations;
}

int findMinStudents(double p,  int test_iterations) {
    int min_students = 2; // Start from 2 students
    while (true) {
        double prob = calculateCollisionProbability(min_students, test_iterations);
        if (prob > p) {
            return min_students;
        }
        min_students++;
    }
}

int main() {
    srand(time(NULL));

    
    int test_iterations = 100000;
    double p;

    cout << "Enter the probability threshold (p): ";
    cin >> p;
    cout << "Target Probability (p) = " << p << endl;

    int min_students = findMinStudents(p, test_iterations);
    cout << "Number of students needed: " << min_students << endl;

    return 0;
}
