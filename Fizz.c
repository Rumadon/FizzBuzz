#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"

const int LINE_SIZE = 8;
const int CHAR_SIZE = 4;
const int NUM_WRITE = 100;


void *populateFunc(char *list[]) {
    int counter = 0;
    char **dest;
    while (1) {
        dest = (list + (counter * CHAR_SIZE * LINE_SIZE));
        char stringCounter[LINE_SIZE];
        snprintf(stringCounter, LINE_SIZE, "%d", counter);
        memcpy(dest, stringCounter, CHAR_SIZE * LINE_SIZE);
        counter++;
        sleep(1);
    }
}

void *fizzFunc(char *list[]) {
    int counter = 1;
    char **dest;
    char stringFizz[LINE_SIZE];
    strncpy(stringFizz, "Fizz    ", LINE_SIZE);
    while (1) {
        dest = (list + (counter * 3 * CHAR_SIZE * LINE_SIZE));
        memcpy(dest, stringFizz, CHAR_SIZE * LINE_SIZE);
        counter++;
        sleep(2);
    }
}

void *buzzFunc(char *list[]) {
    int counter = 1;
    char **dest;
    char stringBuzz[LINE_SIZE];
    strncpy(stringBuzz, "Buzz    ", LINE_SIZE);
    while (1) {
        dest = (list + (counter * 5 * CHAR_SIZE * LINE_SIZE));
        memcpy(dest, stringBuzz, CHAR_SIZE * LINE_SIZE);
        counter++;
        sleep(2);
    }
}

void *fizzBuzzFunc(char *list[]) {
    int counter = 1;
    char **dest;
    char stringFizzBuzz[LINE_SIZE];
    strncpy(stringFizzBuzz, "FizzBuzz", LINE_SIZE);
    while (1) {
        dest = (list + (counter * 15 * CHAR_SIZE * LINE_SIZE));
        memcpy(dest, stringFizzBuzz, CHAR_SIZE * LINE_SIZE);
        counter++;
        sleep(2);
    }
}


void *printFunc(char *list[]) {
    int garbage = 100000;
    int counter = 0;
    char **out;
    while (1) {
        out = list + (counter * CHAR_SIZE * LINE_SIZE);
        printf("%d: %8s \n", counter, out);
        garbage = garbage / (100 - counter);
        counter++;
        sleep(2);
    }
}

int main() {
    char *list;
    list = malloc(CHAR_SIZE * LINE_SIZE * NUM_WRITE * 1000);

    pthread_t populateThread;
    pthread_t fizzThread;
    pthread_t buzzThread;
    pthread_t fizzBuzzThread;
    pthread_t readThread;

    pthread_create(&populateThread, NULL, populateFunc, list);
    sleep(12);
    pthread_create(&fizzThread, NULL, fizzFunc, list);
    sleep(12);
    pthread_create(&buzzThread, NULL, buzzFunc, list);
    sleep(12);
    pthread_create(&fizzBuzzThread, NULL, fizzBuzzFunc, list);
    sleep(16);
    pthread_create(&readThread, NULL, printFunc, list);
    sleep(400);
}

#pragma clang diagnostic pop