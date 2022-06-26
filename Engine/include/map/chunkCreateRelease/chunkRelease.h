/*
 * =================== chunkRelease.h =======================
 *                          -- tpr --
 *                                        CREATE -- 2019.07.11
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 */
#ifndef TPR_CHUNK_RELEASE_H
#define TPR_CHUNK_RELEASE_H

//-------------------- Engine --------------------//
#include "tools/IntVec.h"
#include "map/fieldKey.h"
#include "map/chunkKey.h"

namespace chunkRelease {//------- namespace: chunkRelease ----------//

void collect_chunks_need_to_be_release_in_update();
void release_one_chunk();

}//----------------- namespace: chunkRelease: end -------------------//
#endif 

