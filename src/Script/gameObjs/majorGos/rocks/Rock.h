/*
 * =========================== Rock.h ==========================
 *                          -- tpr --
 *                                        CREATE -- 2019.10.09
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 */
#ifndef TPR_GO_ROCK_H
#define TPR_GO_ROCK_H

//-------------------- Engine --------------------//
#include "gameObj/GameObj.h"
#include "dynamicParam/DyParam.h"

namespace gameObjs{//------------- namespace gameObjs ----------------

class Rock{
public:
    static void init(GameObj &goRef_,const DyParam &dyParams_ );
private:                            
    static void bind( GameObj &goRef_ );
    static void rebind( GameObj &goRef_ );

    //--- callback ---//
    static void OnRenderUpdate( GameObj &goRef_ ); 
    static void OnLogicUpdate( GameObj &goRef_ ); 
    static void OnActionSwitch( GameObj &goRef_, ActionSwitchType type_ );
};


}//------------- namespace gameObjs: end ----------------
#endif 

