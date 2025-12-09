int countSetBits(int n) {
    if (!n) return 0;
    int x = 0, temp = n;
    while (temp >>= 1) x++;
    return x * (1 << (x - 1)) + (n - (1 << x) + 1) + countSetBits(n - (1 << x));
}
