/*
** EPITECH PROJECT, 2023
** Day09
** File description:
** Placeholder
*/

#include <stdarg.h>

#ifndef MY_H_
    #define MY_H_

union union_nb {
    double d;
    unsigned long int l;
};
typedef struct params {
    int flags;
    int width;
    int *precision;
    int length;
    int specifier;
} params_t;
typedef struct to_print {
    char space;
    char *left_pad;
    char sign;
    char *alt_form;
    char *arg;
    char *right_pad;
} to_print_t;
int get_exponent(union union_nb nb);
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_find_prime_sup(int);
int my_getnbr(char const *);
int my_isneg(int);
int my_is_prime(int);
int my_putnbr_base(int, char const *);
int my_putstr(char const *);
char *my_revstr(char *);
int my_showstr(char const *);
char *my_strcapitalize(char *);
char *my_strcat(char *, char const *);
int my_strcmp(char const *, char const *);
char *my_strcpy(char *, char const *);
int my_str_isalpha(char const *);
int my_str_islower(char const *);
int my_str_isnum(char const *);
int my_str_isprintable(char const *);
int my_str_isupper(char const *);
int my_strlen(char const *);
char *my_strlowcase(char *);
char *my_strncat(char *, char const *, int);
int my_strncmp(char const *, char const *, int);
char *my_strncpy(char *, char const *, int);
char *my_strstr(char *, char const *);
char *my_strupcase(char *);
int my_swap(int *, int *);
int my_is_prime2(int);
int verif(int, long);
long my_getnbr2(char const *, int, long);
int len_st(char const *);
void write_str(char *, int);
long is_negative(long);
long reverse_nb(long);
int my_strlen2(char const *);
int len_st2(char const *);
void write_str2(char *, int);
int my_putnbr_base2(int, char const *);
int my_show_word_array(char const **);
int is_number(char);
int is_upper_case(char);
int is_lower_case(char);
int is_letter_number(char);
int is_ucase(char);
int is_lcase(char);
int is_lower(char);
int is_num(char);
int is_upper(char);
int str_len(char const *);
int my_strncmp2(char const *, char const *, int);
int len_str(char const *);
int is_anum(char);
int count_words(char const *);
void modify_str(char const *, char **);
char **my_str_to_word_array(char const *);
void my_putnbr(int);
float step01(char *, char);
void step02(int, char **);
void step03(char **, int);
char *my_putnbr_str(int);
int len_nbr(int);
void do_hashtag(to_print_t *, params_t);
void do_space(to_print_t *, params_t);
void do_plus(to_print_t *, params_t);
void do_flags(to_print_t *, params_t);
int is_flag(char);
int get_flags(const char *restrict);
int get_length(const char *restrict);
void get_params(params_t *, const char *restrict);
int get_specifier(char);
int my_printf_percent(va_list list, params_t *);
int write_struct(to_print_t);
void min_digits_precision(char **arg, int precision);
to_print_t initialize_to_print(void);
int my_printf_o(va_list list, params_t *params);
int my_printf_u(va_list list, params_t *params);
int my_printf_x(va_list list, params_t *params);
int my_printf_ux(va_list list, params_t *params);
int my_printf_s(va_list list, params_t *params);
int my_printf_c(va_list list, params_t *params);
int my_printf_p(va_list list, params_t *params);
void my_printf_n(va_list list, params_t *params, int count);
int my_printf_b(va_list list, params_t *params);
int my_printf_f(va_list list, params_t *params);
int my_printf_a(va_list list, params_t *params);
int my_printf_ua(va_list list, params_t *params);
int my_printf_g(va_list list, params_t *params);
int is_specifier(char c);
int go_to_specifier(const char *restrict format);
int found_percent(va_list list, const char *restrict format, int total);
int my_printf(const char *restrict format, ...);
char *my_putnbr_str_double(double, to_print_t *);
int my_printf_d(va_list list, params_t *params);
int my_printf_i(va_list list, params_t *params);
char *my_printf_e_str(double, params_t *);
char *my_printf_e_precision(double, params_t *, int);
to_print_t my_printf_e(double, params_t *);
int my_printf_ee(va_list list, params_t *);
char *my_putnbr_str_float(double, params_t *);
char *my_putnbr_str_float_final(double, params_t *);
char *my_printf_ue_str(double, params_t *);
char *my_printf_ue_precision(double, params_t *, int);
to_print_t my_printf_ue(double, params_t *);
int my_printf_uee(va_list list, params_t *);
int my_printf_ug(va_list list, params_t *);
#endif /* MY_H_ */
