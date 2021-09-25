// Solution to problem 1

int m35() {
    int sum = 0;
    int counter;
    for (counter = 0; counter < 1000; counter++) {
        if (counter % 3 == 0 || counter % 5 == 0) {
            sum += counter;
        }
    }
    return sum;
}

// Solution to 5

int smallest_multiple() {
    int multiple, remainder, counter;
    for (multiple = 2520; 1; multiple += 20) {
        for (counter = 11; counter < 21; counter++) {
            remainder = multiple % counter;
            if (remainder != 0) {
                break;
            }
        }
        if (remainder == 0) {
            return multiple;
        }
    }
}   