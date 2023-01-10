void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PYTHON_EVAL_init__(PYTHON_EVAL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_EVAL_body__(PYTHON_EVAL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_EVAL_body__() 





void PYTHON_POLL_init__(PYTHON_POLL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_POLL_body__(PYTHON_POLL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_POLL_body__() 





void PYTHON_GEAR_init__(PYTHON_GEAR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->N,0,retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  PYTHON_EVAL_init__(&data__->PY_EVAL,retain);
  __INIT_VAR(data__->COUNTER,0,retain)
  __INIT_VAR(data__->_TMP_ADD10_OUT,0,retain)
  __INIT_VAR(data__->_TMP_EQ13_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_SEL15_OUT,0,retain)
  __INIT_VAR(data__->_TMP_AND7_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_GEAR_body__(PYTHON_GEAR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_ADD10_OUT,,ADD__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->COUNTER,),
    (UINT)1));
  __SET_VAR(data__->,_TMP_EQ13_OUT,,EQ__BOOL__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->N,),
    (UINT)__GET_VAR(data__->_TMP_ADD10_OUT,)));
  __SET_VAR(data__->,_TMP_SEL15_OUT,,SEL__UINT__BOOL__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->_TMP_EQ13_OUT,),
    (UINT)__GET_VAR(data__->_TMP_ADD10_OUT,),
    (UINT)0));
  __SET_VAR(data__->,COUNTER,,__GET_VAR(data__->_TMP_SEL15_OUT,));
  __SET_VAR(data__->,_TMP_AND7_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_EQ13_OUT,),
    (BOOL)__GET_VAR(data__->TRIG,)));
  __SET_VAR(data__->PY_EVAL.,TRIG,,__GET_VAR(data__->_TMP_AND7_OUT,));
  __SET_VAR(data__->PY_EVAL.,CODE,,__GET_VAR(data__->CODE,));
  PYTHON_EVAL_body__(&data__->PY_EVAL);
  __SET_VAR(data__->,ACK,,__GET_VAR(data__->PY_EVAL.ACK,));
  __SET_VAR(data__->,RESULT,,__GET_VAR(data__->PY_EVAL.RESULT,));

  goto __end;

__end:
  return;
} // PYTHON_GEAR_body__() 





static inline REAL __VA_CONTROL_MOVE__REAL__REAL1(BOOL EN,
  REAL IN,
  VA_CONTROL *data__)
{
  REAL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE67_ENO,);
  __res = MOVE__REAL__REAL(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE67_ENO,,__TMP_ENO);
  return __res;
}

static inline REAL __VA_CONTROL_MOVE__REAL__REAL2(BOOL EN,
  REAL IN,
  VA_CONTROL *data__)
{
  REAL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE79_ENO,);
  __res = MOVE__REAL__REAL(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE79_ENO,,__TMP_ENO);
  return __res;
}

static inline REAL __VA_CONTROL_SUB__REAL__REAL__REAL3(BOOL EN,
  REAL IN1,
  REAL IN2,
  VA_CONTROL *data__)
{
  REAL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_SUB216_ENO,);
  __res = SUB__REAL__REAL__REAL(EN,
    &__TMP_ENO,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_SUB216_ENO,,__TMP_ENO);
  return __res;
}

static inline REAL __VA_CONTROL_MUL__REAL__REAL4(BOOL EN,
  UINT __PARAM_COUNT,
  REAL IN1,
  REAL IN2,
  VA_CONTROL *data__)
{
  REAL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MUL219_ENO,);
  __res = MUL__REAL__REAL(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_MUL219_ENO,,__TMP_ENO);
  return __res;
}

static inline REAL __VA_CONTROL_MUL__REAL__REAL5(BOOL EN,
  UINT __PARAM_COUNT,
  REAL IN1,
  REAL IN2,
  VA_CONTROL *data__)
{
  REAL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MUL233_ENO,);
  __res = MUL__REAL__REAL(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_MUL233_ENO,,__TMP_ENO);
  return __res;
}

static inline REAL __VA_CONTROL_ADD__REAL__REAL6(BOOL EN,
  UINT __PARAM_COUNT,
  REAL IN1,
  REAL IN2,
  VA_CONTROL *data__)
{
  REAL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_ADD224_ENO,);
  __res = ADD__REAL__REAL(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_ADD224_ENO,,__TMP_ENO);
  return __res;
}

static inline REAL __VA_CONTROL_LIMIT__REAL__REAL__REAL__REAL7(BOOL EN,
  REAL MN,
  REAL IN,
  REAL MX,
  VA_CONTROL *data__)
{
  REAL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_LIMIT225_ENO,);
  __res = LIMIT__REAL__REAL__REAL__REAL(EN,
    &__TMP_ENO,
    MN,
    IN,
    MX);
  __SET_VAR(,data__->_TMP_LIMIT225_ENO,,__TMP_ENO);
  return __res;
}

