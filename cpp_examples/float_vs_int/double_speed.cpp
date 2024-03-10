int main() {
    double a = 0;
    for(int i=0;i<1e7;i++) {
        a += (double)i/10 * (double)i;
    }
    return 0;
}