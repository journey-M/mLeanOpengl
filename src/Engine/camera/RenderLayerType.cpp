/*
 * ===================== RenderLayerType.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.02.22
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 */

#include "camera/RenderLayerType.h"

//--------------- Libs ------------------//
#include "magic_enum.hpp"
#include "tprDebug/tprDebug.h"



std::string renderLayerType_2_str( RenderLayerType dir_ )noexcept{
    return std::string{ magic_enum::enum_name( dir_ ) };
}


RenderLayerType str_2_renderLayerType( const std::string &str_ )noexcept{

    auto labelOP = magic_enum::enum_cast<RenderLayerType>(str_);
    if( labelOP.has_value() ){
        return *labelOP;
    }else{
        tprDebug::console( "can't find RenderLayerType: {}", str_ );
        return RenderLayerType::MajorGoes; // never reach
    }
}