void VA_CONTROL_init__(VA_CONTROL *data__, BOOL retain) {
  __INIT_VAR(data__->VA_AD,0,retain)
  __INIT_VAR(data__->NM_AD,0,retain)
  __INIT_VAR(data__->VREF,0.0,retain)
  __INIT_VAR(data__->VA,0.0,retain)
  __INIT_VAR(data__->DUTY_VA,0.0,retain)
  __INIT_VAR(data__->PWM1,0,retain)
  __INIT_VAR(data__->R_RUN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->R1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->R2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RTIM0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RTIM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RTIM2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RTIM3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RTIM4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RUN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STOP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->G_RESET,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->TON1,retain);
  TON_init__(&data__->TON0,retain);
  RAMP_init__(&data__->RAMP0,retain);
  TON_init__(&data__->TON2,retain);
  TON_init__(&data__->TON3,retain);
  TON_init__(&data__->TON4,retain);
  TON_init__(&data__->TON5,retain);
  RAMP_init__(&data__->RAMP1,retain);
  RAMP_init__(&data__->RAMP2,retain);
  RAMP_init__(&data__->RAMP3,retain);
  RAMP_init__(&data__->RAMP5,retain);
  INTEGRAL_init__(&data__->INTEGRAL0,retain);
  TON_init__(&data__->TON6,retain);
  __INIT_VAR(data__->_TMP_REAL_TO_WORD212_OUT,0,retain)
  __INIT_VAR(data__->_TMP_WORD_TO_REAL89_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE67_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE67_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE79_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE79_OUT,0,retain)
  __INIT_VAR(data__->_TMP_ADD206_OUT,0,retain)
  __INIT_VAR(data__->_TMP_ADD207_OUT,0,retain)
  __INIT_VAR(data__->_TMP_ADD208_OUT,0,retain)
  __INIT_VAR(data__->_TMP_ADD209_OUT,0,retain)
  __INIT_VAR(data__->_TMP_SUB216_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_SUB216_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MUL219_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MUL219_OUT,0,retain)
  __INIT_VAR(data__->_TMP_SUB228_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MUL229_OUT,0,retain)
  __INIT_VAR(data__->_TMP_SUB231_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MUL233_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MUL233_OUT,0,retain)
  __INIT_VAR(data__->_TMP_ADD224_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_ADD224_OUT,0,retain)
  __INIT_VAR(data__->_TMP_LIMIT225_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_LIMIT225_OUT,0,retain)
}

