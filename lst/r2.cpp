double CompareTimestamps(const char* trace1, const char* trace2){
    FILE* file1 = fopen(trace1, "r");
    FILE* file2 = fopen(trace2, "r");
    if (!file1 || !file2) {
        perror("[fopen]");
        return EXIT_FAILURE;
    }

    double y, val2;
    double ss_res = 0.0, ss_tot = 0.0;
    double mean_y = mean(trace1);

    while ((fscanf(file1, "%lf", &y)==1) && (fscanf(file2, "%lf", &val2)==1)) {
        ss_res += (y - val2) * (y - val2);
        ss_tot += (y - mean_y) * (y - mean_y);
    }

    fclose(file1);
    fclose(file2);

    if (ss_tot < EPSILON){
      fprintf(stderr, "\nss_tot nul\n");
      return -1.0;
    }

    double R2 = 1.0 - ss_res / ss_tot;
    return R2;
}