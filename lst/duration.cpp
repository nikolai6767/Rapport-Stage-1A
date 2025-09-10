/* Duration structure */
  typedef struct {
    /* Total duration of the program */
	  double total_d;
    /* Minimal duration of the function */
	  double min_d;
    /* Maximal duration of the function */
	  double max_d;
    /* Number of calls */
	  int count;
    /* size of the details structure */
    int size;
    /* Has size blocs and contains all the detailed data */
    double* durations;
    /* Has size blocs and contains the (sub-)vector sizes for each duration*/
    int* sizes;
  } Duration;

extern Duration durations[NB_FUNCTIONS];
