/*
 * int counter = 1;  // define and initialize counter
 * int main() {
 *     extern int counter; // explicitly declare counter
 *     counter++;
 *     counter++;
 *     counter++;
 *     return 0;
 * }
 */
unsigned int counter = 0x0;
int main() {
    unsigned int *p_int = (unsigned int *)0x20000000;
    ++(*p_int);
    ++(*p_int);
    ++(*p_int);
    counter ++;
    return 0;
}
