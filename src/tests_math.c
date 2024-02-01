/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "s21_math.check" instead.
 */

#include <check.h>
#include <ctype.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(s21_abs_test) {
  // READY
  ck_assert_int_eq(abs(-1), s21_abs(-1));
  ck_assert_int_eq(abs(0), s21_abs(0));
  ck_assert_int_eq(abs(12), s21_abs(12));
}
END_TEST

START_TEST(s21_sqrt_test) {
  // READY
  ck_assert_ldouble_eq_tol(sqrt(1.123123), s21_sqrt(1.123123), S21_EPS);
  ck_assert_ldouble_eq_tol(sqrt(4.23124), s21_sqrt(4.23124), S21_EPS);
  ck_assert_float_nan(s21_sqrt(-121.));
  ck_assert_float_nan(s21_sqrt(-2.89));
  ck_assert_float_nan(s21_sqrt(NAN));
  ck_assert_float_infinite(s21_sqrt(INFINITY));
  ck_assert_float_nan(s21_sqrt(-INFINITY));
  ck_assert_ldouble_eq_tol(sqrt(1234567890.123456), s21_sqrt(1234567890.123456),
                           S21_EPS);
  ck_assert_ldouble_eq_tol(sqrt(0.), s21_sqrt(0.), S21_EPS);
}
END_TEST

START_TEST(s21_cos_test) {
  // READY
  ck_assert_ldouble_eq_tol(cos(2), s21_cos(2), S21_EPS);
  ck_assert_ldouble_eq_tol(cos(-2), s21_cos(-2), S21_EPS);
  ck_assert_ldouble_eq_tol(cos(923423), s21_cos(923423), S21_EPS);
  ck_assert_ldouble_eq_tol(cos(-243235), s21_cos(-243235), S21_EPS);
  ck_assert_ldouble_eq_tol(cos(1 + S21_EPS), s21_cos(1 + S21_EPS), S21_EPS);
  ck_assert_ldouble_eq_tol(cos(-1 - S21_EPS), s21_cos(-1 - S21_EPS), S21_EPS);
  ck_assert_ldouble_eq_tol(cos(-9234231234.123456), s21_cos(-9234231234.123456),
                           1e-06);  // error дальше 6 знаков тоже наверно
  ck_assert_ldouble_eq_tol(cos(9234231234.123456), s21_cos(9234231234.123456),
                           1e-06);  // error дальше 6 знаков тоже наверно
  ck_assert_ldouble_eq_tol(cos(0), s21_cos(0), S21_EPS);
  ck_assert_ldouble_eq_tol(cos(0.123312), s21_cos(0.123312), S21_EPS);
  ck_assert_ldouble_eq_tol(cos(S21_PI), s21_cos(S21_PI), S21_EPS);
  ck_assert_float_nan(s21_cos(INFINITY));
  ck_assert_float_nan(s21_cos(NAN));
  ck_assert_float_nan(s21_cos(-INFINITY));
}
END_TEST

START_TEST(s21_exp_test) {
  // READY
  ck_assert_float_eq_tol(exp(24.34), s21_exp(24.34), S21_EPS);
  ck_assert_float_eq_tol(exp(-24.34), s21_exp(-24.34), S21_EPS);
  ck_assert_float_eq_tol(exp(-17.45), s21_exp(-17.45), S21_EPS);
  ck_assert_ldouble_eq_tol(exp(12), s21_exp(12), S21_EPS);
  ck_assert_ldouble_eq_tol(exp(-12), s21_exp(-12), S21_EPS);
  ck_assert_ldouble_eq_tol(exp(-17.123456), s21_exp(-17.123456), S21_EPS);
  ck_assert_ldouble_eq_tol(exp(-0.45), s21_exp(-0.45), S21_EPS);
  ck_assert_ldouble_eq_tol(exp(0.45), s21_exp(0.45), S21_EPS);
  ck_assert_ldouble_eq_tol(exp(0), s21_exp(0), S21_EPS);
  ck_assert_float_infinite(s21_exp(INFINITY));
  ck_assert_float_nan(s21_exp(NAN));
  ck_assert_float_eq_tol(exp(-INFINITY), s21_exp(-INFINITY), S21_EPS);
}
END_TEST

