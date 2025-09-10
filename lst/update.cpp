void update_durations(Duration* d, struct timespec t1, struct timespec t2, int blocs){

	long time = (t2.tv_sec - t1.tv_sec) * 1e9 + (t2.tv_nsec - t1.tv_nsec);
	d->total_d += time;
	if (time < d ->min_d) d->min_d = time;
	if (time > d -> max_d) d-> max_d = time;
	d->count++;
    if (d->size == 0) {
        d->size = 100000;
        d->durations = (double*) malloc(d->size * sizeof(double));
        d->sizes = (int*) malloc(d->size * sizeof(int));
    }    if (d->count >= d->size){
        d->size *= 10;
        d->durations = (double*) realloc(d->durations,d->size * sizeof(double));
        d->sizes = (int*) realloc(d->sizes,d->size * sizeof(int));
    }
    d->durations[d->count] = time;
    d->sizes[d->count] = blocs;

}
