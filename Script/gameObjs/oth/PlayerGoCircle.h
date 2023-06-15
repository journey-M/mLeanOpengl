/*
 * ===================== PlayerGoCircle.h ==========================
 *                          -- tpr --
 *                                        CREATE -- 2019.08.19
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 */
#ifndef TPR_GO_PLAYER_GO_CIRCLE_H
#define TPR_GO_PLAYER_GO_CIRCLE_H

//-------------------- Engine --------------------//
#include "gameObj/GameObj.h"
#include "dynamicParam/DyParam.h"

namespace gameObjs{//------------- namespace gameObjs ----------------

class PlayerGoCircle{
public:
    static void init(GameObj &goRef_, const DyParam &dyParams_ );
private:
    //--- callback ---//
    static void OnRenderUpdate( GameObj &goRef_ ); 
    static void OnActionSwitch( GameObj &goRef_, ActionSwitchType type_ );
};


}//------------- namespace gameObjs: end ----------------
#endif 
