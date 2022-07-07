/*
 * ================== esrc_ecoObjMemState.h ==========================
 *                          -- tpr --
 *                                        CREATE -- 2019.11.29
 *                                        MODIFY --
 * ----------------------------------------------------------
 * only included by esrc_ecoObj.h
 */
#ifndef TPR_ESRC_ECO_OBJ_MEM_STATE_H
#define TPR_ESRC_ECO_OBJ_MEM_STATE_H

//-------------------- CPP --------------------//
#include <utility>
#include <unordered_set>
#include <unordered_map>

//-------------------- Engine --------------------// 
#include "map/sectionKey.h"
#include "tools/IntVec.h"
#include "ecoSys/EcoObjMemState.h"


namespace esrc {//------------------ namespace: esrc -------------------------//

void init_ecoObjMemStates()noexcept;

EcoObjMemState get_ecoObjMemState( sectionKey_t ecoObjKey_ )noexcept;


void insert_ecoObjKey_2_onCreating( sectionKey_t ecoObjKey_ )noexcept;
void move_ecoObjKey_from_onCreating_2_active( sectionKey_t ecoObjKey_ )noexcept;
void move_ecoObjKey_from_active_2_onReleasing( sectionKey_t ecoObjKey_ )noexcept;
void erase_ecoObjKey_from_onReleasing( sectionKey_t ecoObjKey_ )noexcept;


}//---------------------- namespace: esrc -------------------------//
#endif 