START_TEST(s21_acos_test) {
  // READY
  double x = 0.999999;
  ck_assert_float_eq_tol(acos(x), s21_acos(x), S21_EPS);
  x = -1.123456;
  ck_assert_float_nan(s21_acos(x));
  x = 0;
  ck_assert_ldouble_eq_tol(acos(x), s21_acos(x), S21_EPS);
  x = INFINITY;
  ck_assert_ldouble_nan(s21_acos(x));
  x = NAN;
  ck_assert_ldouble_nan(s21_acos(x));
  ck_assert_ldouble_nan(s21_acos(1.000001));
  ck_assert_ldouble_eq_tol(acos(-1 - 1e-16), s21_acos(-1 - 1e-16), S21_EPS);
  ck_assert_ldouble_eq_tol(acos(1 + 1e-16), s21_acos(1 + 1e-16), S21_EPS);
}
END_TEST

START_TEST(s21_asin_test) {
  // READY
  double x = 5;
  ck_assert_ldouble_nan(s21_asin(x));
  x = -5;
  ck_assert_ldouble_nan(s21_asin(x));
  x = 0;
  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), S21_EPS);
  ck_assert_ldouble_eq_tol(asin(S21_EPS), s21_asin(S21_EPS), S21_EPS);
  ck_assert_float_eq_tol(asin(0.131231), s21_asin(0.131231), S21_EPS);
  ck_assert_ldouble_eq_tol(asin(1), s21_asin(1), S21_EPS);
  ck_assert_ldouble_eq_tol(asin(-1), s21_asin(-1), S21_EPS);
  ck_assert_ldouble_nan(s21_asin(NAN));
  ck_assert_ldouble_nan(s21_asin(INFINITY));
  ck_assert_ldouble_nan(s21_asin(-INFINITY));
}
END_TEST

START_TEST(s21_atan_test) {
  // READY
  ck_assert_double_eq_tol(atan(-11), s21_atan(-11), S21_EPS);
  ck_assert_double_eq_tol(atan(1), s21_atan(1), S21_EPS);
  ck_assert_ldouble_eq_tol(atan(-1), s21_atan(-1), S21_EPS);
  ck_assert_ldouble_eq_tol(atan(100000000), s21_atan(100000000), S21_EPS);
  ck_assert_ldouble_eq_tol(atan(-10000000000), s21_atan(-10000000000), S21_EPS);
  ck_assert_ldouble_eq_tol(atan(0.923456789012345678901234567890),
                           s21_atan(0.923456789012345678901234567890), S21_EPS);
  ck_assert_ldouble_eq_tol(atan(-0.923456789012345678901234567890),
                           s21_atan(-0.923456789012345678901234567890),
                           S21_EPS);
  ck_assert_ldouble_eq_tol(atan(INFINITY), s21_atan(INFINITY), S21_EPS);
  ck_assert_ldouble_eq_tol(atan(-INFINITY), s21_atan(-INFINITY), S21_EPS);
  ck_assert_double_eq_tol(atan(2), s21_atan(2), S21_EPS);
  ck_assert_ldouble_eq_tol(atan(0), s21_atan(0), S21_EPS);
  ck_assert_ldouble_eq_tol(atan(-4.5553), s21_atan(-4.5553), S21_EPS);
  ck_assert_ldouble_nan(s21_atan(NAN));
  ck_assert_ldouble_eq_tol(atan(INFINITY), s21_atan(INFINITY), S21_EPS);
}
END_TEST

START_TEST(s21_ceil_test) {
  // READY
  ck_assert_float_eq(ceil(0), s21_ceil(0));
  ck_assert_float_eq(ceil(1234), s21_ceil(1234));
  ck_assert_float_eq(ceil(-1234), s21_ceil(-1234));
  ck_assert_float_eq(ceil(1), s21_ceil(1));
  ck_assert_float_eq(ceil(-1), s21_ceil(-1));
  ck_assert_ldouble_eq(ceil(-10.7), s21_ceil(-10.7));
  ck_assert_ldouble_eq(ceil(INFINITY), s21_ceil(INFINITY));
  ck_assert_ldouble_nan(ceil(NAN));
  ck_assert_ldouble_eq(ceil(-INFINITY), s21_ceil(-INFINITY));
}
END_TEST

START_TEST(s21_fabs_test) {
  // READY
  ck_assert_int_eq(fabs(0.0), s21_fabs(0.0));
  ck_assert_int_eq(fabs(0.12), s21_fabs(0.12));
  ck_assert_int_eq(fabs(-0.12), s21_fabs(-0.12));
  ck_assert_int_eq(fabs(34.5), s21_fabs(34.5));
  ck_assert_int_eq(fabs(-34.5), s21_fabs(-34.5));
  ck_assert_int_eq(fabs(3412312312.52321), s21_fabs(3412312312.52321));
  ck_assert_int_eq(fabs(-3412312312.52321), s21_fabs(-3412312312.52321));
}
END_TEST

