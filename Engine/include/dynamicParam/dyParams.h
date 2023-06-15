/*
 * ======================== dyParams.h ==========================
 *                          -- tpr --
 *                                        CREATE -- 2019.10.05
 *                                        MODIFY --
 * ----------------------------------------------------------
 */
#ifndef TPR_DY_PARAMS_H
#define TPR_DY_PARAMS_H

//-------------------- CPP --------------------//
#include <vector>
#include <set>
#include <cstdint> // uint8_t


//-------------------- Engine --------------------//
#include "dynamicParam/DyParam.h"
#include "gameObj/goDataForCreate/GoDataForCreate.h"



struct DyParams_GoDataForCreate{    
    const GoDataForCreate   *goDataPtr {};
};


#endif 
