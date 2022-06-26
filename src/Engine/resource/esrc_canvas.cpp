/*
 * ================= esrc_canvas.cpp =====================
 *                          -- tpr --
 *                                        CREATE -- 2019.03.31
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 */


//-------------------- Engine --------------------//
#include "camera/ViewingBox.h"
#include "esrc_canvas.h"
#include "resource/esrc_window.h"
#include "resource/esrc_camera.h" 
#include "resource/esrc_gameSeed.h"

#include "resource/esrc_shader.h"
#include "resource/esrc_state.h"


namespace esrc{//------------------ namespace: esrc -------------------------//


namespace canvas_inn {//-------- namespace: canvas_inn --------------//
    std::unique_ptr<Canvas> groundCanvasUPtr;

}//------------- namespace: canvas_inn end --------------//


/* ===========================================================
 *                     init_canvases
 * -----------------------------------------------------------
 */
void init_canvases(){

    tprAssert( esrc::is_setState("shader") );

    canvas_inn::groundCanvasUPtr = std::make_unique<Canvas>();

    //------------------//
    //    groundCanvas
    //------------------//
    canvas_inn::groundCanvasUPtr->init( &(ViewingBox::gameSZ),
                            esrc::get_shaderPtr(ShaderType::Ground) );

    esrc::insertState("canvas");
}

/* ===========================================================
 *                    draw_groundCanvas
 * -----------------------------------------------------------
 */
void draw_groundCanvas(){

    canvas_inn::groundCanvasUPtr->use_shaderProgram(); //- MUST !!! 

    glm::vec2 canvasFPos = get_camera().calc_canvasFPos();

    canvas_inn::groundCanvasUPtr->set_translate(canvasFPos.x,
                                                canvasFPos.y,
                                      static_cast<float>(get_camera().get_zFar() + ViewingBox::ground_zOff) );
        
    canvas_inn::groundCanvasUPtr->draw();
}

}//---------------------- namespace: esrc -------------------------//

