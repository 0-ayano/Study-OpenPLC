#include "beremiz.h"
#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

__DECLARE_ENUMERATED_TYPE(LOGLEVEL,
  LOGLEVEL__CRITICAL,
  LOGLEVEL__WARNING,
  LOGLEVEL__INFO,
  LOGLEVEL__DEBUG
)
// FUNCTION_BLOCK LOGGER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,MSG)
  __DECLARE_VAR(LOGLEVEL,LEVEL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TRIG0)

} LOGGER;

void LOGGER_init__(LOGGER *data__, BOOL retain);
// Code part
void LOGGER_body__(LOGGER *data__);
// FUNCTION_BLOCK PYTHON_EVAL
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,CODE)
  __DECLARE_VAR(BOOL,ACK)
  __DECLARE_VAR(STRING,RESULT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(DWORD,STATE)
  __DECLARE_VAR(STRING,BUFFER)
  __DECLARE_VAR(STRING,PREBUFFER)
  __DECLARE_VAR(BOOL,TRIGM1)
  __DECLARE_VAR(BOOL,TRIGGED)

} PYTHON_EVAL;

void PYTHON_EVAL_init__(PYTHON_EVAL *data__, BOOL retain);
// Code part
void PYTHON_EVAL_body__(PYTHON_EVAL *data__);
// FUNCTION_BLOCK PYTHON_POLL
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,CODE)
  __DECLARE_VAR(BOOL,ACK)
  __DECLARE_VAR(STRING,RESULT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(DWORD,STATE)
  __DECLARE_VAR(STRING,BUFFER)
  __DECLARE_VAR(STRING,PREBUFFER)
  __DECLARE_VAR(BOOL,TRIGM1)
  __DECLARE_VAR(BOOL,TRIGGED)

} PYTHON_POLL;

void PYTHON_POLL_init__(PYTHON_POLL *data__, BOOL retain);
// Code part
void PYTHON_POLL_body__(PYTHON_POLL *data__);
// FUNCTION_BLOCK PYTHON_GEAR
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(UINT,N)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,CODE)
  __DECLARE_VAR(BOOL,ACK)
  __DECLARE_VAR(STRING,RESULT)

  // FB private variables - TEMP, private and located variables
  PYTHON_EVAL PY_EVAL;
  __DECLARE_VAR(UINT,COUNTER)
  __DECLARE_VAR(UINT,_TMP_ADD10_OUT)
  __DECLARE_VAR(BOOL,_TMP_EQ13_OUT)
  __DECLARE_VAR(UINT,_TMP_SEL15_OUT)
  __DECLARE_VAR(BOOL,_TMP_AND7_OUT)

} PYTHON_GEAR;

void PYTHON_GEAR_init__(PYTHON_GEAR *data__, BOOL retain);
// Code part
void PYTHON_GEAR_body__(PYTHON_GEAR *data__);
// PROGRAM VA_CONTROL
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(WORD,VA_AD)
  __DECLARE_VAR(WORD,NM_AD)
  __DECLARE_VAR(REAL,VREF)
  __DECLARE_VAR(REAL,VA)
  __DECLARE_VAR(REAL,DUTY_VA)
  __DECLARE_VAR(WORD,PWM1)
  __DECLARE_VAR(BOOL,R_RUN)
  __DECLARE_VAR(BOOL,R1)
  __DECLARE_VAR(BOOL,R2)
  __DECLARE_VAR(BOOL,RTIM0)
  __DECLARE_VAR(BOOL,RTIM1)
  __DECLARE_VAR(BOOL,RTIM2)
  __DECLARE_VAR(BOOL,RTIM3)
  __DECLARE_VAR(BOOL,RTIM4)
  __DECLARE_VAR(BOOL,RUN)
  __DECLARE_VAR(BOOL,STOP)
  __DECLARE_VAR(BOOL,G_RESET)
  TON TON1;
  TON TON0;
  RAMP RAMP0;
  TON TON2;
  TON TON3;
  TON TON4;
  TON TON5;
  RAMP RAMP1;
  RAMP RAMP2;
  RAMP RAMP3;
  RAMP RAMP5;
  INTEGRAL INTEGRAL0;
  TON TON6;
  __DECLARE_VAR(WORD,_TMP_REAL_TO_WORD212_OUT)
  __DECLARE_VAR(REAL,_TMP_WORD_TO_REAL89_OUT)
  __DECLARE_VAR(BOOL,_TMP_MOVE67_ENO)
  __DECLARE_VAR(REAL,_TMP_MOVE67_OUT)
  __DECLARE_VAR(BOOL,_TMP_MOVE79_ENO)
  __DECLARE_VAR(REAL,_TMP_MOVE79_OUT)
  __DECLARE_VAR(REAL,_TMP_ADD206_OUT)
  __DECLARE_VAR(REAL,_TMP_ADD207_OUT)
  __DECLARE_VAR(REAL,_TMP_ADD208_OUT)
  __DECLARE_VAR(REAL,_TMP_ADD209_OUT)
  __DECLARE_VAR(BOOL,_TMP_SUB216_ENO)
  __DECLARE_VAR(REAL,_TMP_SUB216_OUT)
  __DECLARE_VAR(BOOL,_TMP_MUL219_ENO)
  __DECLARE_VAR(REAL,_TMP_MUL219_OUT)
  __DECLARE_VAR(REAL,_TMP_SUB228_OUT)
  __DECLARE_VAR(REAL,_TMP_MUL229_OUT)
  __DECLARE_VAR(REAL,_TMP_SUB231_OUT)
  __DECLARE_VAR(BOOL,_TMP_MUL233_ENO)
  __DECLARE_VAR(REAL,_TMP_MUL233_OUT)
  __DECLARE_VAR(BOOL,_TMP_ADD224_ENO)
  __DECLARE_VAR(REAL,_TMP_ADD224_OUT)
  __DECLARE_VAR(BOOL,_TMP_LIMIT225_ENO)
  __DECLARE_VAR(REAL,_TMP_LIMIT225_OUT)

} VA_CONTROL;

void VA_CONTROL_init__(VA_CONTROL *data__, BOOL retain);
// Code part
void VA_CONTROL_body__(VA_CONTROL *data__);
#endif //__POUS_H