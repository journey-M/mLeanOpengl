/*
 * ===================== DiskGameObj.h ==========================
 *                          -- tpr --
 *                                        CREATE -- 2019.05.02
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 *    GameObj 各种数据 结构
 * ----------------------------
 */
#ifndef TPR_DISK_GAME_OBJ_H
#define TPR_DISK_GAME_OBJ_H


//------------------- Engine --------------------//
#include "tools/IntVec.h"
#include "gameObj/GameObjType.h"
#include "gameObj/goDataForCreate/goLabelId.h"
#include "tools/NineDirection.h"
#include "gameObj/BrokenLvl.h"


class DiskGameObj{
public:
    goid_t         goid     {}; //- u64   
    goSpeciesId_t  goSpeciesId {}; //- u32
    goLabelId_t    goLabelId {}; // u64
    glm::dvec2     dpos     {}; //- double, double
    size_t         goUWeight {}; // u64
    NineDirection  dir {}; // int
    BrokenLvl      brokenLvl {}; // int

};




#endif 

