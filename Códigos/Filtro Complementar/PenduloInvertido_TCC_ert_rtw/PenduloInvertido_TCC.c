/*
 * PenduloInvertido_TCC.c
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

#include "PenduloInvertido_TCC.h"
#include "PenduloInvertido_TCC_private.h"

/* Block signals (default storage) */
B_PenduloInvertido_TCC_T PenduloInvertido_TCC_B;

/* Block states (default storage) */
DW_PenduloInvertido_TCC_T PenduloInvertido_TCC_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_PenduloInvertido_TCC_T PenduloInvertido_TCC_Y;

/* Real-time model */
RT_MODEL_PenduloInvertido_TCC_T PenduloInvertido_TCC_M_;
RT_MODEL_PenduloInvertido_TCC_T *const PenduloInvertido_TCC_M =
  &PenduloInvertido_TCC_M_;

/* Forward declaration for local functions */
static void matlabCodegenHandle_matlabCod_h(soMPU6050Accel_PenduloInverti_T *obj);
static void matlabCodegenHandle_matlabCodeg(soMPU6050Gyro_PenduloInvertid_T *obj);
real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int16_T u0_0;
  int16_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

static void matlabCodegenHandle_matlabCod_h(soMPU6050Accel_PenduloInverti_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void matlabCodegenHandle_matlabCodeg(soMPU6050Gyro_PenduloInvertid_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

/* Model step function */
void PenduloInvertido_TCC_step(void)
{
  /* local block i/o variables */
  real_T rtb_Sum_e;
  int16_T rtb_Accelerometer_o1;
  int16_T rtb_Accelerometer_o3;
  int16_T rtb_Gyroscope_o2;
  int16_T out[3];

  /* MATLABSystem: '<S3>/Accelerometer' */
  MPU6050Accel_Read(out);
  rtb_Accelerometer_o1 = out[0];
  rtb_Accelerometer_o3 = out[2];

  /* MATLABSystem: '<S3>/Gyroscope' */
  MPU6050Gyro_Read(out);
  rtb_Gyroscope_o2 = out[1];

  /* Sum: '<S2>/Sum' incorporates:
   *  Constant: '<S1>/Gyro Y Bias'
   *  Constant: '<S1>/Sample Time'
   *  Constant: '<S1>/X Bias'
   *  Constant: '<S1>/Z Bias'
   *  Delay: '<S2>/Delay'
   *  Gain: '<S1>/Gain1'
   *  Gain: '<S1>/Gain2'
   *  Gain: '<S1>/Ganho (Rad//s)'
   *  Gain: '<S2>/Gain1'
   *  Gain: '<S2>/Gain2'
   *  Product: '<S2>/Product'
   *  Sum: '<S1>/Sum'
   *  Sum: '<S1>/Sum1'
   *  Sum: '<S1>/Sum2'
   *  Sum: '<S2>/Sum1'
   *  Trigonometry: '<S1>/Trigonometric Function'
   */
  rtb_Sum_e = ((PenduloInvertido_TCC_P.GyroYBias_Value + (real_T)
                rtb_Gyroscope_o2) * PenduloInvertido_TCC_P.GanhoRads_Gain *
               PenduloInvertido_TCC_P.SampleTime_Value +
               PenduloInvertido_TCC_DW.Delay_DSTATE) *
    PenduloInvertido_TCC_P.Gain2_Gain_o + rt_atan2d_snf(((real_T)
    rtb_Accelerometer_o1 - PenduloInvertido_TCC_P.XBias_Value) *
    PenduloInvertido_TCC_P.Gain2_Gain, ((real_T)rtb_Accelerometer_o3 -
    PenduloInvertido_TCC_P.ZBias_Value) * PenduloInvertido_TCC_P.Gain1_Gain) *
    PenduloInvertido_TCC_P.Gain1_Gain_i;

  /* Outport: '<Root>/Angulo Segway' */
  PenduloInvertido_TCC_Y.AnguloSegway = rtb_Sum_e;

  /* Clock: '<S1>/Clock' */
  PenduloInvertido_TCC_B.Clock = PenduloInvertido_TCC_M->Timing.t[0];

  /* Update for Delay: '<S2>/Delay' */
  PenduloInvertido_TCC_DW.Delay_DSTATE = rtb_Sum_e;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++PenduloInvertido_TCC_M->Timing.clockTick0)) {
    ++PenduloInvertido_TCC_M->Timing.clockTickH0;
  }

  PenduloInvertido_TCC_M->Timing.t[0] =
    PenduloInvertido_TCC_M->Timing.clockTick0 *
    PenduloInvertido_TCC_M->Timing.stepSize0 +
    PenduloInvertido_TCC_M->Timing.clockTickH0 *
    PenduloInvertido_TCC_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.02s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.02, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    PenduloInvertido_TCC_M->Timing.clockTick1++;
    if (!PenduloInvertido_TCC_M->Timing.clockTick1) {
      PenduloInvertido_TCC_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void PenduloInvertido_TCC_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)PenduloInvertido_TCC_M, 0,
                sizeof(RT_MODEL_PenduloInvertido_TCC_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&PenduloInvertido_TCC_M->solverInfo,
                          &PenduloInvertido_TCC_M->Timing.simTimeStep);
    rtsiSetTPtr(&PenduloInvertido_TCC_M->solverInfo, &rtmGetTPtr
                (PenduloInvertido_TCC_M));
    rtsiSetStepSizePtr(&PenduloInvertido_TCC_M->solverInfo,
                       &PenduloInvertido_TCC_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&PenduloInvertido_TCC_M->solverInfo,
                          (&rtmGetErrorStatus(PenduloInvertido_TCC_M)));
    rtsiSetRTModelPtr(&PenduloInvertido_TCC_M->solverInfo,
                      PenduloInvertido_TCC_M);
  }

  rtsiSetSimTimeStep(&PenduloInvertido_TCC_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&PenduloInvertido_TCC_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(PenduloInvertido_TCC_M, &PenduloInvertido_TCC_M->Timing.tArray[0]);
  PenduloInvertido_TCC_M->Timing.stepSize0 = 0.02;

  /* block I/O */
  (void) memset(((void *) &PenduloInvertido_TCC_B), 0,
                sizeof(B_PenduloInvertido_TCC_T));

  /* states (dwork) */
  (void) memset((void *)&PenduloInvertido_TCC_DW, 0,
                sizeof(DW_PenduloInvertido_TCC_T));

  /* external outputs */
  PenduloInvertido_TCC_Y.AnguloSegway = 0.0;

  /* Start for MATLABSystem: '<S3>/Accelerometer' */
  PenduloInvertido_TCC_DW.obj.matlabCodegenIsDeleted = false;
  PenduloInvertido_TCC_DW.objisempty = true;
  PenduloInvertido_TCC_DW.obj.isInitialized = 1L;
  MPU6050Accel_Init();
  PenduloInvertido_TCC_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/Gyroscope' */
  PenduloInvertido_TCC_DW.obj_h.matlabCodegenIsDeleted = false;
  PenduloInvertido_TCC_DW.objisempty_g = true;
  PenduloInvertido_TCC_DW.obj_h.isInitialized = 1L;
  MPU6050Gyro_Init(0.0);
  PenduloInvertido_TCC_DW.obj_h.isSetupComplete = true;

  /* InitializeConditions for Delay: '<S2>/Delay' */
  PenduloInvertido_TCC_DW.Delay_DSTATE =
    PenduloInvertido_TCC_P.Delay_InitialCondition;
}

/* Model terminate function */
void PenduloInvertido_TCC_terminate(void)
{
  /* Terminate for MATLABSystem: '<S3>/Accelerometer' */
  matlabCodegenHandle_matlabCod_h(&PenduloInvertido_TCC_DW.obj);

  /* Terminate for MATLABSystem: '<S3>/Gyroscope' */
  matlabCodegenHandle_matlabCodeg(&PenduloInvertido_TCC_DW.obj_h);
}
