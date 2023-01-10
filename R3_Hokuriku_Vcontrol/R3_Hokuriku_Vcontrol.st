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
    REAL_TO_WORD212_OUT : WORD;
    WORD_TO_REAL89_OUT : REAL;
    MOVE67_ENO : BOOL;
    MOVE67_OUT : REAL;
    MOVE79_ENO : BOOL;
    MOVE79_OUT : REAL;
    ADD206_OUT : REAL;
    ADD207_OUT : REAL;
    ADD208_OUT : REAL;
    ADD209_OUT : REAL;
    SUB216_ENO : BOOL;
    SUB216_OUT : REAL;
    MUL219_ENO : BOOL;
    MUL219_OUT : REAL;
    SUB228_OUT : REAL;
    MUL229_OUT : REAL;
    SUB231_OUT : REAL;
    MUL233_ENO : BOOL;
    MUL233_OUT : REAL;
    ADD224_ENO : BOOL;
    ADD224_OUT : REAL;
    LIMIT225_ENO : BOOL;
    LIMIT225_OUT : REAL;
  END_VAR

  R_run := NOT(Stop) AND (R_run OR Run);
  G_reset := Stop;
  TON1(IN := R_run, PT := T#1s);
  R1 := TON1.Q;
  REAL_TO_WORD212_OUT := REAL_TO_WORD(Duty_Va);
  PWM1 := REAL_TO_WORD212_OUT;
  WORD_TO_REAL89_OUT := WORD_TO_REAL(Va_AD);
  Va := WORD_TO_REAL89_OUT;
  TON0(IN := R1, PT := T#2s);
  Rtim0 := TON0.Q;
  TON2(IN := Rtim0, PT := T#7s);
  Rtim1 := TON2.Q;
  MOVE67_OUT := MOVE(EN := NOT(R_run), IN := 0.0, ENO => MOVE67_ENO);
  IF MOVE67_ENO THEN
      Vref := MOVE67_OUT;
  END_IF;
  TON3(IN := Rtim1, PT := T#7s);
  Rtim2 := TON3.Q;
  MOVE79_OUT := MOVE(EN := NOT(R_run), IN := 0.0, ENO => MOVE79_ENO);
  IF MOVE79_ENO THEN
      Duty_Va := MOVE79_OUT;
  END_IF;
  TON4(IN := Rtim2, PT := T#7s);
  Rtim3 := TON4.Q;
  TON6(IN := R1, PT := T#1s);
  R2 := TON6.Q;
  TON5(IN := Rtim3, PT := T#7s);
  Rtim4 := TON5.Q;
  RAMP0(RUN := Rtim0, X0 := 0.0, X1 := 4797.6, TR := T#2s, CYCLE := T#1ms);
  RAMP1(RUN := Rtim1, X0 := 0.0, X1 := 4797.6, TR := T#2s, CYCLE := T#1ms);
  ADD206_OUT := ADD(RAMP0.XOUT, RAMP1.XOUT);
  RAMP3(RUN := Rtim2, X0 := 0.0, X1 := 4797.6, TR := T#2s, CYCLE := T#1ms);
  ADD207_OUT := ADD(ADD206_OUT, RAMP3.XOUT);
  RAMP2(RUN := Rtim3, X0 := 0.0, X1 := 4797.6, TR := T#2s, CYCLE := T#1ms);
  ADD208_OUT := ADD(ADD207_OUT, RAMP2.XOUT);
  RAMP5(RUN := Rtim4, X0 := 0.0, X1 := 4797.6, TR := T#2s, CYCLE := T#1ms);
  ADD209_OUT := ADD(ADD208_OUT, RAMP5.XOUT);
  Vref := ADD209_OUT;
  SUB216_OUT := SUB(EN := R1, IN1 := Vref, IN2 := Va, ENO => SUB216_ENO);
  MUL219_OUT := MUL(EN := R1, IN1 := SUB216_OUT, IN2 := 0.625, ENO => MUL219_ENO);
  SUB228_OUT := SUB(ADD224_OUT, LIMIT225_OUT);
  MUL229_OUT := MUL(SUB228_OUT, 1.6);
  SUB231_OUT := SUB(SUB216_OUT, MUL229_OUT);
  MUL233_OUT := MUL(EN := R1, IN1 := SUB231_OUT, IN2 := 2.5, ENO => MUL233_ENO);
  INTEGRAL0(RUN := R1, R1 := NOT(R_run), XIN := MUL233_OUT, X0 := 0.0, CYCLE := T#1ms);
  ADD224_OUT := ADD(EN := R1, IN1 := MUL219_OUT, IN2 := INTEGRAL0.XOUT, ENO => ADD224_ENO);
  LIMIT225_OUT := LIMIT(EN := R1, MN := 0.0, IN := ADD224_OUT, MX := 59000.0, ENO => LIMIT225_ENO);
  IF LIMIT225_ENO THEN
      Duty_Va := LIMIT225_OUT;
  END_IF;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#1ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : va_control;
  END_RESOURCE
END_CONFIGURATION