START_TEST(s21_floor_test) {
  // READY
  ck_assert_ldouble_eq(floor(0), s21_floor(0));
  ck_assert_ldouble_eq(floor(1), s21_floor(1));
  ck_assert_ldouble_eq(floor(123123), s21_floor(123123));
  ck_assert_ldouble_eq(floor(-123123), s21_floor(-123123));
  ck_assert_ldouble_eq(floor(2.5), s21_floor(2.5));
  ck_assert_int_eq(floor(-0.7), s21_floor(-0.7));
  ck_assert_int_eq(floor(-1.7), s21_floor(-1.7));
  ck_assert_ldouble_eq(floor(-2.5), s21_floor(-2.5));
  ck_assert_ldouble_eq(floor(1.8), s21_floor(1.8));
  ck_assert_ldouble_eq(floor(-1.8), s21_floor(-1.8));
  ck_assert_ldouble_eq(floor(0.123123213), s21_floor(0.123123213));
  ck_assert_ldouble_eq(floor(INFINITY), s21_floor(INFINITY));
  ck_assert_ldouble_eq(floor(-INFINITY), s21_floor(-INFINITY));
  ck_assert_ldouble_nan(floor(NAN));
}
END_TEST

START_TEST(s21_fmod_test) {
  // READY
  ck_assert_float_nan(s21_fmod(32452354.23423, 0));
  ck_assert_double_nan(s21_fmod(0, NAN));
  ck_assert_double_nan(s21_fmod(0, NAN));
  ck_assert_double_nan(s21_fmod(0, -NAN));
  ck_assert_double_nan(s21_fmod(NAN, NAN));
  ck_assert_double_nan(s21_fmod(NAN, 2345.123123));
  ck_assert_float_nan(s21_fmod(INFINITY, 3423423.31231));
  ck_assert_float_nan(s21_fmod(INFINITY, 3423423.31231));
  ck_assert_float_nan(s21_fmod(INFINITY, 0));
  ck_assert_float_nan(s21_fmod(-INFINITY, 0));
  ck_assert_ldouble_eq_tol(fmod(0, INFINITY), s21_fmod(0, INFINITY), S21_EPS);
  ck_assert_ldouble_eq_tol(fmod(4363467.34523, INFINITY),
                           s21_fmod(4363467.34523, INFINITY), S21_EPS);
  ck_assert_ldouble_eq_tol(fmod(4363467.34523, -INFINITY),
                           s21_fmod(4363467.34523, -INFINITY), S21_EPS);
  ck_assert_float_eq_tol(fmod(4363467.34523, 4322.12313),
                         s21_fmod(4363467.34523, 4322.12313), S21_EPS);
  ck_assert_float_eq_tol(fmod(4363467.34523, -4322.12313),
                         s21_fmod(4363467.34523, -4322.12313), S21_EPS);
  ck_assert_float_eq_tol(fmod(0, 4363467.34523), s21_fmod(0, 4363467.34523),
                         S21_EPS);
  ck_assert_float_eq_tol(fmod(-5.2, -1.9), s21_fmod(-5.2, -1.9), S21_EPS);
}
END_TEST

START_TEST(s21_log_test) {
  // READY
  ck_assert_ldouble_nan(s21_log(NAN));
  ck_assert_ldouble_nan(s21_log(-NAN));
  ck_assert_ldouble_nan(s21_log(-INFINITY));
  ck_assert_float_eq_tol(log(5.3123123), s21_log(5.3123123), S21_EPS);
  ck_assert_float_nan(s21_log(-343234.423));
  ck_assert_float_eq_tol(log(4.3234323e-43), s21_log(4.3234323e-43), S21_EPS);
  ck_assert_float_eq_tol(log(2.345), s21_log(2.345), S21_EPS);
}
END_TEST

