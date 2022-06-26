/*
 * ========================= esrc_ecoObj.h ==========================
 *                          -- tpr --
 *                                        CREATE -- 2019.04.19
 *                                        MODIFY --
 * ----------------------------------------------------------
 */
#ifndef TPR_ESRC_ECO_OBJ_H
#define TPR_ESRC_ECO_OBJ_H

//-------------------- CPP --------------------//
#include <unordered_map>
#include <utility> //- pair
#include <memory>

//-------------------- Engine --------------------//
#include "ecoSys/EcoObj.h"
#include "tools/IntVec.h"
#include "map/sectionKey.h"
#include "ecoSys/EcoObj_ReadOnly.h"
#include "ecoSys/GoSpecData.h"

#include "resource/esrc_ecoObjMemState.h"



namespace esrc {//------------------ namespace: esrc -------------------------//

void init_ecoObjs()noexcept;

void moveIn_ecoObjUPtr_from_job( sectionKey_t ecoObjKey_, std::unique_ptr<EcoObj> ecoObjUPtr_ );

void del_ecoObjs_tooFarAway()noexcept;

//-- 更加精细的 元素数据 只读访问 接口 [值传递] --
std::unique_ptr<EcoObj_ReadOnly> get_ecoObj_readOnly( sectionKey_t sectionkey_ )noexcept;

EcoObj &get_ecoObjRef( sectionKey_t sectionkey_ )noexcept;

}//---------------------- namespace: esrc -------------------------//
#endif

