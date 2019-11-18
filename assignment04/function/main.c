
int expand2(int i1, int i2);
int expand4(int i1, int i2, int i3, int i4);
int sum8(int i1, int i2, int i3, int i4, int i5, int i6, int i7, int i8);
int get();
void main(void) {
    int odd = 3;
    int even = get();

    int result = expand2(even, odd);
    (void)result; // squelch unused complaint
}
int get() { return 2; }
int expand2(int i1, int i2) {
    int j1;
    int j2;
    int j3;
    int j4;
    int jsum;

    j1 = i1 + 2;
    j2 = i2 + 2;
    j3 = i1 + 4;
    j4 = i2 + 4;
    jsum = expand4(j1, j2, j3, j4);
    return jsum;
}
int expand4(int i1, int i2, int i3, int i4) {
    int j1;
    int j2;
    int j3;
    int j4;
    int j5;
    int j6;
    int j7;
    int j8;
    int jsum;

    j1 = i1 + 2;
    j2 = i2 + 2;
    j3 = i1 + 4;
    j4 = i2 + 4;
    j5 = i1 + 6;
    j6 = i2 + 6;
    j7 = i1 + 8;
    j8 = i2 + 8;
    jsum = sum8(j1, j2, j3, j4, j5, j6, j7, j8);
    return jsum;
}

int sum8(int i1, int i2, int i3, int i4, int i5, int i6, int i7, int i8) {
    int j1;
    int j2;
    int j3;
    int j4;
    int j5;
    int j6;
    int j7;
    int j8;
    int jsum;

    j1 = i1 + 2;
    j2 = i2 + 2;
    j3 = i1 + 4;
    j4 = i2 + 4;
    j5 = i1 + 6;
    j6 = i2 + 6;
    j7 = i1 + 8;
    j8 = i2 + 8;
    jsum = j1 + j2 + j3 + j4 + j5 + j6 + j7 + j8;
    return jsum;
}