// Code part
void VA_CONTROL_body__(VA_CONTROL *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,R_RUN,,(!(__GET_VAR(data__->STOP,)) && (__GET_VAR(data__->R_RUN,) || __GET_VAR(data__->RUN,))));
  __SET_VAR(data__->,G_RESET,,__GET_VAR(data__->STOP,));
  __SET_VAR(data__->TON1.,IN,,__GET_VAR(data__->R_RUN,));
  __SET_VAR(data__->TON1.,PT,,__time_to_timespec(1, 0, 1, 0, 0, 0));
  TON_body__(&data__->TON1);
  __SET_VAR(data__->,R1,,__GET_VAR(data__->TON1.Q,));
  __SET_VAR(data__->,_TMP_REAL_TO_WORD212_OUT,,REAL_TO_WORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->DUTY_VA,)));
  __SET_VAR(data__->,PWM1,,__GET_VAR(data__->_TMP_REAL_TO_WORD212_OUT,));
  __SET_VAR(data__->,_TMP_WORD_TO_REAL89_OUT,,WORD_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (WORD)__GET_VAR(data__->VA_AD,)));
  __SET_VAR(data__->,VA,,__GET_VAR(data__->_TMP_WORD_TO_REAL89_OUT,));
  __SET_VAR(data__->TON0.,IN,,__GET_VAR(data__->R1,));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 0, 2, 0, 0, 0));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->,RTIM0,,__GET_VAR(data__->TON0.Q,));
  __SET_VAR(data__->TON2.,IN,,__GET_VAR(data__->RTIM0,));
  __SET_VAR(data__->TON2.,PT,,__time_to_timespec(1, 0, 7, 0, 0, 0));
  TON_body__(&data__->TON2);
  __SET_VAR(data__->,RTIM1,,__GET_VAR(data__->TON2.Q,));
  __SET_VAR(data__->,_TMP_MOVE67_OUT,,__VA_CONTROL_MOVE__REAL__REAL1(
    (BOOL)!(__GET_VAR(data__->R_RUN,)),
    (REAL)0.0,
    data__));
  if (__GET_VAR(data__->_TMP_MOVE67_ENO,)) {
    __SET_VAR(data__->,VREF,,__GET_VAR(data__->_TMP_MOVE67_OUT,));
  };
  __SET_VAR(data__->TON3.,IN,,__GET_VAR(data__->RTIM1,));
  __SET_VAR(data__->TON3.,PT,,__time_to_timespec(1, 0, 7, 0, 0, 0));
  TON_body__(&data__->TON3);
  __SET_VAR(data__->,RTIM2,,__GET_VAR(data__->TON3.Q,));
  __SET_VAR(data__->,_TMP_MOVE79_OUT,,__VA_CONTROL_MOVE__REAL__REAL2(
    (BOOL)!(__GET_VAR(data__->R_RUN,)),
    (REAL)0.0,
    data__));
  if (__GET_VAR(data__->_TMP_MOVE79_ENO,)) {
    __SET_VAR(data__->,DUTY_VA,,__GET_VAR(data__->_TMP_MOVE79_OUT,));
  };
  __SET_VAR(data__->TON4.,IN,,__GET_VAR(data__->RTIM2,));
  __SET_VAR(data__->TON4.,PT,,__time_to_timespec(1, 0, 7, 0, 0, 0));
  TON_body__(&data__->TON4);
  __SET_VAR(data__->,RTIM3,,__GET_VAR(data__->TON4.Q,));
  __SET_VAR(data__->TON6.,IN,,__GET_VAR(data__->R1,));
  __SET_VAR(data__->TON6.,PT,,__time_to_timespec(1, 0, 1, 0, 0, 0));
  TON_body__(&data__->TON6);
  __SET_VAR(data__->,R2,,__GET_VAR(data__->TON6.Q,));
  __SET_VAR(data__->TON5.,IN,,__GET_VAR(data__->RTIM3,));
  __SET_VAR(data__->TON5.,PT,,__time_to_timespec(1, 0, 7, 0, 0, 0));
  TON_body__(&data__->TON5);
  __SET_VAR(data__->,RTIM4,,__GET_VAR(data__->TON5.Q,));
  __SET_VAR(data__->RAMP0.,RUN,,__GET_VAR(data__->RTIM0,));
  __SET_VAR(data__->RAMP0.,X0,,0.0);
  __SET_VAR(data__->RAMP0.,X1,,4797.6);
  __SET_VAR(data__->RAMP0.,TR,,__time_to_timespec(1, 0, 2, 0, 0, 0));
  __SET_VAR(data__->RAMP0.,CYCLE,,__time_to_timespec(1, 1, 0, 0, 0, 0));
  RAMP_body__(&data__->RAMP0);
  __SET_VAR(data__->RAMP1.,RUN,,__GET_VAR(data__->RTIM1,));
  __SET_VAR(data__->RAMP1.,X0,,0.0);
  __SET_VAR(data__->RAMP1.,X1,,4797.6);
  __SET_VAR(data__->RAMP1.,TR,,__time_to_timespec(1, 0, 2, 0, 0, 0));
  __SET_VAR(data__->RAMP1.,CYCLE,,__time_to_timespec(1, 1, 0, 0, 0, 0));
  RAMP_body__(&data__->RAMP1);
  __SET_VAR(data__->,_TMP_ADD206_OUT,,ADD__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->RAMP0.XOUT,),
    (REAL)__GET_VAR(data__->RAMP1.XOUT,)));
  __SET_VAR(data__->RAMP3.,RUN,,__GET_VAR(data__->RTIM2,));
  __SET_VAR(data__->RAMP3.,X0,,0.0);
  __SET_VAR(data__->RAMP3.,X1,,4797.6);
  __SET_VAR(data__->RAMP3.,TR,,__time_to_timespec(1, 0, 2, 0, 0, 0));
  __SET_VAR(data__->RAMP3.,CYCLE,,__time_to_timespec(1, 1, 0, 0, 0, 0));
  RAMP_body__(&data__->RAMP3);
  __SET_VAR(data__->,_TMP_ADD207_OUT,,ADD__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->_TMP_ADD206_OUT,),
    (REAL)__GET_VAR(data__->RAMP3.XOUT,)));
  __SET_VAR(data__->RAMP2.,RUN,,__GET_VAR(data__->RTIM3,));
  __SET_VAR(data__->RAMP2.,X0,,0.0);
  __SET_VAR(data__->RAMP2.,X1,,4797.6);
  __SET_VAR(data__->RAMP2.,TR,,__time_to_timespec(1, 0, 2, 0, 0, 0));
  __SET_VAR(data__->RAMP2.,CYCLE,,__time_to_timespec(1, 1, 0, 0, 0, 0));
  RAMP_body__(&data__->RAMP2);
  __SET_VAR(data__->,_TMP_ADD208_OUT,,ADD__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->_TMP_ADD207_OUT,),
    (REAL)__GET_VAR(data__->RAMP2.XOUT,)));
  __SET_VAR(data__->RAMP5.,RUN,,__GET_VAR(data__->RTIM4,));
  __SET_VAR(data__->RAMP5.,X0,,0.0);
  __SET_VAR(data__->RAMP5.,X1,,4797.6);
  __SET_VAR(data__->RAMP5.,TR,,__time_to_timespec(1, 0, 2, 0, 0, 0));
  __SET_VAR(data__->RAMP5.,CYCLE,,__time_to_timespec(1, 1, 0, 0, 0, 0));
  RAMP_body__(&data__->RAMP5);
  __SET_VAR(data__->,_TMP_ADD209_OUT,,ADD__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->_TMP_ADD208_OUT,),
    (REAL)__GET_VAR(data__->RAMP5.XOUT,)));
  __SET_VAR(data__->,VREF,,__GET_VAR(data__->_TMP_ADD209_OUT,));
  __SET_VAR(data__->,_TMP_SUB216_OUT,,__VA_CONTROL_SUB__REAL__REAL__REAL3(
    (BOOL)__GET_VAR(data__->R1,),
    (REAL)__GET_VAR(data__->VREF,),
    (REAL)__GET_VAR(data__->VA,),
    data__));
  __SET_VAR(data__->,_TMP_MUL219_OUT,,__VA_CONTROL_MUL__REAL__REAL4(
    (BOOL)__GET_VAR(data__->R1,),
    (UINT)2,
    (REAL)__GET_VAR(data__->_TMP_SUB216_OUT,),
    (REAL)0.625,
    data__));
  __SET_VAR(data__->,_TMP_SUB228_OUT,,SUB__REAL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->_TMP_ADD224_OUT,),
    (REAL)__GET_VAR(data__->_TMP_LIMIT225_OUT,)));
  __SET_VAR(data__->,_TMP_MUL229_OUT,,MUL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->_TMP_SUB228_OUT,),
    (REAL)1.6));
  __SET_VAR(data__->,_TMP_SUB231_OUT,,SUB__REAL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->_TMP_SUB216_OUT,),
    (REAL)__GET_VAR(data__->_TMP_MUL229_OUT,)));
  __SET_VAR(data__->,_TMP_MUL233_OUT,,__VA_CONTROL_MUL__REAL__REAL5(
    (BOOL)__GET_VAR(data__->R1,),
    (UINT)2,
    (REAL)__GET_VAR(data__->_TMP_SUB231_OUT,),
    (REAL)2.5,
    data__));
  __SET_VAR(data__->INTEGRAL0.,RUN,,__GET_VAR(data__->R1,));
  __SET_VAR(data__->INTEGRAL0.,R1,,!(__GET_VAR(data__->R_RUN,)));
  __SET_VAR(data__->INTEGRAL0.,XIN,,__GET_VAR(data__->_TMP_MUL233_OUT,));
  __SET_VAR(data__->INTEGRAL0.,X0,,0.0);
  __SET_VAR(data__->INTEGRAL0.,CYCLE,,__time_to_timespec(1, 1, 0, 0, 0, 0));
  INTEGRAL_body__(&data__->INTEGRAL0);
  __SET_VAR(data__->,_TMP_ADD224_OUT,,__VA_CONTROL_ADD__REAL__REAL6(
    (BOOL)__GET_VAR(data__->R1,),
    (UINT)2,
    (REAL)__GET_VAR(data__->_TMP_MUL219_OUT,),
    (REAL)__GET_VAR(data__->INTEGRAL0.XOUT,),
    data__));
  __SET_VAR(data__->,_TMP_LIMIT225_OUT,,__VA_CONTROL_LIMIT__REAL__REAL__REAL__REAL7(
    (BOOL)__GET_VAR(data__->R1,),
    (REAL)0.0,
    (REAL)__GET_VAR(data__->_TMP_ADD224_OUT,),
    (REAL)59000.0,
    data__));
  if (__GET_VAR(data__->_TMP_LIMIT225_ENO,)) {
    __SET_VAR(data__->,DUTY_VA,,__GET_VAR(data__->_TMP_LIMIT225_OUT,));
  };

  goto __end;

__end:
  return;
} // VA_CONTROL_body__() 





