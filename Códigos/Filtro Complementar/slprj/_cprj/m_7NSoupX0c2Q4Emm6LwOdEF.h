#ifndef __7NSoupX0c2Q4Emm6LwOdEF_h__
#define __7NSoupX0c2Q4Emm6LwOdEF_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef struct_tag_jmW87ivuiBvGFMMEZDviKC
#define struct_tag_jmW87ivuiBvGFMMEZDviKC

struct tag_jmW87ivuiBvGFMMEZDviKC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 /*struct_tag_jmW87ivuiBvGFMMEZDviKC*/

#ifndef typedef_soMPU6050Accel
#define typedef_soMPU6050Accel

typedef struct tag_jmW87ivuiBvGFMMEZDviKC soMPU6050Accel;

#endif                                 /*typedef_soMPU6050Accel*/

#ifndef struct_tag_UX05GARjqsuR9QofOrwOSD
#define struct_tag_UX05GARjqsuR9QofOrwOSD

struct tag_UX05GARjqsuR9QofOrwOSD
{
  char_T f1[27];
  char_T f2[21];
  char_T f3[26];
};

#endif                                 /*struct_tag_UX05GARjqsuR9QofOrwOSD*/

#ifndef typedef_cell
#define typedef_cell

typedef struct tag_UX05GARjqsuR9QofOrwOSD cell;

#endif                                 /*typedef_cell*/

#ifndef struct_tag_uo7PCp2pQzQ8uFrW43NfEH
#define struct_tag_uo7PCp2pQzQ8uFrW43NfEH

struct tag_uo7PCp2pQzQ8uFrW43NfEH
{
  char_T f1[28];
  char_T f2[22];
  char_T f3[35];
  char_T f4[26];
  char_T f5[36];
  char_T f6[39];
};

#endif                                 /*struct_tag_uo7PCp2pQzQ8uFrW43NfEH*/

#ifndef typedef_b_cell
#define typedef_b_cell

typedef struct tag_uo7PCp2pQzQ8uFrW43NfEH b_cell;

#endif                                 /*typedef_b_cell*/

#ifndef struct_tag_6khVZLlzg3270lst7fcoXG
#define struct_tag_6khVZLlzg3270lst7fcoXG

struct tag_6khVZLlzg3270lst7fcoXG
{
  cell _data;
};

#endif                                 /*struct_tag_6khVZLlzg3270lst7fcoXG*/

#ifndef typedef_s_6khVZLlzg3270lst7fcoXG
#define typedef_s_6khVZLlzg3270lst7fcoXG

typedef struct tag_6khVZLlzg3270lst7fcoXG s_6khVZLlzg3270lst7fcoXG;

#endif                                 /*typedef_s_6khVZLlzg3270lst7fcoXG*/

#ifndef struct_tag_Q9exWnM4P2vFrlJou54v4D
#define struct_tag_Q9exWnM4P2vFrlJou54v4D

struct tag_Q9exWnM4P2vFrlJou54v4D
{
  b_cell _data;
};

#endif                                 /*struct_tag_Q9exWnM4P2vFrlJou54v4D*/

#ifndef typedef_s_Q9exWnM4P2vFrlJou54v4D
#define typedef_s_Q9exWnM4P2vFrlJou54v4D

typedef struct tag_Q9exWnM4P2vFrlJou54v4D s_Q9exWnM4P2vFrlJou54v4D;

#endif                                 /*typedef_s_Q9exWnM4P2vFrlJou54v4D*/

#ifndef typedef_InstanceStruct_7NSoupX0c2Q4Emm6LwOdEF
#define typedef_InstanceStruct_7NSoupX0c2Q4Emm6LwOdEF

typedef struct {
  SimStruct *S;
  soMPU6050Accel sysobj;
  boolean_T sysobj_not_empty;
  void *emlrtRootTLSGlobal;
  int16_T *b_y0;
  int16_T *b_y1;
  int16_T *y2;
  covrtInstance *covInst_CONTAINER_BLOCK_INDEX;
} InstanceStruct_7NSoupX0c2Q4Emm6LwOdEF;

#endif                                 /*typedef_InstanceStruct_7NSoupX0c2Q4Emm6LwOdEF*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_7NSoupX0c2Q4Emm6LwOdEF(SimStruct *S, int_T method,
  void* data);

#endif
