/*
 * ========================== jobs_all.h =======================
 *                          -- tpr --
 *                                        CREATE -- 2019.04.25
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 */
#ifndef TPR_JOBS_ALL_H
#define TPR_JOBS_ALL_H

//-------------------- Engine --------------------//
#include "multiThread/Job.h"
#include "map/chunkKey.h"
#include "map/sectionKey.h"

// POD
// job.argBinary
// use std::any to pass
struct ArgBinary_Create_Job_Chunk{
    chunkKey_t  chunkKey;
};

void create_job_chunk_main( const Job &job_ );



// POD
// job.argBinary
// use std::any to pass
struct ArgBinary_Create_Job_EcoObj{
    sectionKey_t  ecoObjKey;
};

void create_job_ecoObj_main( const Job &job_ );




#endif 

