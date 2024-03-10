int main() {
    float a = 0;
    for(int i=0;i<1e7;i++) {
        a += (float)i/10 * (float) i;
    }
    return 0;
}