/*
 * ========================= esrc_coordinate.h ==========================
 *                          -- tpr --
 *                                        CREATE -- 2019.11.15
 *                                        MODIFY --
 * ----------------------------------------------------------
 */
#ifndef TPR_ESRC_COORDINATE_H
#define TPR_ESRC_COORDINATE_H

//-------------------- Engine --------------------//
#include "../coordinate/Coordinate.h"
#include "tprDebug/tprDebug.h"
#include <memory>

namespace esrc {//------------------ namespace: esrc -------------------------//


void init_coordinate();

const Coordinate &get_worldCoordRef()noexcept;


}//---------------------- namespace: esrc -------------------------//
#endif

