/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivork <ivork@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/15 22:39:36 by ivork         #+#    #+#                 */
/*   Updated: 2021/10/12 17:42:49 by ivork         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdbool.h>
# include "../libft.h"

typedef struct s_flags
{
	char			specifier;
	int				count;
	int				width;
	int				precision;
	bool			left_align;
	bool			zero;
	bool			preci;
}					t_flags;

int					ft_printf(const char *str, ...);
void				ft_print_char(char c, t_flags flags);
void				ft_print_str(char *str, t_flags feat);
void				ft_putnstr_fd(char *s, int fd, int n);
void				ft_print_int(int x, t_flags flag);
void				ft_print_pos(char *str, t_flags flag);
void				ft_print_neg(char *str, t_flags flag);
void				ft_print_unsi(long long x, t_flags flag);
void				ft_print_hexa(unsigned int x, t_flags flag);
void				ft_print_point(unsigned long long x, t_flags flag);
char				*ft_uitoa(unsigned int n);
t_flags				ft_init_flag(void);
#endif
