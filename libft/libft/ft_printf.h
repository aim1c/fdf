/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 00:59:57 by marvin            #+#    #+#             */
/*   Updated: 2019/05/29 00:58:10 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_FT_PRINTF_H
# define FILLIT_FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>

/*
** -------------------------- define for return ft_printf ----------------
*/

# define RETURN		100000000
# define SET_NULL	100000001
# define TRUE 1
# define FALSE 0

/*
** -------------------------- define for Doubles --------------------------
*/

# define EX0 1023
# define EX1 16383
# define MAX(a, b) (a > b) ? (a) : (b)
# define PINF "0111111111110000000000000000000000000000000000000000000000000000"
# define MINF "1111111111110000000000000000000000000000000000000000000000000000"
# define NAAN "1111111111111000000000000000000000000000000000000000000000000000"

/*
** -------------------------- define for Colors --------------------------
*/

# define BLACK "\033[1;30m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MADJENTA "\033[1;35m"
# define CIAN "\033[1;36m"
# define WHITE "\033[1;37m"
# define RESET	"\033[0m"

typedef struct	s_print
{
	char		*format;
	int			form;
	char		*flag;
	int			width;
	int			strike;
	char		spec;
	char		lenght[3];
	va_list		ap;
}				t_prin;

typedef struct	s_flags
{
	int			minus;
	int			plus;
	int			space;
	int			zero;
	int			zero_space;
	int			plus_zero;
	int			all_flags;
	int			plus_space;
	int			plus_minus;
	int			len;
}				t_flags;

typedef struct	s_double
{
	char		*exp;
	char		*mantis;
	int			strike;
	int			sign;
	char		*res;
	char		*lowres;
}				t_double;

int				ft_printf(const char *format, ...);

/*
** -------------------------- Check L, ll, l, h, hh ------------------
*/

void			ft_get_lenght(t_prin *p);
int				is_spec(int a);

/*
** -------------------------- Doubles --------------------------------
*/

void			fprint(t_prin *p);
void			flprint(t_prin *p);
char			*ft_getdbl(double dbl, int strike);
char			*ft_get_ldbl(long double dbl, int strike);
char			*ft_sum_str(char *s1, char *s2);
char			*ft_mult_str5(int m, int exp);
char			*ft_mult_str2(int m, int exp);
char			*ft_mult_str10(char *s);
char			*ft_make_small(char *mantis, int ex);
/*
** Only negative int - ft_make_small
*/

int				ft_round_off(char *lowres, int strike);
void			ft_putzero(char **lowres, int strike);
void			ft_round(char **res);
void			ft_strike(t_double *suka, char *trash);
void			ft_setresult(char *mantis, t_double *suka);
void			ft_set_lresult(char *mantis, t_double *suka);

/*
** -------------------------- Strings --------------------------------
*/

void			sprint(char *tmp, int sp);
void			ssprint(int *tmp, int sp);
void			sdprint(t_prin *print);
void			ssdprint(t_prin *p);
void			cprint(t_prin *p);
int				ft_prin_c(int a);
/*
** -------------------------- Digits ---------------------------------
*/

void			dprint(t_prin *print);
void			eprint(t_prin *p);
void			oprint(t_prin *p);
void			uprint(t_prin *p);
void			xprint(t_prin *p);

/*
** -------------------------- Check % --------------------------------
*/

void			check_spec(t_prin *print);
void			what_do(int c, t_prin *p);
void			tim(t_prin *p);
int				ft_flag(char *dest, char *flags);
void			free_p(t_prin *p);
int				ft_a_null(const char *tmp, int i);

/*
** -------------------------- Write ' ', '0', str --------------------
*/

void			ft_putstr_rev(char *tmp, int i);
void			print_null_sp(int widh, char a);

/*
** ----------------------------- %n ----------------------------------
*/

void			nprint(t_prin *p);

/*
** -------------------------- %p ------------------------------------
*/

void			pprint(t_prin *p);
void			j_p_p(int len, char *tmm);
void			write_this_shit(t_prin *p, char *tmm);
char			table_hex(int i, char spec);

/*
** -------------------------- %% ------------------------------------
*/

void			piskaprint(t_prin *p);
void			getcolor(t_prin *p);

/*
** -------------------------- ЗАЕБАЛСЯ ДЕЛАЮ В ЛОБ ИНТ -------------
*/

int64_t			ft_get_res(t_prin *p);
void			get_curren_flags_int(t_flags *f, t_prin *p);
void			int_zero_space(t_prin *p, t_flags *f, int mi, char *tmm);
void			int_all_flags(t_prin *p, int mi, char *tmm);
void			int_plus_zero(t_prin *p, t_flags *f, int mi, char *tmm);
void			int_print_without_flag(t_prin *p, int mi, char *tmm);
void			int_only_plus(t_prin *p, int mi, char *tmm);
void			int_only_minus(t_prin *p, int mi, char *tmm);
void			int_only_zero(t_prin *p, int mi, char *tmm);
void			int_only_space(t_prin *p, int mi, char *tmm);
size_t			ft_get_ures(t_prin *p);

#endif