START_TEST(s21_pow_test) {
  // READY
  ck_assert_double_infinite(s21_pow(0, -1));
  ck_assert_double_infinite(s21_pow(INFINITY, 12));
  ck_assert_double_eq_tol(pow(-INFINITY, -12), s21_pow(-INFINITY, -12),
                          S21_EPS);
  ck_assert_double_infinite(s21_pow(-INFINITY, 12));
  ck_assert_double_eq_tol(pow(INFINITY, -12), s21_pow(-INFINITY, -12), S21_EPS);
  ck_assert_float_infinite(s21_pow(0.234234, -INFINITY));
  ck_assert_float_eq_tol(pow(0.234234, INFINITY), s21_pow(0.234234, INFINITY),
                         S21_EPS);
  ck_assert_double_eq_tol(pow(13, -INFINITY), s21_pow(13, -INFINITY), S21_EPS);
  ck_assert_double_infinite(s21_pow(13, INFINITY));
  ck_assert_float_eq_tol(pow(-1, INFINITY), s21_pow(-1, INFINITY), S21_EPS);
  ck_assert_double_eq_tol(pow(0, 12), s21_pow(0, 12), S21_EPS);
  ck_assert_double_infinite(s21_pow(0, -12));
  ck_assert_double_eq_tol(pow(0, 0), s21_pow(0, 0), S21_EPS);
  ck_assert_float_eq_tol(pow(123.35, 1.4), s21_pow(123.35, 1.4), S21_EPS);
  ck_assert_double_eq_tol(pow(12.35, 20.5e-34), s21_pow(12.35, 20.5e-34),
                          S21_EPS);
  ck_assert_float_eq_tol(pow(1233.35, -42.), s21_pow(1233.35, -42.), S21_EPS);
  ck_assert_double_eq_tol(pow(2.3, 3.), s21_pow(2.3, 3.), S21_EPS);
  ck_assert_float_nan(s21_pow(-27.45, 1.0 / 3.0));
  ck_assert_double_nan(s21_pow(-10.1, -1.5));
  ck_assert_double_eq_tol(pow(-10.1, -3.), s21_pow(-10.1, -3.), S21_EPS);
  ck_assert_double_eq_tol(pow(-10.1, 2.), s21_pow(-10.1, 2.), S21_EPS);
  ck_assert_float_eq_tol(pow(10.1, 0.123), s21_pow(10.1, 0.123), S21_EPS);
  ck_assert_double_eq_tol(pow(1.0, 1), s21_pow(1.0, 1), S21_EPS);
  ck_assert_double_eq_tol(pow(1.0, 0), s21_pow(1.0, 0), S21_EPS);
  ck_assert_double_eq_tol(pow(1.0, 1.23), s21_pow(1.0, 1.23), S21_EPS);
  ck_assert_double_eq_tol(pow(1.0, -1.23), s21_pow(1.0, -1.23), S21_EPS);
  ck_assert_double_eq_tol(pow(1.0, NAN), s21_pow(1.0, NAN), S21_EPS);
  ck_assert_double_eq_tol(pow(1.0, -NAN), s21_pow(1.0, -NAN), S21_EPS);
  ck_assert_double_eq_tol(pow(1.0, INFINITY), s21_pow(1.0, INFINITY), S21_EPS);
  ck_assert_double_eq_tol(pow(1.0, -INFINITY), s21_pow(1.0, -INFINITY),
                          S21_EPS);
  ck_assert_double_eq_tol(pow(1.12, 0), s21_pow(1.12, 0), S21_EPS);
  ck_assert_double_eq_tol(pow(-1.12, 0), s21_pow(-1.12, 0), S21_EPS);
  ck_assert_float_nan(s21_pow(-34.25, NAN));
  ck_assert_float_nan(s21_pow(-34.25, -NAN));
  ck_assert_float_nan(s21_pow(INFINITY, -NAN));
  ck_assert_float_nan(s21_pow(INFINITY, NAN));
  ck_assert_float_nan(s21_pow(-INFINITY, NAN));
  ck_assert_float_nan(s21_pow(-INFINITY, -NAN));
  ck_assert_float_nan(s21_pow(34.25, NAN));
  ck_assert_float_nan(s21_pow(-34.25, -NAN));
  ck_assert_double_nan(s21_pow(2, NAN));
  ck_assert_float_nan(s21_pow(NAN, NAN));
  ck_assert_float_nan(s21_pow(NAN, -NAN));
  ck_assert_float_nan(s21_pow(-NAN, NAN));
  ck_assert_float_nan(s21_pow(-NAN, -NAN));
  ck_assert_float_nan(s21_pow(123.2312, -NAN));
  ck_assert_float_nan(s21_pow(123.2312, NAN));
  ck_assert_float_nan(s21_pow(NAN, 1));
  ck_assert_float_nan(s21_pow(NAN, -1));
  ck_assert_float_nan(s21_pow(-NAN, 1));
  ck_assert_float_nan(s21_pow(NAN, -11.1));
  ck_assert_float_nan(s21_pow(-NAN, 11.1));
  ck_assert_float_nan(s21_pow(NAN, INFINITY));
  ck_assert_float_nan(s21_pow(NAN, -INFINITY));
  ck_assert_float_nan(s21_pow(-NAN, -1));
  ck_assert_float_nan(s21_pow(-NAN, INFINITY));
  ck_assert_float_nan(s21_pow(-NAN, -INFINITY));
  ck_assert_float_eq_tol(pow(35.5, 2.4), s21_pow(35.5, 2.4), S21_EPS);
  ck_assert_double_eq_tol(pow(INFINITY, 0), s21_pow(INFINITY, 0), S21_EPS);
  ck_assert_double_eq_tol(pow(-INFINITY, 0), s21_pow(-INFINITY, 0), S21_EPS);
  ck_assert_double_eq_tol(pow(NAN, 0), s21_pow(NAN, 0), S21_EPS);
  ck_assert_double_eq_tol(pow(-NAN, 0), s21_pow(-NAN, 0), S21_EPS);
  ck_assert_float_eq_tol(pow(9.24, 0.345), s21_pow(9.24, 0.345), S21_EPS);
  ck_assert_double_eq_tol(pow(10, 1), s21_pow(10, 1), S21_EPS);
  ck_assert_float_eq_tol(pow(10.3456, 1), s21_pow(10.3456, 1), S21_EPS);
}
END_TEST

