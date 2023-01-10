PROGRAM va_control
  VAR
    Va_AD AT %IW102 : WORD;
    Nm_AD AT %IW103 : WORD;
  END_VAR
  VAR
    Vref : REAL := 0.0;
    Va : REAL := 0.0;
    Duty_Va : REAL := 0.0;
  END_VAR
  VAR
    PWM1 AT %QW101 : WORD;
  END_VAR
  VAR
    R_run : BOOL;
  END_VAR
  VAR
    R1 AT %QX100.2 : BOOL;
    R2 AT %QX100.3 : BOOL;
  END_VAR
  VAR
    Rtim0 : BOOL;
    Rtim1 : BOOL;
    Rtim2 : BOOL;
    Rtim3 : BOOL;
    Rtim4 : BOOL;
  END_VAR
  VAR
    Run AT %IX100.0 : BOOL;
    Stop AT %IX100.1 : BOOL;
    G_reset AT %QX100.1 : BOOL;
  END_VAR
  VAR
    TON1 : TON;
    TON0 : TON;
    RAMP0 : RAMP;
    TON2 : TON;
    TON3 : TON;
    TON4 : TON;
    TON5 : TON;
    RAMP1 : RAMP;
    RAMP2 : RAMP;
    RAMP3 : RAMP;
    RAMP5 : RAMP;
    INTEGRAL0 : INTEGRAL;
    TON6 : TON;
    _TMP_REAL_TO_WORD212_OUT : WORD;
    _TMP_WORD_TO_REAL89_OUT : REAL;
    _TMP_MOVE67_ENO : BOOL;
    _TMP_MOVE67_OUT : REAL;
    _TMP_MOVE79_ENO : BOOL;
    _TMP_MOVE79_OUT : REAL;
    _TMP_ADD206_OUT : REAL;
    _TMP_ADD207_OUT : REAL;
    _TMP_ADD208_OUT : REAL;
    _TMP_ADD209_OUT : REAL;
    _TMP_SUB216_ENO : BOOL;
    _TMP_SUB216_OUT : REAL;
    _TMP_MUL219_ENO : BOOL;
    _TMP_MUL219_OUT : REAL;
    _TMP_SUB228_OUT : REAL;
    _TMP_MUL229_OUT : REAL;
    _TMP_SUB231_OUT : REAL;
    _TMP_MUL233_ENO : BOOL;
    _TMP_MUL233_OUT : REAL;
    _TMP_ADD224_ENO : BOOL;
    _TMP_ADD224_OUT : REAL;
    _TMP_LIMIT225_ENO : BOOL;
    _TMP_LIMIT225_OUT : REAL;
  END_VAR

  R_run := NOT(Stop) AND (R_run OR Run);
  G_reset := Stop;
  TON1(IN := R_run, PT := T#1s);
  R1 := TON1.Q;
  _TMP_REAL_TO_WORD212_OUT := REAL_TO_WORD(Duty_Va);
  PWM1 := _TMP_REAL_TO_WORD212_OUT;
  _TMP_WORD_TO_REAL89_OUT := WORD_TO_REAL(Va_AD);
  Va := _TMP_WORD_TO_REAL89_OUT;
  TON0(IN := R1, PT := T#2s);
  Rtim0 := TON0.Q;
  TON2(IN := Rtim0, PT := T#7s);
  Rtim1 := TON2.Q;
  _TMP_MOVE67_OUT := MOVE(EN := NOT(R_run), IN := 0.0, ENO => _TMP_MOVE67_ENO);
  IF _TMP_MOVE67_ENO THEN
      Vref := _TMP_MOVE67_OUT;
  END_IF;
  TON3(IN := Rtim1, PT := T#7s);
  Rtim2 := TON3.Q;
  _TMP_MOVE79_OUT := MOVE(EN := NOT(R_run), IN := 0.0, ENO => _TMP_MOVE79_ENO);
  IF _TMP_MOVE79_ENO THEN
      Duty_Va := _TMP_MOVE79_OUT;
  END_IF;
  TON4(IN := Rtim2, PT := T#7s);
  Rtim3 := TON4.Q;
  TON6(IN := R1, PT := T#1s);
  R2 := TON6.Q;
  TON5(IN := Rtim3, PT := T#7s);
  Rtim4 := TON5.Q;
  RAMP0(RUN := Rtim0, X0 := 0.0, X1 := 4797.6, TR := T#2s, CYCLE := T#1ms);
  RAMP1(RUN := Rtim1, X0 := 0.0, X1 := 4797.6, TR := T#2s, CYCLE := T#1ms);
  _TMP_ADD206_OUT := ADD(RAMP0.XOUT, RAMP1.XOUT);
  RAMP3(RUN := Rtim2, X0 := 0.0, X1 := 4797.6, TR := T#2s, CYCLE := T#1ms);
  _TMP_ADD207_OUT := ADD(_TMP_ADD206_OUT, RAMP3.XOUT);
  RAMP2(RUN := Rtim3, X0 := 0.0, X1 := 4797.6, TR := T#2s, CYCLE := T#1ms);
  _TMP_ADD208_OUT := ADD(_TMP_ADD207_OUT, RAMP2.XOUT);
  RAMP5(RUN := Rtim4, X0 := 0.0, X1 := 4797.6, TR := T#2s, CYCLE := T#1ms);
  _TMP_ADD209_OUT := ADD(_TMP_ADD208_OUT, RAMP5.XOUT);
  Vref := _TMP_ADD209_OUT;
  _TMP_SUB216_OUT := SUB(EN := R1, IN1 := Vref, IN2 := Va, ENO => _TMP_SUB216_ENO);
  _TMP_MUL219_OUT := MUL(EN := R1, IN1 := _TMP_SUB216_OUT, IN2 := 0.625, ENO => _TMP_MUL219_ENO);
  _TMP_SUB228_OUT := SUB(_TMP_ADD224_OUT, _TMP_LIMIT225_OUT);
  _TMP_MUL229_OUT := MUL(_TMP_SUB228_OUT, 1.6);
  _TMP_SUB231_OUT := SUB(_TMP_SUB216_OUT, _TMP_MUL229_OUT);
  _TMP_MUL233_OUT := MUL(EN := R1, IN1 := _TMP_SUB231_OUT, IN2 := 2.5, ENO => _TMP_MUL233_ENO);
  INTEGRAL0(RUN := R1, R1 := NOT(R_run), XIN := _TMP_MUL233_OUT, X0 := 0.0, CYCLE := T#1ms);
  _TMP_ADD224_OUT := ADD(EN := R1, IN1 := _TMP_MUL219_OUT, IN2 := INTEGRAL0.XOUT, ENO => _TMP_ADD224_ENO);
  _TMP_LIMIT225_OUT := LIMIT(EN := R1, MN := 0.0, IN := _TMP_ADD224_OUT, MX := 59000.0, ENO => _TMP_LIMIT225_ENO);
  IF _TMP_LIMIT225_ENO THEN
      Duty_Va := _TMP_LIMIT225_OUT;
  END_IF;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#1ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : va_control;
  END_RESOURCE
END_CONFIGURATION
