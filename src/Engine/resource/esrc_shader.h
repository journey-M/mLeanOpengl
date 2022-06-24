/*
 * ========================= esrc_shader.h ==========================
 *                          -- tpr --
 *                                        CREATE -- 2019.04.19
 *                                        MODIFY --
 * ----------------------------------------------------------
 */
#ifndef TPR_ESRC_SHADER_H
#define TPR_ESRC_SHADER_H

//-------------------- Engine --------------------//
#include "ShaderProgram.h"
#include "ShaderType.h"

namespace esrc {//------------------ namespace: esrc -------------------------//

void init_shaders();

ShaderProgram &get_shaderRef( ShaderType type_ )noexcept;
ShaderProgram *get_shaderPtr( ShaderType type_ )noexcept;


}//---------------------- namespace: esrc -------------------------//
#endif

