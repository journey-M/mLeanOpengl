/*
 * ========================= esrc_state.h ==========================
 *                          -- tpr --
 *                                        CREATE -- 2019.09.29
 *                                        MODIFY --
 * ----------------------------------------------------------
 */
#ifndef TPR_ESRC_STATE_H
#define TPR_ESRC_STATE_H

//-------------------- CPP --------------------//
#include <string>
#include <unordered_set>
#include "tprDebug/tprDebug.h"
#include "tprDebug/tprAssert.h"


namespace esrc {//------------------ namespace: esrc -------------------------//

void insertState( const std::string &str_ );
bool is_setState( const std::string &str_ );

}//---------------------- namespace: esrc -------------------------//
#endif

