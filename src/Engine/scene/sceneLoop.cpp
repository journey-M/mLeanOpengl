/*
 * ==================== sceneLoop.cpp =======================
 *                          -- tpr --
 *                                        CREATE -- 2019.04.29
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 */

//-------------------- Engine --------------------//
#include "scene/sceneLoop.h"
#include "scene/sceneLoopInn.h"
#include "tprDebug/tprDebug.h"


void switch_sceneLoop( SceneLoopType type_ ){

    switch (type_){
        
        /*
        case SceneLoopType::FirstPlayInputSet:
            sceneLogicLoopFunc = std::bind( sceneLogicLoop_firstPlayInputSet );
            sceneRenderLoopFunc = std::bind( sceneRenderLoop_firstPlayInputSet );
            break;
        */

        case SceneLoopType::Begin:
            sceneLogicLoopFunc = std::bind( sceneLogicLoop_begin );
            sceneRenderLoopFunc = std::bind( sceneRenderLoop_begin );
            break;

        case SceneLoopType::World:
            sceneLogicLoopFunc = std::bind( sceneLogicLoop_world );
            sceneRenderLoopFunc = std::bind( sceneRenderLoop_world );
            break;
        
        default:
            tprAssert(0);
            break;
    }

}

