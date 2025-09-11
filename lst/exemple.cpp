void pallas::LinkedVector::SubArray::write_to_file(FILE* file,  const ParameterHandler& parameter_handler) {

    struct timespec t1, t2;
    clock_gettime(CLOCK_MONOTONIC, &t1);
    first_value = array[0];
    last_value = array[size-1];
    offset = ftell(file);
    _pallas_compress_write(array, size, file, parameter_handler);
    delete[] array;
    array = nullptr;
    clock_gettime(CLOCK_MONOTONIC, &t2);
      if (TRACK_PERF){
    update_durations(&durations[WRITE_SUBVEC], t1, t2, size);
    duration_write_csv("write_subvec", &durations[WRITE_SUBVEC]);
      }

}