int divide(int dividend, int divisor) {

    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;
    
    int negative = (dividend < 0) ^ (divisor < 0);

    long long ldividend = llabs((long long)dividend);
    long long ldivisor = llabs((long long)divisor);
    
    long long result = 0;

    while (ldividend >= ldivisor) {
        long long temp = ldivisor;
        long long multiple = 1;

        while ((temp << 1) <= ldividend) {
            temp <<= 1;
            multiple <<= 1;
        }

        ldividend -= temp;
        result += multiple;
    }

    if (negative) result = -result;

    if (result > INT_MAX) return INT_MAX;
    if (result < INT_MIN) return INT_MIN;

    return (int)result;
}