/*
 * PenduloInvertido_TCC.h
 *
 * Code generation for model "PenduloInvertido_TCC".
 *
 * Model version              : 1.10
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Wed Aug 18 14:00:46 2021
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PenduloInvertido_TCC_h_
#define RTW_HEADER_PenduloInvertido_TCC_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef PenduloInvertido_TCC_COMMON_INCLUDES_
# define PenduloInvertido_TCC_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MPU6050wrapper.h"
#endif                               /* PenduloInvertido_TCC_COMMON_INCLUDES_ */

#include "PenduloInvertido_TCC_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Clock;                        /* '<S1>/Clock' */
} B_PenduloInvertido_TCC_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  soMPU6050Accel_PenduloInverti_T obj; /* '<S3>/Accelerometer' */
  soMPU6050Gyro_PenduloInvertid_T obj_h;/* '<S3>/Gyroscope' */
  real_T Delay_DSTATE;                 /* '<S2>/Delay' */
  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK;                /* '<S1>/To Workspace2' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<S1>/To Workspace' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK;                /* '<S1>/To Workspace1' */

  struct {
    void *LoggedData;
  } SimulationTime_PWORK;              /* '<S1>/Simulation Time' */

  boolean_T objisempty;                /* '<S3>/Accelerometer' */
  boolean_T objisempty_g;              /* '<S3>/Gyroscope' */
} DW_PenduloInvertido_TCC_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T AnguloSegway;                 /* '<Root>/Angulo Segway' */
} ExtY_PenduloInvertido_TCC_T;

/* Parameters (default storage) */
struct P_PenduloInvertido_TCC_T_ {
  real_T XBias_Value;                  /* Expression: 806.16
                                        * Referenced by: '<S1>/X Bias'
                                        */
  real_T Gain2_Gain;                   /* Expression: -1
                                        * Referenced by: '<S1>/Gain2'
                                        */
  real_T ZBias_Value;                  /* Expression: -768.4
                                        * Referenced by: '<S1>/Z Bias'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T Gain1_Gain_i;                 /* Expression: 0.1
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real_T GyroYBias_Value;              /* Expression: 173
                                        * Referenced by: '<S1>/Gyro Y Bias'
                                        */
  real_T GanhoRads_Gain;               /* Expression: 0.000133158
                                        * Referenced by: '<S1>/Ganho (Rad//s)'
                                        */
  real_T SampleTime_Value;             /* Expression: 0.02
                                        * Referenced by: '<S1>/Sample Time'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S2>/Delay'
                                        */
  real_T Gain2_Gain_o;                 /* Expression: 0.9
                                        * Referenced by: '<S2>/Gain2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_PenduloInvertido_TCC_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_PenduloInvertido_TCC_T PenduloInvertido_TCC_P;

/* Block signals (default storage) */
extern B_PenduloInvertido_TCC_T PenduloInvertido_TCC_B;

/* Block states (default storage) */
extern DW_PenduloInvertido_TCC_T PenduloInvertido_TCC_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_PenduloInvertido_TCC_T PenduloInvertido_TCC_Y;

/* Model entry point functions */
extern void PenduloInvertido_TCC_initialize(void);
extern void PenduloInvertido_TCC_step(void);
extern void PenduloInvertido_TCC_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PenduloInvertido_TCC_T *const PenduloInvertido_TCC_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion2' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'PenduloInvertido_TCC'
 * '<S1>'   : 'PenduloInvertido_TCC/Sensor MPU6050 Correto'
 * '<S2>'   : 'PenduloInvertido_TCC/Sensor MPU6050 Correto/Filtro Complementar'
 * '<S3>'   : 'PenduloInvertido_TCC/Sensor MPU6050 Correto/MPU6050'
 */
#endif                                 /* RTW_HEADER_PenduloInvertido_TCC_h_ */
