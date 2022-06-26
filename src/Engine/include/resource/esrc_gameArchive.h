/*
 * ===================== esrc_gameArchive.h ====================
 *                          -- tpr --
 *                                        CREATE -- 2019.05.02
 *                                        MODIFY --
 * ----------------------------------------------------------
 */
#ifndef TPR_ESRC_GAME_ARCHIVE_H
#define TPR_ESRC_GAME_ARCHIVE_H

//-------------------- Engine --------------------//
#include "player/GameArchive.h"
#include "glm_no_warnings.h"
#include <memory>

namespace esrc {//------------------ namespace: esrc -------------------------//

void init_gameArchive();
GameArchive &get_gameArchive();


}//---------------------- namespace: esrc -------------------------//
#endif

