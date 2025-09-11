for (uint aid = 0; aid < (uint) trace->nb_archives; aid++) {

    if(details) fprintf(stdout, "%s: archive id = %d\n", name, aid);
    auto archive = trace->archive_list[aid];

      for (uint i = 0; i < archive->nb_threads; i++) {

	    const pallas::Thread *thread = archive->getThreadAt(i);

      for (unsigned j = 0; j < thread->nb_events; j++) {
          pallas::EventSummary& e = thread->events[j];
            auto* timestamps = e.timestamps;

            for (size_t k =0; k<timestamps->size; k++){
              uint64_t t = timestamps->at(k);
              write_csv_details(copy, t);
            }
            timestamps->free_data();
            e.cleanEventSummary();
        }
      archive->freeThreadAt(i);
      }
   }