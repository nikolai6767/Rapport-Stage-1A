void duration_write_csv(const char* filename, const Duration* d) {
    std::ofstream file(std::string(filename) + ".csv");
    file << "name,calls,total_us,min_us,max_us,average_us\n";
    file << std::string(filename) << "," << d->count << "," << d->total_d << "," << d->min_d << "," << d->max_d << ",";
    file << (d->count ? d->total_d / d->count : 0) << "\n";
}


void write_duration_details(const char* filename, const char* output, const Duration* d){
    std::ofstream file(std::string(output) + ".csv");
    for (int i = 0; i < d->count; i++){
        if (d-> sizes != NULL)
            file << std::string(filename) << "," << d->durations[i] << "," << d->sizes[i] << "\n";
        else
            file << std::string(filename) << "," << d->durations[i] << "\n";
    }
}