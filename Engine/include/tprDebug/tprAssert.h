/*
 * ======================= tprAssert.h ==========================
 *                          -- tpr --
 *                                        CREATE -- 2019.06.05
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * a poor assert macro, support win/unix
 * ---------------------
 */
#ifndef TPR_ASSERT_H
#define TPR_ASSERT_H


/* ===========================================================
 *                    tprAssert_inn
 * -----------------------------------------------------------
 */
#include <cassert>
#define tprAssert_inn(e,File,Line) assert(e);


/* ===========================================================
 *                    tprAssert
 * -----------------------------------------------------------
 */
#define tprAssert(e) tprAssert_inn(e,__FILE__, __LINE__)


#endif 