START_TEST(s21_sin_test) {
  // READY
  ck_assert_ldouble_eq_tol(sin(0.123443), s21_sin(0.123443), S21_EPS);
  ck_assert_ldouble_eq_tol(sin(0), s21_sin(0), S21_EPS);
  ck_assert_ldouble_eq_tol(sin(2), s21_sin(2), S21_EPS);
  ck_assert_ldouble_eq_tol(sin(-2), s21_sin(-2), S21_EPS);
  ck_assert_ldouble_eq_tol(sin(2.344), s21_sin(2.344), S21_EPS);
  ck_assert_ldouble_eq_tol(sin(-2.344356), s21_sin(-2.344356), S21_EPS);
  ck_assert_float_eq_tol(sin(9234239234.123456), s21_sin(9234239234.123456),
                         1e-6);
  ck_assert_float_eq_tol(sin(-9234239234.123456), s21_sin(-9234239234.123456),
                         1e-6);
  ck_assert_float_nan(s21_sin(NAN));
  ck_assert_float_nan(s21_sin(INFINITY));
}
END_TEST

START_TEST(s21_tan_test) {
  ck_assert_double_nan(s21_tan(NAN));
  ck_assert_double_nan(s21_tan(INFINITY));
  ck_assert_double_nan(s21_tan(-INFINITY));
  ck_assert_double_eq_tol(tan(S21_PI), s21_tan(S21_PI), S21_EPS);
  ck_assert_double_eq_tol(tan(0.1231342355237567), s21_tan(0.1231342355237567),
                          S21_EPS);
  ck_assert_double_eq_tol(tan(0), s21_tan(0), S21_EPS);
  ck_assert_double_eq_tol(tan(1), s21_tan(1), S21_EPS);
  ck_assert_double_eq_tol(tan(-1), s21_tan(-1), S21_EPS);
  ck_assert_double_eq_tol(tan(0.5), s21_tan(0.5), S21_EPS);
  ck_assert_double_eq_tol(tan(400000.123), s21_tan(400000.123), S21_EPS);
  ck_assert_double_eq_tol(tan(-400000.123), s21_tan(-400000.123), S21_EPS);
  ck_assert_double_eq_tol(tan(1 + S21_EPS), s21_tan(1 + S21_EPS), S21_EPS);
  ck_assert_double_eq_tol(tan(-1 - S21_EPS), s21_tan(-1 - S21_EPS), S21_EPS);

  // printf("%.16f\n", atan(S21_NAN));
  // printf("%.16Lf", s21_atan(S21_NAN));
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_abs_test);
  tcase_add_test(tc1_1, s21_sqrt_test);
  tcase_add_test(tc1_1, s21_cos_test);
  tcase_add_test(tc1_1, s21_exp_test);
  tcase_add_test(tc1_1, s21_acos_test);
  tcase_add_test(tc1_1, s21_asin_test);
  tcase_add_test(tc1_1, s21_atan_test);
  tcase_add_test(tc1_1, s21_ceil_test);
  tcase_add_test(tc1_1, s21_fabs_test);
  tcase_add_test(tc1_1, s21_floor_test);
  tcase_add_test(tc1_1, s21_fmod_test);
  tcase_add_test(tc1_1, s21_log_test);
  tcase_add_test(tc1_1, s21_pow_test);
  tcase_add_test(tc1_1, s21_sin_test);
  tcase_add_test(tc1_1, s21_tan_test);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}