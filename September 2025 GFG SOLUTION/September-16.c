int evaluate(char* arr[], int size) {
    int stack[size], top = -1;
    for (int i = 0; i < size; i++) {
        char* t = arr[i];
        if (strlen(t) == 1 && strchr("+-*/^", t[0])) {
            int b = stack[top--], a = stack[top--];
            if (t[0] == '/') stack[++top] = (a < 0) ^ (b < 0) && a % b ? a / b - 1 : a / b;
            else stack[++top] = t[0] == '+' ? a + b : t[0] == '-' ? a - b : 
                              t[0] == '*' ? a * b : (int)pow(a, b);
        } else stack[++top] = atoi(t);
    }
    return stack[top];
}
