/*
 * ======================= fileIO.h ==========================
 *                          -- tpr --
 *                                        创建 -- 2019.07.08
 *                                        修改 -- 
 * ----------------------------------------------------------
 */

#include "fileIO/fileIO.h"

//--------------- Libs ------------------//
#include "tprFileSys_unix.h"

/* ===========================================================
 *                    read_a_file
 * -----------------------------------------------------------
 * cross platform
 */
std::unique_ptr<std::string> read_a_file( const std::string &filePath_ ){

    auto bufUPtr = std::make_unique<std::string>();
    //-- read files --
    tprUnix::file_load( filePath_, *bufUPtr );

    return bufUPtr;
}
