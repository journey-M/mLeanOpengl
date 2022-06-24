/*
 * ======================== speedLog.h ==========================
 *                          -- tpr --
 *                                        CREATE -- 2019.10.05
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 */
#ifndef TPR_SPEED_LOG_H
#define TPR_SPEED_LOG_H


namespace tprDebug {//---------- namespace: tprDebug --------------//


void init_speedLog();
void collect_playerSpeed( const glm::dvec2 &speedV_ );
void process_and_echo_speedLog();

void collect_cameraSpeed( const glm::dvec2 &speedV_ );


}//-------------------- namespace: tprDebug end --------------//
#endif 

